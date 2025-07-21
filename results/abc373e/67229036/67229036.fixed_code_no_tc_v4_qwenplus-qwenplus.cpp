#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 2 * 100000 + 5;

int n, m, k;
int a[N], sorted_votes[N];

// Binary search to determine minimum votes needed for candidate i to win
int compute_min_votes(int idx) {
    int low = 0;
    int high = k + 1;
    
    // current candidate's current votes
    int base = a[idx];
    
    while (low < high) {
        int mid = (low + high) / 2;
        int required = base + mid;
        
        // We want to count how many candidates can get more than `required`
        // Use binary search on sorted list of votes
        int cnt = n - (lower_bound(sorted_votes + 1, sorted_votes + n + 1, required) - (sorted_votes + 1));
        
        if (cnt < m) {
            high = mid;
        } else {
            low = mid + 1;
        }
    }

    return low <= k ? low : -1;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m >> k;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        k -= a[i];
    }

    // Copy votes and sort them
    for (int i = 1; i <= n; ++i) {
        sorted_votes[i] = a[i];
    }
    sort(sorted_votes + 1, sorted_votes + n + 1);

    // For each candidate, compute the answer
    for (int i = 1; i <= n; ++i) {
        int res = compute_min_votes(i);
        if (res == -1) {
            cout << "-1 ";
        } else {
            cout << res << " ";
        }
    }

    return 0;
}