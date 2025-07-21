#include<bits/stdc++.h>
using namespace std;

vector<int> A, B;
vector<vector<int>> distances;

void preprocess() {
    int n = A.size(), m = B.size();
    distances.resize(m, vector<int>(n));
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            distances[i][j] = abs(A[j] - B[i]);
        }
        sort(distances[i].begin(), distances[i].end());
    }
}

int query(int i, int k) {
    return distances[i][k - 1];
}

int main() {
    int n, q;
    cin >> n >> q;
    A.resize(n), B.resize(q);
    for (int i = 0; i < n; ++i) cin >> A[i];
    for (int i = 0; i < q; ++i) cin >> B[i] >> k[i];
    
    preprocess();

    for (int i = 0; i < q; ++i) {
        cout << query(i, k[i]) << endl;
    }

    return 0;
}