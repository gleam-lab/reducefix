#include <bits/stdc++.h>
using namespace std;

#define int long long
const int N = 2e5 + 5;

int n, m, k, sum, cnt, a[N], b[N], c[N];

// Function to check if candidate i can secure victory with x additional votes
bool check(int i, int x) {
    int total_votes = a[i] + x;
    int remaining_candidates = n - m;
    
    // Calculate the maximum votes any other candidate can get
    int max_votes_others = 0;
    for (int j = 1; j <= n; ++j) {
        if (j != i) {
            max_votes_others = max(max_votes_others, a[j]);
        }
    }

    // Check if the current candidate can still win after accounting for max_votes_others
    return total_votes > max_votes_others + remaining_candidates;
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int i, j, x, y, z, t;
    cin >> n >> m >> k;
    
    for (i = 1; i <= n; ++i) {
        cin >> a[i];
        k -= a[i];
    }
    
    sort(a + 1, a + n + 1);
    
    // Calculate prefix sums
    for (i = 1; i <= n; ++i) {
        c[i] = c[i - 1] + a[i];
    }

    for (i = 1; i <= n; ++i) {
        if (check(i, 0)) {
            cout << "0 ";
        } else {
            int l = 0, r = k + 1;
            while (l < r) {
                int mid = (l + r) / 2;
                if (check(i, mid)) {
                    r = mid;
                } else {
                    l = mid + 1;
                }
            }
            if (l <= k) {
                cout << l << " ";
            } else {
                cout << "-1 ";
            }
        }
    }

    return 0;
}