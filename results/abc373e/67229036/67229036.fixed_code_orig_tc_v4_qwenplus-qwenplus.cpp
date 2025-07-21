#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 2e5 + 5;

int n, m, k;
int a[N];
int b[N], prefix[N];

// Check if giving 'x' additional votes to candidate with current votes 'base'
// guarantees a win under any vote distribution.
bool is_possible(int base, int x) {
    int total = 0;
    for (int i = 1; i <= n; ++i)
        b[i] = a[i];
    b[n+1] = base + x;
    sort(b + 1, b + n + 2);

    // Find index of our candidate in sorted list
    int idx = lower_bound(b + 1, b + n + 2, b[n+1]) - b;
    int rank = n + 2 - idx;

    return rank <= n - m + 1;
}

// Binary search for minimum required votes
int solve(int base) {
    int low = 0, high = k + 1;
    int res = -1;

    while (low <= high) {
        int mid = (low + high) / 2;
        if (is_possible(base, mid)) {
            res = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    if (res > k) return -1;
    return res;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> k;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    vector<int> result(n + 1);

    for (int i = 1; i <= n; ++i) {
        result[i] = solve(a[i]);
    }

    for (int i = 1; i <= n; ++i) {
        cout << result[i] << " ";
    }

    return 0;
}