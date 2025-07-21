#include <bits/stdc++.h>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<long long> H(N);
    for (int i = 0; i < N; ++i) {
        cin >> H[i];
    }

    long long T = 0;

    for (int i = 0; i < N; ++i) {
        // For each enemy, determine how many triple attacks we can use
        // Each triple attack (at T divisible by 3) deals 3 damage
        // And two single attacks in between
        // So every "cycle" of 3 attacks deals 5 damage (3 + 1 + 1)
        
        long long cycles = H[i] / 5;
        long long rem = H[i] % 5;
        
        T += cycles * 3;
        
        if (rem > 0) {
            T += 1; // One triple attack
            if (rem > 3) {
                T += 1; // One more single attack
            }
        }
    }

    cout << T << endl;
    return 0;
}