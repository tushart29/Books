// ---------------------------------------------------------------------------
// fiction.cpp
// Derived class of Book class for Fiction books
//---------------------------------------------------------------------------
// Fiction class Implementation and assumptions:  
//   -- Item* create() function returns new Fiction object for use
//      in factory class
//   -- setData function sets all data members for fiction book from 
//      data file
//   -- setTransaction Data function sets all relevant data members from 
//      transaction data file
//   -- Addition of author first and last name data members
//   -- Comparison overloads reflect sorting criteria of Fiction 
//      class: sorted by author, then title. No other data used for sorting, 
//      and criteria uniquely identifies each fiction book.
//   -- ifstream for setData functions assumed to be well formatted, though
//      input data may not be valid. Invalid data will be discarded.
//   -- print function to be used to print books in the library and 
//      printcheckoutbooks function to print the transactions occured in a 
//      patron
//
//---------------------------------------------------------------------------

#include "fiction.h"
#include "patron.h"

// ---------------------------------------------------------------------------
// Constructor 
// Default constructor for class Fiction 
Fiction::Fiction(){
    first = "first_name";
    last = "last_name";
    year = 0;
    num_copies = 5;
    num_patrons_in_book = 5;
   
}

// ---------------------------------------------------------------------------
// Destructor 
// when the allocation of a new memory occurs, the destructor deallocates
Fiction::~Fiction(){
    
}

// ---------------------------------------------------------------------------
// create
// Item* create returns Fiction object
Item* Fiction::create() const{
    return new Fiction;
}

// ---------------------------------------------------------------------------
// setData
// sets all data members for Fiction's book from data file
bool Fiction::setData(istream& infile){
    // F Pirsig Robert, Zen & the Art of Motorcycle Maint, 1974
    
    string input_first;
    string input_last;
    string input_title;
    int input_year;
    // get (and ignore) blank before author, // don't use if you want to keep the blank
    infile.get(); 

    // input last name, looks for space terminator
    getline(infile, input_last, ' '); 
    // input first name, looks for comma terminator 
    getline(infile, input_first, ','); 

    // get (and ignore) blank before title
    infile.get();

    // input title
    getline(infile, input_title, ',');      

    // reads year
    infile >> year;
    first = input_first;
    last = input_last;
    title = input_title;
    year = year;
    return true;

}


//---------------------------------------------------------------------------
// operator==  
// Determine if two fiction books are equal.
bool Fiction::operator==(const Item & otherFiction) const{
    if(last == static_cast<const Fiction&>(otherFiction).last &&
        first == static_cast<const Fiction&>(otherFiction).first &&
        title == static_cast<const Fiction&>(otherFiction).title){
            return true;
    }
    return false;
}

//---------------------------------------------------------------------------
// operator!=  
// Determine if two childrensbook are not equal.
bool Fiction::operator!=(const Item & otherFiction) const{
    return !(*this == otherFiction);
}
    
//---------------------------------------------------------------------------
// operator< 
// compares the two fiction books using the less operator
bool Fiction::operator<(const Item & otherFiction) const {
    
    if(last < static_cast<const Fiction&>(otherFiction).last){
        return true;  
    }
    else if(last == static_cast<const Fiction&>(otherFiction).last &&
    first < static_cast<const Fiction&>(otherFiction).first){
        return true;
    }
    else if(last == static_cast<const Fiction&>(otherFiction).last &&
    first == static_cast<const Fiction&>(otherFiction).first &&
    title < static_cast<const Fiction&>(otherFiction).title){
        return true;
    }
    return false;
    
}

//---------------------------------------------------------------------------
// operator< 
// compares the two fiction books using the greater operator
bool Fiction::operator>(const Item & otherFiction) const{
    if(last > static_cast<const Fiction&>(otherFiction).last){
        return true;  
    }
    else if(last == static_cast<const Fiction&>(otherFiction).last &&
    first > static_cast<const Fiction&>(otherFiction).first){
        return true;
    }
    else if(last == static_cast<const Fiction&>(otherFiction).last &&
    first == static_cast<const Fiction&>(otherFiction).first &&
    title > static_cast<const Fiction&>(otherFiction).title){
        return true;
    }
    return false;
}

//---------------------------------------------------------------------------
// print
// prints a fiction which will be used to print the library
void Fiction::print() const {
    
    cout << left << setw(15) << num_copies
     << setw(25) << last + " " + first 
     << setw(40) << title
     << setw(4) << year
     << endl;
}

//---------------------------------------------------------------------------
// printCheckoutBooks
// prints a fiction which will be used to print the transaction
void Fiction:: printCheckoutBooks() const{
    cout << left << setw(25) << title
     << setw(30) << last + " " +  first
     << setw(4) << year 
     << endl;
}

// ---------------------------------------------------------------------------
// setTransactionData
// sets all data members for Fiction's book from data file
bool Fiction::setTransactionData(istream& infile){
    string first_name;
    string last_name;
    string new_title;
   
    // Example: C 8000 F H Kerouac Jack, On the Road,
    
    getline(infile, last_name, ' '); 
    getline(infile, first_name, ','); 
    infile.get();
    getline(infile,new_title,',');
    first = first_name;
    last = last_name;
    title = new_title;
    // get the year 
    return true;
}

//---------------------------------------------------------------------------
// getCopies
// returns number of copies avaliable
int Fiction:: getCopies() const{
    return num_copies;
}

//---------------------------------------------------------------------------
// setCopies
// sets the data field 
void Fiction::setCopies(int copies){
    num_copies = copies;
}

//---------------------------------------------------------------------------
// getNumPatronsInBook
// returns number of patrons in a book
int Fiction:: getNumPatronsInBook() const{
    return num_patrons_in_book;
}

//---------------------------------------------------------------------------
// setNumPatronsInBook
// sets the data field 
void Fiction::setNumPatronsInBook(int patron){
    num_patrons_in_book = patron;
}
