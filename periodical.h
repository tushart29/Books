//---------------------------------------------------------------------------
// periodical.h
// Derived class of Book class for Periodicals
//---------------------------------------------------------------------------
// Periodical class Implementation and assumptions:  
//   -- Item* create() function returns new Periodical object for use
//      in factory class
//   -- setData function sets all data members for periodical from 
//      data file
//   -- setTransaction Data function sets all relevant data members from 
//      transaction data file
//   -- Addition of month data member
//   -- Comparison overloads reflect sorting criteria of periodical 
//      class: sorted by year, then month, then title. No other data used 
//      for sorting, and criteria uniquely identifies each periodical.
//   -- ifstream for setData functions assumed to be well formatted, though
//      input data may not be valid. Invalid data will be discarded.
//   -- print function to be used to print books in the library and 
//      printcheckoutbooks function to print the transactions occured in a 
//      patron
//
//---------------------------------------------------------------------------
#ifndef PERIODICAL
#define PERIODICAL

#include "book.h"
#include <iomanip> 

class Periodical : public Book
{
    public:
        //---------------------------------------------------------------------
        // Default Constructor
        Periodical();

        //---------------------------------------------------------------------
        // Destructor
        virtual ~Periodical();

        //---------------------------------------------------------------------
        // Getters/Setters
        virtual int getCopies() const;
        virtual void setCopies(int copies);
        virtual int getNumPatronsInBook() const;
        virtual void setNumPatronsInBook(int patron);

        //---------------------------------------------------------------------
        // For use with bookfactory class creates - creates and returns
        // and instance of the Periodical book class 
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
        
        // virtual print function for use to print transactions
        virtual void printCheckoutBooks() const;

        //---------------------------------------------------------------------
        // Operator overloads
        virtual bool operator==(const Item &) const;
        virtual bool operator!=(const Item &) const;
        virtual bool operator<(const Item &) const;
        virtual bool operator>(const Item &) const;

    protected:
        int month;
        int year;
        int num_copies;
        int num_patrons_in_book;
};

#endif