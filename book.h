//---------------------------------------------------------------------------
// book.h
// Derived class of Item, Parent class for all books contained in the library
//---------------------------------------------------------------------------
// Implementation and assumptions:
//   -- Pure virtual functions to be defined in derived classes
//   -- Book class not intended to be called directly other than as a pointer
//      to a derived class.
//   -- Addition of publication year (int) and booktype (char) as data members
//---------------------------------------------------------------------------
#ifndef BOOK
#define BOOK

#include "item.h"

class Book : public Item
{
    public:
        //---------------------------------------------------------------------
        // Default Constructor
        Book();

        //---------------------------------------------------------------------
        // Destructor
        virtual ~Book();
        
        //---------------------------------------------------------------------
        // For use with bookfactory class (pure virtual)
        virtual Item* create() const = 0; 
    
        //---------------------------------------------------------------------
        // sets book data from data file (pure virtual)
        virtual bool setData(istream&) = 0;

        //---------------------------------------------------------------------
        // sets item data from transaction data file (pure virtual)
        virtual bool setTransactionData(istream&) = 0;

        //---------------------------------------------------------------------
        // Virtual print function for use to print the book data
        virtual void print() const = 0;
        
        //---------------------------------------------------------------------
        //Virtual print function for use to print transactions for each patron
        virtual void printCheckoutBooks() const = 0;

        //---------------------------------------------------------------------
        // Operator overloads (pure virtual)
        virtual bool operator==(const Item &) const = 0;
        virtual bool operator!=(const Item &) const = 0;
        virtual bool operator<(const Item &) const = 0;
        virtual bool operator>(const Item &) const = 0;

    protected:
        // further data members for book items
        int year;
        char bookType;
    
};

#endif