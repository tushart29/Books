//---------------------------------------------------------------------------
// display.h
// Derived transaction class for returning a checked out book
//---------------------------------------------------------------------------
// Display class Implementation and assumptions:  
//   -- Assumes Patron and Book both exist and are in system. 
//   -- Transaction* create returns Display object, for use with 
//      transaction factory class
//---------------------------------------------------------------------------
#ifndef DISPLAY
#define DISPLAY
#include "transaction.h"
class Library;
class Display : public Transaction
{
    public:
        //---------------------------------------------------------------------
        // Default Constructor
        Display();

        //---------------------------------------------------------------------
        // Destructor
        ~Display();

        //---------------------------------------------------------------------
        // For use with transactionfactory class - creates and returns an 
        // instance of the ReturnBook class
        virtual Transaction* create() const;


        virtual bool setData(istream& infile, BookFactory &books);
        //---------------------------------------------------------------------
        // Virtual print method for use with output overload
        virtual void print() const; 

        //---------------------------------------------------------------------
        // Virtual function to perform the transaction
        virtual bool execute(Library* library) ;    
};

#endif