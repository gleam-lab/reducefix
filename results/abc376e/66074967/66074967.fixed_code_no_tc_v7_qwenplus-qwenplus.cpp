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

    // Sort items by A_i in ascending order
    sort(A.begin(), A.end());

    // Min-heap to maintain top K smallest B_i values
    priority_queue<int, vector<int>, less<int>> max_heap;
    int sum_B = 0;
    int result = 1e18;  // Large initial value

    // We process from the K-th item to the end
    for (int i = 0; i < n; ++i) {
        int a_val = A[i].first;
        int b_val = A[i].second;

        // Add current B_i
        max_heap.push(b_val);
        sum_B += b_val;

        // If more than K elements, remove the largest B seen so far
        if (max_heap.size() > k) {
            sum_B -= max_heap.top();
            max_heap.pop();
        }

        // Once we have at least K elements, compute the expression
        if (max_heap.size() == k) {
            result = min(result, a_val * sum_B);
        }
    }

    cout << result << "\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}