#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 2e5 + 5;

int n, m, k;
int a[N];
int sorted_votes[N];
int prefix[N];

// Check if candidate i with x added votes can be guaranteed to win
bool can_win(int i, int x) {
    // Create a copy of original array
    for (int j = 0; j < n; ++j)
        sorted_votes[j] = a[j];

    // Add x votes to the current candidate
    sorted_votes[i] += x;

    // Sort the array to determine rankings
    sort(sorted_votes, sorted_votes + n);

    // Count how many candidates have strictly more votes
    int count = 0;
    for (int j = n - 1; j >= 0; --j) {
        if (count >= m) break;
        if (sorted_votes[j] > a[i] + x) {
            count++;
        }
    }

    // Candidate i wins if less than M candidates have more votes
    return count < m;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> k;
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    vector<int> res(n, -1);

    // Pre-sort the votes for reference
    vector<int> b(a, a + n);
    sort(b.begin(), b.end());

    // Build prefix sum of sorted votes
    vector<int> prefix(n + 1);
    for (int i = 1; i <= n; ++i)
        prefix[i] = prefix[i - 1] + b[i - 1];

    // For each candidate, perform binary search
    for (int i = 0; i < n; ++i) {
        int lo = 0, hi = k, ans = -1;
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            if (can_win(i, mid)) {
                ans = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        if (ans <= k)
            res[i] = ans;
        else
            res[i] = -1;
    }

    for (int i = 0; i < n; ++i)
        cout << res[i] << " ";
    cout << "\n";

    return 0;
}