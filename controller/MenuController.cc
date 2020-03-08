#include <iostream>
#include <string>
#include "MenuController.h"
#include "../model/User.h"

void MenuController::registerUser(string name, string email, string password)
{
  //TODO: Register a user in a file
  User user(name, email, password);

  user.save();
}

void MenuController::login(string email, string password)
{
  //TODO: Search for a user
  User user = User::findOne(email, password);
  cout << user.get_name() << endl;
}
