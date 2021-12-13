// Mohammed Sohail
// 22001513

#include <iostream>
#include <string>
#include <Flower.h>
using namespace std;

// CONSTRUCTORS

// 1. Default constructor
Flower::Flower() {

};

// 2. Constructor with string input
Flower::Flower(string flowerName);

// 3. Copy constructor
Flower::Flower(const Flower& aFlower);

// DESTRUCTOR
~Flower();

// METHODS

// Determines whether the Flower object is empty (no flowerName given)
bool isEmpty() const;

// Determines the length of the Flower object's flowerName
int getLength() const;

// Add a feature to the Flower object
bool add(string feature);

// Remove a feature from the Flower object
bool remove(string feature);

// Print the properties of the Flower object
string printFlower() const;
