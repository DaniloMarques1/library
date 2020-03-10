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

void Book::list(vector<json> books)
{
  for (auto book: books)
  {
    cout << "============================" << endl;
    string title = book["title"];
    string category = book["category"];

    cout << "Title of the book: " << title << endl;
    cout << "Category of the book: " << category << endl;
  }

/*   json users = load(); */   
/*   vector<json> usersArr = users["users"]; */

/*   for (int i = 0; i < usersArr.size(); i++) */
/*   { */
/*     if (usersArr[i]["id"] == id) */
/*     { */
/*       // getting the books array of the user */
/*       vector<json> books = usersArr[i]["books"]; */
/*       int size = books.size(); */
/*       cout << "You have " << size << " book(s)" << endl; */
/*       for (auto bookJson: books) */
/*       { */
/*         cout << "============================" << endl; */
/*         string title = bookJson["title"]; */ 
/*         string category = bookJson["category"]; */ 

/*         cout << "Book title: " << title << endl; */
/*         cout << "Category of the book: " << category << endl; */
/*       } */

/*       break; */
/*     } */
/*   } */
}
