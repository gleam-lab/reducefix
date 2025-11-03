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
    int pos = 0; // position in cycle: 0 -> next attack is not multiple of 3, 1 -> is multiple of 3

    for (int i = 0; i < N; ++i) {
        long long health = H[i];
        
        // We simulate the attacks on enemy i until its health drops to 0 or below
        while (health > 0) {
            T++;
            pos = (pos + 1) % 3;

            if (pos == 0) {
                health -= 3; // T is multiple of 3
            } else {
                health -= 1; // T is not multiple of 3
            }
        }
    }

    cout << T << endl;
    return 0;
}