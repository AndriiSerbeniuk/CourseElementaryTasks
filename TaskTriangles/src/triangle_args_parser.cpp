#include "triangle_args_parser.h"

TriangleArgsParser::TriangleArgsParser() : raw_(), name_(),
  side_a_(0), side_b_(0), side_c_(0), area_(0) {}

TriangleArgsParser::TriangleArgsParser(const std::string triangle) 
  : raw_(triangle) {
    parse();
}

TriangleArgsParser::~TriangleArgsParser() {}

void TriangleArgsParser::parse() {
  const char* arg_start = raw_.c_str(), *arg_end = arg_start;
  std::vector<std::string> args;
  std::string cur_arg;
  // Divide name and each side
  while (arg_end) {
    arg_end = strchr(arg_start, ',');
    if (arg_end)
      cur_arg.assign(arg_start, 0, arg_end - arg_start);     
    else 
      cur_arg.assign(arg_start);  
    cur_arg = trim(cur_arg);
    args.push_back(cur_arg);
    arg_start = arg_end + 1;
    if (args.size() > 4)
      throw std::invalid_argument("Too many arguments provided.");
  }
  if (args.size() != 4)
      throw std::invalid_argument("Too few arguments provided.");
  // Process the arguments
  name_ = args[0];
  // Parse sides
  side_a_ = process_side(args[1]);
  side_b_ = process_side(args[2]);
  side_c_ = process_side(args[3]);
}

std::string TriangleArgsParser::trim(const std::string& name) {
  if (!name.length())
    return name;
  // Trim whitespaces in the front
  int name_start = 0;
  while (isspace(name[name_start]))
    name_start++;
  // Trim whitespaces in the back
  int name_end = name.length() - 1;
  while (isspace(name[name_end]))
    name_end--;
  return std::string(name, name_start, name_end - name_start + 1);
}

float TriangleArgsParser::process_side(const std::string& side_len) {
  float ret_num;
  try {
    ret_num = std::stof(side_len);
  }
  catch (const std::exception& e){
    throw std::invalid_argument("Invalid side length provided: \"" + side_len + "\"");
  }
  if (ret_num <= 0)
    throw std::invalid_argument("Invalid side length provided: \"" + side_len + "\"");
  return ret_num;
}

std::string TriangleArgsParser::get_name() const  {
  return name_;
}

float TriangleArgsParser::get_side_a() const  {
  return side_a_;
}

float TriangleArgsParser::get_side_b() const {
  return side_b_;
}

float TriangleArgsParser::get_side_c() const {
  return side_c_;
}

void TriangleArgsParser::set_raw(const std::string triangle) {
  raw_ = triangle;
  parse();
}
