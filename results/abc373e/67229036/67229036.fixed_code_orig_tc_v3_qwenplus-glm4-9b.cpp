#include <bits/stdc++.h>
using namespace std;
#define INT_MAX 2000000000

int n, m, k;
long long a[200005], b[200005], c[200005];

bool can_win(int x, int i) {
    long long votes_needed = a[i] + x;
    long long total_votes = votes_needed;
    long long votes_excess = 0;

    // Count how many candidates can have more votes than i in the worst case
    for (int j = 0; j < n; ++j) {
        if (j != i) {
            long long votes_for_j = a[j] + (j < i ? x : 0);
            if (votes_for_j > votes_needed) {
                total_votes += votes_for_j - votes_needed;
                votes_excess++;
            }
        }
    }

    // If the excess votes are less than or equal to the remaining votes, i can win
    return votes_excess <= (m - 1) && total_votes <= k;
}

int main() {
    cin >> n >> m >> k;
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    for (int i = 0; i < n; ++i)
        b[i] = a[i];

    for (int i = 0; i < n; ++i)
        c[i] = c[i - 1] + b[i];

    for (int i = 0; i < n; ++i) {
        int l = 0, r = k + 1;
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (can_win(mid, i)) {
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
    return 0;
}