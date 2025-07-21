#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 2e5 + 5;

int n, m, k, a[N], sorted_a[N];

// Function to compute the minimum additional votes needed for candidate at index i
int compute_min_votes(int idx, int total_remaining) {
    int left = 0, right = total_remaining + 1;
    
    while (left < right) {
        int mid = (left + right) / 2;
        
        // Candidate i gets mid more votes
        int curr_vote = a[idx] + mid;
        
        // We want to find how many candidates can get strictly more than curr_vote
        // Using binary search on sorted_a
        int* ptr = upper_bound(sorted_a + 1, sorted_a + n + 1, curr_vote);
        int num_strictly_more = n - (ptr - sorted_a - 1);
        
        // Exclude current candidate if they are in the list
        if (a[idx] + mid == *ptr && ptr != sorted_a + n + 1)
            num_strictly_more--;

        // To guarantee election, at most M-1 candidates can have more votes
        if (num_strictly_more <= m - 1)
            right = mid;
        else
            left = mid + 1;
    }

    return (left <= total_remaining) ? left : -1;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> k;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        k -= a[i];
    }

    // Sort a copy for binary searching
    memcpy(sorted_a + 1, a, n * sizeof(a[0]));
    sort(sorted_a + 1, sorted_a + n + 1);

    // Compute result for each candidate
    vector<int> result(n);
    for (int i = 0; i < n; ++i) {
        int res = compute_min_votes(i, k);
        result[i] = (res == -1 ? -1 : res);
    }

    // Print results
    for (int i = 0; i < n; ++i)
        cout << result[i] << " ";
    cout << "\n";

    return 0;
}