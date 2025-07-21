#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
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
        
        int left = 0, right = A.size() - 1;
        vector<int> distances;
        for (int i = 0; i < N; ++i) {
            distances.push_back(abs(A[i] - b));
        }
        sort(distances.begin(), distances.end());
        
        cout << distances[k - 1] << '\n';
    }
    
    return 0;
}