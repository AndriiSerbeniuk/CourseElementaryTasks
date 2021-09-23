#pragma once
#include <string.h>
#include <fstream>
#include <vector>

class FileParser {
  public:
    FileParser(const std::string& path);
    
    // find_line() and increment counter while !EOF
    int count_instances(const std::string& line);

    // find_line() then replace (look up how to replace)
    void replace(const std::string& line);

  private:
    std::string path_;
    
    int find_line(std::ifstream& file, const char* line);
};