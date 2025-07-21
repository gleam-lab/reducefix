#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int N, K;
    cin >> N >> K;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) cin >> A[i];

    // Min heap and Max heap for sliding window
    multiset<int> minSet, maxSet;
    int result = LLONG_MAX;

    // Initialize first window
    for (int i = 0; i < N - K; ++i) {
        minSet.insert(A[i]);
        maxSet.insert(-A[i]);  // Use negative for max set
    }

    result = *minSet.rbegin() - *minSet.begin();

    for (int i = N - K; i < N; ++i) {
        int out = A[i - (N - K)];
        int in = A[i];

        // Remove old element
        auto it = minSet.find(out);
        if (it != minSet.end()) {
            minSet.erase(it);
            maxSet.erase(maxSet.find(-out));
        }

        // Add new element
        minSet.insert(in);
        maxSet.insert(-in);

        // Update result
        int currDiff = *minSet.rbegin() - *minSet.begin();
        result = min(result, currDiff);
    }

    cout << result << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}