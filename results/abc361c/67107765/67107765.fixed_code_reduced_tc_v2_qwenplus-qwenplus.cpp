#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define pb push_back
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)

using ll = long long;
using P = pair<int, int>;

const int INF = 1001001001;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    vector<int> A(n);
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
    }

    // We will consider all intervals of size (n - K) and find min and max in them
    // Using sliding window with multiset to maintain current window elements

    multiset<int> window;
    int res = numeric_limits<int>::max();

    // Initialize the first window
    for (int i = 0; i < n - k; ++i) {
        window.insert(A[i]);
    }

    for (int i = 0; i <= k; ++i) {
        // Compute current range
        res = min(res, *window.rbegin() - *window.begin());

        // Move window forward if not last iteration
        if (i < k) {
            window.erase(window.find(A[i]));          // Remove element going out
            window.insert(A[i + (n - k)]);           // Add new element coming in
        }
    }

    cout << res << endl;
}