#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int N, K;
        cin >> N >> K;

        vector<pair<int, int>> items(N);
        for (int i = 0; i < N; ++i) {
            cin >> items[i].first;
        }
        for (int i = 0; i < N; ++i) {
            cin >> items[i].second;
        }

        // Sort by A[i]
        sort(items.begin(), items.end());

        multiset<int> b_values;
        long long sumB = 0;
        long long result = numeric_limits<long long>::max();

        for (int i = 0; i < N; ++i) {
            int a = items[i].first;
            int b = items[i].second;

            b_values.insert(b);
            sumB += b;

            if (b_values.size() > K) {
                // Remove the smallest B in the set
                auto it = b_values.begin();
                sumB -= *it;
                b_values.erase(it);
            }

            if (b_values.size() == K) {
                result = min(result, a * sumB);
            }
        }

        cout << result << '\n';
    }

    return 0;
}