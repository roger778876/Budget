#include <iostream>
#include <string>
#include <vector>

#include "parser.h"

using namespace std;

// this contains all of the user commands when first starting the program
vector<string> initialPrompts = {"Add Transaction"};

// prompts user for command when first starting the program
void initialPrompt() {
  cout << "What would you like to do?\n";
  for (int i = 0; i < initialPrompts.size(); i++) {
    cout << i << ": " << initialPrompts[i] << endl;
  }
}