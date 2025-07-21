#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

#define int long long
const int N = 200005;

int n, k;
vector<pair<int, int>> a, b;

int solve() {
    // Create a vector of pairs consisting of (b[i], i) to sort by b[i] first
    vector<pair<int, int>> c(a.size());
    for (int i = 0; i < a.size(); ++i) {
        c[i] = {b[i].first, a[i].second};
    }
    
    // Sort c based on the first element of the pair (b[i])
    sort(c.begin(), c.end());

    // Priority queue to keep track of the sum of the K smallest b[i]
    priority_queue<int, vector<int>, greater<int>> pq;

    long long sum_b = 0; // To keep track of the sum of b[i] of the current K elements
    long long max_a = 0; // To keep track of the maximum a[i] for the current K elements
    long long result = LLONG_MAX; // To keep track of the minimum result

    // Iterate over the sorted vector c
    for (int i = 0; i < a.size(); ++i) {
        // Add the current b[i] to the sum and to the priority queue
        sum_b += c[i].first;
        pq.push(c[i].first);
        
        // If we have more than K elements, remove the smallest one
        if (pq.size() > k) {
            sum_b -= pq.top();
            pq.pop();
        }

        // If we have exactly K elements, calculate the result
        if (pq.size() == k) {
            max_a = max(max_a, a[c[i].second].first);
            result = min(result, max_a * sum_b);
        }
    }

    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--) {
        cin >> n >> k;
        a.assign(n, {0, 0});
        b.assign(n, {0, 0});

        for (int i = 0; i < n; ++i) {
            cin >> a[i].first;
            a[i].second = i;
        }
        for (int i = 0; i < n; ++i) {
            cin >> b[i].first;
            b[i].second = i;
        }

        // Sort a by the first element so that we can access the maximum a[i] for the current K elements
        sort(a.begin(), a.end());

        cout << solve() << '\n';
    }

    return 0;
}