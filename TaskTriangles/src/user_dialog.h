// TODO: rewrite triangles creation using TriangleFactory
// #pragma once
// #include "Triangle.hpp"
// #include <iostream>
// #include <set>

// // Console user dialog
// class UserDialog {
// 	public:
//     UserDialog();
//     virtual ~UserDialog();

//     void run();

//   private:
//     // Triangles storage
//     std::multiset<Triangle, std::greater<Triangle>> triangles_;

//     static const char* kEntryPrompt;

//     bool ask_start();
//     Triangle ask_triangle();
//     void form_triangles_table();
// };