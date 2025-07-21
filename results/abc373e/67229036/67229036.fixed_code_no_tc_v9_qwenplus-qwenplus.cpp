#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 2e5 + 5;

int n, m, k;
int a[N], sorted_a[N];

// Binary search to find minimum additional votes needed for candidate i to be elected
int solve_for_candidate(int base) {
    int l = 0, r = k;
    int ans = -1;

    while (l <= r) {
        int mid = (l + r) / 2;
        int total = base + mid;
        
        // We want at most M-1 candidates to have more than 'total' votes
        // So we need to bound the number of candidates that can get >total votes
        
        // Use binary search to find how many candidates currently have >total
        // Then simulate giving remaining votes to top candidates to surpass 'total'
        
        int cnt = 0;
        int remaining = k - mid;  // Remaining votes after giving mid to current candidate
        
        // We want to count how many candidates can potentially exceed our candidate's total
        // Try to allocate as many votes as possible to the strongest competitors
        // That is, start from the largest values and try to increase them above 'total'

        // Use prefix sums on sorted array
        int* pos = upper_bound(sorted_a + 1, sorted_a + n + 1, total, greater<int>());
        int idx = pos - sorted_a;

        // idx is the first position where value <= total in descending order
        // So there are (idx - 1) candidates with >total initially

        if (idx - 1 < m) {
            // Already good, not enough candidates ahead
            ans = mid;
            r = mid - 1;
            continue;
        }

        // Need to prevent at least (idx - 1 - (m - 1)) = (idx - m) candidates from getting >total
        int need_to_block = idx - m;
        int excess_votes = 0;

        // For the first (idx) candidates (i.e., those who may exceed total), calculate how much needed to bring them to total+1
        for (int i = 1; i <= idx; ++i) {
            int diff = sorted_a[i] - total;
            if (diff > 0) {
                excess_votes += diff;
            }
        }

        if (excess_votes <= remaining) {
            // Can block enough candidates from exceeding us
            ans = mid;
            r = mid - 1;
        } else {
            // Not enough votes to block
            l = mid + 1;
        }
    }

    return ans;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> k;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    // Sort a copy of the array in descending order
    memcpy(sorted_a, a, sizeof(a));
    sort(sorted_a + 1, sorted_a + n + 1, greater<int>);

    // Compute prefix sum
    int prefix[N];
    prefix[0] = 0;
    for (int i = 1; i <= n; ++i) {
        prefix[i] = prefix[i - 1] + sorted_a[i];
    }

    // Solve for each candidate
    for (int i = 1; i <= n; ++i) {
        int res = solve_for_candidate(a[i]);
        cout << res << " ";
    }

    return 0;
}