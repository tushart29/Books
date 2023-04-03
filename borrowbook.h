//---------------------------------------------------------------------------
// borrowbook.h
// Derived transaction class for checking out a book
//---------------------------------------------------------------------------
// BorrowBook class Implementation and assumptions:  
//   -- Assumed Patron and Book both exist and are in system.
//   -- Transaction* create returns BorrowBook object, for use with 
//      transaction factory class
//   -- print function prints the checkout transaction with book borrowed
//   -- executes function process the transaction 
//   -- setData function reads in the file, and sets the data to the object
//---------------------------------------------------------------------------
#ifndef BORROWBOOK
#define BORROWBOOK
#include "transaction.h"
class Patron;
class Item;

class BorrowBook : public Transaction
{
    public:
        //---------------------------------------------------------------------
        // Default Constructor
        BorrowBook();

        //---------------------------------------------------------------------
        // Destructor
        ~BorrowBook();

        //---------------------------------------------------------------------
        // For use with transactionfactory class - creates and returns an 
        // instance of the BorrowBook class
        virtual Transaction* create() const;

        //---------------------------------------------------------------------
        // Virtual print method for use to print transactions
        virtual void print() const; 
        
        //---------------------------------------------------------------------
        // Virtual setData method to set data members from transaction file
        virtual bool setData(istream& infile, BookFactory& books);

        //---------------------------------------------------------------------
        // Virtual function to perform the transaction
        virtual bool execute(Library* library) ;

    

        protected:
            Patron* patron;
            Item* book; // retrieved book
            Item* partial_book;
            bool inTree;
            char book_type;
            int patron_id;
            
        
};

#endif