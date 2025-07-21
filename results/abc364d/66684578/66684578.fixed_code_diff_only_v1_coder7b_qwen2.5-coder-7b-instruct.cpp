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

const int big = 100000000;

int get(const vector<int>& dists, int k) {
    return dists[k - 1];
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    int n, q; cin >> n >> q;
    vi a(n), dists(n);
    rep(i, n) cin >> a[i];
    
    rep(i, q) {
        int b, k; cin >> b >> k;
        rep(j, n) dists[j] = abs(a[j] - b);
        sort(dists.begin(), dists.end());
        
        cout << get(dists, k) << endl;
    }
    
    return 0;
}