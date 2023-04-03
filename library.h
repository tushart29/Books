//---------------------------------------------------------------------------
// library.h
// Primary manager class to be called by the main. Handles building of the
// library, creating list of patrons, and processing transactions.
//---------------------------------------------------------------------------
// Library class Implementation and assumptions:  
//   -- Data members include the hashmap of patrons, hash table of binary 
//      trees holding all books, book and transaction factory objects for
//      instantiating book and transaction objects.
//   -- Hash function maps char of book type (C for childrens book, F for
//      fiction, and P for Periodical) to indexes in the array of Binary 
//      Trees. Assumes 1:1 mapping (closed hashing), no collision handling
//
//---------------------------------------------------------------------------
#ifndef LIBRARY_H
#define LIBRARY_H

#include "patronhashmap.h"
#include "bookinventory.h"
#include "bookfactory.h"
#include "transactionfactory.h"

class Library
{
    public:
        //---------------------------------------------------------------------
        // Default constructor 
        Library();
        //---------------------------------------------------------------------
        // Destructor
        ~Library();
        //---------------------------------------------------------------------
        // Executes transactions 
        void processTransactions(istream&);
        //---------------------------------------------------------------------
        // adds books into binary search tree
        void addBooks(istream&);
        //---------------------------------------------------------------------
        // prints all the books in the library 
        void print();
        //---------------------------------------------------------------------
        // adds patrons in the hashmap 
        void addPatrons(istream&);

        //---------------------------------------------------------------------
        // getters to called in transaction classes
        PatronHashMap& getPatrons();
        BookInventory& getBookInventory(char book_type);
        
        
    private:
        // strorage of patrons
        PatronHashMap patrons;
        // storage of books
        BookInventory books[26];
        // factory for getting type of books
        BookFactory bookFactory;
        // factory for getting type of transaction
        TransactionFactory transactionFactory;
       
};

#endif 