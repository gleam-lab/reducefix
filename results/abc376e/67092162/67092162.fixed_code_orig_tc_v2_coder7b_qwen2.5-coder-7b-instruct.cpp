#include <bits/stdc++.h>
using namespace std;
const int maxN = 2e5 + 5;
int t, n, k, a[maxN], b[maxN];
pair<int, int> p[maxN];

// Comparator function to sort pairs based on the ratio of first element to second
bool cmp(pair<int, int> p1, pair<int, int> p2) {
    double r1 = (double)p1.first / p1.second;
    double r2 = (double)p2.first / p2.second;
    if (r1 != r2) return r1 > r2; // Sort in descending order of ratios
    else return p1.first > p2.first; // If ratios are equal, sort by first element in descending order
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> t;
    while (t--) {
        cin >> n >> k;
        vector<pair<int, int>> v(n); // Using vector instead of array for easier manipulation
        for (int i = 0; i < n; ++i) cin >> a[i], v[i].first = a[i]; // Store A values and their indices
        for (int i = 0; i < n; ++i) cin >> b[i], v[i].second = b[i]; // Store B values and their indices

        sort(v.begin(), v.end(), cmp); // Sort based on the custom comparator

        long long sum = 0, ans = LLONG_MAX; // Initialize sum and answer with appropriate types
        for (int i = 0; i < k; ++i) {
            sum += v[i].second; // Sum up the B values for the first k elements
        }

        for (int i = 0; i <= n - k; ++i) { // Iterate through the sorted list to find the best subset
            ans = min(ans, static_cast<long long>(v[i].first * sum)); // Update answer with the minimum product found
            if (i + k < n) { // Check if there are enough elements left to replace the current one
                sum -= v[i].second; // Remove the smallest B value added previously
                sum += v[i + k].second; // Add the next largest B value
            }
        }

        cout << ans << '\n'; // Print the final result
    }

    return 0;
}