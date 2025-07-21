#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<long long> H(N);
    for (int i = 0; i < N; ++i) {
        cin >> H[i];
    }

    long long total_attacks = 0;
    long long current_pos = 0; // T % 3

    for (int i = 0; i < N; ++i) {
        long long hi = H[i];
        // Binary search to find the minimal T that satisfies the condition
        long long low = 0;
        long long high = hi * 2; // Upper bound
        long long T = 0;
        while (low <= high) {
            long long mid = (low + high) / 2;
            long long special = mid / 3;
            long long normal = mid - special;
            long long damage = normal * 1 + special * 3;
            if (damage >= hi) {
                T = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        // Now, calculate the actual T with the current_pos
        // The first attack on this enemy starts at (total_attacks + 1)
        // So, the attacks for this enemy are from (total_attacks + 1) to (total_attacks + T)
        // We need the minimal T such that the sum of damages >= H[i]
        // But attacks are affected by their positions in modulo 3
        // So, the actual number of attacks is T, but the damage depends on which attacks are special
        // So, the previous approach's binary search is correct in finding T
        total_attacks += T;
    }

    cout << total_attacks << endl;
    return 0;
}