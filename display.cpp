//---------------------------------------------------------------------------
// display.cpp
// Derived transaction class for returning a checked out book
//---------------------------------------------------------------------------
// Display class Implementation and assumptions:  
//   -- Assumes Patron and Book both exist and are in system. 
//   -- Transaction* create returns Display object, for use with 
//      transaction factory class
//--------------------------------------------------------------------------- 
 
 #include "display.h"
 #include "library.h"
//---------------------------------------------------------------------
// Default Constructor
Display::Display(){

}

//---------------------------------------------------------------------
// Destructor
Display::~Display(){

}

//---------------------------------------------------------------------
// For use with transactionfactory class - creates and returns an 
// instance of the ReturnBook class
Transaction* Display::create() const{
    return new Display;
}


bool Display::setData(istream& infile, BookFactory &books){
    return true;
}
//---------------------------------------------------------------------
// Virtual print method for use with output overload
void Display::print() const{

}

        
//---------------------------------------------------------------------
// Virtual function to perform the transaction
bool Display:: execute(Library* library){
    library->print();
    return false;
}

        