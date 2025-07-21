#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 2e5 + 5;

int n, m, k;
int a[N];
int sorted_a[N];

// Function to compute the minimum votes needed for candidate i
int compute_min_votes(int idx) {
    int own = a[idx];
    int left = 0, right = k + 1;
    while (left < right) {
        int mid = (left + right) / 2;
        int total_needed = own + mid;

        // Binary search to find how many candidates can have strictly more than total_needed
        int cnt = n - (upper_bound(sorted_a, sorted_a + n, total_needed) - sorted_a);

        if (cnt >= m) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }

    return (left <= k) ? left : -1;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m >> k;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    // Copy and sort the array of current votes
    memcpy(sorted_a, a, sizeof(a));
    sort(sorted_a, sorted_a + n);

    // For each candidate, compute the minimum number of additional votes needed
    for (int i = 0; i < n; ++i) {
        cout << compute_min_votes(i) << " ";
    }
    cout << "\n";

    return 0;
}