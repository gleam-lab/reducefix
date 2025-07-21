#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define pb push_back
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

    // We need to choose N - K elements to keep, so that the difference between max and min is minimized.
    // Try all possible windows of size (n - k) in A.

    multiset<int> window;
    for (int i = 0; i < n - k; ++i) {
        window.insert(A[i]);
    }

    int ans = *window.rbegin() - *window.begin();

    for (int i = n - k; i < n; ++i) {
        window.erase(window.find(A[i - (n - k)]));
        window.insert(A[i]);
        int current_diff = *window.rbegin() - *window.begin();
        chmin(ans, current_diff);
    }

    cout << ans << endl;
}