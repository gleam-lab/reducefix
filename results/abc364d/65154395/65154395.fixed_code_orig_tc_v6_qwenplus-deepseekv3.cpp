#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, Q;
    cin >> N >> Q;
    vector<ll> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    sort(A.begin(), A.end());
    
    while (Q--) {
        ll b_j;
        int k_j;
        cin >> b_j >> k_j;
        
        vector<ll> distances(N);
        for (int i = 0; i < N; ++i) {
            distances[i] = abs(A[i] - b_j);
        }
        sort(distances.begin(), distances.end());
        cout << distances[k_j - 1] << '\n';
    }
}

int main() {
    solve();
    return 0;
}