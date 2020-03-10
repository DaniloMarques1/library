#include <iostream>
#include <string>
#include "../model/User.h"
#include "../model/Book.h"
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

void MenuController::addBook(int id, string title, string category)
{
  Book book(title, category);

  book.save(id);
}
