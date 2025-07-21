#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, q;
    cin >> n >> q;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<pair<int, int>> queries(q);
    for (int i = 0; i < q; ++i) {
        int x, k;
        cin >> x >> k;
        queries[i] = {x, k};
    }

    // Store all distances
    vector<int> distances;
    for (int i = 0; i < n; ++i) {
        for (auto& [x, k] : queries) {
            distances.push_back(abs(a[i] - x));
        }
    }

    // Sort all distances
    sort(distances.begin(), distances.end());

    // Answer each query
    for (auto& [x, k] : queries) {
        int kth_smallest_distance = distances[(k - 1) * n];
        cout << kth_smallest_distance << endl;
    }

    return 0;
}