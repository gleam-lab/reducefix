#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 2e5 + 5;
int n, m, k;
int a[N], b[N], prefix[N];

// Check if candidate i with x votes added can be elected
bool check(int i, int x) {
    int total_used = 0;
    // Assign initial votes: candidate i gets x extra
    int my_votes = a[i] + x;

    // Try to assign up to x votes to other candidates to maximize those above me
    // We pick top (n - M) candidates who can get boosted to be >= my_votes

    // Binary search the first index where b[j] >= my_votes
    int low = 0, high = n, pos = n;
    while (low < high) {
        int mid = (low + high) / 2;
        if (b[mid] >= my_votes)
            high = mid;
        else
            low = mid + 1;
    }
    pos = low;

    // Now we try to increase (n - M) other candidates to at least my_votes
    int needed = max(0LL, (n - m) - (n - pos));
    int left = x;

    // Greedily boost top (n - M) candidates to just exceed or equal my_votes
    for (int j = 0; j < needed; ++j) {
        int idx = n - 1 - j;
        if (idx >= pos) continue;
        int delta = my_votes - b[idx];
        if (delta > 0) {
            if (left < delta) return false;
            left -= delta;
        }
    }

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

    // Copy and sort original array
    for (int i = 0; i < n; ++i)
        b[i] = a[i];
    sort(b, b + n);

    // Compute prefix sums
    prefix[0] = 0;
    for (int i = 1; i <= n; ++i)
        prefix[i] = prefix[i - 1] + b[i - 1];

    // For each candidate, binary search on minimum required additional votes
    for (int i = 0; i < n; ++i) {
        int lo = 0, hi = k + 1, ans = -1;
        while (lo < hi) {
            int mid = (lo + hi) / 2;
            if (check(i, mid)) {
                ans = mid;
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }

        // Output result
        if (ans <= k)
            cout << ans << " ";
        else
            cout << "-1 ";
    }

    return 0;
}