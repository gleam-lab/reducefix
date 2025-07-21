#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    vector<long long> a(n), b(n-1);
    
    for(int i = 0; i < n; ++i)
        cin >> a[i];
    for(int i = 0; i < n-1; ++i)
        cin >> b[i];
    
    // Sort both arrays to facilitate comparison
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    
    // Initialize the answer with the maximum element in 'a' as a lower bound
    long long ans = *max_element(a.begin(), a.end());
    
    // Iterate through each box size in 'b'
    for(int i = 0; i < n-1; ++i) {
        // If the current box size is smaller than the smallest toy, return -1
        if(b[i] < a[0]) {
            cout << -1 << "\n";
            return 0;
        }
        // Check if we need a bigger box for the next toy
        if(i+1 < n && b[i] < a[i+1]) {
            ans = max(ans, a[i+1]);
        }
    }
    
    // Output the minimum box size needed
    cout << ans << "\n";
    
    return 0;
}