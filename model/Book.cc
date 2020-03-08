#include <string>
#include "Book.h"

using namespace std;

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
