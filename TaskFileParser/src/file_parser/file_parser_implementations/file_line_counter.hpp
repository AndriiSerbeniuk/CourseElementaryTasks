#pragma once
#include "file_parser.hpp"

class FileLineCounter : public FileParser
{
    public:
        FileLineCounter(const std::string& path, const std::string& line, int& ret_count);

        void process();

    private:
        std::string line_;
        int& return_variable_;
};
