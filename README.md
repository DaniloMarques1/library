## Library

User will be able to create an account log in and add books.

1. Register of a new user.
2. Login of a user.
3. Add a new book.
4. List all books.
5. Delete a book.

The user info will be saved on a file.

Example how the data will be stored in the file:

```json
{
  "users": [
    {
      "name": "Name of the user",
      "email": "email",
      "password": "password",
      "books": [
        { "title": "Percy Jackson", "category": "aventura" },
        { "title": "Percy Jackson", "category": "aventura" }
      ]
    },
    {
      "name": "Name of the user",
      "email": "email",
      "password": "password",
      "books": [
        { "title": "Percy Jackson", "category": "aventura" },
        { "title": "Percy Jackson", "category": "aventura" }
      ]
    }
  ]
}
```
