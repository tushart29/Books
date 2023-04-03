//---------------------------------------------------------------------------
// book.cpp
// Derived class of Item, Parent class for all books contained in the library
//---------------------------------------------------------------------------
// Implementation and assumptions:
//   -- Pure virtual functions to be defined in derived classes
//   -- Book class not intended to be called directly other than as a pointer
//      to a derived class.
//   -- Addition of publication year (int) and booktype (char) as data members
//---------------------------------------------------------------------------

#include "book.h"
// ---------------------------------------------------------------------------
// Constructor 
// Default constructor for class Book
Book::Book(){
    year = 0;
    bookType = 'Z';
}
// ---------------------------------------------------------------------------
// Destructor 
// when the allocation of a new memory occurs, the destructor deallocates
Book::~Book(){
    
}
