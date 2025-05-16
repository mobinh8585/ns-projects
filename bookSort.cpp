#include <iostream>

using namespace std;

// By Hosseini

struct Book{
    string name;
    string author;
    int code;
    bool isBorrowed;
};

void swap(Book &a, Book &b);
void mainMenu(Book book[], int size);
void bubbleSort(Book arr[], int size, bool sortByCode);
int binarySearchByNameAndCode(Book arr[], int size, string name, int code);
void searchByName(Book arr[], int size);
void searchByCode(Book arr[], int size);
void borrowReturnBook(Book arr[], int size);
void showAvailableBooks(Book arr[], int size);

int main(){

    cout << "Welcome to the Library Management System! completely made by Hosseini" << endl;
    cout << "Please enter the number of books: ";
    int size;
    cin >> size;
    Book book[size];
    for (int i = 0; i < size; i++)
    {
        cout << "Enter the name of book " << i + 1 << ": ";
        cin >> book[i].name;
        cout << "Enter the author of book " << i + 1 << ": ";
        cin >> book[i].author;
        cout << "Enter the code of book " << i + 1 << ": ";
        cin >> book[i].code;
        cout << "Is the book " << book[i].name << " borrowed? (1 for yes, 0 for no): ";
        cin >> book[i].isBorrowed;
    }
    
    mainMenu(book, size);
}

void swap(Book &a, Book &b){
    Book temp = a;
    a = b;
    b = temp;
}

void mainMenu(Book book[], int size){

    cout << "What do you want to do?" << endl;
    cout << "1. Search books by name" << endl;
    cout << "2. Search books by code" << endl;
    cout << "3. Borrow/Return a book" << endl;
    cout << "4. Show available books" << endl;
    int choice;
    cin >> choice;
    switch (choice)
    {
    case 1:
        searchByName(book, size);
        break;
    case 2:
        searchByCode(book, size);
        break;
    case 3:
        borrowReturnBook(book, size);
        break;
    case 4:
        showAvailableBooks(book, size);
        break;
    default:
        cout << "Invalid choice, please try again" << endl;
        mainMenu(book, size);
    }

}

void bubbleSort(Book arr[], int size, bool sortByCode) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (sortByCode) {
                if (arr[j].code > arr[j + 1].code) {
                    swap(arr[j], arr[j + 1]);
                }
            } else {
                if (arr[j].name > arr[j + 1].name) {
                    swap(arr[j], arr[j + 1]);
                }
            }
        }
    }
}

int binarySearchByNameAndCode(Book arr[], int size, string name, int code){
    int left = 0;
    int right = size - 1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        if (arr[mid].name == name || arr[mid].code == code) {
            return mid;
        }
        
        else if (arr[mid].name < name || arr[mid].code < code) {
            left = mid + 1;
        }
        else if (arr[mid].name > name || arr[mid].code > code){
            right = mid - 1;
        }
    }
    
    return -1;
}

void searchByName(Book arr[], int size){
    bubbleSort(arr, size, false);
    
    string name;
    cout << "Enter the name of the book to search: ";
    cin >> name;
    
    int result = binarySearchByNameAndCode(arr, size, name, -1000);
    
    if (result != -1) {
        cout << "The book " << name << " on the index " << result << " has found" << endl;
        cout << "Name: " << arr[result].name << ", Author: " << arr[result].author << ", Code: " << arr[result].code << ", Is Borrowed: " << arr[result].isBorrowed << endl;
    } else {
        cout << "The book " << name << " has not been found." << endl;  
    }

    mainMenu(arr, size);
}

void searchByCode(Book arr[], int size){
    bubbleSort(arr, size, true);
    
    int code;
    cout << "Enter the code of the book to search: ";
    cin >> code;
    
    int result = binarySearchByNameAndCode(arr, size, "", code);
    
    if (result != -1) {
        cout << "The book " << code << " on the index " << result << " has found" << endl;
        cout << "Name: " << arr[result].name << ", Author: " << arr[result].author << ", Code: " << arr[result].code << ", Is Borrowed: " << arr[result].isBorrowed << endl;
    } else {
        cout << "The book " << code << " has not been found." << endl;
    }

    mainMenu(arr, size);
}

void borrowReturnBook(Book arr[], int size){
    bool borrowOrReturn;
    cout << "Do you want to borrow or return a book? (1 for borrow, 0 for return): ";
    cin >> borrowOrReturn;

    bool isCode;
    cout << "Do you want to search by code or name? (1 for code, 0 for name): ";
    cin >> isCode;
    
    int code;
    string name;
    if (isCode)
    {
        cout << "Enter the code of the book to borrow or return: ";
        cin >> code;
    }
    else
    {
        cout << "Enter the name of the book to borrow or return: ";
        cin >> name;
    }

    bool found = false;
    for (int i = 0; i < size; i++)
    {

            if (arr[i].code == code || arr[i].name == name)
            {
                found = true;
                if (borrowOrReturn)
                {
                    if (arr[i].isBorrowed)
                    {
                        cout << "Error: This book is already borrowed." << endl;
                    }
                    else
                    {
                        arr[i].isBorrowed = true;
                        cout << "Book successfully borrowed." << endl;
                    }
                }
                else
                {
                    if (!arr[i].isBorrowed)
                    {
                        cout << "Error: This book is not currently borrowed." << endl;
                    }
                    else
                    {
                        arr[i].isBorrowed = false;
                        cout << "Book successfully returned." << endl;
                    }
                }
            }
    }
    
    if (!found)
    {
        if (isCode)
        {
            cout << "Error: Book with code " << code << " not found." << endl;
        }
        else
        {
            cout << "Error: Book with name " << name << " not found." << endl;
        }
    }

    mainMenu(arr, size);
}

void showAvailableBooks(Book arr[], int size){

    cout << "Here's the array of available books: " << endl;
    int count = 1;
    for (int i = 0; i < size; i++)
    {
        if (!arr[i].isBorrowed)
        {
            cout << count << ". " << "Name: " << arr[i].name << ", Author: " << arr[i].author << ", Code: " << arr[i].code << endl;
            count++;
        }
    }
    
    mainMenu(arr, size);
}
