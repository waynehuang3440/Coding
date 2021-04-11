#include <iostream>

using namespace std;

class Square{
public:
    //write something
private:
    float area;
};

class Circle{
public:
    //write something
private:
    static const  int pi = 3;
    float area;
};

class Area{
public:
    //write something
};

int main(){
    int r;
    cin >> r;
    cout << "Circle Area:" << Circle::circleArea(r) << endl;

    //new一個半徑為10的Circle Class
    Circle r1(10);
    //new一個半徑為3的Circle Class
    Circle r2(3);
    //new一個邊長為3的Square Class
    Square s1(3);
    //new一個邊長為10的Square Class
    Square s2(10);
    //r1和s1比較面積
    r1.compareArea(s1);
    //r2和s2比較面積
    Area::compare(r2,s2);
    return 0;
}
