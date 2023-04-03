// ---------------------------------------------------------------------------
// fiction.h
// Derived class of Book class for Fiction books
//---------------------------------------------------------------------------
// Fiction class Implementation and assumptions:  
//   -- Item* create() function returns new Fiction object for use
//      in factory class
//   -- setData function sets all data members for fiction book from 
//      data file
//   -- setTransaction Data function sets all relevant data members from 
//      transaction data file
//   -- Addition of author first and last name data members
//   -- Comparison overloads reflect sorting criteria of Fiction 
//      class: sorted by author, then title. No other data used for sorting, 
//      and criteria uniquely identifies each fiction book.
//   -- ifstream for setData functions assumed to be well formatted, though
//      input data may not be valid. Invalid data will be discarded.
//   -- print function to be used to print books in the library and 
//      printcheckoutbooks function to print the transactions occured in a 
//      patron
//
//---------------------------------------------------------------------------
#ifndef FICTION
#define FICTION

#include "book.h"
#include <limits.h>
#include <iomanip> 

class Fiction : public Book
{
    public:
        //---------------------------------------------------------------------
        // Default Constructor
        Fiction();

        //---------------------------------------------------------------------
        // Destructor
        virtual ~Fiction();

        //---------------------------------------------------------------------
        // Getters/Setters
        virtual int getCopies() const;
        virtual void setCopies(int copies);
        virtual int getNumPatronsInBook() const;
        virtual void setNumPatronsInBook(int patron);

        //---------------------------------------------------------------------
        // For use with bookfactory class creates - creates and returns
        // and instance of the Fiction book class 
        virtual Item* create() const; 
        
        //---------------------------------------------------------------------
        // sets book data from data file
        virtual bool setData(istream&);

        //---------------------------------------------------------------------
        // sets book data from data file 
        virtual bool setTransactionData(istream&);

        //---------------------------------------------------------------------
        // Virtual print function for use to printing books
        virtual void print() const; 

        // virtual print function for use to print transaction
        virtual void printCheckoutBooks() const;

        //---------------------------------------------------------------------
        // Operator overloads
        virtual bool operator==(const Item &) const;
        virtual bool operator!=(const Item &) const;
        virtual bool operator<(const Item &) const;
        virtual bool operator>(const Item &) const;

    protected:
        string first;
        string last;
        int num_copies;
        int num_patrons_in_book;
};

#endif