#include<bits/stdc++.h>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> H(N);
    for (int i = 0; i < N; i++) cin >> H[i];
    long long T = 0;
    
    // Iterate through each enemy
    for (int i = 0; i < N; i++) {
        // Calculate the remaining health after repeatedly dealing 3 damage
        while (H[i] > 0) {
            if (H[i] % 3 == 0) {
                // If the health is a multiple of 3, deal 3 damage each time
                H[i] -= 3;
                T += 3;
            } else {
                // If the health is not a multiple of 3, deal 1 damage at a time
                H[i]--;
                T++;
            }
        }
    }
    
    cout << T << endl;
    return 0;
}