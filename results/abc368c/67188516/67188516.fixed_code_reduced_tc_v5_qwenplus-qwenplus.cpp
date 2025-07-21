#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<long long> H(N);
    for (int i = 0; i < N; ++i) {
        cin >> H[i];
    }

    long long ans = 0;
    long long pos = 0; // 0, 1, or 2 representing current position in the 3-step cycle

    for (int i = 0; i < N; ++i) {
        long long h = H[i];
        if (h <= 0) continue;

        // Calculate how many full cycles of 3 attacks we can do on this enemy
        long long full_cycles = h / 5;
        ans += full_cycles * 3;
        long long remainder = h % 5;

        // Apply the attacks for the remainder
        for (long long j = 0; j < remainder; ++j) {
            // Advance time and check if it's a multiple of 3 for stronger attack
            ++ans;
            if (ans % 3 == 0) {
                // Triple attack
                --h;
            } else {
                // Single attack
                --h;
            }
            // We don't need to track pos anymore as we're directly using ans
        }
    }

    cout << ans << endl;
    return 0;
}