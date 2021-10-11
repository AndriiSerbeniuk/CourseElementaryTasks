#include <iostream>
#include "user_dialog.h"
// TODO: remove when finished with testing
#include "TriangleFactory.hpp"
#include "Triangle.hpp"
#include "StringArgs.hpp"
#include "StringExtractor.hpp"

int main() {
    //UserDialog d;
    //d.run();
    TriangleFactory factory;
    StringArgs args;
    args.triangle_text = "\t    triangle 1, 3, 4, 5";
    StringExtractor extractor;
    Triangle* triangle = (Triangle*)factory.GetTriangle(&args, &extractor);

    delete triangle;

    return 0;
}