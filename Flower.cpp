// Mohammed Sohail
// 22001513

#include <string>
#include <iostream>
#include "Flower.h"
using namespace std;

// CONSTRUCTORS

// 1. Default constructor
Flower::Flower(): size(0), head(NULL) {

    // Initialize flowerName
    flowerName = "";

}

// 2. Constructor with string input
Flower::Flower(string newFlowerName): size(0), head(NULL) {

    // Initialize flowerName
    flowerName = newFlowerName;

}

// 3. Copy constructor
Flower::Flower(const Flower& aFlower): size(aFlower.size) {

    if (aFlower.head == NULL) {
        head = NULL;  // original list is empty
    }

    else {

        // copy first node
        head = new FeatureNode;
        head->feature = aFlower.head->feature;

        // copy rest of list
        FeatureNode *newPtr = head;  // new list ptr

        for (
            FeatureNode *origPtr    = aFlower.head->next;
            origPtr                 != NULL;
            origPtr                 = origPtr->next
        ) {
            newPtr->next            = new FeatureNode;
            newPtr                  = newPtr->next;
            newPtr->feature            = origPtr->feature;
        }

        newPtr->next = NULL;

    }

}

// DESTRUCTOR
Flower::~Flower() {

    while (head != NULL) {

        FeatureNode* tmp;

        tmp = head;

        head = head->next;

        delete tmp;

        tmp = NULL;

    }

}

// METHODS

// Determines whether the Flower object is empty (no features available)
bool Flower::isEmpty() const {
    return size == 0;
}

// Determines the length of the Flower object's features linked list
int Flower::getLength() const {
    return size;
}

bool Flower::find(string feature) const {

    // Verify if the given feature exists in the Flower
    for (FeatureNode *curPtr = head; curPtr != NULL; curPtr = curPtr->next) {
        if (curPtr->feature == feature) {
            return true;
        }
    }

    return false;

}

// Add a feature to the Flower object
bool Flower::add(string feature) {

    // check if the feature is a duplicate
    if (isDuplicate(feature)) {
        return false;
    }

    // create a FeatureNode from the given 'feature' string
    FeatureNode *newFeatureNode = new FeatureNode;
    newFeatureNode->feature = feature;

    // If list is empty or new item needs to be inserted at the start
    if (head == NULL || head->feature > newFeatureNode->feature) {
        newFeatureNode->next = head;
        head = newFeatureNode;
    }

    // Find the correct
    else {

        // Current FeatureNode (used in while loop)
        FeatureNode *cur;

        // Points to to the head of the existing linked list
        cur = head;

        // Loop until suitable location is found
        while (cur->next != NULL && cur->next->feature <= newFeatureNode->feature) {
            cur = cur->next;
        }

        // Newly created node will point to current node's next
        newFeatureNode->next = cur->next;

        // Current node's next will point to newly created node
        cur->next = newFeatureNode;

    }

    size++;
    cout << feature << " is added into " << flowerName << endl;
    return true;

}

// Remove a feature from the Flower object
bool Flower::remove(string feature) {

    // 1. The linked list is empty - nothing to remove
    if (head != NULL) {

        // Current FeatureNode (used in while loop)
        FeatureNode *cur;

        // Points to to the head of the existing linked list
        cur = head;

        // 2. The first item in the list is matched - point head to second item in list
        if (head->feature == feature) {
            head = head->next;
            --size;
            delete cur;
            cout << feature << " is removed from " << flowerName << endl;
            return true;
        }

        else {
            // 3. Loop through list to find item and remove if found
            // while (cur->next != NULL && cur->next->feature <= feature) {
            while (cur->next != NULL) {
                if (cur->next->feature == feature) {

                    FeatureNode* tmp = cur->next;
                    cur->next = cur->next->next;
                    --size;
                    delete tmp;
                    cout << feature << " is removed from " << flowerName << endl;
                    return true;

                }
                else {
                    cur = cur->next;
                }
            }
        }

    }

    cout << feature << " doesn't exist in magnolia" << endl;
    return false;

}

// Print the properties of the Flower object
string Flower::printFlower() const {

    string response;
    string features;

    // Loop through features and concat. them in a string
    for (FeatureNode *curPtr = head; curPtr != NULL; curPtr = curPtr->next) {

        features += curPtr->feature;

        if (curPtr->next != NULL) {
            features += ", ";
        }

    }

    // If no features are found, use default string
    if (features == "") {
        features = "No feature";
    }

    // Concat. flowerName and features in a single string
    response = flowerName + ": " + features;

    // Return concat. string
    return response;

}

string Flower::getName() const {
    return flowerName;
}

void Flower::setName(string newName) {
    flowerName = newName;
}

bool Flower::isDuplicate(string feature) const {

    // Traverse through list of features
    for (FeatureNode *curPtr = head; curPtr != NULL; curPtr = curPtr->next) {

        // Return true if given feature is already present in feature list
        if (curPtr->feature == feature) {
            cout << feature << " already exists in " << flowerName << endl;
            return true;
        }

    }

    // No match found - given feature isn't a duplicate
    return false;

}
