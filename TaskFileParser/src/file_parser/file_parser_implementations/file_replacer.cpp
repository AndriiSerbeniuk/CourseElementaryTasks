#include "file_replacer.hpp"

FileReplacer::FileReplacer(const std::string& path, 
    const std::string& original, const std::string& replacement)
    : FileParser(path), original_line_(original),
    replacement_line_(replacement)
    {}

void FileReplacer::process()
{
        std::ifstream rfile(path_);
    if (!rfile.is_open())
    {
        throw std::ios_base::failure("Couldn't open \"" + path_ + "\" for reading");
    }
    // Find the specified line instances in the file
    std::vector<int> positions;
    int line_pos = 0;
    do 
    {
        line_pos = find_line(rfile, original_line_.c_str());
        if (line_pos != -1) 
        {
            positions.push_back(line_pos);
        }
    } while (line_pos != -1);
    // Write new contents with replaced lines into a temporary file
    FILE* temp = tmpfile();
    if (!temp)
    {
        throw std::ios_base::failure("Couldn't create a temporary file");
    }
    rfile.seekg(0);
    int start_pos = 0;
    int copy_len, line_len = original_line_.length();
    char* buf;
    // Copy unmodified contents, skip previously found lines
    // and write replacement lines instead
    for (auto pos : positions) 
    {
        copy_len = pos - start_pos;
        buf = new char[copy_len + 1];
        rfile.read(buf, copy_len);
        fprintf(temp, "%s%s", buf, replacement_line_.c_str());
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
        throw std::ios_base::failure("Couldn't open \"" + path_ + "\" for writing");
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
