#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,n) for(int i=0;i<(int)n;i++)

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, q;
    cin >> n >> q;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];
    sort(a.begin(), a.end());
    rep(i, q) {
        ll b, k;
        cin >> b >> k;
        vector<ll> distances;
        rep(j, n) {
            distances.push_back(abs(a[j] - b));
        }
        sort(distances.begin(), distances.end());
        cout << distances[k-1] << '\n';
    }
    return 0;
}