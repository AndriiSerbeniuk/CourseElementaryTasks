#include "file_parser.h"

FileParser::FileParser(const std::string& path) : path_(path) {}

int FileParser::count_instances(const std::string& line) {
  std::ifstream file(path_);
  int line_pos, line_count = 0;
  do {
    line_pos = find_line(file, line.c_str());
    if (line_pos != -1) {
      line_count++;
    }
  } while (line_pos != -1);
  file.close();

  return line_count;
}

void replace(const std::string& line) {
  std::ifstream rfile(path_);
  std::vector<int> positions;
  int line_pos = 0;
  do {
    line_pos = find_line(rfile, line.c_str());
    if (line_pos != -1) {
      positions.push_back(line_pos);
    }
  } while (line_pos != -1);
  rfile.close();
  std::ofstream wfile(path_, std::ofstream::trunc);
  // TODO: continue work from here

}

int FileParser::find_line(std::ifstream& file, const char* line) {
  if (!file.is_open()) {
    // TODO: throw some kind of exception
    return -1;
  }
  
  int cur_pos, ret_val = -1;
  bool found_line = false;
  const int bufsize = 4096;
  char linebuf[bufsize];
  while (!file.eof() && !found_line) {
    cur_pos = file.tellg();
    file.getline(linebuf, bufsize, '\n');
    found_line = strcmp(linebuf, line) == 0;
  }
  if (found_line) {
    ret_val = cur_pos;
  }
  
  return ret_val;
}