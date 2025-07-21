#include<bits/stdc++.h>
using namespace std;
using LL = __int128;
typedef long long ll;
const int N = 1e6+7;

int main() {
    int n, m;
    cin >> n;
    vector<int> a(n+1, 0), b(n+1, 0), c(n+1, 0);
    
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    
    for(int i = 1; i <= n; i++){
        cin >> b[i];
        c[i] = b[i] + c[i-1];
    }
    
    cin >> m;
    while(m--){
        int l, r;
        cin >> l >> r;
        
        // Find first element >= l
        int left_idx = lower_bound(a.begin()+1, a.end(), l) - a.begin();
        // Find first element > r
        int right_idx = upper_bound(a.begin()+1, a.end(), r) - a.begin();
        
        if(left_idx > n) {
            // All elements are smaller than l
            cout << 0 << endl;
        } else if(right_idx <= 1) {
            // All elements are larger than r
            cout << 0 << endl;
        } else {
            // Calculate sum between left_idx and right_idx-1
            cout << c[right_idx-1] - c[left_idx-1] << endl;
        }
    }
    return 0;
}