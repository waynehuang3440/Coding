#include <iostream>
using namespace std;

class Square{
public:
    friend class Area;
    friend class Circle;
    Square ( int L ) {
        area = L * L;
    }
    
private:
    float area;
};

class Circle{
public:
    friend class Area;
    Circle( int R ) {
        area = R * R * pi;
    }
    static int circleArea( int R ) {
        return int( R * R * pi );
    }
    void compareArea( Square S ) {
        if ( this->area > S.area ) {
            cout << "Circle one is the biggest." << endl;
        } 
        else {
            cout << "Square one is the biggest." << endl;
        }
    } 
private:
    static const int pi = 3;
    float area;
};

class Area{
public:
    void static compare( Circle C, Square S ) {
        if ( C.area > S.area ) {
            cout << "Circle one is the biggest." << endl;
        }
        else {
            cout << "Square one is the biggest." << endl;
        }
    }
};

int main(){
    int r;
    cin >> r;
    cout << "Circle Area:" << Circle::circleArea( r ) << endl;
    Circle r1( 10 );
    Circle r2( 3 );
    Square s1( 3 );
    Square s2( 10 );
    r1.compareArea( s1 );
    Area::compare( r2, s2 );
    return 0;
}