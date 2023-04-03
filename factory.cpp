//---------------------------------------------------------------------------
// factory.cpp
// Parent Factory class for use with derived BookFactory and 
// TransactionFactory classes
//---------------------------------------------------------------------------
// Factory class:  Parent factory class with minimal functionality. 
//
// Implementation and assumptions:
//      -- Factory class not intended to be called directly.
//      -- Implementation is largely left to derived classes
//      -- Hash function assumes size of hash table in child classes to 
//         to be 26, with unique (closed) hashing.
//      -- No collision handling.
//---------------------------------------------------------------------------

#include  "factory.h"

// ---------------------------------------------------------------------------
// Constructor 
// Default constructor for class Factory 
Factory::Factory(){

}

// ---------------------------------------------------------------------------
// Destructor 
// when the allocation of a new memory occurs, the destructor deallocates
Factory::~Factory(){
    
}

// ---------------------------------------------------------------------------
// hash 
// returns a integer when type is hashed 
int Factory::hash(char type) const{
    return type - 'A';
}