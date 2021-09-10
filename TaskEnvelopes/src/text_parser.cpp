#include "text_parser.h"
#include <stdexcept>

TextParser::TextParser() {}
TextParser::~TextParser() {}

float TextParser::to_float(const std::string& text) {
  return std::stof(text);
}

char TextParser::to_char(const std::string& text) {
  std::string tcopy(text);
  // Erase all whitespaces
  for (int i = 0; i < tcopy.size(); i++)
  {
    if (isspace(tcopy[i]))
    {
      tcopy.erase(tcopy[i]);
      i--;
    }
  }
  if (tcopy.size() != 1)
    throw std::invalid_argument("Entered line can't be narrowed down to a char.");
  return tcopy[0];
}