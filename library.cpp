//---------------------------------------------------------------------------
// library.cpp
// Primary manager class to be called by the main. Handles building of the
// library, creating list of patrons, and processing transactions.
//---------------------------------------------------------------------------
// Library class Implementation and assumptions:  
//   -- Data members include the hashmap of patrons, hash table of binary 
//      trees holding all books, book and transaction factory objects for
//      instantiating book and transaction objects.
//   -- Hash function maps char of book type (C for childrens book, F for
//      fiction, and P for Periodical) to indexes in the array of Binary 
//      Trees. Assumes 1:1 mapping (closed hashing), no collision handling
//
//---------------------------------------------------------------------------

#include "library.h"
#include <limits>

// ---------------------------------------------------------------------------
// Constructor 
// Default constructor for class Library 
Library::Library(){
   
}

// ---------------------------------------------------------------------------
// Destructor 
// when the allocation of a new memory occurs, the destructor deallocates
Library::~Library(){

}

//---------------------------------------------------------------------------
// print
// prints the whole library 
void Library::print(){
    cout << "FICTION BOOKS " << endl;
    cout << left << setw(15) << "AVAIL"
    << setw(25) << "Author"
    << setw(40) << "Title"
    << setw(4) << "Year"
    << endl;
     
    books['F'-'A'].inOrderPrint();    
    cout << endl << endl;

    cout << "CHILDRENS BOOKS " << endl;
    cout << left << setw(15) << "AVAIL"
    << setw(25) << "Author"
    << setw(40) << "Title"
    << setw(4) << "Year"
    << endl;    
    books['C'-'A'].inOrderPrint();
    cout << endl << endl;

    cout << "PERIODICAL BOOKS " << endl;
    cout << left << setw(15) << "AVAIL"
    << setw(40) << "Title"
    << setw(25) << "Month"
    << setw(4) << "Year"
    << endl;
    books['P'-'A'].inOrderPrint();  
    cout << endl << endl;
    
}

//---------------------------------------------------------------------
// addBooks
// adds books into binary search tree
void Library::addBooks(istream& infile){
    // Sample line of data: F Pirsig Robert, 
    // Zen & the Art of Motorcycle Maint, 1974
    Item* new_item;
    bool success_data = false;
    while(true) {
        
        char code;
        bool insert;
        // reads the 'F' code
        infile >> code; 
        
        if(infile.eof()){
            break;
        }
        new_item = bookFactory.createObject(code);
        if(new_item == nullptr){
            cout << "ERROR: Item " << code << 
            " passed in is invalid (nullptr) " << endl;
            infile.ignore(numeric_limits<streamsize>::max(), '\n');
            
        }
        else{
            
            success_data = new_item->setData(infile); 
            if(success_data == true){
                
                insert = books[code-'A'].insert(new_item);
                if(insert == false){
                    delete new_item;
                    new_item = nullptr;
                }
            }
            else{
                delete new_item;
                new_item = nullptr;
            }
            
        }
    }
}

//---------------------------------------------------------------------
// addPatrons
// adds patrons into hash map 
void Library::addPatrons(istream& infile){
    
    int new_id;
    
    bool result;
    while(true){
        infile >> new_id;
    
        if(infile.eof()){
            break;
        }
        Patron* patron = new Patron;
        
        patron->setData(infile, new_id);
       
        result = patrons.insert(patron);
        
        if(result == false){
            delete patron;
            patron = nullptr;
        }
        
    }
}

//---------------------------------------------------------------------
// processTransactions
// process transactions from the file
void Library::processTransactions(istream& infile){
    Transaction* new_transaction;
    bool success_data;
    bool success_transaction;
    string s;
    while(true){
        char type;
        infile >> type;

        if(infile.eof()){
            break;
        }
        
        new_transaction = transactionFactory.createObject(type);
        
        if(new_transaction == nullptr){
            cout << "ERROR: Transaction Type " << type 
            << " passed in is invalid (nullptr) " << endl;
            infile.ignore(numeric_limits<streamsize>::max(),'\n');
        }
        
        else{
            infile.get();
            success_data=new_transaction->setData(infile,bookFactory); 
            if(success_data == true){
                success_transaction = new_transaction->execute(this);
                if(!success_transaction){
                    delete new_transaction;
                    new_transaction = nullptr;
                }
               
            }
            else{
                delete new_transaction;
                new_transaction = nullptr;
                infile.ignore(numeric_limits<streamsize>::max(),'\n');
            }
            
        }
        
    }

}

//---------------------------------------------------------------------
// getPatrons
// returns the patron hashmap by reference 
PatronHashMap& Library::getPatrons(){
    return patrons;
}

//---------------------------------------------------------------------
// getBookInventory
// returns the book inventory by reference 
BookInventory& Library::getBookInventory(char book_type){
    return books[book_type-'A'];
}

