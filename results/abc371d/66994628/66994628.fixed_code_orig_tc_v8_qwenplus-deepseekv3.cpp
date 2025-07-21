#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
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
        int l, r;
        cin >> l >> r;
        int left_pos = lower_bound(x.begin()+1, x.end(), l) - x.begin();
        int right_pos = upper_bound(x.begin()+1, x.end(), r) - x.begin();
        cout << sum[right_pos-1] - sum[left_pos-1] << '\n';
    }
    
    return 0;
}