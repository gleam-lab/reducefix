#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    vector<int> a(n+1), b(n+1);
    vector<ll> c(n+1, 0);
    
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for(int i = 1; i <= n; i++) {
        cin >> b[i];
        c[i] = c[i-1] + b[i];
    }
    
    int m;
    cin >> m;
    while(m--) {
        int l, r;
        cin >> l >> r;
        
        auto left_it = lower_bound(a.begin()+1, a.end(), l);
        auto right_it = upper_bound(a.begin()+1, a.end(), r);
        
        int left_pos = left_it - a.begin();
        int right_pos = right_it - a.begin();
        
        ll sum = c[right_pos-1] - c[left_pos-1];
        cout << sum << '\n';
    }
    
    return 0;
}