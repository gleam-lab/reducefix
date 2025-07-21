#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX_N = 200005; // Slightly larger than 10^5 to handle any offset

int main() {
    int n, q;
    cin >> n >> q;
    vector<int> a(MAX_N);
    vector<pair<int, int>> queries;

    // Reading point A coordinates and filling the array
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a[(x + MAX_N / 2) % MAX_N]++;
    }

    // Preprocess the array to get the prefix sums
    for (int i = 1; i < MAX_N; i++) {
        a[i] += a[i - 1];
    }

    // Reading queries and storing them
    for (int i = 0; i < q; i++) {
        int x, k;
        cin >> x >> k;
        queries.push_back({x, k});
    }

    // Sorting queries by B_j values
    sort(queries.begin(), queries.end());

    // Answering each query
    for (auto &query : queries) {
        int x = query.first;
        int k = query.second;
        // Binary search for the k-th smallest distance
        int l = 0, r = MAX_N;
        while (r - l > 1) {
            int mid = (l + r) / 2;
            int count = upper_bound(a.begin(), a.begin() + mid, (x + MAX_N / 2) % MAX_N) - a.begin();
            if (count >= k) {
                r = mid;
            } else {
                l = mid;
            }
        }
        // Calculate the distance
        cout << abs(r - x) * MAX_N << endl;
    }

    return 0;
}