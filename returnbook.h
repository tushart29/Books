//---------------------------------------------------------------------------
// returnbook.h
// Derived transaction class for returning a checked out book
//---------------------------------------------------------------------------
// ReturnBook class Implementation and assumptions:  
//   -- Assumes Patron and Book both exist and are in system. 
//   -- Checks to make sure book is in Patron's list of currently
//      checked out books
//   -- Transaction* create returns ReturnBook object, for use with 
//      transaction factory class
//---------------------------------------------------------------------------
#ifndef RETURNBOOK
#define RETURNBOOK
#include "transaction.h"
class Patron;
class Item;
class ReturnBook : public Transaction
{
    public:
        //---------------------------------------------------------------------
        // Default Constructor
        ReturnBook();

        //---------------------------------------------------------------------
        // Destructor
        ~ReturnBook();

        //---------------------------------------------------------------------
        // For use with transactionfactory class - creates and returns an 
        // instance of the ReturnBook class
        virtual Transaction* create() const;


        virtual bool setData(istream& infile, BookFactory &books);
        //---------------------------------------------------------------------
        // Virtual print method to print transaction
        virtual void print() const; 

        //---------------------------------------------------------------------
        // Virtual function to perform the transaction
        virtual bool execute(Library* library) ;
        
        protected:
            // retrieved patron 
            Patron* patron;
            // retrieved book
            Item* book; 
            // book read from file to find retrived book in inventory
            Item* partial_book; 
            char book_type;
            int patron_id;
        
};

#endif