#include "file_parser.h"

const int FileParser::kBufSize = 4096;

FileParser::FileParser(std::string path) : path_(path) {}

std::string FileParser::get_path() const
{
    return path_;
}

void FileParser::set_path(std::string path)
{
    path_ = path;
}

int FileParser::count_instances(const std::string& line) 
{
    std::ifstream file(path_);
    int line_pos, line_count = 0;
    do 
    {
        line_pos = find_line(file, line.c_str());
        // Actual positions don't matter in this case, unless there is none
        if (line_pos != -1) 
        {
            line_count++;
        }
    } while (line_pos != -1);
    file.close();

    return line_count;
}

void FileParser::replace(const std::string& original, 
    const std::string& replacement)
{
    std::ifstream rfile(path_);
    if (!rfile.is_open())
    {
        throw std::exception();
    }
    // Find the specified line instances in the file
    std::vector<int> positions;
    int line_pos = 0;
    do 
    {
        line_pos = find_line(rfile, original.c_str());
        if (line_pos != -1) 
        {
            positions.push_back(line_pos);
        }
    } while (line_pos != -1);
    // Write new contents with replaced lines into a temporary file
    FILE* temp = tmpfile();
    rfile.seekg(0);
    int buf_size, start_pos = 0;
    int copy_len, line_len = original.length();
    char* buf;
    // Copy unmodified contents, skip previously found lines
    // and write replacement lines instead
    for (auto pos : positions) 
    {
        copy_len = pos - start_pos;
        buf = new char[copy_len + 1];
        rfile.read(buf, copy_len);
        fprintf(temp, "%s%s", buf, replacement.c_str());
        delete[] buf;
        start_pos = pos + line_len;
        rfile.seekg(start_pos);
    }
    // Copy all that's left after the last replaced line
    buf = new char[copy_len + 1];
    rfile.read(buf, copy_len);
    fprintf(temp, "%s", buf);

    rfile.close();
    // Write modified contents into the original file
    std::ofstream wfile(path_);
    if (!wfile.is_open())
    {
        throw std::exception();
    }
    fseek(temp, 0, SEEK_SET);
    buf = new char[kBufSize];
    while (!feof(temp)) 
    {
        fread(buf, sizeof(char), kBufSize, temp);
        wfile << buf;
    }
    delete[] buf;

    wfile.close();
    fclose(temp);
}

int FileParser::find_line(std::ifstream& file, const char* line) 
{
    if (!file.is_open()) 
    {
        // TODO: Use files related exception type
        throw std::exception();
    }
    int cur_pos, ret_val = -1;
    char linebuf[kBufSize];
    while (!file.eof() && ret_val == -1) 
    {
        cur_pos = file.tellg();
        file.getline(linebuf, kBufSize, '\n');
        if (!strcmp(linebuf, line))
        {
            ret_val = cur_pos;
        }
    }
    
    return ret_val;
}