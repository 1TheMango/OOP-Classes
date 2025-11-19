#include <iostream>
using namespace std;
class Angels{
    public:
        Angels(int w) : wings(w) {}
        int wings;
};
class HeavenlyAngel : virtual public Angels {
    private:
        int haloSize;
    public:
        HeavenlyAngel(int w, int h) : Angels(w), haloSize(h) {}
};
class FallenAngel : virtual public Angels {
    protected:
        int horns;
    public:
        FallenAngel(int w, int h) : Angels(w), horns(h) {}
};
class DarkAngel : public HeavenlyAngel, public FallenAngel {
    private:
        int darknessLevel;
    public:
        DarkAngel(int w, int h, int hornCount, int dLevel)
            : Angels(w),  // MUST initialize virtual base directly
              HeavenlyAngel(w, h), 
              FallenAngel(w, hornCount), 
              darknessLevel(dLevel) {}
};
int main(){
    DarkAngel A(1,2,3,4);
    cout<<++A.wings<<endl;

}