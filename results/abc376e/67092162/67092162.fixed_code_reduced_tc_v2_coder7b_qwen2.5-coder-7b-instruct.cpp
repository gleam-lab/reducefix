#include <bits/stdc++.h>
using namespace std;

const int maxN = 2e5 + 5;
int t, n, k, a[maxN], b[maxN];

// Comparator function to sort pairs based on the ratio of first to second element
bool cmp(pair<int, int> p1, pair<int, int> p2) {
    double r1 = static_cast<double>(p1.first) / p1.second;
    double r2 = static_cast<double>(p2.first) / p2.second;
    return r1 > r2; // We want the maximum ratio first
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;
    while (t--) {
        cin >> n >> k;
        vector<pair<int, int>> v(n);
        
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            v[i] = {a[i], b[i]};
        }

        // Sort the vector based on the custom comparator
        sort(v.begin(), v.end(), cmp);

        long long sum = 0, ans = LLONG_MAX;
        priority_queue<int> pq;

        // Initialize the sum and min-heap with the first K elements
        for (int i = 0; i < k; ++i) {
            sum += v[i].second;
            pq.push(-v[i].second); // Using negative values to simulate min-heap using max-heap
        }

        // Calculate the initial answer
        ans = static_cast<long long>(v[k - 1].first) * sum;

        // Iterate through the remaining elements
        for (int i = k; i < n; ++i) {
            // If the current element's second value is smaller than the largest value in the heap
            if (-pq.top() > v[i].second) {
                sum -= pq.top(); // Remove the largest value from the sum
                pq.pop();       // Remove the largest value from the heap
                sum += v[i].second; // Add the new smallest value to the sum
                pq.push(-v[i].second); // Add the new smallest value to the heap
            }
            // Update the answer
            ans = min(ans, static_cast<long long>(v[i].first) * sum);
        }

        cout << ans << "\n";
    }

    return 0;
}