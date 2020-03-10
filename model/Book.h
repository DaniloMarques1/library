#ifndef BOOK
#define BOOK

#include <string>
#include "../json.hpp"

using namespace std;
using namespace nlohmann;

class Book
{
  string title, category;    
  public:
    Book(string title, string category);

    string get_title();
    string get_category();

    json load();
    // id of the user
    void save(int id);
};

#endif // BOOK
