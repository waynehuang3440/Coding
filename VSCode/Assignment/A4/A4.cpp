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

    //new�@�ӥb�|��10��Circle Class
    Circle r1(10);
    //new�@�ӥb�|��3��Circle Class
    Circle r2(3);
    //new�@�������3��Square Class
    Square s1(3);
    //new�@�������10��Square Class
    Square s2(10);
    //r1�Ms1������n
    r1.compareArea(s1);
    //r2�Ms2������n
    Area::compare(r2,s2);
    return 0;
}
