#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "Book.h"
#include "../json.hpp"

using namespace std;
using namespace nlohmann;

Book::Book(string t, string c)
{
  title = t;
  category = c;
}

string Book::get_category()
{
  return category;
}

string Book::get_title()
{
  return title;
}

json Book::load()
{
  fstream jsonFile;
  jsonFile.open("users.json", ios::in);
  json j;

  jsonFile >> j;

  return j;
}

void Book::save(int id)
{

  cout << id << endl;
  cout << get_title() << endl;

  json user;
  json users = load();
  vector<json> usersArr = users["users"];
  // searching for the user
  for (int i = 0; i < usersArr.size(); i++)
  {
    if (usersArr[i]["id"] == id)
    {
      // getting the books array of the user
      vector<json> books = usersArr[i]["books"];
      json book;

      // adding a new books to the users array
      book["title"] = get_title();
      book["category"] = get_category();
      books.push_back(book);

      usersArr[i]["books"] = books;
      break;
    }
  }

  users["users"] = usersArr;
  fstream file;
  file.open("users.json", ios::out);

  // writing back to the file
  file << users.dump();
}

void Book::list(int id)
{
  json users = load();   
  vector<json> usersArr = users["users"];

  for (int i = 0; i < usersArr.size(); i++)
  {
    if (usersArr[i]["id"] == id)
    {
      // getting the books array of the user
      vector<json> books = usersArr[i]["books"];
      cout << "You have " << books.size() << " books" << endl;
      for (auto bookJson: books)
      {
        //TODO: printing with quotes
        cout << "Book title: " <<  bookJson["title"] << endl;
        cout << "Category of the book: " << bookJson["category"] << endl;
      }
      break;
    }
  }

}
