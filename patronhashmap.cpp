//---------------------------------------------------------------------------
// patronhashmap.cpp
// Hash table to store all patrons. 
//---------------------------------------------------------------------------
// PatronHashMap class Implementation and assumptions:  
//   -- Hash function computes index of array based on patron's id
//   -- Open hashing, collisions handled via linked lists stored in each slot
//      of array rather than the patrons themselves. 
//   -- Memory allocated dynamically as more patrons are added to the hash 
//      table.
//   -- Assumes patron's ids are determined randomly to maintain fast lookup 
//      ~O(1) time.
//
//---------------------------------------------------------------------------

#include "patronhashmap.h"

// ---------------------------------------------------------------------------
// Constructor 
// Default constructor for class PatronHashMap
PatronHashMap::PatronHashMap(){
    for(int i = 0; i < 10000; i++){
        // total_patrons[i]->setFirstName("FIRSTNAME");
        // total_patrons[i]->setLastName("LASTNAME");
        total_patrons[i] = nullptr;
    }
}

// ---------------------------------------------------------------------------
// Destructor 
// when the allocation of a new memory occurs, the destructor deallocates
PatronHashMap::~PatronHashMap(){
    for(int i = 0; i < 10000; i++){
        if(total_patrons[i] != nullptr){
            
            delete total_patrons[i];
            total_patrons[i]=nullptr;
        }
    }    
}


// ---------------------------------------------------------------------------
// hashId 
// hashes ID by the size  to get a subscript 
int PatronHashMap::hashID(int number) const{
    
    if(number > 10000){
        cout << "ID " << number << " IS GREATER THAN 10000";
        return -2;
    }
    if(number <= 999){
        cout << "ID " << number << " :IS NOT AN 4 DIGIT NUMBER";
        return -2;
    }
    return number % 10000;
}

// ---------------------------------------------------------------------------
// insert 
// inserts the patron into the hashmap 
bool PatronHashMap::insert(Patron*& patron){
    int subscript = hashID(patron->getID());
    if(patron == nullptr){
        return false;
    }
    if(subscript == -2){
        return false;
    }
    if(total_patrons[subscript] != nullptr){
        cout << "Patron " << patron->getID() << " already exists " << endl;
        return false;
    }
    else{
        total_patrons[subscript] = patron;
    }
   
    return true;
    
}

// ---------------------------------------------------------------------------
// retrieve
// retrives patron if patron exists 
bool PatronHashMap::retrieve(int ID, Patron*& patron){
    int subscript = hashID(ID);
    if(total_patrons[subscript] == nullptr){
        return false;
    }
    patron = total_patrons[subscript];
    return true;
}

// ---------------------------------------------------------------------------
// print
// prints all patrons in the patron hashmap 
void PatronHashMap::print(){
    for(int i = 0; i < 10000; i++){
        if(total_patrons[i] != nullptr){
            
            cout << "PATRON: " << total_patrons[i]->getFirstName() 
            << " " << total_patrons[i]->getLastName()
            << " " << total_patrons[i]->getID() << endl;
        }
    }
}