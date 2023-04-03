//---------------------------------------------------------------------------
// childrensbook.cpp
// Derived class of Book class for book type of Children's Book
//---------------------------------------------------------------------------
// ChildrensBook class Implementation and assumptions:  
//   -- Item* create() function returns new ChildrensBook object for use
//      in factory class
//   -- setData function sets all data members for Children's book from 
//      data file
//   -- setTransaction Data function sets all relevant data members from 
//      transaction data file
//   -- Addition of author first and last name data members
//   -- Comparison overloads reflect sorting criteria of ChildrensBook 
//      class: sorted by title, then author. No other data used for sorting, 
//      and criteria uniquely identifies each childrens book.
//   -- ifstream for setData functions assumed to be well formatted, though
//      input data may not be valid. Invalid data will be discarded.
//   -- print function to be used to print books in the library and 
//      printcheckoutbooks function to print the transactions occured in a 
//      patron
//
//---------------------------------------------------------------------------
#include "childrensbook.h"

// ---------------------------------------------------------------------------
// Constructor 
// Default constructor for class Childrensbook
ChildrensBook::ChildrensBook(){
    first = "first_name";
    last = "last_name";
    year = 0;
    num_copies = 5;
    num_patrons_in_book = 5;

}

// ---------------------------------------------------------------------------
// Destructor 
// when the allocation of a new memory occurs, the destructor deallocates
ChildrensBook::~ChildrensBook(){
    
}

// ---------------------------------------------------------------------------
// create
// Item* create returns Childrensbook object
Item* ChildrensBook::create() const{
    return new ChildrensBook;
}

// ---------------------------------------------------------------------------
// setData
// sets all data members for Children's book from data file
bool ChildrensBook::setData(istream& infile){
    
    
    string input_first;
    string input_last;
    string input_title;
    int input_year;
    // get (and ignore) blank before author, 
    infile.get(); 

    // input first name, looks for space terminator
    getline(infile, input_last, ' '); 
    // input last name, looks for comma terminator 
    getline(infile, input_first, ','); 

    // get (and ignore) blank before title
    infile.get();

    // input title
    getline(infile, title, ',');      

    // reads year
    infile >> year;
    first = input_first;
    last = input_last;
    year = year;
    return true;

}

//---------------------------------------------------------------------------
// operator==  
// Determine if two childrensbook are equal.
bool ChildrensBook::operator==(const Item & otherChildrenBook) const{
    if(last == static_cast<const ChildrensBook&>(otherChildrenBook).last &&
    first == static_cast<const ChildrensBook&>(otherChildrenBook).first &&
    title == static_cast<const ChildrensBook&>(otherChildrenBook).title){
        return true;
    }
    return false;
    
}

//---------------------------------------------------------------------------
// operator!=  
// Determine if two childrensbook are not equal.
bool ChildrensBook::operator!=(const Item & otherChildrenBook) const{
    return !(*this == otherChildrenBook);
   
}

//---------------------------------------------------------------------------
// operator< 
// compares the two childrens book using the less operator
bool ChildrensBook::operator<(const Item & otherChildrenBook) const {
    
    if(title < static_cast<const ChildrensBook&>(otherChildrenBook).title){
        return true;  
    }
    else if(title==static_cast<const ChildrensBook&>(otherChildrenBook).title&&
    last < static_cast<const ChildrensBook&>(otherChildrenBook).last){
        return true;
    }
    else if(title == static_cast<const ChildrensBook&>(otherChildrenBook).title&&
    last == static_cast<const ChildrensBook&>(otherChildrenBook).last &&
    first < static_cast<const ChildrensBook&>(otherChildrenBook).first){
        return true;
    }
    return false;
}

//---------------------------------------------------------------------------
// operator< 
// compares the two childrens book using the greater operator
bool ChildrensBook::operator>(const Item & otherChildrenBook) const{

    if(title > static_cast<const ChildrensBook&>(otherChildrenBook).title){
        return true;  
    }
    else if(title==static_cast<const ChildrensBook&>(otherChildrenBook).title&&
    last > static_cast<const ChildrensBook&>(otherChildrenBook).last){
        return true;
    }
    else if(title==static_cast<const ChildrensBook&>(otherChildrenBook).title&&
    last == static_cast<const ChildrensBook&>(otherChildrenBook).last &&
    first > static_cast<const ChildrensBook&>(otherChildrenBook).first){
        return true;
    }
    return false;
}

//---------------------------------------------------------------------------
// getCopies
// returns number of copies avaliable
int ChildrensBook:: getCopies() const{
    return num_copies;
}

//---------------------------------------------------------------------------
// setCopies
// sets the data field 
void ChildrensBook::setCopies(int copies){
    num_copies = copies;
}

//---------------------------------------------------------------------------
// getNumPatronsInBook
// returns number of patrons in a book
int ChildrensBook:: getNumPatronsInBook() const{
    return num_patrons_in_book;
}

//---------------------------------------------------------------------------
// setNumPatronsInBook
// sets the data field 
void ChildrensBook::setNumPatronsInBook(int patron){
    num_patrons_in_book = patron;
}

//---------------------------------------------------------------------------
// print
// prints a childrensbook which will be used to print the library
void ChildrensBook::print() const {
    
    cout << left << setw(15) << num_copies
     << setw(25) << last + " " + first 
     << setw(40) << title
     << setw(4) << year
     << endl;
}

//---------------------------------------------------------------------------
// printCheckoutBooks
// prints a childrensbook which will be used to print the transaction
void ChildrensBook::printCheckoutBooks() const{

    cout << left << setw(25) << title
     << setw(30) << last + " " +  first
     << setw(4) << year 
     << endl;
}

// ---------------------------------------------------------------------------
// setTransactionData
// sets all data members for Children's book from data file
bool ChildrensBook::setTransactionData(istream& infile){
    // title, then the author 
    string first_name;
    string last_name;
    string new_title;
   
    // Example: C 1111 C H Danny Dunn & the Homework Machine, Williams Jay,
    
    getline(infile, new_title, ','); 
    infile.get();
    getline(infile,last_name,' ');
    getline(infile,first_name,',');
    first = first_name;
    last = last_name;
    title = new_title;
    return true;
    
}
