// Mohammed Sohail
// 22001513

#include <iostream>
#include "FlowerList.h"
using namespace std;

int main() {

    // 1. Testing Flower class
    Flower f = Flower("google");

    cout << "isEmpty(): " << f.isEmpty() << endl;
    cout << "getLength(): " << f.getLength() << endl;

    f.add("nice");
    f.add("nOOt");
    f.add("z");
    f.add("a");
    f.add("a");
    f.add("a");
    f.add("ab");
    f.add("az");

    cout << "isEmpty(): " << f.isEmpty() << endl;
    cout << "getLength(): " << f.getLength() << endl;

    cout << f.printFlower();

    f.remove("nice");
    f.remove("not");

    cout << "isEmpty(): " << f.isEmpty() << endl;
    cout << "getLength(): " << f.getLength() << endl;

    cout << f.printFlower() << endl;

    cout << "end of Flower class testing" << endl;

    // 2. Testing FlowerList class
    FlowerList fl = FlowerList();

    cout << "isEmpty(): " << fl.isEmpty() << endl;
    cout << "getLength(): " << fl.getLength() << endl;

    fl.add("zzzz");
    fl.add("aaaa");
    fl.add("aaaa");
    fl.add("aaaa");
    fl.add("cccc");
    fl.add("bbbb");
    // fl.add("gulo");
    // fl.add("Mulo");
    // fl.add("bulo");

    cout << "isEmpty(): " << fl.isEmpty() << endl;
    cout << "getLength(): " << fl.getLength() << endl;

    cout << fl.printFlowerList() << endl;

    fl.remove("cccc");
    cout << fl.printFlowerList() << endl;
    fl.remove("bulo");

    cout << "isEmpty(): " << fl.isEmpty() << endl;
    cout << "getLength(): " << fl.getLength() << endl;

    cout << fl.printFlowerList() << endl;
    fl.remove("SHATO");
    cout << fl.printFlowerList() << endl;

    Flower retrieved;
    cout << fl.retrieve("cccc", retrieved) << endl;

    return 0;
}
