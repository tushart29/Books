//---------------------------------------------------------------------------
// childrensbook.h
// Derived class of Book class for book type of Children's Book
//---------------------------------------------------------------------------
// ChildrensBook class Implementation and assumptions:  
//   -- Item* create() function returns new ChildrensBook object for use
//      in factory class
//   -- setData function sets all data members for Children's book from 
//      data file
//   -- setTransaction Data function sets all relevant data members from 
//      transaction data file
//   -- Addition of author first and last name data members
//   -- Comparison overloads reflect sorting criteria of ChildrensBook 
//      class: sorted by title, then author. No other data used for sorting, 
//      and criteria uniquely identifies each childrens book.
//   -- ifstream for setData functions assumed to be well formatted, though
//      input data may not be valid. Invalid data will be discarded.
//   -- print function to be used to print books in the library and 
//      printcheckoutbooks function to print the transactions occured in a 
//      patron
//
//---------------------------------------------------------------------------
#ifndef CHILDRENSBOOK
#define CHILDRENSBOOK

#include "book.h"
#include <iomanip> 
class ChildrensBook : public Book
{
    public:
        //---------------------------------------------------------------------
        // Default Constructor
        ChildrensBook();

        //---------------------------------------------------------------------
        // Destructor
        virtual ~ChildrensBook();

        //---------------------------------------------------------------------
        // Getters/Setters
        virtual int getCopies() const;
        virtual void setCopies(int copies);
        virtual int getNumPatronsInBook() const;
        virtual void setNumPatronsInBook(int patron);
        

        //---------------------------------------------------------------------
        // For use with bookfactory class - creates and returns
        // an instance of the ChildrensBook class 
        virtual Item* create() const; 
        
        //---------------------------------------------------------------------
        // sets book data from book data file
        virtual bool setData(istream&);
        
        //---------------------------------------------------------------------
        // sets item data from transaction data file
        virtual bool setTransactionData(istream&);

        //---------------------------------------------------------------------
        // Virtual print function to use printing books
        virtual void print() const;   

        // virtual print function for use to print transactions
        virtual void printCheckoutBooks() const;

        //---------------------------------------------------------------------
        // Operator overloads
        virtual bool operator==(const Item&) const;
        virtual bool operator!=(const Item&) const;
        virtual bool operator<(const Item&) const;
        virtual bool operator>(const Item&) const;

    protected:
        string first;
        string last;
        int num_copies;
        int num_patrons_in_book;
};

#endif