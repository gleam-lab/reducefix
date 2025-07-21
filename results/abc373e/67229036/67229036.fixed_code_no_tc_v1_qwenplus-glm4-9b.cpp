#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5 + 5;
int n, m, k, sum, cnt, a[N], b[N], c[N];
int ans[N];

bool canWin(int i, int votes) {
    // Calculate the number of votes needed to ensure candidate i wins
    return votes + a[i] >= c[n - m] + m;
}

bool canLose(int i, int votes) {
    // Calculate the number of votes needed for candidate i to lose
    return votes + a[i] < c[n - m - 1] - (n - m + 1 - i);
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // Sort candidates by their current votes in descending order
    sort(a, a + n, greater<int>());

    // Calculate prefix sums of sorted votes
    for (int i = 0; i < n; i++) {
        c[i] = (i == 0 ? 0 : c[i - 1]) + a[i];
    }

    // Calculate the total votes needed to guarantee a win for each candidate
    for (int i = 0; i < n; i++) {
        // Check if the candidate already wins
        if (canWin(i, 0)) {
            ans[i] = 0;
        } else {
            // Binary search to find the minimum votes needed to guarantee a win
            int lo = 0, hi = k + 1;
            while (hi - lo > 1) {
                int mid = (lo + hi) / 2;
                if (canWin(i, mid)) {
                    hi = mid;
                } else {
                    lo = mid;
                }
            }
            // Check if the candidate can win with `hi` additional votes
            if (canLose(i, hi)) {
                ans[i] = hi;
            } else {
                ans[i] = -1;
            }
        }
    }

    // Output the results
    for (int i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}