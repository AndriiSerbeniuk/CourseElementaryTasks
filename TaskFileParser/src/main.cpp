#include <iostream>
#include "file_parser.h"

int main()
{
    FileParser fp("text.txt");
    int c = fp.count_instances("line");

    return 0;
}