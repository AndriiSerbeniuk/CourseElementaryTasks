#include "file_line_counter.hpp"

FileLineCounter::FileLineCounter(const std::string& path, const std::string& line, 
    int& ret_count) : FileParser(path), line_(line), return_variable_(ret_count)
    {}

void FileLineCounter::process()
{
    std::ifstream file(path_);
    if (!file.is_open())
    {
        throw std::ios_base::failure("Couldn't open \"" + path_ + "\" for reading");
    }
    int line_pos, line_count = 0;
    do 
    {
        line_pos = find_line(file, line_.c_str());
        // Actual positions don't matter in this case, unless there is none
        if (line_pos != -1) 
        {
            line_count++;
        }
    } while (line_pos != -1);
    file.close();

    return_variable_ = line_count;
}