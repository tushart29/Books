// Derived class of Factory class for returning transaction objects
//---------------------------------------------------------------------------
// Transactionfactory class Implementation and assumptions:  
//   -- Item* createObject(char) function returns new Transaction object, 
//      where the type of transaction is determined by input char 
//      ('C' for checkout, 'R' for return, 'H' for displaying a patron's
//      history).
//   -- objFactory data member is array of Transaction*, where each each 
//      index maps to a particular transaction type. 
//   -- Hashing function used to map a given char value to index of array
//   -- Invalid input chars return null pointers
//
//---------------------------------------------------------------------------


#include "transactionfactory.h"


// ---------------------------------------------------------------------------
// Constructor 
// Default constructor for class TransactionFactory 
TransactionFactory::TransactionFactory(){
    for(int i = 0; i < CHARACTERS; i++){
        objFactory[i] = nullptr;
    }
    objFactory['C'-'A'] = new BorrowBook();
    objFactory['R'-'A'] = new ReturnBook();
    objFactory['H'-'A'] = new DisplayHistory();
    objFactory['D'-'A'] = new Display();
    // first create these .cpp classes, then test 
}

// ---------------------------------------------------------------------------
// Destructor 
// when the allocation of a new memory occurs, the destructor deallocates
TransactionFactory::~TransactionFactory(){
    for(int i = 0; i < CHARACTERS; i++){
        if(objFactory[i] != nullptr){
            delete objFactory[i];
            objFactory[i] = nullptr;
        }
        
    }
}


// ---------------------------------------------------------------------------
// create
// Transaction* create a transaction object
Transaction* TransactionFactory::createObject(char transaction_type) const{
   

    if(transaction_type - 'A' < 0 || transaction_type - 'A' > 25){
        return nullptr;
    }
    
    int subscript = hash(transaction_type);
    if(objFactory[subscript] == nullptr){
        return nullptr;
    }
    return objFactory[subscript]->create();
}

