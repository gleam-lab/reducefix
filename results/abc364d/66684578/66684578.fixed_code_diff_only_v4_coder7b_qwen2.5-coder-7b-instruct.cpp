#include <bits/stdc++.h>
using namespace std;

const int MAX = 2e8 + 10;
const int INF = 1e9;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    vector<int> a(n), b(q), k(q);
    vector<long long> dists(n * q);

    // Read coordinates of points A and distances
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        for (int j = 0; j < q; ++j) {
            dists[i * q + j] = abs(a[i] - b[j]);
        }
    }

    // Read coordinates of points B and their corresponding k values
    for (int j = 0; j < q; ++j) {
        cin >> b[j] >> k[j];
    }

    // Sort all distances
    sort(dists.begin(), dists.end());

    // Process each query
    for (int j = 0; j < q; ++j) {
        cout << dists[(k[j] - 1) * n + j] << '\n';
    }

    return 0;
}