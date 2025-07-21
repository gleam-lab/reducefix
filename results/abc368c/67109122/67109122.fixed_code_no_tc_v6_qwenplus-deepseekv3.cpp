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
        // The number of attacks where T ≡ 1 or 2 mod 3 (damage 1)
        // and T ≡ 0 mod 3 (damage 3)
        // Let x be the number of attacks with damage 3, and y with damage 1
        // We need 3x + y >= h, and x + y is minimized
        // Also, for the i-th enemy, the attacks must be in the sequence where
        // the total attacks up to this enemy is T_prev + x + y
        // So, T_prev is the T before starting to attack this enemy
        // The attacks on this enemy start at T_prev + 1
        // The T during attacks on this enemy is T_prev + 1, T_prev + 2, ..., T_prev + x + y
        // The damage is 1 for T not divisible by 3, 3 otherwise
        // To find x and y:
        // The minimal x is such that 3x + (h - 3x) >= h, but we need a better approach
        // Alternatively, for each enemy, the attacks can be viewed in batches:
        // Every 3 attacks (T+1, T+2, T+3), the damage is 1 + 1 + 3 = 5 per 3 attacks
        // So, h = 5 * k + r, where r is the remaining health after k full batches
        // Then, the remaining r can be covered by 1 or 2 attacks (damage 1 or 3)
        // But need to align the attacks with the global T
        long long k = h / 5;
        long long r = h % 5;
        long long added_T;
        if (r == 0) {
            added_T = 3 * k;
        } else if (r <= 2) {
            added_T = 3 * k + r;
        } else {
            added_T = 3 * k + 3;
        }
        // The above assumes that the attacks start at T+1 ≡ 1 mod 3
        // But the actual start depends on the current T
        // So, we need to adjust based on T % 3
        long long start_mod = (T + 1) % 3;
        if (start_mod == 1) {
            // Sequence is 1, 2, 0, 1, 2, 0, ...
            // Damage per 3 attacks: 1 + 1 + 3 = 5
            k = h / 5;
            r = h % 5;
            if (r == 0) {
                added_T = 3 * k;
            } else if (r <= 2) {
                added_T = 3 * k + r;
            } else {
                added_T = 3 * k + 3;
            }
        } else if (start_mod == 2) {
            // Sequence is 2, 0, 1, 2, 0, 1, ...
            // Damage per 3 attacks: 1 + 3 + 1 = 5
            k = h / 5;
            r = h % 5;
            if (r == 0) {
                added_T = 3 * k;
            } else if (r == 1) {
                added_T = 3 * k + 1;
            } else if (r == 2) {
                added_T = 3 * k + 2;
            } else if (r == 3) {
                added_T = 3 * k + 2;
            } else { // r ==4
                added_T = 3 * k + 3;
            }
        } else { // start_mod == 0
            // Sequence is 0, 1, 2, 0, 1, 2, ...
            // Damage per 3 attacks: 3 + 1 + 1 = 5
            k = h / 5;
            r = h % 5;
            if (r == 0) {
                added_T = 3 * k;
            } else if (r == 1) {
                added_T = 3 * k + 1;
            } else if (r == 2) {
                added_T = 3 * k + 1;
            } else if (r == 3) {
                added_T = 3 * k + 1;
            } else { // r ==4
                added_T = 3 * k + 2;
            }
        }
        T += added_T;
    }
    cout << T << endl;
    return 0;
}