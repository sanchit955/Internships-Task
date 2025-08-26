#include <iostream>
#include <vector>
#include <string>
#include <ctime>
using namespace std;

struct Book {
    string title, author, ISBN;
    bool available = true;
};

struct Borrower {
    string name;
};

struct Transaction {
    int bookIndex;
    int borrowerIndex;
    time_t dueDate;
    bool returned = false;
};

vector<Book> books;
vector<Borrower> borrowers;
vector<Transaction> transactions;

void addBook() {
    Book b;
    cout << "Title: "; getline(cin, b.title);
    cout << "Author: "; getline(cin, b.author);
    cout << "ISBN: "; getline(cin, b.ISBN);
    books.push_back(b);
}

void addBorrower() {
    Borrower br;
    cout << "Borrower name: "; getline(cin, br.name);
    borrowers.push_back(br);
}

void listBooks() {
    for (int i = 0; i < books.size(); i++) {
        cout << i+1 << ". " << books[i].title << " by " << books[i].author << " (ISBN: " << books[i].ISBN << ") - "
             << (books[i].available ? "Available" : "Checked out") << "\n";
    }
}

void searchBooks() {
    cout << "Search by (1) Title (2) Author (3) ISBN: ";
    int type; cin >> type; cin.ignore();
    string term;
    cout << "Enter search term: ";
    getline(cin, term);
    for (int i = 0; i < books.size(); i++) {
        bool found = false;
        if (type == 1 && books[i].title.find(term) != string::npos) found = true;
        else if (type == 2 && books[i].author.find(term) != string::npos) found = true;
        else if (type == 3 && books[i].ISBN.find(term) != string::npos) found = true;
        if (found)
            cout << i+1 << ". " << books[i].title << " by " << books[i].author << " - " 
                 << (books[i].available ? "Available" : "Checked out") << "\n";
    }
}

void checkoutBook() {
    if (borrowers.empty()) {
        cout << "No borrowers, add one first.\n";
        return;
    }
    listBooks();
    cout << "Choose book number to checkout: ";
    int bi; cin >> bi; cin.ignore();
    if (bi < 1 || bi > books.size() || !books[bi-1].available) {
        cout << "Invalid choice or book not available\n";
        return;
    }
    for (int i = 0; i < borrowers.size(); i++)
        cout << i+1 << ". " << borrowers[i].name << "\n";
    cout << "Pick borrower number: ";
    int br; cin >> br; cin.ignore();
    if (br < 1 || br > borrowers.size()) {
        cout << "Invalid borrower\n";
        return;
    }
    books[bi-1].available = false;
    time_t now = time(0);
    time_t due = now + 14*24*3600; // 2 weeks
    transactions.push_back({bi-1, br-1, due, false});
    cout << "Book checked out, due in 2 weeks.\n";
}

void returnBook() {
    cout << "Checked out books:\n";
    bool hasOut = false;
    for (int i = 0; i < transactions.size(); i++) {
        if (!transactions[i].returned) {
            hasOut = true;
            int bi = transactions[i].bookIndex;
            int br = transactions[i].borrowerIndex;
            cout << i+1 << ". " << books[bi].title << " borrowed by " << borrowers[br].name << "\n";
        }
    }
    if (!hasOut) {
        cout << "No books to return.\n";
        return;
    }
    cout << "Transaction number to return: ";
    int t; cin >> t; cin.ignore();
    if (t < 1 || t > transactions.size() || transactions[t-1].returned) {
        cout << "Invalid transaction\n";
        return;
    }
    transactions[t-1].returned = true;
    books[transactions[t-1].bookIndex].available = true;

    time_t now = time(0);
    if (now > transactions[t-1].dueDate) {
        double daysLate = difftime(now, transactions[t-1].dueDate) / (24*3600);
        double fine = daysLate * 1.0; // 1 unit fine per late day
        cout << "Book returned late by " << (int)daysLate << " days. Fine: " << fine << "\n";
    } else {
        cout << "Book returned on time. No fine.\n";
    }
}

int main() {
    while (true) {
        cout << "\nLibrary System\n1.Add Book 2.Add Borrower 3.List Books 4.Search Books 5.Checkout Book 6.Return Book 7.Exit\nChoose: ";
        int choice; cin >> choice; cin.ignore();
        if (choice == 1) addBook();
        else if (choice == 2) addBorrower();
        else if (choice == 3) listBooks();
        else if (choice == 4) searchBooks();
        else if (choice == 5) checkoutBook();
        else if (choice == 6) returnBook();
        else if (choice == 7) break;
        else cout << "Invalid option\n";
    }
    return 0;
}
