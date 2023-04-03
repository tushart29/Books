
1. Describe the state of your program, exactly what works and what does not work.

My program works and it prints the output that I wanted without any memory leaks.

2. List your hash table(s) that you wrote (not STL) - briefly what they are used for and file they are found in. (Include any factories that are essentially hash tables).

TransactionFactory: 
They include the transactionfactory.h and transactionfactory.cpp.  This factory inherits from my factory
class and the objects such as borrowbook, return, display, and display history gets created depending
on the character type.

PatronHashMap: 
They include patronhashmap.h and patronhashmap.cpp. This hash-table is used to store my patrons.

BookFactory: They include my bookfactory.h and bookfactory.cpp. This factory also inherits from my 
factory class and the objects such as Fiction, Childrensbook, and periodical are created depending
on the character type. 

Factory: factory. hand factory.cpp This factory is the parent class for the other two factories. 


3. State which file and which function you read the book data, just high-level function calls, i.e., how/where it gets into your collections.

I initially read the character from the my add books method in the library.cpp. From here, I pass this 
book type character into my bookfactory class which gives me the specfic object assosisiated with the 
character. From here, I call my setData method which can be in the fiction.cpp, childrensbook.cpp, and 
periodical.cpp. Depending on the object, the file would be passed into the setData function in any of those 
classes. In set data function, I read in the required information such as year, title, author, and other information
depending on the book type. After setting the data to that item, it would be inserted into a array of 
binary search trees depending on which type of book it is.  


4. State which file and which function you read the command data, high-level function calls, i.e., how/where you perform the commands.

I initially read the character from my processTransaction method in the library.cpp. Fro here, I pass the 
command type character into my transactionfactory class which gives me the specfic object associated with 
command type. From here, I call my setData method which can be in the borrowbook.cpp, display.cpp,
display history.cpp, and returnbook.cpp. Depending on the character type, the file and the bookinventory object from
my library class will get passed in to the any of those classes. In the set data function, I read in the
required information such as book type, author, and copy type (Hard copy or no not). After setting the data,
I would perform my transactions in my execute function. 

5. Describe any dirty little secrets (e.g., switch used, or if-else-if, etc.)  If you feel they do not violate the open-closed design principle, explain.

I feel that I did not violate the open-closed principle because I did not use any switches or any
if-else-if statements to check for a specfic character. My factories take care of all that
to ensure I don't violate this principle. For instance, I don't check if the character is 'D' in my library. 
Instead, I have a transactionfactory where it checks if this given character is 'D' and it gives me this instance
and then I can execute or do anything with that given display object. 

6. Describe anything you are particularly proud of . . .

I am proud of doing this project. I honestly never thought I would do something this in CSS 343 where I have
multiple classes like these and I would understand how these classes interact. It is also interesting to build
a library system from scratch from the use of inheritence.
