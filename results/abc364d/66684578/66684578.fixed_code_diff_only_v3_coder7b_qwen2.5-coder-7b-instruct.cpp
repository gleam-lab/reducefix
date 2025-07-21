#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,n) for(int i=0;i<n;i++)
#define vi vector<int>
#define vl vector<ll>
#define vb vector<bool>

int main() {
    int n, q; cin >> n >> q;
    vi a(n), dist(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for(int i = 0; i < q; i++) {
        int b, k; cin >> b >> k;
        for(int j = 0; j < n; j++) {
            dist[j] = abs(a[j] - b);
        }
        sort(dist.begin(), dist.end());
        cout << dist[k-1] << endl;
    }

    return 0;
}