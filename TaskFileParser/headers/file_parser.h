#pragma once
#include <string>

class FileParser {
  public:
    
    // find_line() and increment counter while !EOF
    int count_instances(const std::string& line);

    // find_line() then replace (look up how to replace)
    void replace(const std::string& line);

  private:
    std::string path_;

    fpos_t find_line(fpos_t start_pos, const std::string& line);
};