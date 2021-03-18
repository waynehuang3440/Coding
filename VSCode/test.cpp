#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector< int > vec;
    vec.p_back( 1 );
    vec.at( 0 ) = 2;
    cout << vec.at( 0 );
}