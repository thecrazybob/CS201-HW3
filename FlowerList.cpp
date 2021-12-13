// Mohammed Sohail
// 22001513

#include <iostream>
#include <string>
#include "FlowerList.cpp"
using namespace std;

// CONSTRUCTORS

// 1. Default constructor
FlowerList();

// 2. Copy constructor
FlowerList(const FlowerList& aList);

// DESTRUCTOR
~FlowerList();

// METHODS

// Determines whether the FlowerList is empty
bool isEmpty() const;

// Determines the length of the FlowerList
int getLength() const;

// Retrieves the given Flower
bool retrieve(string flowerName, Flower& flower) const;

// Adds a flower to the FlowerList
bool add(string flowerName);

// Removes the given flower
bool remove(string flowerName);
