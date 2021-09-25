#include <iostream>
#include "parser_factory.hpp"

int main(int argc, const char** argv)
{
    if (argc < 3 || argc > 4)
    {
        std::cout << "Wrong amount of arguments provided. Required arguments:\n"
            << "\"filepath\" \"line\" - count instances of the line in the file;\n"
            << "\"filepath\" \"line\" \"replacement line\" - replace instances "
            << "of one line with another line.\n\n";
        return 0;
    }

    ParserFactory pf;
    FileParser* parser;
    switch (argc)
    {
    case 3:
    {
        try
        {
            int count;
            parser = pf.get_counter(argv[1], argv[2], count);
            parser->process();
            std::cout << "\"" << argv[2] << "\" was met " << count << " times.";
            delete parser;
        }
        catch(const std::exception& e)
        {
            std::cerr << "Error while working with the file: "
                << e.what();
        }
    }
        break;
    case 4:
        try
        {
            parser = pf.get_replaser(argv[1], argv[2], argv[3]);
            parser->process();
            std::cout << "All \"" << argv[2] << "\" instances have been" 
                << " replaced with \"" << argv[3] << "\"";
            delete parser;
        }
        catch(const std::exception& e)
        {
            std::cerr << "Error while working with the file.";
        }
        break;
    }
    std::cout << "\n\n";
    return 0;
}