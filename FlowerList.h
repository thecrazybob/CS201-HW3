// Mohammed Sohail
// 22001513

#include "Flower.h"
using namespace std;

class FlowerList {

    public:

        FlowerList();

        FlowerList(const FlowerList& aList);

        ~FlowerList();

        bool isEmpty() const;

        int getLength() const;

        bool retrieve(string flowerName, Flower& flower) const;

        bool retrievePointer(string flowerName, Flower*& flower) const;

        bool add(string flowerName);

        bool remove(string flowerName);

        string printFlowerList() const;

        bool isDuplicate(string flowerName) const;

    private:

        struct FlowerNode{
            Flower f;
            FlowerNode* next;
        };

        int size;

        FlowerNode* head; // the flowers are stored in a sorted singly linear linked list

};
