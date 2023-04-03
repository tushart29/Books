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
#ifndef TRANSACTION_FACTORY
#define TRANSACTION_FACTORY

#include "factory.h"
#include "transaction.h"
#include "borrowbook.h"
#include "returnbook.h"
#include "displayhistory.h"
#include "display.h"

class TransactionFactory : public Factory
{
    public:
        //---------------------------------------------------------------------
        // constructor 
        TransactionFactory();

        //---------------------------------------------------------------------
        // destructor 
        virtual ~TransactionFactory();

        //---------------------------------------------------------------------
        // creates a type of a transaction object 
        Transaction* createObject(char) const;
    protected:
        // used to create a transaction type according to type
        Transaction* objFactory[CHARACTERS];

};

#endif