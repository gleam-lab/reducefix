#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e6+7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m;
    cin >> n;
    vector<int> a(n+1), b(n+1), c(n+1);
    
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    
    for(int i = 1; i <= n; i++) {
        cin >> b[i];
        c[i] = b[i] + c[i-1];
    }
    
    cin >> m;
    while(m--) {
        int l, r;
        cin >> l >> r;
        
        // Find first element >= l
        int i = lower_bound(a.begin()+1, a.end(), l) - a.begin();
        
        // Find first element > r
        int j = upper_bound(a.begin()+1, a.end(), r) - a.begin();
        
        cout << c[j-1] - c[i-1] << '\n';
    }
    
    return 0;
}