#include <iostream>
using namespace std;

class weight {
    public:
        weight( int, int, string, string );
        void change();
        void compare();
    private:
        string fn1;
        string fn2;
        int fw1;
        int fw2; 
};

int main() {
    string FN1, FN2;
    int FW1, FW2;
    cin >> FN1 >> FW1 >> FN2 >> FW2;
    weight input( FW1, FW2, FN1, FN2 );
    input.compare();
    input.change();
    input.compare();
    return 0;
}

weight::weight( int FW1, int FW2, string FN1, string FN2 ) {
    fw1 = FW1;
    fw2 = FW2;
    fn1 = FN1;
    fn2 = FN2;
}

void weight::change() {
        if ( fw1 > fw2 ) {
            cout << fn1 << " > " << fn2 << endl;
        }
        else {
            cout << fn2 << " > " << fn1 << endl;
        }
        int cw;
        cw = fw1;
        fw1 = fw2;
        fw2 = cw;
}

void weight::compare() {
    if ( fw1 > fw2 ) {
        cout << fn1 << " is heavy" << endl;
    }
    else {
        cout << fn2 << " is heavy" << endl;
    }
}