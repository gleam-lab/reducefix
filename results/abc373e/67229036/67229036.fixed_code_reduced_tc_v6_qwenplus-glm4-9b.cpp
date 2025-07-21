#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5 + 5;
int n, m, k, sum, a[N], b[N], c[N];

bool canWin(int votes, int rank, int remainingVotes) {
    // Calculate how many votes are required to ensure victory
    int votesNeeded = rank * votes - (sum - rank * votes);
    // If remaining votes are less than or equal to the votes needed,
    // the candidate cannot win.
    if (remainingVotes < votesNeeded) return false;
    // Check if this candidate can still win
    int maxVotesBehind = max(0, sum - rank * votes - remainingVotes);
    if (maxVotesBehind < votesNeeded / rank) return false;
    return true;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m >> k;
    sum = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    // Sort candidates by their votes in descending order
    sort(a + 1, a + n + 1, greater<int>());

    // Iterate over each candidate to determine the minimum votes needed
    for (int i = 1; i <= n; i++) {
        // Find the number of candidates that can potentially win
        int rank = upper_bound(a + 1, a + n + 1, a[i]) - (a + 1) - 1;
        // If the current candidate is already in the top m candidates,
        // they can win without additional votes.
        if (rank < m) {
            cout << 0 << " ";
        } else {
            // Calculate the minimum votes needed to ensure victory
            int votes = a[i];
            int remainingVotes = k - sum;
            // Binary search to find the minimum number of additional votes
            int low = 0, high = remainingVotes + 1;
            while (low < high) {
                int mid = (low + high) / 2;
                if (canWin(votes + mid, rank + 1, remainingVotes - mid)) {
                    high = mid;
                } else {
                    low = mid + 1;
                }
            }
            cout << low << " ";
        }
    }
    return 0;
}