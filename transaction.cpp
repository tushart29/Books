//---------------------------------------------------------------------------
// transaction.cpp
// Parent transaction class for main transaction types: checkout, return, 
// and display history
//---------------------------------------------------------------------------
// Transaction class Implementation and assumptions:  
//   -- Transaction class not intended to be called directly other than as
//      a pointer to derived classes.
//   -- Data members include pointer to Item object upon which it is acting, 
//      pointer to patron who is taking part in transaction, a bool type for 
//      confirming whether book data member is in library, and char for 
//      transaction type ('C' for checkout, 'R' for return, 'H' for 
//      displaying history)
//   -- Transaction* create to be implemented in derived classes, returns 
//      pointer to transaction object.
//---------------------------------------------------------------------------


#include "transaction.h"
#include "library.h"
#include "bookfactory.h"
#include "item.h"
#include "patron.h"


// ---------------------------------------------------------------------------
// Constructor 
// Default constructor for class Transaction 
Transaction::Transaction(){

}

// ---------------------------------------------------------------------------
// Destructor 
// when the allocation of a new memory occurs, the destructor deallocates
Transaction::~Transaction(){
    
}


// ---------------------------------------------------------------------------
// getTransactionType
// returns the transaction type
char Transaction::getTransactionType() const{
    return transactionType;
}

// ---------------------------------------------------------------------------
// setTransactionType
// sets the transaction type
void Transaction::setTransactionType(char t_type){
    transactionType = t_type;
}
