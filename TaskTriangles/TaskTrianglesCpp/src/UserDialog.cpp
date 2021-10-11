#include "UserDialog.hpp"
#include <limits>

const char* UserDialog::kEntryPrompt = "\n>: ";

void UserDialog::run() {
  while (ask_start())
  {
    std::unique_ptr<Triangle> tr = ask_triangle();
    m_triangles.insert(Triangle(*tr));
    form_triangles_table();
  }
}

bool UserDialog::ask_start() {
  std::cout << "\nWould you like to start? (y/n)" << kEntryPrompt;
  char ans;
  bool ret_val = false;
  do {
    ans = fgetc(stdin);
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    ans = tolower(ans);
    switch (ans) {
      case 'y':
        ret_val = true;
        break;
      case 'n':
        break;
      default:
        std::cout << "\nUnknown command. Try again." << kEntryPrompt;
        continue;
    }

  } while (ans != 'y' && ans != 'n');
  return ret_val;
}

std::unique_ptr<Triangle> UserDialog::ask_triangle() {
    std::unique_ptr<Triangle> triangle;
    TriangleFactory factory;
    StringArgs args;
    StringExtractor extractor;

    std::cout << "\nEnter a triangle in the following format:\n"
      << "\"name, side a, side b, side c\"\n" << kEntryPrompt;
    bool success = false;
    int text_size = 256;
    char text[256];
    do 
    {
        std::cin.getline(text, text_size);
        try 
        {
            args.triangle_text = text;
            triangle.reset((Triangle*)factory.GetTriangle(&args, &extractor));
            success = true;
        }
        catch (const std::exception& e) 
        {
            std::cout << "Invalid arguments: " << e.what() 
                << "\nTry again." << kEntryPrompt;
        }
    } while (!success);

    return triangle;
}

void UserDialog::form_triangles_table() {
  int i = 1;
  std::cout << "\n============== Triangles list ==============\n";
  for (auto t = m_triangles.cbegin(), e = m_triangles.cend(); t != e; t++, i++) {    
    std::cout << i << ". " << (std::string)*t << "\n";
  }
}
