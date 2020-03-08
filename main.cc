#include <iostream>
#include "model/User.h"
#include "model/Book.h"
#include "view/MenuView.h"
#include "controller//MenuController.h"

using namespace std;

int getInputMenu();
int main()
{ 
  int choice; 
  choice = getInputMenu();

  switch(choice)
  {
    case 1:
    {
      string name, email, password; 

      cout << "What is your name? ";
      // gets all line including the end of a line \n
      getline(cin, name);

      cout << "What is your email? ";
      // gets the line until hits non numerical character(space, end of line...)
      cin >> email;
      cin.ignore();

      cout << "Choose a good password:  ";
      // gets the line until hits non numerical character(space, end of line...)
      cin >> password;
      // since the laste cin left a end of a line in the input buffer, we need to ignore it
      cin.ignore();

      MenuController::registerUser(name, email, password);
      break;
    }
    case 2:
      break;
    default:
      break;

  }
  
  return 0;
}

int getInputMenu()
{
  MenuView::showMenu();
  int choice;

  cout << "Your choice: ";
  cin >> choice; 
  // since the laste cin left a end of a line in the input buffer, we need to ignore it
  cin.ignore();

  return choice;
}
