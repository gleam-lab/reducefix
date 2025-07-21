#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define int long long
#define endl '\n'

const int MAXN = 1e5 + 9;
int n, q;
vector<int> a, b, k_values;

void precompute() {
    // Precompute all possible distances from each point in A to each point in B
    vector<vector<int>> distances(n + 1, vector<int>(q + 1, INT_MAX));
    
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < q; ++j) {
            distances[i][j] = abs(a[i] - b[j]);
        }
    }
    
    // Sort distances for each point in B
    for (int j = 0; j < q; ++j) {
        sort(distances[1].begin(), distances[1].end());
    }
}

int query(int pos, int k) {
    // Return the k-th smallest distance for point B[pos]
    return k_values[pos] == 0 ? distances[1][k - 1] : distances[k_values[pos]][k - 1];
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n >> q;
    a.resize(n + 1);
    b.resize(q);
    k_values.resize(q);
    
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    
    for (int j = 0; j < q; ++j) {
        cin >> b[j] >> k_values[j];
    }
    
    precompute();
    
    for (int j = 0; j < q; ++j) {
        cout << query(j + 1, k_values[j]) << endl;
    }
    
    return 0;
}