// Mohammed Sohail
// 22001513

#include <string>
using namespace std;

class Flower {

    public:

        Flower();

        Flower(string flowerName);

        Flower(const Flower& aFlower);

        ~Flower();

        bool isEmpty() const;

        int getLength() const;

        bool add(string feature);

        bool remove(string feature);

        string printFlower() const;

        string getName() const;

        void setName(string newName);

        bool isDuplicate(string feature) const;

    private:

        struct FeatureNode {
            string feature;
            FeatureNode* next;
        };

        int size;

        string flowerName;

        FeatureNode *head; // the features are stored in a sorted singly linear linked list

};
