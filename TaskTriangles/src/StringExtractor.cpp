#include <stdexcept>
#include <string.h>
#include <algorithm>
#include "StringExtractor.hpp"

StringExtractor::StringExtractor(const StringArgs& args) : ITriangleArgsExtractor()
{
    m_args = args;
}

void StringExtractor::SetArgs(const IExtractorArgs*& args)
{
    try
    {
        StringArgs* str_args = (StringArgs*)args;
        m_args.triangle_text = str_args->triangle_text;
    }
    catch(const std::exception& e)
    {
        throw std::invalid_argument("StringExtractor requires StringArgs implementation of IExtractorArgs");
    }
}

std::string StringExtractor::ExtractName() const 
{
    const char* arg_start = m_args.triangle_text.c_str(), *arg_end = arg_start;
    std::string name;

    // Name should be written first
    arg_end = strchr(arg_start, ',');
    if (arg_end)
    {
        name.assign(arg_start, 0, arg_end - arg_start);
    }
    else 
    {
        name.assign(arg_start);
    }

    Trim(name);

    return name;
}

std::vector<float> StringExtractor::ExtractSides() const
{
    const char* arg_start = m_args.triangle_text.c_str(), *arg_end = arg_start;
    std::vector<std::string> args;
    std::string cur_arg;

    // Exclude the name
    arg_start = strchr(arg_start, ',');
    if (!arg_start)
    {
        throw std::invalid_argument("Sides were not provided.");
    }
    ++arg_start;

    // Divide each side
    while (arg_end) {
        arg_end = strchr(arg_start, ',');
        if (arg_end)
          cur_arg.assign(arg_start, 0, arg_end - arg_start);     
        else 
          cur_arg.assign(arg_start);  
        Trim(cur_arg);
        args.push_back(cur_arg);
        arg_start = arg_end + 1;
    }

    if (args.size() < 3)
    {
        throw std::invalid_argument("Too few sides provided.");
    }
    else
    {
        if (args.size() > 3)
        {
            throw std::invalid_argument("Too many sides provided.");
        }
    }

    // Parse the sides
    std::vector<float> sides(3);

    sides[0] = ProcessSide(args[0]);
    sides[1] = ProcessSide(args[1]);
    sides[2] = ProcessSide(args[2]);

    return sides;
}

float StringExtractor::ProcessSide(const std::string& side) const
{
    float side_len;

    try 
    {
        side_len = std::stof(side);
    }
    catch (const std::exception& e)
    {
        throw std::invalid_argument("Invalid side length provided: \"" + side + "\"");
    }
    if (side_len <= 0)
    {
        throw std::invalid_argument("Invalid side length provided: \"" + side + "\"");
    }
    
    return side_len;
}

void StringExtractor::Trim(std::string& str) const
{
    auto not_space = [](char c) {
        return !isspace(c);
    };
    // Erase from the left
    str.erase(str.begin(), std::find_if(str.cbegin(), str.cend(), not_space));

    // Erase from the right
    str.erase(std::find_if(str.crbegin(), str.crend(), not_space).base(), str.end());
}
