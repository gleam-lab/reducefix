#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e6+7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m;
    cin >> n;
    vector<int> a(n+1, 0);
    vector<ll> c(n+1, 0);  // Changed to long long to prevent overflow
    
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    
    for(int i = 1; i <= n; i++) {
        int b;
        cin >> b;
        c[i] = c[i-1] + b;  // Using long long to accumulate sums
    }
    
    cin >> m;
    while(m--) {
        int l, r;
        cin >> l >> r;
        
        auto l_it = lower_bound(a.begin()+1, a.end(), l);
        auto r_it = upper_bound(a.begin()+1, a.end(), r);
        
        int i = l_it - a.begin();
        int j = r_it - a.begin();
        
        ll sum = c[j-1] - c[i-1];
        cout << sum << '\n';
    }
    
    return 0;
}