#pragma once
#include <string.h>
#include <stdexcept>
#include <vector>

// Parses a string into triangle arguments
class TriangleArgsParser {
  public:
    TriangleArgsParser();
    TriangleArgsParser(const std::string triangle);
    virtual ~TriangleArgsParser();

    std::string get_name() const;
    float get_side_a() const;
    float get_side_b() const;
    float get_side_c() const;
    void set_raw(const std::string triangle);

  private:
    std::string raw_;
    std::string name_;
    float side_a_;
    float side_b_;
    float side_c_;
    float area_;

    void parse();
    std::string trim(const std::string& name);
    float process_side(const std::string& side_len);
};