#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 100005;
const int Q = 100005;
int n, q;
vector<ll> a(N), b(Q), k(Q);

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    cin >> n >> q;
    for(int i = 1; i <= n; ++i) cin >> a[i];
    for(int i = 1; i <= q; ++i) cin >> b[i] >> k[i];
    
    sort(a.begin() + 1, a.begin() + n + 1);
    
    for(int i = 1; i <= q; ++i) {
        auto it = lower_bound(a.begin() + 1, a.begin() + n + 1, b[i]);
        int pos = it - a.begin();
        
        if(k[i] == pos) cout << abs(b[i] - a[pos]) << '\n';
        else if(k[i] < pos) cout << abs(b[i] - a[pos - 1]) << '\n';
        else cout << abs(b[i] - a[pos]) << '\n';
    }
    
    return 0;
}