#include<bits/stdc++.h>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> H(N);
    for (int i = 0; i < N; i++) cin >> H[i];
    long long T = 0;
    
    // Process each enemy
    for (int i = 0; i < N; i++) {
        // Calculate how many full attacks of 3 can be applied
        int full_attacks = H[i] / 3;
        // Add full attacks to T
        T += full_attacks;
        // If there's a remainder, adjust T to make it a multiple of 3
        if (H[i] % 3 == 1) {
            if (T % 3 == 1) T += 1; // If T is 1, make it 4
            else if (T % 3 == 2) T -= 1; // If T is 2, make it 3
        }
    }
    
    cout << T << endl;
    return 0;
}