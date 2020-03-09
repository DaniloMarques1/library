#ifndef USER
#define USER

#include <string>
#include "../json.hpp"

using namespace nlohmann;

class User
{
  int id;
  std::string name, password, email;
  public:
    User(std::string name,  std::string email,std::string password);
    User();

    void set_id(int i);
    int get_id();

    std::string get_name();
    std::string get_email();
    std::string get_password();

    static json load();
    void save();
    static User findOne(std::string email, std::string password);
    static User findById(int id);
    bool isEmpty();
};

#endif // ending USER
