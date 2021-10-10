// #include "user_dialog.h"
// #include <limits>

// const char* UserDialog::kEntryPrompt = "\n>: ";

// UserDialog::UserDialog() {}

// UserDialog::~UserDialog() {}

// void UserDialog::run() {
//   while (ask_start())
//   {
//     Triangle tr = ask_triangle();
//     triangles_.insert(tr);
//     form_triangles_table();
//   }
// }

// bool UserDialog::ask_start() {
//   std::cout << "\nWould you like to start? (y/n)" << kEntryPrompt;
//   char ans;
//   bool ret_val = false;
//   do {
//     ans = fgetc(stdin);
//     std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

//     ans = tolower(ans);
//     switch (ans) {
//       case 'y':
//         ret_val = true;
//         break;
//       case 'n':
//         break;
//       default:
//         std::cout << "\nUnknown command. Try again." << kEntryPrompt;
//         continue;
//     }

//   } while (ans != 'y' && ans != 'n');
//   return ret_val;
// }

// Triangle UserDialog::ask_triangle() {
//   Triangle tr;
//   std::cout << "\nEnter a triangle in the following format:\n"
//     << "\"name, side a, side b, side c\"\n" << kEntryPrompt;
//   bool success = false;
//   int text_size = 256;
//   char text[256];
//   do {
//     std::cin.getline(text, text_size);
//     try {
//       tr = Triangle(text);
//       success = true;
//     }
//     catch (const std::exception& e) {
//       std::cout << "Invalid arguments: " << e.what() 
//       << "\nTry again." << kEntryPrompt;
//     }
//   } while (!success);

//   return tr;
// }

// void UserDialog::form_triangles_table() {
//   int i = 1;
//   std::cout << "\n============== Triangles list ==============\n";
//   for (auto t = triangles_.cbegin(), e = triangles_.cend(); t != e; t++, i++) {    
//     std::cout << i << ". [" << t->get_name() << "]: " << t->get_area() << " cm\n";
//   }
// }
