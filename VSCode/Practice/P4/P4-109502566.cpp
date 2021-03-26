#include <iostream>
#include <vector>
using namespace std;

class int_vec{
    public:
        int_vec ( int size ) {
            vec_size = size;
            for ( int i = 0; i < size; i++ ) {
                v.push_back( 0 );
            }
        }
        friend ostream &operator<< ( ostream &output, const int_vec &vec ) {
            output << "[";
            for ( int i = 0; i < vec.vec_size; i++ ) {
                if ( i < vec.vec_size - 1 ) {
                    output << vec.v.at( i ) << ", ";
                }
                else {
                    output << vec.v.at( i );
                }
            }
            output << "]" ;
            return output;
        }
        friend istream &operator>> ( istream &input, int_vec &vec ) {
            int x;
            vec.v.clear();
            for ( int i = 0; i < vec.vec_size; i++ ) {
                input >> x;
                vec.v.push_back( x );
            }
            return input;
        }
        int_vec operator+ ( int_vec &vec ) {
            for ( int i = 0; i < vec.vec_size; i++ ) {
                this->v.push_back( vec.v.at( i ) );
                this->vec_size++;
            }
            for ( int i = 0; i < this->vec_size - 1; i++ ) {
                for ( int j = 0; j < this->vec_size - 1 - i; j++ ) {
                    if ( this->v.at( j ) > this->v.at( j + 1 ) ) {
                        int copy;
                        copy = v.at( j );
                        this->v.at( j ) = this->v.at( j + 1 );
                        this->v.at( j + 1 ) = copy;
                    }
                }
            }
            return *this;
        }
        void getSize() {
            cout << this->vec_size << endl;
        }
    private:
        int vec_size;
        vector< int > v;
};

int main() {
    int vs1, vs2;
    cin >> vs1;
    cin >> vs2;
    int_vec v1( vs1 );
    int_vec v2( vs2 );
    cin >> v1;
    cin >> v2;
    cout << v1 << endl;
    cout << v2 << endl;
    v1 = v1 + v2;
    cout << v1 << endl;
    return 0;
}