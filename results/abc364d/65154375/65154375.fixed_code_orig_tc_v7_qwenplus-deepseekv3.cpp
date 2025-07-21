#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
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
        ll b;
        int k;
        cin >> b >> k;
        k--; // convert to 0-based index
        
        int left = 0;
        int right = N - 1;
        vector<ll> distances;
        
        // Binary search to find the position of b in A
        auto it = lower_bound(A.begin(), A.end(), b);
        int pos = it - A.begin();
        
        // Collect the closest elements around pos
        int l = max(0, pos - 100000);
        int r = min(N - 1, pos + 100000);
        for (int i = l; i <= r; ++i) {
            distances.push_back(abs(A[i] - b));
        }
        
        // Sort the distances and pick the k-th smallest
        sort(distances.begin(), distances.end());
        cout << distances[k] << '\n';
    }
    
    return 0;
}