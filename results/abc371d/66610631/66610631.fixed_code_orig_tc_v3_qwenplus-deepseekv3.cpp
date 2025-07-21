#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 1e6+7;

int main() {
    int n, m;
    cin >> n;
    vector<int> a(n+1, 0), b(n+1, 0);
    vector<ll> prefix(n+1, 0);  // Changed to long long for prefix sums
    
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    
    for(int i = 1; i <= n; i++) {
        cin >> b[i];
        prefix[i] = prefix[i-1] + b[i];  // Using long long to prevent overflow
    }
    
    cin >> m;
    while(m--) {
        int l, r;
        cin >> l >> r;
        
        auto left_it = lower_bound(a.begin()+1, a.end(), l);
        auto right_it = upper_bound(a.begin()+1, a.end(), r);
        
        int left_idx = left_it - a.begin();
        int right_idx = right_it - a.begin();
        
        ll sum = 0;
        if(left_idx <= right_idx) {
            sum = prefix[right_idx-1] - (left_idx > 1 ? prefix[left_idx-2] : 0);
        }
        
        cout << sum << endl;
    }
    
    return 0;
}