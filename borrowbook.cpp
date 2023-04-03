//---------------------------------------------------------------------------
// borrowbook.cpp
// Derived transaction class for checking out a book
//---------------------------------------------------------------------------
// BorrowBook class Implementation and assumptions:  
//   -- Assumed Patron and Book both exist and are in system.
//   -- Transaction* create returns BorrowBook object, for use with 
//      transaction factory class
//   -- print function prints the checkout transaction with book borrowed
//   -- executes function process the transaction 
//   -- setData function reads in the file, and sets the data to the object
//---------------------------------------------------------------------------
#include "borrowbook.h"
#include "item.h"
#include "patron.h"
#include "bookinventory.h"
#include "bookfactory.h"
#include "library.h"

// ---------------------------------------------------------------------------
// Constructor 
// Default constructor for class BorrowBook
BorrowBook::BorrowBook(){
    transactionType = 'C';
    partial_book = nullptr;
}
// ---------------------------------------------------------------------------
// Destructor 
// when the allocation of a new memory occurs, the destructor deallocates
BorrowBook::~BorrowBook(){
    delete partial_book;
}
// ---------------------------------------------------------------------------
// create
// Transaction* create returns BorrowBook object
Transaction* BorrowBook::create()const{
    return new BorrowBook();
}

// ---------------------------------------------------------------------------
// print
// prints transaction that the patron made 
void BorrowBook::print() const{
    cout << "Checkout  ";
    book->printCheckoutBooks();
}

// ---------------------------------------------------------------------------
// setData
// set data members from transaction file by reading the file
// returns false if copy type is not a hard copy ('H')
// returns false if book type is not 'C, 'F', and 'P'
bool BorrowBook::setData(istream& infile, BookFactory& books){

   
    int new_patron_ID;
    char copy_type; // hard copy
    infile >> new_patron_ID;
    infile.get();
    infile >> book_type;
    infile.get();
    infile >> copy_type;
    if(copy_type != 'H'){
        cout << "ERROR: copy type " <<  copy_type << 
        " is not a HARD COPY " << endl;
        return false;
    }
    infile.get();
    partial_book = books.createObject(book_type);
    if(partial_book == nullptr){
        cout << "ERROR: Book Type " << book_type  
        << " is incorrect " << endl;
        return false;
    }
    partial_book->setTransactionData(infile);
    patron_id = new_patron_ID;

    return true;
}
// ---------------------------------------------------------------------------
// execute
// executes function process the transaction if transaction type if 'C'
// returns false if patron and book does not exist
// returns false if number of copies are 0
bool BorrowBook::execute(Library* library) {
    /*
    finding the patron; 
    finding the book; 
    associating patron with book so the book becomes a part of the 
    patron's history; 
    associating book with patron so it is known that the book 
    is checked out by the patron and that the book has been checked out
    */
    
    if(!(library->getPatrons().retrieve(patron_id,patron))){
        cout << "ERROR: Patron ID " << patron_id << " DOES NOT EXIST " 
        << endl;
        return false;
    }
    
    if(library->getBookInventory(book_type).retrieve(*partial_book,book)){ 
        if(book->getCopies() == 0 && book->getNumPatronsInBook() == 0){
            cout << "ERROR: This book " << partial_book->getTitle() 
            << " is currently not avaliable " << endl;
            return false;
        }
        else{
            book->setCopies(book->getCopies()-1);
            
            book->setNumPatronsInBook(book->getNumPatronsInBook()-1);

            patron->addToBorrowList(book);
            
            patron->addToHistory(this);
            
            return true;
        }     
    }
    else{
        cout << "ERROR: Book "  << partial_book->getTitle()  
        << " does not exist in the library " << endl;
        return false;
    }
   
}
