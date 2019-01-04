#include <iostream>
#include <string>
#include <vector>
#include "parser.h"
using namespace std;

// this contains all of the user commands when first starting the program
vector<string> initialPrompts = {"Add Transaction"};

// prompts user for command when first starting the program
void initialPrompt() {
  cout << "What would you like to do? Type the command number.\n";
  for (int i = 0; i < initialPrompts.size(); i++) {
    cout << i << ": " << initialPrompts[i] << endl;
  }
}

// reads in integer corresponding to index of command in initalPrompts{}
int readInitialPrompt() {
  int input;
  cin >> input;

  // if user doesn't input integer
  while (cin.fail()) {
    cout << "Please type an integer.\n";
    cin.clear();
    cin.ignore(256,'\n');
    cin >> input;
  }

  return input;
}