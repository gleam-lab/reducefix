#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
int n, m, k, sum, cnt, a[N], b[N], c[N];

// Function to check if a candidate can win with x additional votes
bool check(int i, int x) {
    int current_votes = a[i] + x;
    int remaining_candidates = n - i;
    int required_wins = min(remaining_candidates, m);

    // Calculate the maximum votes the top 'required_wins' candidates can get
    int max_votes_by_top_winners = 0;
    for (int j = 1; j <= required_wins; ++j) {
        max_votes_by_top_winners += b[j];
    }

    // Calculate the votes needed to surpass the top 'required_wins' candidates
    int votes_needed_to_surpass = max_votes_by_top_winners - current_votes + 1;

    return votes_needed_to_surpass <= k;
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int i, j, x, y, z, t;
    cin >> n >> m >> k;
    
    for (i = 1; i <= n; ++i) {
        cin >> a[i];
        k -= a[i];
        b[i] = a[i];
    }
    
    sort(b + 1, b + n + 1);
    for (i = 1; i <= n; ++i) {
        c[i] = c[i - 1] + b[i];
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