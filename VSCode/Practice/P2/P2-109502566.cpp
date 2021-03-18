#include <iostream>
using namespace std;
class Student {
    public: 
        Student( string ID, string NAME, int SCORE ) {
            id = ID;
            name = NAME;
            score = SCORE;
        }
        string getId();
        string getName();
        int getScore();
        void changeScore( int new_score );
    private:
        string id;
        string name;
        int score;
};

int main() {
    Student Alex( "109123445", "Alex", 90 );
    Student Kiki( "109876543", "Kiki", 75 );
    cout << "Before" << endl;
    cout << Alex.getId() << " : " << Alex.getName() << " : " << Alex.getScore() << endl;
    cout << Kiki.getId() << " : " << Kiki.getName() << " : " << Kiki.getScore() << endl;
    Alex.changeScore( 61 );
    Kiki.changeScore( 89 );
    cout << "After" << endl;
    cout << Alex.getId() << " : " << Alex.getName() << " : " << Alex.getScore() << endl;
    cout << Kiki.getId() << " : " << Kiki.getName() << " : " << Kiki.getScore() << endl;
    return 0;
}

string Student::getId() {
    return id;
}

string Student::getName() {
    return name;
}

int Student::getScore() {
    return score;
}

void Student::changeScore( int new_score ) {
    score = new_score;
}