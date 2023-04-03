
#include "library.h"
#include <iostream>
using namespace std;

int main() {
    Library library;
    ifstream inFile("data4patrons.txt");
    library.addPatrons(inFile);
    
    
    ifstream inFile2("data4books.txt");
    library.addBooks(inFile2); 
   

    ifstream inFile3("data4commands.txt");
    library.processTransactions(inFile3);
    
    return 0;
}
