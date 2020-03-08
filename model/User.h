// header guard will come soon
#include <string>

class User
{
  std::string name, password, email;
  public:
    User(std::string name,  std::string email,std::string password);

    std::string get_name();
    std::string get_email();
    std::string get_password();

    std::string load();
    void save();
};
