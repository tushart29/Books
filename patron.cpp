//---------------------------------------------------------------------------
// patron.cpp
// Class representing a patron registered with the library
//---------------------------------------------------------------------------
// Patron class:
//
// Implementation and assumptions:
// -- Maintains history of transactions and list of borrowed books
// -- Performs methods to history such as adding and printing a 
// Patron's history, transactions and also adding and removing book items 
// from the borrowed list. 
// -- Assumes Item class and its derived classes have been properly 
// implemented
// 
//---------------------------------------------------------------------------

#include "patron.h"
#include "item.h"
#include "transaction.h"

// ---------------------------------------------------------------------------
// Constructor 
// Default constructor for class Patron 
Patron::Patron(){
    first = "FIRST";
    last = "LAST";
    patronID = 0;

}


// ---------------------------------------------------------------------------
// Destructor 
// when the allocation of a new memory occurs, the destructor deallocates
Patron::~Patron(){
    
    for (list<Transaction*>::iterator it= history.begin(); it != history.end(); ++it) {
        
        delete (*it);
        *it = nullptr;
    }
    
}



//---------------------------------------------------------------------------
// getFirstName
// returns firstname
string Patron::getFirstName() const{
    return first;
}

//---------------------------------------------------------------------------
// getLastName
// returns last
string Patron::getLastName() const{
    return last;
}

//---------------------------------------------------------------------------
// getID
// returns ID
int Patron::getID() const{
    return patronID;
}


//---------------------------------------------------------------------------
// setFirstName
// sets the data field 
void Patron::setFirstName(string first_name){
    first = first_name;
}

//---------------------------------------------------------------------------
// setLastName
// sets the data field 
void Patron::setLastName(string last_name){
    last = last_name;
}

//---------------------------------------------------------------------------
// setID
// sets the data field 
void Patron::setID(int ID){
    patronID = ID;
}

//---------------------------------------------------------------------------
// addToBorrowList
// pushes the book to the borrowllist list 
void Patron::addToBorrowList(Item* book){
    borrowllist.push_back(book);
}

//---------------------------------------------------------------------------
// addToHistory
// pushes the book to the history list 
void Patron::addToHistory(Transaction* current_transaction){
    history.push_back(current_transaction);
}

//---------------------------------------------------------------------------
// removeFromBorrowList
// removes the book from the list 
void Patron::removeFromBorrowList(Item* book){
    for(list<Item*>::iterator it=borrowllist.begin();it != borrowllist.end();++it){
        if(*it == book){
            it = borrowllist.erase(it);
            break;
        }
            
    }
}

//---------------------------------------------------------------------------
// printBorrowList
// prints the book list that the patron borrowed 
void Patron::printBorrowList(){
    
    if(borrowllist.empty()){
        
    }
    for(list<Transaction*>::iterator it=history.begin();it!=history.end();++it){
        (*it)->print();
    }
    cout << endl << endl;
}

//---------------------------------------------------------------------------
// retrieveInList
// returns true if book is in the list 
bool Patron::retrieveInList(Item* returnBook){
    for(list<Item*>::iterator it=borrowllist.begin();it!=borrowllist.end();++it){
        if(*it == returnBook){
            return true;
        }   
    }
    return false;
}

//---------------------------------------------------------------------------
// print
// prints patron's data 
void Patron::print(){
    cout << first << " " << last << " " << patronID << endl;
}


//---------------------------------------------------------------------------
// setData
// sets data from infile to current data fields 
bool Patron::setData(istream& infile, int ID){
    patronID = ID;
    infile >> last;
    infile >> first;
    return true;

}
