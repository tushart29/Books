//---------------------------------------------------------------------------
// item.cpp
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
//   -- data members include itemFormat (e.g. 'H' for hardcopy) and title
//     
//---------------------------------------------------------------------------
#include "item.h"


// ---------------------------------------------------------------------------
// Constructor 
// Default constructor for class Item 
Item::Item(){
    itemFormat = 'X';
    title = "";
    
}

// ---------------------------------------------------------------------------
// Destructor 
// when the allocation of a new memory occurs, the destructor deallocates
Item::~Item(){

}
//---------------------------------------------------------------------
// getTitle
// returns the title
string Item::getTitle() const{
    return title;
}


