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

    // We need to choose N - K elements such that the max - min of the selected elements is minimized.
    // The selected elements must remain in order.

    // Since we are allowed to remove K elements freely, we can try all possible intervals of length (n - k)
    // and find the one with minimal (max - min).

    int len = n - k;
    if (len == 0) {
        cout << 0 << endl;
        return 0;
    }

    // Use a sliding window with a multiset to maintain the min and max in current window
    multiset<int> window;

    // Initialize the first window
    for (int i = 0; i < len; ++i) {
        window.insert(A[i]);
    }

    ll res = (*window.rbegin()) - (*window.begin());

    // Slide the window
    for (int i = len; i < n; ++i) {
        // Remove the element going out
        auto it = window.find(A[i - len]);
        if (it != window.end()) {
            window.erase(it);
        }
        // Add the new element coming in
        window.insert(A[i]);

        ll current_diff = (*window.rbegin()) - (*window.begin());
        chmin(res, current_diff);
    }

    cout << res << endl;
}