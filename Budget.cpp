#include <iostream>
#include <string>
#include <vector>
#include "user.h"
#include "parser.h"
#include "ledger.h"
using namespace std;

int main() {
  cout << "Welcome! ";
  initialPrompt(); // from parser.cpp
  int input = readInitialPrompt(); // index of command in initialPrompts{} (from parser.cpp)

  switch (input) {
    case 0: // Add Transaction


  }


  return 0;
}