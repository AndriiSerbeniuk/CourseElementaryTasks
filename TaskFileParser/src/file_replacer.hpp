#pragma once
#include "file_parser.hpp"

class FileReplacer : public FileParser
{
    public:
        FileReplacer(const std::string& path, const std::string& original,
            const std::string& replacement);

        void process();

    private:
        std::string original_line_;
        std::string replacement_line_;
};
