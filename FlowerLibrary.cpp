// Mohammed Sohail
// 22001513

#include <iostream>
#include <string>
#include "FlowerLibrary.h"
using namespace std;

// CONSTRUCTOR
FlowerLibrary::FlowerLibrary() {
    flowers = FlowerList();
}

// DESTRUCTOR
FlowerLibrary::~FlowerLibrary() {

}

// METHODS

// Add Flower to the FlowerLibrary
void FlowerLibrary::addFlower(string name) {

    // Convert flowerName string to lowercase string
    toLowerCase(name);

    flowers.add(name);

}

// Remove Flower from the FlowerLibrary
void FlowerLibrary::removeFlower(string name) {

    // Convert flowerName string to lowercase string
    toLowerCase(name);

    flowers.remove(name);

}

// List all Flowers in the FlowerLibrary
void FlowerLibrary::listFlowers() const {

    cout << flowers.printFlowerList() << endl;

}

// List features of the given flower
void FlowerLibrary::listFeatures(string name) const {

    toLowerCase(name);

    Flower* retrievedFlower;

    if (flowers.retrievePointer(name, retrievedFlower)) {
        cout << retrievedFlower->printFlower() << endl;
    }

}

// Add feature to the given flower
void FlowerLibrary::addFeature(string name, string feature) {

    // Convert flowerName string to lowercase string
    toLowerCase(name);
    toLowerCase(feature);

    Flower* retrievedFlower;

    if (flowers.retrievePointer(name, retrievedFlower)) {
        retrievedFlower->add(feature);
    }

}

// Remove feature from the given flower
void FlowerLibrary::removeFeature(string name, string feature) {

    // Convert flowerName string to lowercase string
    toLowerCase(name);
    toLowerCase(feature);

    Flower* retrievedFlower;

    if (flowers.retrievePointer(name, retrievedFlower)) {
        retrievedFlower->remove(feature);
    }

}

// Find Flowers with the given feature
void FlowerLibrary::findFlowers(string feature) const {

    // Convert flowerName string to lowercase string
    toLowerCase(feature);

}


void FlowerLibrary::toLowerCase(string &originalString) const {
    string lowercaseString = "";

    for (int i = 0; i < originalString.length(); i++) {
        lowercaseString+= (char) tolower(originalString[i]);
    }

    originalString = lowercaseString;
}
