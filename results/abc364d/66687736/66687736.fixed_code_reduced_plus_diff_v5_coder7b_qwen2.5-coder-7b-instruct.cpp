#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll INF = 1e18;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    int n, q;
    cin >> n >> q;
    
    vector<ll> A(n), B(q);
    vector<int> K(q);
    
    for(int i = 0; i < n; ++i) {
        cin >> A[i];
    }
    
    for(int i = 0; i < q; ++i) {
        cin >> B[i] >> K[i];
    }
    
    sort(A.begin(), A.end());
    
    for(int i = 0; i < q; ++i) {
        int idx = upper_bound(A.begin(), A.end(), B[i]) - A.begin();
        if(idx == 0) {
            cout << abs(B[i] - A[0]) << '\n';
        } else if(idx == n) {
            cout << abs(B[i] - A[n-1]) << '\n';
        } else {
            int dist1 = abs(B[i] - A[idx]);
            int dist2 = abs(B[i] - A[idx-1]);
            if(dist1 <= dist2) {
                cout << dist1 << '\n';
            } else {
                cout << dist2 << '\n';
            }
        }
    }
    
    return 0;
}