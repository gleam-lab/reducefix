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

        multiset<int> b_values;
        ll sumB = 0;
        ll result = LINF;

        // First, take the first K elements
        for (int i = 0; i < K; ++i) {
            b_values.insert(pairs[i].second);
            sumB += pairs[i].second;
        }
        result = min(result, 1LL * pairs[K - 1].first * sumB);

        // Now slide window: for each i from K to N-1
        for (int i = K; i < N; ++i) {
            // Current A[i], we must include it
            // So remove the largest B in set and add current B[i]
            int max_b = *prev(b_values.end());
            b_values.erase(prev(b_values.end()));
            sumB -= max_b;

            b_values.insert(pairs[i].second);
            sumB += pairs[i].second;

            result = min(result, 1LL * pairs[i].first * sumB);
        }

        cout << result << '\n';
    }

    return 0;
}