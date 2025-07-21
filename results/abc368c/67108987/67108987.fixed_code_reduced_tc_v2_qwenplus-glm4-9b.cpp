#include<bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> H(N);
    for (int i = 0; i < N; i++) cin >> H[i];
    long long T = 0;
    for (int i = 0; i < N; i++) {
        // Calculate the number of full 3 attacks we can use on this enemy
        int full_attacks = H[i] / 3;
        T += full_attacks * 3;
        H[i] -= full_attacks * 3;
        
        // If there's any health left after using full attacks, use a single attack
        if (H[i] > 0) {
            T += 1;
            H[i]--;
        }
    }
    cout << T << endl;
    return 0;
}