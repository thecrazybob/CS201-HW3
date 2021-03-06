// Mohammed Sohail
// 22001513

#include "FlowerList.h"

class FlowerLibrary {

    public:

        FlowerLibrary();

        ~FlowerLibrary();

        void addFlower(string name);

        void removeFlower(string name);

        void listFlowers() const;

        void listFeatures(string name) const;

        void addFeature(string name, string feature);

        void removeFeature(string name, string feature);

        void findFlowers(string feature) const;

        void toLowerCase(string &originalString) const;

    private:

        FlowerList flowers;

};
