//---------------------------------------------------------------------------
// displayhistory.h
// Derived transaction class for displaying a patron's history
//---------------------------------------------------------------------------
// DisplayHistory class Implementation and assumptions:  
//   -- Assumed Patron exists and is in the system.
//   -- Item* data member set to nullptr.
//   -- Transaction* create returns DisplayHistory object, for use with 
//      transaction factory class
//---------------------------------------------------------------------------
#ifndef DISPLAY_LIBRARY
#define DISPLAY_LIBRARY
#include "transaction.h"
class Patron;
class Item;

class DisplayHistory : public Transaction
{
    public:
        //---------------------------------------------------------------------
        // Default Constructor
        DisplayHistory();

        //---------------------------------------------------------------------
        // Destructor
        ~DisplayHistory();

        //---------------------------------------------------------------------
        // For use with transactionfactory class - creates and returns an 
        // instance of the ReturnBook class
        virtual Transaction* create() const;

        //---------------------------------------------------------------------
        // sets data from commands file to the attributes in this class
        virtual bool setData(istream& infile, BookFactory &books);


        //---------------------------------------------------------------------
        // Virtual print method for use with output overload
        virtual void print() const; 
        
        //---------------------------------------------------------------------
        // Virtual function to perform the transaction
        virtual bool execute(Library* library) ;

        protected:
            int patron_id;
            Patron* patron;
            
};

#endif