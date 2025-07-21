#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m;
    cin >> n;
    vector<int> a(n+1, 0);
    vector<long long> c(n+1, 0); // Using long long for prefix sums
    
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    
    for(int i = 1; i <= n; i++) {
        int b;
        cin >> b;
        c[i] = c[i-1] + b; // Calculate prefix sums
    }
    
    cin >> m;
    while(m--) {
        int l, r;
        cin >> l >> r;
        
        // Find first element >= l
        auto left_it = lower_bound(a.begin()+1, a.end(), l);
        int left = left_it - a.begin();
        
        // Find first element > r
        auto right_it = upper_bound(a.begin()+1, a.end(), r);
        int right = right_it - a.begin();
        
        // Calculate the sum from left to right-1
        long long sum = c[right-1] - c[left-1];
        cout << sum << '\n';
    }
    
    return 0;
}