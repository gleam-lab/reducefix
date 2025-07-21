#include<bits/stdc++.h>
using namespace std;
using LL = __int128;
typedef long long ll;
const int N = 1e6+7;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m;
    cin >> n;
    vector<int> a(n+1, 0), b(n+1, 0), c(n+1, 0);
    
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
        
        // Adjust if all elements are smaller than l
        if(i > n) {
            cout << "0\n";
            continue;
        }
        
        // At least one element is <= r
        cout << c[j-1] - c[i-1] << '\n';
    }
    return 0;
}