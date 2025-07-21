#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, Q;
    cin >> N >> Q;
    
    vector<ll> A(N), B(Q);
    vector<vector<ll>> distances(Q);
    
    // Read points A_i
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    
    // Read points B_j and calculate distances
    for (int j = 0; j < Q; ++j) {
        cin >> B[j] >> N; // N is the k-th smallest distance we need to find
        distances[j].resize(N);
        for (int i = 0; i < N; ++i) {
            distances[j][i] = abs(A[i] - B[j]);
        }
        sort(distances[j].begin(), distances[j].end());
    }
    
    // Answer each query using binary search
    for (int j = 0; j < Q; ++j) {
        cout << distances[j][N - 1] << '\n';
    }
    
    return 0;
}