#include <iostream>
#include "file_parser.h"

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

    FileParser fp(argv[1]);
    switch (argc)
    {
    case 3:
    {
        try
        {
            int c = fp.count_instances(argv[2]);
            std::cout << "\"" << argv[2] << "\" was met " << c << " times.";
        }
        catch(const std::exception& e)
        {
            std::cerr << "Error while working with the file.";
        }
    }
        break;
    case 4:
        try
        {
            fp.replace(argv[2], argv[3]);
            std::cout << "All \"" << argv[2] << "\" instances have been" 
                << " replaced with \"" << argv[3] << "\"";
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