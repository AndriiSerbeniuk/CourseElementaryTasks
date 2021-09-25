#pragma once
#include "file_line_counter.hpp"
#include "file_replacer.hpp"

class ParserFactory
{
    public:
        FileParser* get_replaser(std::string path, std::string original,
            std::string replacement);
        
        FileParser* get_counter(std::string path, std::string line,
            int& return_variable);
};