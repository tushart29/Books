//---------------------------------------------------------------------------
// periodical.cpp
// Derived class of Book class for Periodicals
//---------------------------------------------------------------------------
// Periodical class Implementation and assumptions:  
//   -- Item* create() function returns new Periodical object for use
//      in factory class
//   -- setData function sets all data members for periodical from 
//      data file
//   -- setTransaction Data function sets all relevant data members from 
//      transaction data file
//   -- Addition of month data member
//   -- Comparison overloads reflect sorting criteria of periodical 
//      class: sorted by year, then month, then title. No other data used 
//      for sorting, and criteria uniquely identifies each periodical.
//   -- ifstream for setData functions assumed to be well formatted, though
//      input data may not be valid. Invalid data will be discarded.
//   -- print function to be used to print books in the library and 
//      printcheckoutbooks function to print the transactions occured in a 
//      patron
//
//---------------------------------------------------------------------------

#include "periodical.h"

// ---------------------------------------------------------------------------
// Constructor 
// Default constructor for class Periodical  
Periodical::Periodical(){
    month = 0;
    year = 0;
    num_copies = 1;
    num_patrons_in_book = 1;
}

// ---------------------------------------------------------------------------
// Destructor 
// when the allocation of a new memory occurs, the destructor deallocates
Periodical::~Periodical(){
    
}

// ---------------------------------------------------------------------------
// create
// Item* create returns Periodical object
Item* Periodical::create() const{
    return new Periodical;
}

// ---------------------------------------------------------------------------
// setData
// sets all data members for Periodical's book from data file
bool Periodical::setData(istream& infile){
    // P Communications of the ACM, 12 1998 
    
    // check errors in setdata like if year or title is valid then return stuff

    string input_title;
    int input_year;
    int input_month;
    // get (and ignore) blank before title, // don't use if you want to keep the blank
    infile.get(); 

    // input title, looks for comma terminator
    getline(infile, input_title, ','); 
    

    // get (and ignore) blank before month
    infile.get();

    // input month
    infile >> input_month;
    // getline(infile, month); 
    
    // reads year
    infile >> input_year;
    title = input_title;
    month = input_month;
    year = input_year;
    return true;

}


//---------------------------------------------------------------------------
// operator==  
// Determine if two periodical books are equal.
bool Periodical::operator==(const Item & otherPeriodical) const{
    if(year == static_cast<const Periodical&>(otherPeriodical).year &&
        month == static_cast<const Periodical&>(otherPeriodical).month &&
        title == static_cast<const Periodical&>(otherPeriodical).title){
            return true;
    }
    return false;
    
}

//---------------------------------------------------------------------------
// operator!=  
// Determine if two periodical are not equal.
bool Periodical::operator!=(const Item & otherPeriodical) const{
    return !(*this == otherPeriodical);
}

//---------------------------------------------------------------------------
// operator< 
// compares the two periodicals using the less operator
bool Periodical::operator<(const Item & otherPeriodical) const {
    if(year < static_cast<const Periodical&>(otherPeriodical).year){
        return true;
    }
    else if(year == static_cast<const Periodical&>(otherPeriodical).year && 
    month < static_cast<const Periodical&>(otherPeriodical).month){
        return true;
    }
    else if(year == static_cast<const Periodical&>(otherPeriodical).year &&  
    month == static_cast<const Periodical&>(otherPeriodical).month &&
    title < static_cast<const Periodical&>(otherPeriodical).title){
        return true;
    }
    
    return false;       
}
    
//---------------------------------------------------------------------------
// operator< 
// compares the two periodicals using the greater operator    
bool Periodical::operator>(const Item & otherPeriodical) const{
    if(year > static_cast<const Periodical&>(otherPeriodical).year){
        return true;
    }
    else if(year == static_cast<const Periodical&>(otherPeriodical).year && 
    month > static_cast<const Periodical&>(otherPeriodical).month){
        return true;
    }
    else if(year == static_cast<const Periodical&>(otherPeriodical).year &&  
    month == static_cast<const Periodical&>(otherPeriodical).month &&
    title > static_cast<const Periodical&>(otherPeriodical).title){
        return true;
    }
    return false;
}

//---------------------------------------------------------------------------
// print
// prints a periodical which will be used to print the library
void Periodical::print() const {
    
    cout << left << setw(15) << num_copies
    << setw(40) << title
    << setw(25) << month
    << setw(4) << year
    << endl;
}

//---------------------------------------------------------------------------
// printCheckoutBooks
// prints a peridoical which will be used to print the transaction
void Periodical::printCheckoutBooks() const{
    cout << left << setw(10) << month
    << setw(10) << year
    << setw(4) << title
    << endl;
}


//---------------------------------------------------------------------------
// getCopies
// returns number of copies avaliable
int Periodical:: getCopies() const{
    return num_copies;
}

//---------------------------------------------------------------------------
// setCopies
// sets the data field 
void Periodical::setCopies(int copies){
    num_copies = copies;
}

//---------------------------------------------------------------------------
// getNumPatronsInBook
// returns number of patrons in a book
int Periodical:: getNumPatronsInBook() const{
    return num_patrons_in_book;
}

//---------------------------------------------------------------------------
// setNumPatronsInBook
// sets the data field 
void Periodical::setNumPatronsInBook(int patron){
    num_patrons_in_book = patron;
}


// ---------------------------------------------------------------------------
// setTransactionData
// sets all data members for Fiction's book from data file
bool Periodical::setTransactionData(istream& infile){
    // C 1111 P H 2010 2 Communications of the ACM,
    
    int new_year;
    string new_title;
    int new_month;
    infile >> new_year;
    infile >> new_month;
    infile.get();
    getline(infile, new_title, ',');
    title = new_title;
    month = new_month;
    year = new_year;
    return true;
}

