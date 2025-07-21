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
        // For each enemy, calculate how many full cycles of 3 attacks are needed
        // and then handle the remaining damage.
        
        // a: number of full 3-attacks (each cycle of 3 Ticks does 5 damage: 1+1+3)
        long long a = H[i] / 5;
        long long rem = H[i] % 5;
        
        T += a * 3;
        
        if (rem > 0) {
            T += 1; // first 1-damage attack
            rem -= 1;
        }
        if (rem > 0) {
            T += 1; // second 1-damage attack
            rem -= 1;
        }
        if (rem > 0) {
            T += 1; // third 3-damage attack
            rem -= 3;
        }
    }

    cout << T << endl;
    return 0;
}