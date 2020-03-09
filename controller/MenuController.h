#ifndef MENUCONTROLLER
#define MENUCONTROLLER

#include <string>
#include "../model/User.h"

using namespace std;

class MenuController
{
  public:
    // will create a model and add to the file (json)?
    static void registerUser(string name, string email, string password);
    static User login(string email, string password);
};

#endif // MENUCONTROLLER
