#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define int long long

typedef long long ll;
typedef pair<int, int> pii;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> A(n);
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
    }

    // We need to choose N-K elements such that the resulting sequence B has:
    // - max(B) - min(B) minimized
    // Since we can only remove K elements, not reorder them,
    // the best strategy is to try minimizing the range among the tightest windows.

    int windowSize = n - k;
    
    // Sliding window approach: maintain a window of size windowSize,
    // and track min and max in that window.
    // We slide it across the array and find the minimum (max-min)

    multiset<int> ms;
    for (int i = 0; i < windowSize; ++i) {
        ms.insert(A[i]);
    }

    int ans = (*ms.rbegin()) - (*ms.begin());

    for (int i = windowSize; i < n; ++i) {
        ms.erase(ms.find(A[i - windowSize]));  // Remove the element exiting the window
        ms.insert(A[i]);                       // Add the new element entering the window
        ans = min(ans, (*ms.rbegin()) - (*ms.begin()));
    }

    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}