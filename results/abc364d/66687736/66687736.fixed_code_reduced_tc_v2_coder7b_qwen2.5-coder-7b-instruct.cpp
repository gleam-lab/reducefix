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
#define ull unsigned long long

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, q;
    cin >> n >> q;
    vl a(n), dists(n);
    
    rep(i, n) {
        cin >> a[i];
    }
    
    rep(j, q) {
        int b, k;
        cin >> b >> k;
        
        rep(i, n) {
            dists[i] = abs(a[i] - b);
        }
        
        sort(dists.begin(), dists.end());
        
        cout << dists[k - 1] << '\n';
    }
    
    return 0;
}