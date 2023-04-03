//---------------------------------------------------------------------------
// item.h
// Parent class for all items available for use/checkout in 
// the library
//---------------------------------------------------------------------------
// Item class:  
//   includes additional features:
//   -- (Virtual) Getters/Setters for all data members
//   -- Overloaded output operator for use with virtual print method
//
// Implementation and assumptions:
//   -- Pure virtual functions to be defined in derived classes
//   -- Item class not intended to be called directly other than as a pointer
//      to a derived class.
//   -- data members include itemFormat (e.g. 'H' for hardcopy), title,
//      
//---------------------------------------------------------------------------
#ifndef ITEM
#define ITEM

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

class Item
{
    public:
        //---------------------------------------------------------------------
        // Default Constructor
        Item();

        //---------------------------------------------------------------------
        // Virtual destructor: items contained in the library are assigned as
        // Item* pointing to the derived class, so Item's destructor must
        // be virtual.
        virtual ~Item();
    
        //---------------------------------------------------------------------
        // Getters/Setters
 
        virtual int getCopies() const = 0;
        virtual void setCopies(int copies) = 0;
        
        virtual int getNumPatronsInBook() const = 0;
        virtual void setNumPatronsInBook(int patron) = 0;

        virtual string getTitle() const;
        //---------------------------------------------------------------------
        // Creates instance of item for use with factory class (pure virtual)
        virtual Item* create() const = 0; 
    
        //---------------------------------------------------------------------
        // sets item data from book data file (pure virtual)
        virtual bool setData(istream&) = 0;
    
        //---------------------------------------------------------------------
        // sets item data from transaction data file (pure virtual)
        virtual bool setTransactionData(istream&) = 0;

        //---------------------------------------------------------------------
        // Virtual print function for use with printing each type of book
        virtual void print() const = 0;

        // virtual print function for use to print transaction
        virtual void printCheckoutBooks() const = 0;
        
        //---------------------------------------------------------------------
        // Operator overloads (pure virtual)
        virtual bool operator==(const Item &) const = 0;
        virtual bool operator!=(const Item &) const = 0;
        virtual bool operator<(const Item &) const = 0;
        virtual bool operator>(const Item &) const = 0;

    protected:
        char itemFormat;
        string title;
        
};

#endif
