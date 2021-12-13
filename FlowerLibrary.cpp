// Mohammed Sohail
// 22001513

#include <iostream>
#include <string>
#include "FlowerLibrary.h";
using namespace std;

// CONSTRUCTOR
FlowerLibrary();

// DESTRUCTOR
~FlowerLibrary();

// METHODS

// Add Flower to the FlowerLibrary
void addFlower(string name);

// Remove Flower from the FlowerLibrary
void removeFlower(string name);

// List all Flowers in the FlowerLibrary
void listFlowers() const;

// List features of the given flower
void listFeatures(string name) const;

// Add feature to the given flower
void addFeature(string name, string feature);

// Remove feature from the given flower
void removeFeature(string name, string feature);

// Find Flowers with the given feature
void findFlowers(string feature) const;
