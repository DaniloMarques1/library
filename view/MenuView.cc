#include <iostream>
#include <string>
#include "MenuView.h"

using namespace std;

void MenuView::drawLine()
{
  cout << "============================" << endl;
}

void MenuView::showMenu()
{
  MenuView::drawLine();

  cout << "1. Create an account" << endl; 
  cout << "2. Login" << endl; 

  MenuView::drawLine();
}

void MenuView::loggedMenu()
{
  MenuView::drawLine();
  
  cout << "1. Add a new book" << endl;
  cout << "2. List your books" << endl;
  cout << "3. Delete a book" << endl;
  
  MenuView::drawLine();
}

