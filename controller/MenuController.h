#ifndef MENUCONTROLLER
#define MENUCONTROLLER

#include <string>
#include <vector>
#include "../model/User.h"

using namespace std;

class MenuController
{
  public:
    // will create a model and add to the file (json)?
    static void registerUser(string name, string email, string password);
    static User login(string email, string password);

    static void addBook(int id, string title, string category);
    static void listBook(vector<json> books);
    static void deleteBook(string title);
};

#endif // MENUCONTROLLER
