#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool isPossible(const vector<long long>& H, long long T) {
    long long total = 0;
    for (long long h : H) {
        long long attacks = (h + 1) / 2;  // Minimum attacks needed if all were 1-damage
        if (h <= 0) continue;
        // For attacks pattern: 1, 1, 3, 1, 1, 3, ...
        // The number of 3-damage attacks is T / 3
        // The number of 1-damage attacks is T - T / 3
        // Total damage per enemy: (T - T / 3) * 1 + (T / 3) * 3 = T + 2*(T / 3)
        // But we need to consider the position of the enemy in the attack sequence
        // Alternative approach: each attack on an enemy alternates between 1 and 3 but not exactly
        // So, compute the total damage for the enemy based on T
        long long damage = 0;
        long long t3 = T / 3;
        long long t1 = T - t3;
        damage = t1 * 1 + t3 * 3;
        if (damage < h) {
            return false;
        }
    }
    return true;
}

int main() {
    int N;
    cin >> N;
    vector<long long> H(N);
    for (int i = 0; i < N; ++i) {
        cin >> H[i];
    }

    long long left = 0;
    long long right = 1LL << 60;  // A sufficiently large upper bound
    long long answer = right;

    while (left <= right) {
        long long mid = left + (right - left) / 2;
        if (isPossible(H, mid)) {
            answer = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    cout << answer << endl;

    return 0;
}