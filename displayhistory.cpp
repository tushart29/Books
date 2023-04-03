//---------------------------------------------------------------------------
// displayhistory.cpp
// Derived transaction class for displaying a patron's history
//---------------------------------------------------------------------------
// DisplayHistory class Implementation and assumptions:  
//   -- Assumed Patron exists and is in the system.
//   -- Item* data member set to nullptr.
//   -- Transaction* create returns DisplayHistory object, for use with 
//      transaction factory class
//---------------------------------------------------------------------------

#include "displayhistory.h"
#include "item.h"
#include "patron.h"
#include "bookinventory.h"
#include "bookfactory.h"
#include "library.h"

// ---------------------------------------------------------------------------
// Constructor 
// Default constructor for class DisplayHistory 
DisplayHistory::DisplayHistory(){

}

// ---------------------------------------------------------------------------
// Destructor 
// when the allocation of a new memory occurs, the destructor deallocates
DisplayHistory::~DisplayHistory(){

}

// ---------------------------------------------------------------------------
// create
// For use with transactionfactory class - creates and returns an 
// instance of the ReturnBook class
Transaction* DisplayHistory::create()const{
    return new DisplayHistory();
}

// ---------------------------------------------------------------------------
// print
// can be used to print history
void DisplayHistory::print() const{
    cout << "DISPLAYHISTORY print " << endl;
}

// ---------------------------------------------------------------------------
// setData
// sets all data members for displayHistory from data file
bool DisplayHistory::setData(istream& infile, BookFactory &books){
    infile >> patron_id;
    return true;
}

// ---------------------------------------------------------------------------
// execute
// displays transaction history for patron
bool DisplayHistory::execute(Library* library) {
    if(!(library->getPatrons().retrieve(patron_id,patron))){
        cout << "PATRON: " << patron_id << " DOES NOT EXIST " << endl;
        return false;
    }
    cout << patron_id << "  " << patron->getLastName() << ",  " << patron->getFirstName() << endl;
    patron->printBorrowList();
    cout << endl;
    return false;

}
