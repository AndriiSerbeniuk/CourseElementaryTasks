#include "parser_factory.hpp"

FileParser* ParserFactory::get_replaser(std::string path, std::string original,
    std::string replacement)
{
    return new FileReplacer(path, original, replacement);
}
        
FileParser* ParserFactory::get_counter(std::string path, std::string line,
    int& return_variable)
{
    return new FileLineCounter(path, line, return_variable);
}