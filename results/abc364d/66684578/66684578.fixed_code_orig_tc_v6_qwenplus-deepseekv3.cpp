#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, Q;
    cin >> N >> Q;
    vector<ll> a(N);
    rep(i, N) cin >> a[i];
    
    sort(a.begin(), a.end());
    
    vector<ll> b(Q), k(Q);
    rep(i, Q) cin >> b[i] >> k[i];
    
    rep(j, Q) {
        ll B = b[j];
        ll K = k[j];
        
        vector<ll> distances(N);
        rep(i, N) {
            distances[i] = abs(a[i] - B);
        }
        
        sort(distances.begin(), distances.end());
        
        cout << distances[K - 1] << '\n';
    }
    
    return 0;
}