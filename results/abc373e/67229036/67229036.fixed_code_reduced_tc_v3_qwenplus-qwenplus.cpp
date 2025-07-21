#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 2 * 100000 + 5;

int n, m, k;
int a[N];
int sorted_votes[N];
int prefix_sum[N];

// This function checks if candidate i can be guaranteed to win
// when we add 'x' votes to their current total of 'a_i'
bool is_possible(int idx, int x) {
    int remaining = k;
    int my_total = a[idx] + x;

    // We need to determine how many candidates can get more votes than my_total
    // and still allow candidate i to be elected.

    // Binary search for the number of candidates that have > my_total votes already
    int left = 1, right = n;
    int pos = n; // Position where values > my_total start
    while (left <= right) {
        int mid = (left + right) / 2;
        if (sorted_votes[mid] > my_total)
            pos = mid, right = mid - 1;
        else
            left = mid + 1;
    }

    // Number of candidates with votes > my_total
    int cnt = n - pos + 1;

    // If fewer than M candidates can have more than me, I'm safe
    if (cnt <= m - 1)
        return true;

    // Need to raise my score so that at most M-1 candidates can surpass me
    // So we need to block the top (cnt - (M-1)) candidates from beating me

    // We need to raise my score to beat the (pos + M - 1)-th candidate
    int needed_pos = pos + (cnt - (m - 1));
    if (needed_pos > n)
        return true;

    int target = sorted_votes[needed_pos];

    // Now calculate how many extra votes are needed to reach at least target
    if (my_total >= target)
        return true;

    // Total additional votes required to reach target
    int required_votes = target - my_total;

    // Check if we can afford this many votes
    if (required_votes > remaining)
        return false;

    return true;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> k;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    // Sort the array to get sorted_votes
    copy(a + 1, a + n + 1, sorted_votes + 1);
    sort(sorted_votes + 1, sorted_votes + n + 1);

    for (int i = 1; i <= n; ++i) {
        prefix_sum[i] = prefix_sum[i - 1] + sorted_votes[i];
    }

    vector<int> result(n + 1);

    for (int i = 1; i <= n; ++i) {
        int low = 0, high = k + 1;
        while (low < high) {
            int mid = (low + high) / 2;
            if (is_possible(i, mid))
                high = mid;
            else
                low = mid + 1;
        }

        if (low <= k)
            result[i] = low;
        else
            result[i] = -1;
    }

    for (int i = 1; i <= n; ++i)
        cout << result[i] << " ";

    return 0;
}