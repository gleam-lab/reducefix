#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 2e5 + 5;

int n, m, k;
int a[N], sorted_a[N], prefix_sum[N];

// Check if candidate with current votes x and needing X more votes can guarantee victory
// given that other candidates have votes stored in sorted_a
bool is_victory_guaranteed(int x, int X) {
    int total_remaining = k;
    int new_vote = x + X;

    // We need to allow for the worst-case scenario where as many candidates as possible
    // get more than our candidate, but still ensure less than M candidates beat us.

    // We want at most M-1 candidates to have strictly more than new_vote.
    // So we check how many candidates already have > new_vote.
    // Then determine how many of the remaining can be allocated to others without exceeding new_vote.

    // Use binary search to find how many candidates currently have > new_vote
    int cnt = upper_bound(sorted_a + 1, sorted_a + n + 1, new_vote - 1, greater<int>()) - (sorted_a + 1);

    if (cnt < m) return true; // Already good

    // If there are more than or equal to m candidates already above us, we need to block some
    // Let's consider top `m` candidates. We want to raise our score so that at most m-1 remain above.

    // Find number of candidates that must be limited to <= new_vote
    int need_to_limit = cnt - (m - 1);
    if (need_to_limit <= 0) return true;

    // Now calculate how many votes needed to cap these top 'need_to_limit' candidates to <= new_vote
    // We sort all votes descending, and try to make sure only (m-1) stay above new_vote

    // Binary search on position where we start capping
    int low = 1, high = n, ans = n + 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (sorted_a[mid] > new_vote)
            low = mid + 1;
        else {
            ans = mid;
            high = mid - 1;
        }
    }

    // ans is first index where vote <= new_vote
    // So number of candidates > new_vote is ans - 1
    int over = ans - 1;
    if (over <= m - 1) return true;

    // Need to reduce (over - (m - 1)) such candidates by distributing remaining votes
    int extra_needed = 0;
    for (int i = 1; i <= over - (m - 1); ++i) {
        int excess = sorted_a[i] - new_vote;
        extra_needed += excess;
    }

    return extra_needed <= total_remaining - X;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m >> k;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    // Sort a copy for binary searches
    copy(a + 1, a + n + 1, sorted_a + 1);
    sort(sorted_a + 1, sorted_a + n + 1, greater<int>());

    for (int i = 1; i <= n; ++i) {
        prefix_sum[i] = prefix_sum[i - 1] + sorted_a[i];
    }

    for (int i = 1; i <= n; ++i) {
        int left = 0, right = k + 1;
        while (left < right) {
            int mid = (left + right) / 2;
            if (is_victory_guaranteed(a[i], mid))
                right = mid;
            else
                left = mid + 1;
        }

        if (left <= k)
            cout << left << " ";
        else
            cout << "-1 ";
    }

    return 0;
}