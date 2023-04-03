//---------------------------------------------------------------------------
// BookInventory.cpp
// Class representing the inventory of book items in the library
//---------------------------------------------------------------------------
// BookInventory class: Represented by a Binary Tree of Book Items
//
// Implementation and assumptions:
// - Inherits from Item class and assumes the class has been defined
// - Utilizes common binary search tree methods, such insert, retrieve,
// deleting all nodes, and print all nodes inorder, and these method can be
// applies for all the different book items in the library. 
// - Assumes that item class and its derived class contain comparitive 
// operators (<,>,==,!=)
//---------------------------------------------------------------------------


#include "item.h"
#include "bookinventory.h"
// ---------------------------------------------------------------------------
// Constructor 
// Default constructor for class bookinventory
BookInventory::BookInventory() 
{
    this->root = nullptr;
}

// ---------------------------------------------------------------------------
// Destructor 
// when the allocation of a new memory occurs, the destructor deallocates
BookInventory::~BookInventory(){
   this->makeEmpty();
}

// ---------------------------------------------------------------------------
// insert method
// inserts a new node into the current binary tree
bool BookInventory::insert(Item* dataptr) {
   Node* ptr = new Node;   // exception is thrown if memory is not allocated 
   ptr->data = dataptr;
   dataptr = nullptr;
   ptr->left = ptr->right = nullptr;
   if (isEmpty()) {
      root = ptr;
   }
   else {
       
      Node* current = root;
      bool inserted = false;

      // if item is less than current item, insert in left subtree,
      // otherwise insert in right subtree
      while (!inserted) {
         // if(*ptr->right->data == *current->data){
         //       return false;
         // }
         if (*ptr->data < *current->data) {
            
            if (current->left == nullptr) {     // at leaf, insert left
               current->left = ptr;
               inserted = true;
            }
            else
               current = current->left;         // one step left
         }

         else if(*ptr->data > *current->data) {
            
            if (current->right == nullptr) {     // at leaf, insert right
               
               current->right = ptr;
               inserted = true;
            }
            else
               current = current->right;         // one step right
         }
         else{
            delete ptr;
            return false;
         }
         
      }
   }
   return true;
}

// ---------------------------------------------------------------------------
// retrieve 
// Retrieve a given object in the tree
// (via pass-by-reference, the second parameter).
// The second parameter will point to the actual object 
// in the tree if it is found. 
bool BookInventory::retrieve(const Item& info, Item*& found) const
{
   if(root == nullptr){
      return false;
   }
   return retrieveHelper(this->root,info,found);
   
}

bool BookInventory::retrieveHelper(Node* current,const Item &info,Item* &found)
const

{
   if(current == nullptr){
      return false;
   }
   if(*current->data == info){
      
      found = current->data;
      return true;
   }
   else{
      bool left = retrieveHelper(current->left,info,found);
      if(left == true){
         return true;
      }
      bool right = retrieveHelper(current->right,info,found);
      return right;
   }

}

//---------------------------------------------------------------------------
// inOrderPrint
// prints tree inorder

void BookInventory::inOrderPrint() const{
   inOrderHelper(this->root);
}

// // ---------------------------------------------------------------------------
// // inorderHelper
// // will be a helper function which will be used in operator<<
void BookInventory::inOrderHelper(Node* current) const
{
    if(current != nullptr)
    {
        inOrderHelper(current->left);
        current->data->print();
        inOrderHelper(current->right);
    }
    
}


//---------------------------------------------------------------------------
// isEmpty 
// determines if set is empty or not (return's true if empty)
bool BookInventory::isEmpty() const{
   return (root == nullptr);
}

//---------------------------------------------------------------------------
// makeEmpty 
// deletes all the data and memory in the tree
void BookInventory:: makeEmpty(){
   makeEmptyHelper(root);
   
}
void BookInventory::makeEmptyHelper(Node*& current) {
   if(current == nullptr){
      return;
   }
   makeEmptyHelper(current->left);
   makeEmptyHelper(current->right);
   delete current->data;
   current->data = nullptr;
   delete current;
   current = nullptr;
   
}