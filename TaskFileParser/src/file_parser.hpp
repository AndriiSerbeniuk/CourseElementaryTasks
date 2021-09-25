#pragma once
#include <string.h>
#include <fstream>
#include <cstdio>
#include <vector>

// Can modify text in the given file
class FileParser 
{
    public:
        FileParser(const std::string& path);
        virtual ~FileParser() = default;
        
        std::string get_path() const;
        void set_path(const std::string& path);

        // Counts how many times a line is present in the file
        //int count_instances(const std::string& line);
        // Replaces all instances of one line with another line
        //void replace(const std::string& original, const std::string& replacement);

        virtual void process() = 0;
    protected:
        // Buffer size for file reading
        static const int kBufSize;
        // Path to the file
        std::string path_;
        // Returns position of the given line in the file. 
        // Returns -1 if the line was not found.
        int find_line(std::ifstream& file, const char* line);
};