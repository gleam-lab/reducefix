#include <bits/stdc++.h>
using namespace std;

const int maxN = 2e5 + 5;
int t, n, k, a[maxN], b[maxN];

// Custom comparator for sorting pairs based on a descending order of first element and ascending order of second element
bool cmp(const pair<int, int>& p1, const pair<int, int>& p2) {
    if (p1.first != p2.first) return p1.first > p2.first;
    return p1.second < p2.second;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;
    while (t--) {
        cin >> n >> k;
        
        // Store pairs of (a[i], b[i])
        vector<pair<int, int>> p(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i] >> b[i];
            p[i] = {a[i], b[i]};
        }

        // Sort pairs based on the custom comparator
        sort(p.begin(), p.end(), cmp);

        // Initialize variables to keep track of the sum and the maximum value in A
        long long sum = 0;
        int maxA = 0;

        // Select the first K elements from the sorted array
        for (int i = 0; i < k; ++i) {
            sum += p[i].second;
            maxA = max(maxA, p[i].first);
        }

        // Calculate the initial result
        long long ans = maxA * sum;

        // Iterate through the remaining elements to find the minimum possible value
        for (int i = k; i < n; ++i) {
            if (p[i].second > p[i - k].second) {
                sum -= p[i - k].second;
                sum += p[i].second;
                maxA = max(maxA, p[i].first);
                ans = min(ans, maxA * sum);
            }
        }

        // Output the result for the current test case
        cout << ans << "\n";
    }

    return 0;
}