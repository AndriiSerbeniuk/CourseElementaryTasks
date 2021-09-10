#include "user_dialog.h"
#include <stdexcept>
#include <limits>

const char* UserDialog::kEntryPrompt = "\n>: ";

UserDialog::UserDialog() : parser() {}

UserDialog::~UserDialog() {}

void UserDialog::run() {
  std::cout << "Check if one envelope will fit into another one.\n";
  while (ask_start())
  {
    std::cout << "\nOuter envelope:\n";
    Envelope out_en = ask_envelope();
    std::cout << "\nInner envelope:\n";
    Envelope inn_en = ask_envelope();
    std::string out_en_text("(" + std::to_string(out_en.get_width())
      + "x" + std::to_string(out_en.get_height()) + ")");
    std::string inn_en_text("(" + std::to_string(inn_en.get_width())
      + "x" + std::to_string(inn_en.get_height()) + ")");
    std::cout << "The second envelope " << inn_en_text << " can";
    if (out_en <= inn_en) {
      std::cout << " not";
    }
    std::cout << " fit into the first one" << out_en_text << ".\n";
  }
}

bool UserDialog::ask_start() {
  std::cout << "\nWould you like to start? (y/n)" << kEntryPrompt;
  char ans;
  bool ret_val = false;
  do {
    try {
      ans = get_char();
    }
    catch (const std::exception& e){
      invalid_response_msg();
      continue;
    }

    ans = tolower(ans);
    switch (ans) {
      case 'y':
        ret_val = true;
        break;
      case 'n':
        break;
      default:
        invalid_response_msg();
        continue;
    }

  } while (ans != 'y' && ans != 'n');
  return ret_val;
}

Envelope UserDialog::ask_envelope() {
  float width, height;
  bool success;
  Envelope en;
  // Loop for the whole envelope
  do
  {
    // Loop for the width
    success = false;
    std::cout << "Enter width." << kEntryPrompt;
    while (!success)
    {
      try
      {
        width = get_float();
        success = true;
      }
      catch(const std::exception& e)
      { 
        invalid_number_msg();
      }
    }
    // Loop for the height
    success = false;
    std::cout << "\nEnter height." << kEntryPrompt;
    while (!success)
    {
      try
      {
        height = get_float();
        success = true;
      }
      catch(const std::exception& e)
      { 
        invalid_number_msg();
      }
    }
    try {
      Envelope temp(width, height);
      en = temp;
    }
    catch (const std::exception& e)
    {
      invalid_size_msg();
      success = false;
    }
  } while (!success);
  return en;
}

float UserDialog::get_float() {
  std::string resp = get_response();
  return parser.to_float(resp);
}

char UserDialog::get_char() {
  std::string resp = get_response();
  return parser.to_char(resp);
}

std::string UserDialog::get_response() {
  std::string resp;
  std::cin >> resp;
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  return resp;
}

void UserDialog::invalid_number_msg() {
  std::cout << "\nEntered number is invalid. Try again." 
    << kEntryPrompt;
}

void UserDialog::invalid_size_msg() {
  std::cout << "\nEntered size is invalid.\n" 
    << "Both width and height must be > 0. "
    << "Try again." << kEntryPrompt;
}

void UserDialog::invalid_response_msg() {
  std::cout << "\nUnknown command. Try again." << kEntryPrompt; 
}
