#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
constexpr ll LINF = 1001001001001001001ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int N, K;
        cin >> N >> K;
        vector<P> pairs(N);
        for (int i = 0; i < N; ++i) {
            cin >> pairs[i].first;
        }
        for (int i = 0; i < N; ++i) {
            cin >> pairs[i].second;
        }

        // Sort by A_i ascending
        sort(pairs.begin(), pairs.end());

        ll sumB = 0;
        multiset<int> b_values;

        // Initialize with first K elements
        for (int i = 0; i < K; ++i) {
            sumB += pairs[i].second;
            b_values.insert(pairs[i].second);
        }

        ll ans = LINF;

        // For the rest of the window positions
        for (int i = K - 1; i < N; ++i) {
            if (i >= K) {
                // Remove the largest B from set
                sumB -= *prev(b_values.end());
                b_values.erase(prev(b_values.end()));

                // Add new B value
                sumB += pairs[i].second;
                b_values.insert(pairs[i].second);
            }

            ans = min(ans, 1LL * pairs[i].first * sumB);
        }

        cout << ans << '\n';
    }

    return 0;
}