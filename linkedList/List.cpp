#include <iostream>
#include <cstdlib>
#include "List.h"

using namespace std;

List::List(){ // defines the constructor functions for the List class
    head = NULL;
    curr = NULL;
    temp = NULL;
}

void List::addNode(string addData){
    Node* n = new Node; // declares and initializes n to point to a new node(samething as Node* nodeptr)
    n->setNextNode(NULL); // node* n points to node* next which is equal to NULL
    n->setData(addData);
    n->setPrevNode(NULL);
    
     if(head != NULL){
        curr = head;
        while(curr->getNextNode() != NULL){
            curr = curr->getNextNode();
        }
        curr->setNextNode(n);
     }else{
        head = n;
     }
}

void List::deleteNode(string delData){
    Node* delPtr = NULL;
    temp = head;
    curr = head;

    while(curr != NULL && curr->getData() != delData){
        temp = curr; // used to trail next node, to patch up list if delData is in middle of list
        curr = curr->getNextNode();
    }

    if(curr == NULL){
        cout << delData << " was not in the list" << endl;
        delete delPtr; // always delete data we do not use since c++ does not have a garbage collection
    }else{
        delPtr = curr; // delptr is pointing to the node that we want to delete
        curr = curr->getNextNode();// advances through list
        temp->setNextNode(curr);// this patches the list from previous node to next node after the deleted node
        
        if(delPtr == head){
            head = head->getNextNode();
            temp = NULL;
        }

        delete delPtr;
        cout << "The value: " << delData << " was deleted." << endl;
    }
}

void List::printList(){
    curr = head;
    cout<<endl;
    while(curr != NULL){
        cout << curr->getData() << " ";
        curr = curr->getNextNode();
    }
        cout<<endl;

}

void List::swap(string firData, string secData){
    
}
