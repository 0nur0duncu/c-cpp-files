# Library Automation System

This is a simple console-based library automation system written in C. It includes functionalities for book management, user management, and lending operations.

## Book Operations

The system provides the following book-related operations:

### 1. Add Book

- Adds a new book to the library.
- Generates a random book number.
- Sets the initial lending status to 0 (not borrowed).

### 2. List Books

- Displays a list of all books in the library.

### 3. Update Book

- Allows the user to update book information by providing the book number.
- Edits book title, author, and lending status.

### 4. Delete Book

- Deletes a book from the library by providing the book number.

### 5. Search for Books

- Searches for books based on a keyword (title or author).

## User Operations

The system provides the following user-related operations:

### 1. Add User

- Adds a new user to the system.

### 2. List Users

- Displays a list of all users in the system.

### 3. Update User

- Allows the user to update user information by providing the user number.

### 4. Delete User

- Deletes a user from the system by providing the user number.

### 5. Search for Users

- Searches for users based on a keyword (name or surname).

## Lending Operations

The system provides lending-related operations:

### 1. Borrow Book

- Marks a book as borrowed, updating its lending status to 1.
- Associates the book with a user.

### 2. Return Book

- Marks a borrowed book as returned, updating its lending status to 0.
- Removes the association with the user.

### 3. List Borrowed Books

- Displays a list of all borrowed books, including user information.

## Main Menu

The main menu allows users to navigate between the different functionalities of the system:

1. **Book Operations**

   - Manages books in the library.

2. **User Operations**

   - Manages users in the system.

3. **Lending Operations**
   - Manages book borrowing and returning.

Users are prompted to make a selection, and the system reacts accordingly. Incorrect choices are limited to three attempts before the program exits.

Please note that the system utilizes a simple menu-based interface and is suitable for educational purposes.
