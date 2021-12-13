// Mohammed Sohail
// 22001513

#include <iostream>
#include <string>
#include <Flower.h>
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
        head->item = aFlower.head->item;

        // copy rest of list
        FeatureNode *newPtr = head;  // new list ptr

        for (
            FeatureNode *origPtr    = aFlower.head->next;
            origPtr                 != NULL;
            origPtr                 = origPtr->next
        ) {
            newPtr->next            = new FeatureNode;
            newPtr                  = newPtr->next;
            newPtr->item            = origPtr->item;
        }

        newPtr->next = NULL;

    }

}

// DESTRUCTOR
Flower::~Flower(): flowerName("") {

    while(!isEmpty()) {

        for (
            FeatureNode *curPtr    = head;
            curPtr                 != NULL;
            curPtr                 = curPtr->next
        ) {
            remove(curPtr->feature);
        }

    }

}

// METHODS

// Determines whether the Flower object is empty (no features available)
Flower::isEmpty() {
    return size == 0;
}

// Determines the length of the Flower object's features linked list
Flower::getLength() {
    return size;
}

// Add a feature to the Flower object
Flower::add(string feature) {

    for (
        prev = NULL, cur = head;
        (cur != NULL) && (feature > cur->feature);
		prev = cur, cur = cur->next
    ) {

        cur->feature = feature;

    }

    ++size;

    return true;

}

// Remove a feature from the Flower object
Flower::remove(string feature) {

    // todo: find and remove feature from list
    --size;
}

// Print the properties of the Flower object
Flower::printFlower() {
    // todo:
}
