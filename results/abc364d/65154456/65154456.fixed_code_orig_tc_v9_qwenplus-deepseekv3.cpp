#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
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
        int pos = lower_bound(A.begin(), A.end(), b) - A.begin();
        
        vector<ll> distances;
        int l = max(0, pos - k - 1);
        int r = min(N - 1, pos + k + 1);
        for (int i = l; i <= r; ++i) {
            distances.push_back(abs(A[i] - b));
        }
        sort(distances.begin(), distances.end());
        
        cout << distances[k] << '\n';
    }
    
    return 0;
}