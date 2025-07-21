#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define all(v) v.begin(),v.end()

const int N = 1e5 + 10;
int a[N], b[N], c[N], d[N];
vector<int> v;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, q; cin >> n >> q;
    for(int i = 1; i <= n; ++i) {
        cin >> a[i];
        v.pb(a[i]);
    }
    sort(all(v));
    for(int i = 1; i <= n; ++i) {
        a[i] = lower_bound(all(v), a[i]) - v.begin() + 1;
    }

    for(int i = 1; i <= q; ++i) {
        cin >> b[i] >> c[i];
        v.clear();
        for(int j = 1; j <= n; ++j) {
            if(abs(b[i] - a[j]) < abs(c[i] - a[j])) {
                v.pb(j);
            } else if(abs(b[i] - a[j]) == abs(c[i] - a[j]) && a[j] < c[i]) {
                v.pb(j);
            }
        }
        sort(all(v));
        c[i] = v[c[i] - 1];
        b[i] = abs(c[i] - b[i]);
        cout << b[i] << '\n';
    }
    return 0;
}