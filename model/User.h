#ifndef USER
#define USER

#include <string>
#include <vector>
#include "../json.hpp"
#include "Book.h"

using namespace nlohmann;

class User
{
  int id;
  std::string name, password, email;
  
  // vector of books json
  vector<json> books;

  public:
    User(std::string name,  std::string email,std::string password);
    User();

    void set_id(int i);
    int get_id();

    // vector of json of books
    void set_books(vector<json> books);
    vector<json> get_books();

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
