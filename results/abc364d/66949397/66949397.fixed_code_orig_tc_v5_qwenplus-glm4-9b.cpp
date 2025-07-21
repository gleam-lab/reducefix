#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, q;
    cin >> n >> q;

    vector<int> a(n);
    vector<pair<int, int>> b(q);

    // Read all A points
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    // Read all B points and k values
    for (int i = 0; i < q; ++i) {
        cin >> b[i].first >> b[i].second;
    }

    // Process each B point
    for (auto &bb : b) {
        // Calculate distances from B to each point in A
        vector<int> distances;
        for (int i = 0; i < n; ++i) {
            distances.push_back(abs(a[i] - bb.first));
        }

        // Sort distances and find the k-th closest
        sort(distances.begin(), distances.end());

        // Output the k-th smallest distance
        cout << distances[bb.second - 1] << '\n';
    }
}