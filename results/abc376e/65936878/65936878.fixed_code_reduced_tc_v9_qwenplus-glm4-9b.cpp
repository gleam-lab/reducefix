#include <bits/stdc++.h>
#define int long long
using namespace std;

int solve(int n, int k, vector<int>& a, vector<int>& b) {
    // Pair elements of A and B and sort by A in descending order
    vector<pair<int, int>> p(n);
    for (int i = 0; i < n; i++) {
        p[i] = {a[i], b[i]};
    }
    sort(p.begin(), p.end(), [](const pair<int, int>& p1, const pair<int, int>& p2) {
        return p1.first > p2.first;
    });

    // Initialize variables to store the sum of B_i and the maximum A_i for the first k elements
    int sumB = 0, maxA = p[0].first;
    for (int i = 0; i < k; i++) {
        sumB += p[i].second;
    }

    // Initialize the answer with the product of the maximum A_i and the sum of B_i for the first k elements
    int ans = maxA * sumB;

    // Try to find a better combination by swapping elements from k to n-1 for the maximum A_i
    for (int i = k; i < n; i++) {
        // Calculate the new sum of B_i if we choose p[i]
        int newSumB = sumB - p[k - 1].second + p[i].second;
        // Calculate the new maximum A_i, which will be the maximum between the current maxA and p[i].first
        int newMaxA = max(maxA, p[i].first);
        // Update the answer if the new product is smaller
        ans = min(ans, newMaxA * newSumB);
        // Move the k-th element to the position i (swap in descending order)
        p[k - 1] = p[i];
        k++;
    }

    return ans;
}

int32_t main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n), b(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < n; i++) cin >> b[i];
        cout << solve(n, k, a, b) << '\n';
    }
    return 0;
}