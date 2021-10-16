#pragma once
#include <iostream>
#include <set>
#include <memory>
#include "AreaTriangle.hpp"
#include "AreaTriangleFactory.hpp"
#include "StringArgs.hpp"
#include "StringArgsExtractor.hpp"

// Console user dialog
class UserDialog {
public:
    void Run();
    bool AskStart() const;
    std::unique_ptr<AreaTriangle> AskTriangle() const;
    void AddTriangle(const AreaTriangle& triangle);
    std::string FormTrianglesTable() const;

private:
    static const char* ENTRY_PROMPT;
    // Triangles storage
    std::multiset<AreaTriangle, std::greater<AreaTriangle>> m_triangles;

    char ToChar(const std::string& text) const;
};
