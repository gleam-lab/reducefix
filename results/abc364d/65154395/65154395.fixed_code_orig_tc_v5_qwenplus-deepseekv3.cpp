#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N, Q;
    cin >> N >> Q;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    sort(A.begin(), A.end());
    
    while (Q--) {
        int b, k;
        cin >> b >> k;
        
        int left = 0, right = N - 1;
        vector<int> distances(N);
        for (int i = 0; i < N; ++i) {
            distances[i] = abs(A[i] - b);
        }
        
        sort(distances.begin(), distances.end());
        cout << distances[k - 1] << '\n';
    }
    
    return 0;
}