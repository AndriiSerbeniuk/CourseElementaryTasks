#pragma once
#include <iostream>
#include <set>
#include <memory>
#include "Triangle.hpp"
#include "TriangleFactory.hpp"
#include "StringArgs.hpp"
#include "StringExtractor.hpp"

// Console user dialog
class UserDialog {
public:
    void run();

private:
    // Triangles storage
    std::multiset<Triangle, std::greater<Triangle>> m_triangles;

    static const char* kEntryPrompt;

    bool ask_start();
    std::unique_ptr<Triangle> ask_triangle();
    void form_triangles_table();
};