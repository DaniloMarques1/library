#ifndef BOOK
#define BOOK

#include <string>

using namespace std;

class Book
{
  string title, category;    
  public:
    Book(string title, string category);

    string get_title();
    string get_category();
};

#endif // BOOK
