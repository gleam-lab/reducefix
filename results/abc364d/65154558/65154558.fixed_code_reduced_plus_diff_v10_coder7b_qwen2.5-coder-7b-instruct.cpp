#include<bits/stdc++.h>
using namespace std;

vector<int> A;
vector<pair<int, int>> B; // Each pair contains (coordinate, k)

void preprocess() {
    int n = A.size(), m = B.size();
    vector<vector<int>> distances(m, vector<int>(n));
    
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            distances[i][j] = abs(B[i].first - A[j]);
        }
        sort(distances[i].begin(), distances[i].end());
    }
    
    for (int i = 0; i < m; ++i) {
        B[i].second = distances[i][B[i].second - 1];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, q;
    cin >> n >> q;
    
    A.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
    }
    
    B.resize(q);
    for (int i = 0; i < q; ++i) {
        cin >> B[i].first >> B[i].second;
    }
    
    preprocess();
    
    for (auto& b : B) {
        cout << b.second << '\n';
    }
    
    return 0;
}