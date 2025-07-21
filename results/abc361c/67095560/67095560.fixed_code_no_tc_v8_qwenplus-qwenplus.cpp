#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define int long long

typedef long long ll;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> A(n);
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
    }

    // We need to choose N-K elements to keep in order and minimize (max - min)
    // The key is to find all windows of size (N-K) in the array and compute min(max - min)

    deque<int> minDQ;  // stores indices of increasing values
    deque<int> maxDQ;  // stores indices of decreasing values

    int res = LLONG_MAX;

    // Sliding window approach
    for (int i = 0; i < n; ++i) {
        // Maintain min deque
        while (!minDQ.empty() && A[minDQ.back()] >= A[i]) minDQ.pop_back();
        minDQ.push_back(i);

        // Maintain max deque
        while (!maxDQ.empty() && A[maxDQ.back()] <= A[i]) maxDQ.pop_back();
        maxDQ.push_back(i);

        // Remove out of window indices
        if (i >= n - k - 1) {
            while (minDQ.front() < i - (n - k - 1)) minDQ.pop_front();
            while (maxDQ.front() < i - (n - k - 1)) maxDQ.pop_front();

            res = min(res, A[maxDQ.front()] - A[minDQ.front()]);
        }
    }

    cout << res << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}