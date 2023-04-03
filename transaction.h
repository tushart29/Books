//---------------------------------------------------------------------------
// transaction.h
// Parent transaction class for main transaction types: checkout, return, 
// and display history
//---------------------------------------------------------------------------
// Transaction class Implementation and assumptions:  
//   -- Transaction class not intended to be called directly other than as
//      a pointer to derived classes.
//   -- Data members include pointer to Item object upon which it is acting, 
//      pointer to patron who is taking part in transaction, a bool type for 
//      confirming whether book data member is in library, and char for 
//      transaction type ('C' for checkout, 'R' for return, 'H' for 
//      displaying history)
//   -- Transaction* create to be implemented in derived classes, returns 
//      pointer to transaction object.
//---------------------------------------------------------------------------
#ifndef TRANSACTION
#define TRANSACTION

#include <iostream>

using namespace std;
class Library;
class BookFactory;
class Transaction
{
    public:
        //---------------------------------------------------------------------
        // Default Constructor
        Transaction();

        //---------------------------------------------------------------------
        // Destructor
        virtual ~Transaction();

        //---------------------------------------------------------------------
        // Getters/Setters
        virtual char getTransactionType() const;

        virtual void setTransactionType(char);

        //---------------------------------------------------------------------
        // For use with transactionfactory class - creates and returns an 
        // instance of the transaction class
        virtual Transaction* create() const = 0;

        //---------------------------------------------------------------------
        // Virtual print method for use with output overload
        virtual void print() const = 0; 

        //---------------------------------------------------------------------
        // Virtual setData method to set data members from transaction file
        // virtual bool setData(Patron*, Item*, bool);
        virtual bool setData(istream& infile, BookFactory &book_factory) = 0;
        
        //---------------------------------------------------------------------
        // Pure virtual function to perform the transaction
        virtual bool execute(Library* library) = 0;

    protected:
        // transaction type 
        char transactionType; 
        
        
};

#endif