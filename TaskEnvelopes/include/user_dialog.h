#pragma once
#include <iostream>
#include "envelope.h"
#include "text_parser.h"

// Class for interactions with the user
class UserDialog {
private:
  static const char* kEntryPrompt;
  TextParser parser;

  // Ask if the user wants to start execution
  bool ask_start();
  // Ask the user to enter an envelope
  Envelope ask_envelope();

  // Wait for the user to enter response text
  std::string get_response();
  // Wait for the user to enter a float number
  float get_float();
  // Wait for the user to enter a char
  char get_char();

  void invalid_number_msg();
  void invalid_size_msg();
  void invalid_response_msg();

public:
  UserDialog();
  virtual ~UserDialog();

  // Run main program loop 
  void run();
};