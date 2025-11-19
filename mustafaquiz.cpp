#include <iostream>
#include <vector>
using namespace std;


class Quirk{
    public:
    string name;

    Quirk(string name) : name(name) {}
    virtual ~Quirk() {}

    virtual void use() const {
        cout << "Using quirk: " << name << endl;
    }

};

class OneForAll : public Quirk {
public:
    int powerLevel;
    vector<string> previousUsersQuirks;

    OneForAll(int basePower = 1)
        : Quirk("One For All"), powerLevel(basePower) {}

    void inheritQuirk(const string& quirkName) {
        previousUsersQuirks.push_back(quirkName);
        powerLevel += 10;
    }

    void use() const override {
        cout << "Using One For All at power level " 
             << powerLevel << "!" << endl;

        cout << "Inherited quirks: ";
        for (auto &q : previousUsersQuirks)
            cout << q << ", ";
        cout << endl;
    }
};

