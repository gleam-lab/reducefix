#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2 * 100005;

int n, q;
int a[MAXN], b[MAXN];
int k[MAXN];

void preprocess() {
    // Read input
    cin >> n >> q;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < q; ++i) {
        cin >> b[i] >> k[i];
    }

    // Calculate distances and sort them
    vector<pair<int, int>> distances;
    for (int i = 0; i < n; ++i) {
        distances.push_back({abs(a[i] - b[0]), i});
    }
    sort(distances.begin(), distances.end());

    // Store the sorted indices
    vector<int> sorted_indices(n);
    for (int i = 0; i < n; ++i) {
        sorted_indices[i] = distances[i].second;
    }

    // Process each query
    for (int i = 0; i < q; ++i) {
        cout << abs(a[sorted_indices[k[i] - 1]] - b[i]) << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    preprocess();

    return 0;
}