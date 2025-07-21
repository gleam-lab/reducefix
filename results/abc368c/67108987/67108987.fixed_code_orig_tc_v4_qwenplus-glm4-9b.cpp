#include<bits/stdc++.h>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> H(N);
    for (int i = 0; i < N; i++) cin >> H[i];
    long long total_attacks = 0;

    for (int i = 0; i < N; i++) {
        int full_cycles = H[i] / 3;
        int remaining_health = H[i] % 3;
        total_attacks += full_cycles * 3; // Each cycle is 3 attacks
        total_attacks += remaining_health; // Handle the remaining health
        H[i] = 0; // The enemy is defeated
    }

    cout << total_attacks << endl;
    return 0;
}