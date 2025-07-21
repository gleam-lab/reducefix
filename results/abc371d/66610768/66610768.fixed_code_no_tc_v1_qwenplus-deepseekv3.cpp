#include<bits/stdc++.h>
using namespace std;
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
        auto left_it = lower_bound(a.begin()+1, a.end(), l);
        int i = left_it - a.begin();
        
        // Find first element > r
        auto right_it = upper_bound(a.begin()+1, a.end(), r);
        int j = right_it - a.begin();
        
        // Handle cases where l is beyond all elements
        if(left_it == a.end()) {
            cout << 0 << endl;
            continue;
        }
        
        // Sum from i to min(j-1, n)
        int end_idx = min(j-1, n);
        cout << c[end_idx] - c[i-1] << endl;
    }
    
    return 0;
}