#include <bits/stdc++.h>
using namespace std;

vector<int> A, B;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    cin >> N >> Q;

    A.resize(N);
    for(int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    B.resize(Q);
    vector<vector<int>> distances(Q);
    
    for(int i = 0; i < Q; ++i) {
        cin >> B[i] >> A[i]; // A[i] is now the index of the point B[i]
        distances[i].resize(N);
        for(int j = 0; j < N; ++j) {
            distances[i][j] = abs(A[j] - B[i]);
        }
        sort(distances[i].begin(), distances[i].end());
    }

    for(int i = 0; i < Q; ++i) {
        cout << distances[i][A[i] - 1] << '\n'; // Adjusting index to zero-based
    }

    return 0;
}