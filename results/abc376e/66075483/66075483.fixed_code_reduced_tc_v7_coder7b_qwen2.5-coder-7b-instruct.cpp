#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;
        vector<pair<int,int>> a(n), b(n);
        for(int i = 0; i < n; ++i) {
            cin >> a[i].first;
            a[i].second = i;
        }
        for(int i = 0; i < n; ++i) {
            cin >> b[i].first;
            b[i].second = i;
        }
        
        // Sort based on A's values
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        
        // Initialize variables
        long long ans = LLONG_MAX;
        int j = 0;
        
        // Iterate through sorted A array
        for(int i = 0; i < n && j < n; ++i) {
            // Find the corresponding index in B for the current maximum A value
            while(j < n && b[j].second != a[i].second) ++j;
            
            // Calculate the sum of B values up to the current index
            long long sum_b = 0;
            for(int l = 0; l <= j; ++l) sum_b += b[l].first;
            
            // Check if we have enough elements for the subset
            if(j - i + 1 >= k) {
                // Update the answer with the minimum value found
                ans = min(ans, static_cast<long long>(a[i].first) * sum_b);
            }
        }
        
        // Print the result for the current test case
        cout << ans << '\n';
    }
    return 0;
}