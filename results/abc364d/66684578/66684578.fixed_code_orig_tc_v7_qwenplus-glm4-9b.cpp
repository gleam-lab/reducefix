#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n), b(q);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    for (int i = 0; i < q; ++i) {
        cin >> b[i] >> a[i];
    }

    vector<vector<pair<int, int>>> distances(n + 1);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < q; ++j) {
            distances[i].push_back({abs(a[i] - b[j]), j});
        }
    }

    for (int i = 0; i < q; ++i) {
        // Sort distances for each B_j
        sort(distances[i].begin(), distances[i].end());
        // Find the k-th closest point
        int k = a[i] - 1; // Subtract 1 because of 0-based index
        if (distances[i][k].first == 0) {
            cout << 0 << endl;
        } else {
            cout << distances[i][k].first << endl;
        }
    }

    return 0;
}