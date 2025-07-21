#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 2 * 100000 + 5;

int n, m, k;
int a[N];
int sorted_a[N];
int prefix_sum[N];

// Check if candidate with current votes x can guarantee victory with X additional votes
// remaining total votes to distribute is rem = k - used (used is y)
bool is_possible(int x, int X) {
    int rem = k - X;
    if (rem < 0) return false;

    // We want to determine whether candidate i can be in top M positions
    // even if other candidates get as many of the remaining votes as possible
    // We'll binary search on how many candidates can have more votes than us

    // Our total votes
    int total = x + X;

    // We need at least (M-1) candidates who can have >= total votes
    // So we try to find how many candidates can possibly beat us
    // Find first index where sorted_a[i] >= total
    int* ptr = lower_bound(sorted_a, sorted_a + n, total);
    int idx = ptr - sorted_a;

    // Now, we want to pick (m-1) candidates from these `n - idx` candidates
    // that can potentially beat us
    if (n - idx >= m) return false;  // too many candidates can beat us

    // Not enough candidates can beat us => we are in top M
    return true;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m >> k;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        k -= a[i];
    }

    // Create a copy and sort it
    for (int i = 0; i < n; ++i) {
        sorted_a[i] = a[i];
    }
    sort(sorted_a, sorted_a + n);

    // For each candidate, binary search on minimum number of votes needed
    for (int i = 0; i < n; ++i) {
        int left = 0, right = k + 1;
        while (left < right) {
            int mid = (left + right) / 2;
            if (is_possible(a[i], mid)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }

        if (left <= k) {
            cout << left << " ";
        } else {
            cout << -1 << " ";
        }
    }

    return 0;
}