#include <bits/stdc++.h>
using namespace std;

const int maxN = 2e5 + 5;
long long t, n, k, a[maxN], b[maxN];

// Custom comparator for sorting pairs based on ratio (A[i] / B[i])
struct compare {
    bool operator()(const pair<long long, long long>& p1, const pair<long long, long long>& p2) {
        double r1 = static_cast<double>(p1.first) / p1.second;
        double r2 = static_cast<double>(p2.first) / p2.second;
        if (r1 == r2) return p1.second > p2.second; // Break ties by B[i]
        return r1 < r2;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> t;
    while (t--) {
        cin >> n >> k;
        vector<pair<long long, long long>> v(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        for (int i = 0; i < n; ++i) {
            cin >> b[i];
            v[i] = {a[i], b[i]};
        }

        // Sort based on the custom comparator
        sort(v.begin(), v.end(), compare());

        long long maxA = 0, sumB = 0;
        priority_queue<long long, vector<long long>, greater<long long>> pq;

        // Select the top K elements
        for (int i = 0; i < k; ++i) {
            maxA = max(maxA, v[i].first);
            sumB += v[i].second;
            pq.push(v[i].second);
        }

        // Calculate the initial result
        long long result = maxA * sumB;

        // Try to replace elements to potentially get a smaller result
        for (int i = k; i < n; ++i) {
            if (v[i].second <= pq.top()) continue; // Already smaller or equal, no improvement
            sumB -= pq.top(); // Remove the smallest element from the sum
            pq.pop();
            sumB += v[i].second; // Add the new element to the sum
            pq.push(v[i].second); // Push the new element into the priority queue
            maxA = max(maxA, v[i].first); // Update the maximum A value
            result = min(result, maxA * sumB); // Recalculate the result
        }

        cout << result << "\n";
    }

    return 0;
}