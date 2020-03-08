#include <string>

using namespace std;

class MenuController
{
  public:
    // will create a model and add to the file (json)?
    static void registerUser(string name, string email, string password);
    static void login(string email, string password);
};
