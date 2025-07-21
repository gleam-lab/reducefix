#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> H(N);
    for (int i = 0; i < N; i++) cin >> H[i];
    
    long long T = 0;
    for (int i = 0; i < N; i++) {
        if (H[i] % 3 == 0) {
            // If the health is a multiple of 3, attack in multiples of 3
            T += (H[i] / 3) * 3;
            H[i] = 0;
        } else {
            // If the health is not a multiple of 3, attack once and then handle the remainder
            T++;
            H[i] -= 1;
            if (H[i] % 3 == 0) {
                // If after one attack, the health is still a multiple of 3, continue attacking in multiples of 3
                T += (H[i] / 3) * 3;
                H[i] = 0;
            } else {
                // Otherwise, attack 3 times to make the health a multiple of 3
                T += 3;
                H[i] -= 2; // Now, the health should be a multiple of 3
            }
        }
    }
    
    cout << T << endl;
    return 0;
}