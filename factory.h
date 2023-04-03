//---------------------------------------------------------------------------
// factory.h
// Parent Factory class for use with derived BookFactory and 
// TransactionFactory classes
//---------------------------------------------------------------------------
// Factory class:  Parent factory class with minimal functionality. 
//
// Implementation and assumptions:
//      -- Factory class not intended to be called directly.
//      -- Implementation is largely left to derived classes
//      -- Hash function assumes size of hash table in child classes to 
//         to be 36, with unique (closed) hashing.
//      -- No collision handling.
//---------------------------------------------------------------------------

#ifndef FACTORY
#define FACTORY

#include <iostream>
using namespace std;

// size of hash tables in derived classes (26 chars: A-Z)
const int CHARACTERS = 26; 

class Factory
{
    public:
        // Default Constructor
        Factory();     
        // Destructor: 
        ~Factory();
    protected:
        // Protected hash function for use in derived factory classes
        virtual int hash(char) const;
};

#endif