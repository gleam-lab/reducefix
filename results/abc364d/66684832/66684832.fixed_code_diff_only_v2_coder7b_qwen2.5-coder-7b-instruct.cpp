#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7, inf = 0x3f3f3f3f3f3f3f3f;

vector<int> a, b;
vector<pair<int, int>> queries;

// Function to calculate the minimum distance of the kth nearest point
int min_distance(int x, int k) {
    auto it = lower_bound(begin(b), end(b), x); // Find the first point greater than or equal to x
    if (it != begin(b))
        --it; // Move one step back to consider the previous point
    int left = 0, right = b.size() - 1;
    while (left < right) { // Binary search to find the kth nearest point
        int mid = (left + right) / 2;
        if ((x - b[mid]) * (x - b[mid]) <= (b[(mid + 1) % b.size()] - x) * (b[(mid + 1) % b.size()] - x))
            right = mid;
        else
            left = mid + 1;
    }
    return abs(b[left] - x); // Return the minimum distance
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n, q;
    cin >> n >> q;
    a.resize(n + 1);
    b.resize(q);
    queries.resize(q);

    // Read coordinates of points A and distances
    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    // Read coordinates of points B and corresponding indices
    for (int i = 0; i < q; ++i) {
        cin >> b[i] >> queries[i].second;
        queries[i].first = i;
    }

    sort(begin(b), end(b)); // Sort points B to use binary search later

    vector<int> results(q);
    for (auto [index, k] : queries)
        results[index] = min_distance(b[k - 1], k); // Calculate the minimum distance for each query

    // Print all results
    for (int result : results)
        cout << result << '\n';

    return 0;
}