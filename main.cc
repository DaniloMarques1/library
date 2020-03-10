#include <iostream>
#include "model/Book.h"
#include "view/MenuView.h"
#include "controller/MenuController.h"
#include "model/User.h"

using namespace std;

int getInputMenu();
int getLoggedInput();

int main()
{ 
  User user;
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
      // since the last cin left a end of a line in the input buffer, we need to ignore it
      cin.ignore();

      MenuController::registerUser(name, email, password);
      break;
    }
    case 2:
    {
      string email, password;

      cout << "Type your email: ";
      cin >> email;
      cin.ignore();

      cout << "Type your password: ";
      cin >> password;
      cin.ignore();

      user = MenuController::login(email, password);
      break;
    }
    default:
      break;
  }
  
  if (user.isEmpty())
  {
    cout << "WRONG PASSWORD" << endl;
  }
  else
  {
    while(true)
    {
      choice = getLoggedInput();
      if (choice == 4)
      {
        break;
      }
      if(choice == 1)
      {
        string title, category;
        cout << "Title of the book: ";
        getline(cin, title);

        cout << "Category of the book: ";
        getline(cin, category);

        MenuController::addBook(user.get_id(), title, category);
      }
      else if(choice == 2)
      {
        MenuController::listBook(user.get_id());
      }

    }
  }

  return 0;
}

int getInputMenu()
{
  MenuView::showMenu();
  int choice;

  cout << "Your choice: ";
  cin >> choice; 
  // since the last cin left an end of a line in the input buffer, we need to ignore it
  cin.ignore();

  return choice;
}

int getLoggedInput()
{
  int choice;
  MenuView::loggedMenu();
  cout << "Your choice: ";
  cin >> choice;
  cin.ignore();

  return choice;
}
