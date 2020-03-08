// header guard will come soon
#include <string>

class User
{
  std::string name, password, email;
  public:
    User(std::string name,  std::string email,std::string password);
    User();

    std::string get_name();
    std::string get_email();
    std::string get_password();

    static std::string load();
    void save();
    static User findOne(std::string email, std::string password);
    static User findById(int id);
};
