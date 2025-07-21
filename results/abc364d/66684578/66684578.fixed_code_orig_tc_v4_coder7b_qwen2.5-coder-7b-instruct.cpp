#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define vi vector<int>
#define vl vector<ll>
#define vd vector<double>
#define vb vector<bool>
#define vs vector<string>
#define vc vector<char>

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    
    int n, q;
    cin >> n >> q;
    
    vl A(n), B(q), K(q);
    rep(i, n) cin >> A[i];
    rep(j, q) cin >> B[j] >> K[j];

    sort(A.begin(), A.end());
    
    rep(j, q) {
        int b = B[j], k = K[j] - 1; // Adjusting k to zero-indexed
        
        auto it = lower_bound(A.begin(), A.end(), b);
        int pos = it - A.begin();
        
        ll dist1 = INT_MAX, dist2 = INT_MAX;
        
        if(pos > 0) dist1 = abs(A[pos-1] - b);
        if(pos < n) dist2 = abs(A[pos] - b);
        
        if(dist1 <= dist2) cout << dist1 << '\n';
        else cout << dist2 << '\n';
    }

    return 0;
}