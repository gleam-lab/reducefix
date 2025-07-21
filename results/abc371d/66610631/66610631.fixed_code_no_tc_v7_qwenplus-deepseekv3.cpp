#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e6+7;

int main() {
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
        int left_pos = lower_bound(a.begin()+1, a.end(), l) - a.begin();
        // Find first element > r
        int right_pos = upper_bound(a.begin()+1, a.end(), r) - a.begin();
        
        // Calculate the sum
        ll sum = 0;
        if (left_pos <= right_pos) {
            sum = c[right_pos - 1] - c[left_pos - 1];
        }
        
        cout << sum << endl;
    }
    
    return 0;
}