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

// Add a feature to the Flower object
bool Flower::add(string feature) {

    // convert feature string to a lowercase string
    toLowerCase(feature);

    // check if the feature is a duplicate
    if (isDuplicate(feature)) {
        return false;
    }

    // create a FeatureNode from the given 'feature' string
    FeatureNode *newFeature = new FeatureNode;
    newFeature->feature = feature;

    // If list is empty or new item needs to be inserted at the start
    if (head == NULL || head->feature > newFeature->feature) {
        newFeature->next = head;
        head = newFeature;
    }

    // Find the correct
    else {

        // Current FeatureNode (used in while loop)
        FeatureNode *cur;

        // Points to to the head of the existing linked list
        cur = head;

        // Loop until suitable location is found
        while (cur->next != NULL && cur->next->feature <= newFeature->feature) {
            cur = cur->next;
        }

        // Newly created node will point to current node's next
        newFeature->next = cur->next;

        // Current node's next will point to newly created node
        cur->next = newFeature;

    }

    size++;
    return true;

}

// Remove a feature from the Flower object
bool Flower::remove(string feature) {

    // convert feature string to a lowercase string
    toLowerCase(feature);

    // 1. The linked list is empty - nothing to remove
    if (head == NULL) {
        return false;
    }

    else {

        // Current FeatureNode (used in while loop)
        FeatureNode *cur;

        // Points to to the head of the existing linked list
        cur = head;

        // 2. The first item in the list is matched - point head to second item in list
        if (head->feature == feature) {
            head = head->next;
            --size;
            delete cur;
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

// Print the properties of the Flower object
string Flower::printFlower() const {

    string response;
    string features;

    // Loop through features and concat. them in a string
    for (FeatureNode *curPtr = head; curPtr != NULL; curPtr = curPtr->next) {
        features += curPtr->feature + " ";
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

void Flower::toLowerCase(string &originalString) {
    string lowercaseString = "";

    for (int i = 0; i < originalString.length(); i++) {
        lowercaseString+= (char) tolower(originalString[i]);
    }

    originalString = lowercaseString;
}

bool Flower::isDuplicate(string feature) {

    toLowerCase(feature);

    // Traverse through list of flowers
    for (FeatureNode *curPtr = head; curPtr != NULL; curPtr = curPtr->next) {

        // Return true if given flowerName is already present in flower list
        if (curPtr->feature == feature) {
            return true;
        }
    }

    // No match found - given flowerName isn't a duplicate
    return false;

}
