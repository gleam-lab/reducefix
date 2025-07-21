#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define rep(i,n) for(int i=0;i<n;i++)
#define vi vector<int>
#define vl vector<ll>
#define vb vector<bool>
#define vpii vector<pair<int, int>>

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int n, q;
    cin >> n >> q;
    vi a(n), b(q);
    vi k(q);
    
    rep(i, n)
        cin >> a[i];
    
    rep(j, q) {
        cin >> b[j] >> k[j];
    }

    sort(a.begin(), a.end());
    
    rep(j, q) {
        int pos = upper_bound(a.begin(), a.end(), b[j]) - a.begin();
        int dist = min(pos * b[j] - a[pos], (pos == n ? INT_MAX : a[pos + 1] - b[j]));
        cout << dist << '\n';
    }
    
    return 0;
}