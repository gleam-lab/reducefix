#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<long long> H(N);
    
    long long T = 0;
    for (int i = 0; i < N; ++i) {
        cin >> H[i];
        
        while (H[i] > 0) {
            if (T % 3 == 0) {
                // If T is a multiple of 3, attack with 3 damage
                if (H[i] >= 3) {
                    H[i] -= 3;
                } else {
                    // If health is less than 3, finish it off
                    H[i] = 0;
                }
            } else {
                // If T is not a multiple of 3, attack with 1 damage
                H[i]--;
            }
            // Increment T after each attack
            T++;
        }
    }
    
    cout << T << endl;
    
    return 0;
}