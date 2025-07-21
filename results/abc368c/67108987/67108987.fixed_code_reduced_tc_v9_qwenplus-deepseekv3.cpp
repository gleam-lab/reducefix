#include<bits/stdc++.h>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<long long> H(N);
    for (int i = 0; i < N; i++) cin >> H[i];
    long long T = 0;
    for (int i = 0; i < N; i++) {
        long long h = H[i];
        if (h == 0) continue;
        // Calculate the number of triple attacks (3 damage) and single attacks (1 damage)
        // The total attacks needed to reduce h to 0.
        // Let x be the number of triple attacks, and y be the total single attacks.
        // Then, 3x + y >= h, and y + x is minimized.
        // The optimal is to maximize x (since 3x reduces more health per attack).
        // The minimal T is when x is as large as possible.
        // The attack pattern is 1, 1, 3, 1, 1, 3, etc.
        // So for h, the number of full cycles (3 attacks per 5 damage) is h / 5.
        // Then, remaining attacks can be calculated.
        long long full_cycles = h / 5;
        long long remaining = h % 5;
        T += full_cycles * 3;
        h = remaining;
        if (h > 0) {
            if (h <= 1) {
                T += 1;
            } else if (h <= 2) {
                T += 2;
            } else {
                T += 3;
            }
        }
    }
    cout << T << endl;
    return 0;
}