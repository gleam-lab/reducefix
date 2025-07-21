#include<bits/stdc++.h>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> H(N + 9);
    for (int i = 0; i < N; i++) {
        cin >> H[i];
    }
    long long T = 0;
    for (int i = 0; i < N; i++) {
        int damage = 1; // Default damage if no multiples of 3 can be applied
        // Calculate the number of full 3-damage hits
        int full_3_damage_hits = H[i] / 3;
        T += full_3_damage_hits * 3;
        H[i] -= full_3_damage_hits * 3;
        // If there's remainder, apply one more damage
        if (H[i] > 0) {
            T += 1;
            H[i]--;
        }
    }
    cout << T << endl;
    return 0;
}