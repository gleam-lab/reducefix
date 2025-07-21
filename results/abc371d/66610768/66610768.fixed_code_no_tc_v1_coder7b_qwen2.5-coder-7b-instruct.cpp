#include<bits/stdc++.h>
using namespace std;
using LL = __int128;
typedef long long ll;
const int N = 1e6+7;

int main() {
    int n, q;
    cin >> n;
    vector<ll> x(n + 1), p(n + 1), c(n + 1);
    
    for(int i = 1; i <= n; ++i){
        cin >> x[i];
    }
    
    for(int i = 1; i <= n; ++i){
        cin >> p[i];
        c[i] = p[i] + c[i - 1];
    }
    
    cin >> q;
    while(q--){
        ll l, r;
        cin >> l >> r;
        
        // Find the position where l would be inserted (leftmost)
        auto it_l = lower_bound(x.begin(), x.end(), l) - x.begin();
        
        // Find the position where r would be inserted (rightmost)
        auto it_r = upper_bound(x.begin(), x.end(), r) - x.begin();
        
        if(it_r == n && x[it_r] > r) --it_r; // Adjust if r is greater than any village coordinate
        
        // Calculate the result based on the positions found
        if(it_l > it_r) cout << "0\n"; // No villages within range [l, r]
        else cout << c[it_r] - c[it_l - 1] << '\n';
    }
    
    return 0;
}