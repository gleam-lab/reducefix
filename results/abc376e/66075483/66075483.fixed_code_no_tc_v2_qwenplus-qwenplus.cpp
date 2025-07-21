#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

#define int long long

void solve() {
    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> A(n);
    for (int i = 0; i < n; ++i) {
        cin >> A[i].first;
    }
    for (int i = 0; i < n; ++i) {
        cin >> A[i].second;
    }

    // Sort elements by A[i] in ascending order
    sort(A.begin(), A.end());

    // Min-heap to maintain top K B values seen so far
    priority_queue<int, vector<int>, greater<>> pq;
    int sum_b = 0;
    int result = 1e18;  // Large initial value

    // We'll process from index k-1 to n-1
    // For each i, we consider A[i] as the max A in subset
    for (int i = 0; i < n; ++i) {
        pq.push(A[i].second);
        sum_b += A[i].second;

        if (pq.size() > k) {
            sum_b -= pq.top();
            pq.pop();
        }

        if (pq.size() == k) {
            result = min(result, A[i].first * sum_b);
        }
    }

    cout << result << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}