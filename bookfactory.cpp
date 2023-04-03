
//---------------------------------------------------------------------------
// bookfactory.cpp
// Derived class of Factory class for returning book objects
//---------------------------------------------------------------------------
// Bookfactory class Implementation and assumptions:  
//   -- Item* createObject(char) function returns new Book object, where the
//      type of book is determined by input char ('C' for ChildrensBook,
//      'F' for Fiction, 'P' for periodical).
//   -- objFactory data member is array of Item*, where each each index maps 
//      to a particular book type. 
//   -- Hashing function used to map a given char value to index of array
//   -- Invalid input chars return null pointers
//
//---------------------------------------------------------------------------
#include "bookfactory.h"

// ---------------------------------------------------------------------------
// Constructor 
// Default constructor for class Bookfactory
BookFactory::BookFactory(){
    for(int i = 0; i < CHARACTERS; i++){
        objFactory[i] = nullptr;
    }
    objFactory['F'-'A'] = new Fiction();
    objFactory['C'-'A'] = new ChildrensBook();
    objFactory['P'-'A'] = new Periodical();
}
// ---------------------------------------------------------------------------
// Destructor 
// when the allocation of a new memory occurs, the destructor deallocates
BookFactory::~BookFactory(){
    for(int i = 0; i < CHARACTERS; i++){
        delete objFactory[i];
        objFactory[i] = nullptr;
    }
    
}
// ---------------------------------------------------------------------------
// createObject
// creates a type of a item object 
Item* BookFactory::createObject(char book_type) const{
    if(book_type - 'A' < 0 || book_type - 'A' > 25){
        // cout << "error checking " << endl;
        return nullptr;
    }
    
    int subscript = hash(book_type);
    if(objFactory[subscript] == nullptr){
        // cout << "NULL POINTER" << endl;
        return nullptr;
    }
    return objFactory[subscript]->create();
}