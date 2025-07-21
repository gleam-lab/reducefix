#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, q;
    cin >> n;
    vector<int> x(n+1), p(n+1);
    vector<ll> sum(n+1, 0);
    
    for(int i = 1; i <= n; i++) {
        cin >> x[i];
    }
    for(int i = 1; i <= n; i++) {
        cin >> p[i];
        sum[i] = sum[i-1] + p[i];
    }
    
    cin >> q;
    while(q--) {
        int l_val, r_val;
        cin >> l_val >> r_val;
        int l = lower_bound(x.begin()+1, x.end(), l_val) - x.begin();
        int r = upper_bound(x.begin()+1, x.end(), r_val) - x.begin();
        cout << sum[r-1] - sum[l-1] << '\n';
    }
    
    return 0;
}