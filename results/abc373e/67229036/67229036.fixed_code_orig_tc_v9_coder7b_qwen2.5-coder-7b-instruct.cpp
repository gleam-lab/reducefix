#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
int n, m, k, sum, c[N], b[N];

// Function to check if candidate i can win with X additional votes
bool check(int i, int X) {
    vector<int> votes(n);
    copy(c, c + n, votes.begin());
    votes[i] += X;
    sort(votes.begin(), votes.end(), greater<int>());
    
    // Check if candidate i can win
    return votes[0] > accumulate(votes.begin() + 1, votes.begin() + M, 0LL);
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int i, j, x, y, z, t;
    cin >> n >> m >> k;
    for (i = 0; i < n; ++i) {
        cin >> c[i];
        k -= c[i];
        b[i] = c[i];
    }
    sort(b, b + n);
    for (i = 0; i < n; ++i)
        c[i] = c[i] + b[i];
    
    vector<int> ans(n, 0);
    for (i = 0; i < n; ++i) {
        int lo = 0, hi = k + 1;
        while (lo < hi) {
            int mid = (lo + hi) / 2;
            if (check(i, mid))
                hi = mid;
            else
                lo = mid + 1;
        }
        if (lo <= k)
            ans[i] = lo;
        else
            ans[i] = -1;
    }
    
    for (i = 0; i < n; ++i)
        cout << ans[i] << " ";
    cout << endl;
    return 0;
}