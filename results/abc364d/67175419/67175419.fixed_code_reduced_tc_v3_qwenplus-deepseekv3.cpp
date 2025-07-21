#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int N, Q;
    cin >> N >> Q;
    vector<long long> a(N);
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    
    while (Q--) {
        long long b_j;
        int k_j;
        cin >> b_j >> k_j;
        vector<long long> distances(N);
        for (int i = 0; i < N; ++i) {
            distances[i] = abs(a[i] - b_j);
        }
        sort(distances.begin(), distances.end());
        cout << distances[k_j - 1] << "\n";
    }
    
    return 0;
}