//---------------------------------------------------------------------------
// returnbook.cpp
// Derived transaction class for returning a checked out book
//---------------------------------------------------------------------------
// ReturnBook class Implementation and assumptions:  
//   -- Assumes Patron and Book both exist and are in system. 
//   -- Checks to make sure book is in Patron's list of currently
//      checked out books
//   -- Transaction* create returns ReturnBook object, for use with 
//      transaction factory class
//---------------------------------------------------------------------------

#include "returnbook.h"
#include "item.h"
#include "patron.h"
#include "bookinventory.h"
#include "bookfactory.h"
#include "library.h"

// ---------------------------------------------------------------------------
// Constructor 
// Default constructor for class Return 
ReturnBook::ReturnBook(){
    transactionType = 'R';
    partial_book = nullptr;
}

// ---------------------------------------------------------------------------
// Destructor 
// when the allocation of a new memory occurs, the destructor deallocates
ReturnBook::~ReturnBook(){
    delete partial_book;
}

// ---------------------------------------------------------------------------
// create
// Item* create returns ReturnBook object
Transaction* ReturnBook::create()const{
    return new ReturnBook();
}


// ---------------------------------------------------------------------------
// print
// prints transaction that the patron made 
void ReturnBook::print() const{
    cout << "Return  ";
    book->printCheckoutBooks();
}


// ---------------------------------------------------------------------------
// setData
// set data members from transaction file by reading the file
// returns false if copy type is not a hard copy ('H')
// returns false if book type is not 'C, 'F', and 'P'
bool ReturnBook::setData(istream& infile, BookFactory &books){
    // R 1111 C H Danny Dunn & the Homework Machine, Williams Jay,

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
// executes function process the transaction if transaction type if 'R'
// returns false if patron and book does not exist
bool ReturnBook::execute(Library* library) {
    
    if(!(library->getPatrons().retrieve(patron_id,patron))){
        cout << "ERROR: Patron ID " << patron_id 
        << " DOES NOT EXIST " << endl;
        return false;
    }
    
    if(library->getBookInventory(book_type).retrieve(*partial_book,book)){ 
        // check if the this book being return is checked out before 
        if(!(patron->retrieveInList(book))){
            cout << "ERROR: Patron ID " << patron_id 
            << " did not check out the book " << endl;
            return false;
        }
        else{
            // increment the number of copies
            book->setCopies(book->getCopies()+1);
                
            // increment the number of patron avaliable in the book type class
            book->setNumPatronsInBook(book->getNumPatronsInBook()+1);

            // removes the book from the patron list of borrowed books
            
            patron->removeFromBorrowList(book); 
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
