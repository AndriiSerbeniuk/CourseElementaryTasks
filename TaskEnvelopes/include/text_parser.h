#pragma once
#include <string>

// Parser text into other types with some custom logic
class TextParser {
public:
  TextParser();
  virtual ~TextParser();

  float to_float(const std::string& text);
  // Erases all whitespaces
  char to_char(const std::string& text);
};