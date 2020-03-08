#include <iostream>
#include <string>
#include "MenuController.h"
#include "../model/User.h"

void MenuController::registerUser(string name, string email, string password)
{
  User user(name, email, password);

  user.save();
}

void MenuController::login(string email, string password)
{

  User user = User::findOne(email, password);

  cout << user.get_email() << endl;
  cout << user.get_id() << endl;

  /* return user; */ 
}
