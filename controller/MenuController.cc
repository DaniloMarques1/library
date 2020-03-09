#include <iostream>
#include <string>
#include "MenuController.h"

void MenuController::registerUser(string name, string email, string password)
{
  User user(name, email, password);

  user.save();
}

User MenuController::login(string email, string password)
{
  User u = User::findOne(email, password);

  return u;
}
