//---------------------------------------------------------------------------
// patron.h
// Class representing a patron registered with the library
//---------------------------------------------------------------------------
// Patron class:
//
// Implementation and assumptions:
// -- Maintains history of transactions and list of borrowed books
// -- Performs methods to history such as adding and printing a 
// Patron's history, transactions and also adding and removing book items 
// from the borrowed list. 
// -- Assumes Item class and its derived classes have been properly 
// implemented
// 
//---------------------------------------------------------------------------

#ifndef PATRON
#define PATRON

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "childrensbook.h"
#include "fiction.h"
#include "periodical.h"
#include <list>
using namespace std;

class Item;
class Transaction;
class Patron
{
    public:
        //---------------------------------------------------------------------
        // Default Constructor
        Patron();

        //---------------------------------------------------------------------
        // Destructor
        ~Patron();

        //---------------------------------------------------------------------
        // Getters/Setters
        string getFirstName() const;
        string getLastName() const;
        int getID() const;

        void setFirstName(string);
        void setLastName(string);
        void setID(int);

        //---------------------------------------------------------------------
        // Prints out user's information
        void print();

        //---------------------------------------------------------------------
        // adds a transaction to user's history
        void addToHistory(Transaction* transaction);

        //---------------------------------------------------------------------
        // adds a book to user's list of borrowed books
        void addToBorrowList(Item*);

        //---------------------------------------------------------------------
        // Removes a book from user's list of borrowed books
        void removeFromBorrowList(Item*);

        //---------------------------------------------------------------------
        // prints out user's history
        void printBorrowList();

        //---------------------------------------------------------------------
        // checks if the book returned is in the borrowed list
        bool retrieveInList(Item* returnBook);

        //---------------------------------------------------------------------
        // sets patrons data
        bool setData(istream& infile, int ID);

        


    private:
        string first;
        string last;
        int patronID;
        // transaction history for each patron
        list<Transaction*> history;
        // book list checkout for each patron
        list<Item*> borrowllist;
        int size = 0;
};

#endif