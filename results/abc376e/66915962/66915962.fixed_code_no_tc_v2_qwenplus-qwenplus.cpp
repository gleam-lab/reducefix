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
        multiset<int> b_set;

        // First K elements
        for (int i = 0; i < K; ++i) {
            sumB += pairs[i].second;
            b_set.insert(pairs[i].second);
        }

        ll ans = (ll)pairs[K - 1].first * sumB;

        // Sliding window: maintain a set of K smallest B's
        for (int i = K; i < N; ++i) {
            // Add current B_i
            if (pairs[i].second > *b_set.begin()) {
                sumB += pairs[i].second - *b_set.begin();
                b_set.erase(b_set.begin());
                b_set.insert(pairs[i].second);
            }
            // Update answer with current max A_i (pairs[i].first) and sumB
            ans = min(ans, (ll)pairs[i].first * sumB);
        }

        cout << ans << '\n';
    }

    return 0;
}