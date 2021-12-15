// Mohammed Sohail
// 22001513

#include <iostream>
#include <string>
#include "FlowerList.h"
using namespace std;

// CONSTRUCTORS

// 1. Default constructor
FlowerList::FlowerList(): size(0), head(NULL) {};

// 2. Copy constructor
FlowerList::FlowerList(const FlowerList& aList): size(aList.size) {

    if (aList.head == NULL) {
        head = NULL;  // original list is empty
    }

    else {

        // copy first node
        head = new FlowerNode;
        head->f = aList.head->f;

        // copy rest of list
        FlowerNode *newPtr = head;  // new list ptr

        for (
            FlowerNode *origPtr     = aList.head->next;
            origPtr                 != NULL;
            origPtr                 = origPtr->next
        ) {
            newPtr->next            = new FlowerNode;
            newPtr                  = newPtr->next;
            newPtr->f               = origPtr->f;
        }

        newPtr->next = NULL;

    }

}

// DESTRUCTOR
FlowerList::~FlowerList() {

    while (head != NULL) {

        FlowerNode* tmp;

        tmp = head;

        head = head->next;

        delete tmp;

        tmp = NULL;

    }

}

// METHODS

// Determines whether the FlowerList is empty
bool FlowerList::isEmpty() const {
    return size == 0;
}

// Determines the length of the FlowerList
int FlowerList::getLength() const {
    return size;
}

// Retrieves the given Flower
bool FlowerList::retrieve(string flowerName, Flower& flower) const {

    cout << "yes";
    // Convert flowerName string to lowercase string
    string flowerToRetrieve = flowerName;
    toLowerCase(flowerName);
    cout << flowerName;

    // FlowerList empty - nothing to retreieve
    if (isEmpty()) {
        return false;
    }

    else {

        FlowerNode *cur;

        cur = head;

        while (cur != NULL || cur->f.getName() != flowerName) {
            cur->next;
        }

        if (cur->f.getName() == flowerName) {

            flower = cur->f;
            return true;

        }

    }

    return false;

}

// Adds a flower to the FlowerList
bool FlowerList::add(string flowerName) {

    // convert feature string to a lowercase string
    toLowerCase(flowerName);

    // create a FlowerNode from the given 'flowerName' string
    FlowerNode *newFlowerNode = new FlowerNode;
    newFlowerNode->f.setName(flowerName);

    // If list is empty or new items needs to be inserted at the start
    if (head == NULL || head->f.getName() > newFlowerNode->f.getName()) {
        newFlowerNode->next = head;
        head = newFlowerNode;
    }

    // Find the correct
    else {

        // Current FlowerNode (used in while loop)
        FlowerNode *cur;

        // Points to to the head of the existing linked list
        cur = head;

        // Loop until suitable location is found
        while (cur->next != NULL && cur->next->f.getName() <= newFlowerNode->f.getName()) {
            cur = cur->next;
        }

        // Newly created node will point to current node's next
        newFlowerNode->next = cur->next;

        // Current node's next will point to newly created node
        cur->next = newFlowerNode;

    }

    size++;
    return true;

}

// Removes the given flower
bool FlowerList::remove(string flowerName) {

    // convert feature string to a lowercase string
    toLowerCase(flowerName);

    // 1. The linked list is empty - nothing to remove
    if (head == NULL) {
        return false;
    }

    else {

        // Current FeatureNode (used in while loop)
        FlowerNode *cur;

        // Points to to the head of the existing linked list
        cur = head;

        // 2. The first item in the list is matched - point head to second item in list
        if (head->f.getName() == flowerName) {
            head = head->next;
            --size;
            delete cur;
            return true;
        }

        else {
            // 3. Loop through list to find item and remove if found
            while (cur->next != NULL && cur->next->f.getName() <= flowerName) {
                if (cur->next->f.getName() == flowerName) {
                    FlowerNode* tmp;
                    tmp = cur->next;
                    cur->next = cur->next->next;
                    --size;
                    delete tmp;
                    return true;
                }
                else {
                    cur = cur->next;
                }
            }
        }

    }

    return false;

}

string FlowerList::printFlowerList() const {
    string response;
    string flowers;

    // Loop through features and concat. them in a string
    for (FlowerNode *curPtr = head; curPtr != NULL; curPtr = curPtr->next) {
        flowers += curPtr->f.getName() + " ";
    }

    // If no features are found, use default string
    if (flowers == "") {
        flowers = "No flowers";
    }

    // Concat. flowerName and features in a single string
    response = "FlowerList: " + flowers;

    // Return concat. string
    return response;
}

void FlowerList::toLowerCase(string &originalString) const {
    string lowercaseString = "";

    for (int i = 0; i < originalString.length(); i++) {
        lowercaseString+= (char) tolower(originalString[i]);
    }

    originalString = lowercaseString;
}
