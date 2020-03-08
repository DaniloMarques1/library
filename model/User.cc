#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "User.h"
#include "../json.hpp"

using namespace std;
using namespace nlohmann;

User::User(string n, string e, string p)
{
  name = n;
  email = e;
  password = p;
};

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

// it will "load" the json file into a string
// to be later parsed to a json object
string User::load()
{
  fstream jsonFile; 
  jsonFile.open("users.json", ios::in);

  string row, jsonString;
  while(getline(jsonFile, row))
  {
    jsonString.append(row);
  }

  jsonFile.close();

  return jsonString;
}

void User::save()
{
  string jsonString = User::load();
  json users;
  json user;
  
  users = json::parse(jsonString);  
  vector<json> usersArr = users["users"]; 
  
  // creating a json object with the information passed
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