#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;
class ScoreRecord {
    public:
        ScoreRecord( string, string, int, int, int, int );
        void ChangeScore( int, int );
        void PrintAll();
        string GetId();
        void PrintId();
    private:
        string Id;
        string Name;
        int ChineseScore;
        int MathScore;
        int ScienceScore;
        int EnglishScore;
        float Average;
};

int main() {
    vector< ScoreRecord > vec;
    int n = 0;
    int order;
    string ID, NAME;
    int CS, MS, SS, ES;
    int sub, score;
    while ( true ) {
        cout << "(1) Insert (2) Change score (3) Print all (4) Delete (5) Exit" << endl;
        cin >> order;
        if ( order == 1 ) {
            cout << "Please enter student id/name/scores(Chinese/Math/Science/English)" << endl;
            cin >> ID >> NAME >> CS >> MS >> SS >> ES;
            ScoreRecord new_student( ID, NAME, CS, MS, SS, ES );
            vec.push_back( new_student );
            n++;
        }
        else if ( order == 2 ) {
            cout << "Please enter student id" << endl;
            cin >> ID;
            cout << "Which subject? (1) Chinese (2) Math (3) Science (4) English" << endl;
            cin >> sub;
            cout << "Please enter new score" << endl;
            cin >> score;
            for ( int i = 0; i < n; i++ ) {
                if ( ID == vec.at( i ).GetId() ) {
                    vec.at( i ).ChangeScore( sub, score );
                }
            }
        }
        else if ( order == 3 ) {
            for ( int i = 0; i < n - 1; i++ ) {
                for ( int j = 0; j < n - 1 - i; j++ ) {
                    if ( vec.at( j ).GetId() > vec.at( j + 1 ).GetId() ) {
                        ScoreRecord copy = vec.at( j );
                        vec.at( j ) = vec.at( j + 1 );
                        vec.at( j + 1 ) = copy;
                    }
                }
            }
            for ( int i = 0; i < n; i++ ) {
                vec.at( i ).PrintAll();
            }
        }
        else if ( order == 4 ) {
            cout << "Please enter student id" << endl;
            cin >> ID;
            vector< ScoreRecord > :: iterator it;
            for ( int i = 0; i < n; i++ ) {
                if ( ID == vec.at( i ).GetId() ) {
                    it = vec.begin() + i;
                    vec.erase( it );
                }
            }
            n--;
        }
        else {
            break;
        }
    }
    return 0;
}

ScoreRecord::ScoreRecord( string ID, string NAME, int CS, int MS, int SS, int ES ){
    Id = ID;
    Name = NAME;
    ChineseScore = CS;
    MathScore = MS;
    ScienceScore = SS;
    EnglishScore = ES;
    Average = float( ( ChineseScore + MathScore + ScienceScore + EnglishScore ) )/ 4;
}

void ScoreRecord::ChangeScore( int sub, int Score ) {
    if ( sub == 1 ) {
        ChineseScore = Score;
    }
    else if ( sub == 2 ) {
        MathScore = Score;
    }
    else if ( sub == 3 ) {
        ScienceScore = Score;
    }
    else if ( sub == 4 ) {
        EnglishScore = Score;
    }
    Average = float( ( ChineseScore + MathScore + ScienceScore + EnglishScore ) )/ 4;
}

void ScoreRecord::PrintAll() {
    cout << Id << " " << Name << " " << ChineseScore << " " << MathScore << " " << ScienceScore << " " << EnglishScore << " ";
    cout << fixed << setprecision(2) << Average << endl;
}

string ScoreRecord::GetId() {
    return Id;
}