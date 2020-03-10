#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "User.h"
#include "../json.hpp"

using namespace std;
using namespace nlohmann;

User::User()
{
  name = "";
  email = "";
  password = "";
}

User::User(string n, string e, string p)
{
  name = n;
  email = e;
  password = p;
};

void User::set_id(int i)
{
  id = i;
}

int User::get_id()
{
  return id;
}

void User::set_books(vector<json> b)
{
  books = b;
}

vector<json> User::get_books()
{
  return books;
}

string User::get_email()
{
  return email;
}

string User::get_name()
{
  return name;
}

string User::get_password()
{
  return password;
}

bool User::isEmpty()
{
  return email.empty();
}

// it will "load" the json file into a string
// to be later parsed to a json object
json User::load()
{
  fstream jsonFile; 
  jsonFile.open("users.json", ios::in);
  json j;

  jsonFile >> j;

  return j;
}

void User::save()
{
  json users = User::load();
  json user;
  
  vector<json> usersArr = users["users"]; 
  
  // creating a json object with the information passed
  int id = usersArr.size() + 1;
  user["id"] = id;
  user["name"] = get_name();
  user["email"] = get_email();
  user["password"] = get_password();
  // placeholder a empty array for later use
  user["books"] = json::array();

  // push to array
  usersArr.push_back(user);
  // replace the current array with the new array
  users["users"] = usersArr;

  // open the users to write
  fstream file;
  file.open("users.json", ios::out);

  // dumping(string) the updated users json inside the file
  file << users.dump();
} 

// it will be used to log in
User User::findOne(string email, string password)
{
  json users = load();
  vector<json> usersArr = users["users"];
  json user;
  
  for (auto obj: usersArr)
  {
    if (obj["email"] == email)
    {
      user = obj; 

      break;
    }
  }
  
  // user is an json object
  if (user["password"] == password)
  {
    User u(user["name"], user["email"], user["password"]);
    u.set_id(user["id"]);
    u.set_books(user["books"]);

    return u;
  }

  User u;
  return u;
}

/* User User::findById(int id) */
/* { */
/*   //TODO: IMPLEMENT */
/* }; */
