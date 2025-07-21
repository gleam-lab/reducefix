#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    i64 N, M;
    cin >> N >> M;
    vector<array<i64,2>> g(M);
    for (i64 i = 0; i < M; i++) {
        i64 a, b;
        cin >> a >> b;
        g[i] = {a, b};
    }

    // Function to count the number of elements less than or equal to x
    auto count_le = [](const vector<i64>& v, i64 x) {
        if (v.empty()) return 0;
        i64 lo = 0, hi = v.size() - 1;
        while (lo < hi) {
            i64 mid = lo + (hi - lo + 1) / 2;
            if (v[mid] <= x) lo = mid;
            else hi = mid - 1;
        }
        return lo + 1;
    };

    i64 ans = N * N; // Start with all N*N squares

    // Iterate over all positions
    for (i64 i = 1; i <= N; i++) {
        for (i64 j = 1; j <= N; j++) {
            bool is_safe = true;

            // Check if the current position can be captured by any existing piece
            for (const auto& p : g) {
                i64 a = p[0], b = p[1];

                // Check row capture
                if (i == a) is_safe = false;
                // Check column capture
                if (j == b) is_safe = false;
                // Check diagonal capture (i+j)
                if (i + j == a + b) is_safe = false;
                // Check diagonal capture (i-j)
                if (i - j == a - b) is_safe = false;
            }

            // If the position is safe, decrease the count of possible positions
            if (is_safe) ans--;
        }
    }

    cout << ans << endl;

    return 0;
}