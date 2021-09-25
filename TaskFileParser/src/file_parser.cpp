#include "file_parser.hpp"

const int FileParser::kBufSize = 4096;

FileParser::FileParser(const std::string& path) : path_(path) {}

std::string FileParser::get_path() const
{
    return path_;
}

void FileParser::set_path(const std::string& path)
{
    path_ = path;
}

int FileParser::find_line(std::ifstream& file, const char* line) 
{
    if (!file.is_open()) 
    {
        throw std::ios_base::failure("Filestream was not open.");
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