#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 200005;

int n, q, x[MAXN], p[MAXN];
ll sum[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> x[i];
    }
    for(int i = 1; i <= n; i++) {
        cin >> p[i];
        sum[i] = sum[i-1] + p[i];
    }
    
    cin >> q;
    while(q--) {
        int L, R;
        cin >> L >> R;
        int c = lower_bound(x+1, x+n+1, L) - x;
        int d = upper_bound(x+1, x+n+1, R) - x;
        cout << sum[d-1] - sum[c-1] << '\n';
    }
    return 0;
}