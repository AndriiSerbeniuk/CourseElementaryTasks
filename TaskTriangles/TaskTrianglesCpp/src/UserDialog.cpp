#include <limits>
#include <algorithm>
#include "UserDialog.hpp"

const char* UserDialog::ENTRY_PROMPT = "\n>: ";

void UserDialog::Run() 
{
    while (AskStart())
    {
        std::unique_ptr<AreaTriangle> tr = AskTriangle();
        AddTriangle(*tr);
        std::cout << FormTrianglesTable();
    }
}

bool UserDialog::AskStart() const
{
    std::cout << "\nWould you like to start? (y/n)" << ENTRY_PROMPT;
    char ans;
    bool start = false;

    do 
    {
        std::string ans_line;
        std::cin >> ans_line;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        try
        {
            ans = tolower(ToChar(ans_line));
        }
        catch (const std::exception& e)
        {
            ans = '\0';
        }

        switch (ans) 
        {
            case 'y':
                start = true;
                break;
            case 'n':
                break;
            default:
                std::cout << "\nUnknown command. Try again." << ENTRY_PROMPT;
                continue;
        }
    } while (ans != 'y' && ans != 'n');

    return start;
}

std::unique_ptr<AreaTriangle> UserDialog::AskTriangle() const
{
    std::unique_ptr<AreaTriangle> triangle;
    AreaTriangleFactory factory;
    StringArgs args;
    StringArgsExtractor extractor;
    bool success = false;
    int text_size = 256;
    char text[256];

    std::cout << "\nEnter a triangle in the following format:\n"
      << "\"name, side a, side b, side c\"\n" << ENTRY_PROMPT;

    do 
    {
        std::cin.getline(text, text_size);
        
        try 
        {
            args.triangle_text = text;
            triangle.reset((AreaTriangle*)factory.GetTriangle(&args, &extractor));
            success = true;
        }
        catch (const std::exception& e) 
        {
            std::cout << "Invalid arguments: " << e.what() 
                << "\nTry again." << ENTRY_PROMPT;
        }
    } while (!success);

    return triangle;
}

void UserDialog::AddTriangle(const AreaTriangle& triangle)
{
    m_triangles.insert(triangle);
}

std::string UserDialog::FormTrianglesTable() const
{
    int i = 1;
    std::string table;

    table += "\n============== Triangles list ==============\n";
    for (auto t = m_triangles.cbegin(), e = m_triangles.cend(); t != e; t++, i++) 
    {    
      table += std::to_string(i) + ". " + (std::string)*t + "\n";
    }

    return table;
}

char UserDialog::ToChar(const std::string& text) const 
{
    std::string tcopy(text);
    // Erase all whitespaces
    std::remove_if(tcopy.begin(), tcopy.end(), [](char& ch)
    {
        return isspace(ch);
    });
    
    if (tcopy.size() != 1)
    {
        throw std::invalid_argument("Entered line can't be narrowed down to a char.");
    }

    return tcopy[0];
}

