#include<bits/stdc++.h>
using namespace std;
const int N = 1e6+5;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m;
    cin >> n >> m;
    
    vector<int> a(2*n+1);
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i+n] = a[i];  // Create circular array
    }
    
    vector<int> prefix(2*n+1);
    vector<int> mod_count(m, 0);
    mod_count[0] = 1;  // Empty prefix sum
    
    long long result = 0;
    
    for(int i = 1; i < 2*n; i++) {
        // Remove the prefix sum that's now outside our window
        if(i > n) {
            mod_count[prefix[i-n] % m]--;
        }
        
        // Calculate current prefix sum
        prefix[i] = prefix[i-1] + a[i];
        
        // Add the count of matching mod values
        result += mod_count[prefix[i] % m];
        
        // Add current prefix mod to our count if still in first window
        if(i < n) {
            mod_count[prefix[i] % m]++;
        }
    }
    
    cout << result << endl;
    return 0;
}