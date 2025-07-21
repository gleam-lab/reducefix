#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5 + 5;

int n, m, k, sum, a[N], b[N], c[N];

// Check if candidate i can secure victory with x additional votes
bool canSecureVictory(int i, int x) {
    int totalVotesSoFar = accumulate(a, a + n, 0);
    int votesNeeded = m - 1; // We need more than m votes to win
    if (a[i] + x >= votesNeeded) return true;

    // Calculate how many more votes i needs to be sure of winning
    int votesForOthers = 0;
    for (int j = 0; j < n; ++j) {
        if (j != i) {
            votesForOthers += max(0LL, votesNeeded - a[j]);
        }
    }
    int additionalVotesNeeded = votesForOthers - x;
    return totalVotesSoFar + additionalVotesNeeded <= k;
}

// Main logic to find minimum additional votes for each candidate
signed main() {
    cin >> n >> m >> k;
    for (int i = 0; i < n; ++i) cin >> a[i];

    // b[i] will store the number of votes needed for i to secure victory
    for (int i = 0; i < n; ++i) {
        b[i] = max(0LL, m - 1 - a[i]);
    }

    // Sort b to process in increasing order of votes needed
    sort(b, b + n);

    // Accumulate sorted votes
    for (int i = 0; i < n; ++i) {
        c[i] = (i == 0 ? b[i] : c[i - 1] + b[i]);
    }

    // Find the minimum additional votes for each candidate
    for (int i = 0; i < n; ++i) {
        // Binary search for the minimum x to secure victory
        int low = 0, high = k + 1;
        while (low < high) {
            int mid = (low + high) / 2;
            if (canSecureVictory(i, mid)) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }
        if (low <= k) {
            cout << low << " ";
        } else {
            cout << "-1 ";
        }
    }
    return 0;
}