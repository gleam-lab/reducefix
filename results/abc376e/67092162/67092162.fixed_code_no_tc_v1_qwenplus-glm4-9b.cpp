#include <bits/stdc++.h>
using namespace std;
const int maxN = 2e5 + 5;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int t, n, k;
    cin >> t;
    while (t--) {
        cin >> n >> k;
        vector<pair<int, int>> a;
        vector<int> b;
        vector<pair<int, int>> ab; // Pair of (B_i, A_i)
        
        // Read A and B arrays and combine them into ab vector
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            cin >> b[i];
            ab.push_back({b[i], a[i]});
        }
        
        // Sort the combined array by B_i (first element of pair)
        sort(ab.begin(), ab.end());
        
        long long sum = 0;
        long long ans = LLONG_MAX;
        
        // Iterate through the array and find the minimum possible value of the expression
        for (int i = 0; i < n; ++i) {
            if (i >= k) {
                // If we have selected k elements, we need to try to remove the one with the smallest A_i
                sum -= ab[i - k].first;
                sum += ab[i].first;
            }
            
            sum += ab[i].first; // Add B_i to sum
            
            ans = min(ans, ab[i].second * sum); // Calculate new answer and update if smaller
        }
        
        cout << ans << '\n';
    }
    
    return 0;
}