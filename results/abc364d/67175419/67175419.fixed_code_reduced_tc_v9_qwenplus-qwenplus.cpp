#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;

int n, q;
vector<long long> a;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> n >> q;
    a.resize(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    
    sort(a.begin(), a.end());
    
    while (q--) {
        long long b, k;
        cin >> b >> k;
        
        // Binary search on distance
        long long left = 0, right = 2e14;  // Max possible distance
        while (left < right) {
            long long mid = (left + right) / 2;
            
            // Find number of elements in [b-mid, b+mid]
            auto l = lower_bound(a.begin(), a.end(), b - mid);
            auto r = upper_bound(a.begin(), a.end(), b + mid);
            
            if ((r - l) >= k)
                right = mid;
            else
                left = mid + 1;
        }
        
        cout << left << "\n";
    }
    
    return 0;
}