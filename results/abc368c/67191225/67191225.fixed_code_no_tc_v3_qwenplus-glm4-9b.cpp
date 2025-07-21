#include <iostream>
using namespace std;

int main() {
    long long N;
    cin >> N;
    vector<long long> H(N);
    for (int i = 0; i < N; ++i) {
        cin >> H[i];
    }
    
    long long T = 0;
    for (int i = 0; i < N; ++i) {
        // Process the health of the current enemy
        while (H[i] > 0) {
            if (T % 3 == 0) {
                H[i] -= 3;
            } else if (T % 3 == 1) {
                if (H[i] == 1) {
                    break; // If health is 1, just one attack is sufficient
                }
                H[i] -= 1;
            } else { // T % 3 == 2
                if (H[i] == 2 || H[i] == 3) {
                    break; // If health is 2 or 3, just one attack is sufficient
                }
                H[i] -= 1;
            }
            T++;
        }
    }
    
    cout << T << endl;
    return 0;
}