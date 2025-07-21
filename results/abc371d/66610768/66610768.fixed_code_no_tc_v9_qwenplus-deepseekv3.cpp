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
        auto left_it = lower_bound(a.begin()+1, a.end(), l);
        int left_pos = left_it - a.begin();
        
        // Find first element > r
        auto right_it = upper_bound(a.begin()+1, a.end(), r);
        int right_pos = right_it - a.begin();
        
        // Calculate sum
        if(left_pos > n) {
            // All elements are smaller than l
            cout << 0 << endl;
        } else if(right_pos <= 1) {
            // All elements are larger than r
            cout << 0 << endl;
        } else {
            cout << c[right_pos-1] - c[left_pos-1] << endl;
        }
    }
    return 0;
}