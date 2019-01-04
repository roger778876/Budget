#include <iostream>
#include <string>
#include <fstream>
#include "user.h"
using namespace std;

// prompts for username and password
// finds according user CSV file, or creates new one
// returns file stream
void login() {
  while (1) {
    cout << "Username: ";
    string username;
    cin >> username;

    // making sure username doesn't contain commas
    while (username.find(",") != string::npos) {
      cout << "Username cannot contain commas!\nUsername: ";
      cin >> username;
    }

    // const string usersDirectory = "/users/";
    // const string extension = ".csv";
    fstream userfile(username.c_str());

    // if user's file doesn't exist already, create new one
    if (!(bool)userfile) {
      cout << "Creating new ledger for " << username << ".\n";
      cout << "Set a password: ";
      string password;
      cin >> password;

      // making sure password doesn't contain commas
      while (password.find(",") != string::npos) {
        cout << "Password cannot contain commas!\nSet a password: ";
        cin >> password;
      }

      // userfile.close(); // there's probably a better way instead of closing ifstream and reopening as ofstream?
      ofstream userfile(username.c_str());
      userfile << username << "," << password << endl;
      userfile.close();

      cout << "Ledger created! Login again.\n";
    }
    // user exists already, so validate password
    else { 
      cout << "Password: ";
      string password;
      cin >> password;

      string realPass;
      getline(userfile, realPass);
      realPass = realPass.substr(realPass.find(",") + 1);

      if (password != realPass) {
        cout << "Incorrect password!\n";
      }
      else {
        cout << "password validated\n";

        break;
      }
    }
  }
}

int main() {
  login();
}