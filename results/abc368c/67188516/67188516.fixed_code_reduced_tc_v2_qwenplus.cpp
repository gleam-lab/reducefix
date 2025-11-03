#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<long long> H(N);
    for (int i = 0; i < N; ++i) {
        cin >> H[i];
    }

    long long T = 0;
    int pos = 0; // current T mod 3

    for (int i = 0; i < N; ++i) {
        long long health = H[i];
        
        // While this enemy is still alive
        while (health > 0) {
            T++;
            pos = T % 3;
            if (pos == 0) {
                health -= 3;
            } else {
                health -= 1;
            }
        }
    }

    cout << T << endl;
    return 0;
}