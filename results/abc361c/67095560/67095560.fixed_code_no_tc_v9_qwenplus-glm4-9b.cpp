#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define pb push_back

typedef long long ll;

int main() {
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    
    // Read the array elements
    for (ll i = 0; i < n; i++) cin >> a[i];
    
    // Sort the array to make it easier to remove elements from the ends
    sort(a.begin(), a.end());
    
    // We need to consider the scenario where we remove K elements
    // and find the minimum possible value of the maximum and minimum
    // in the remaining array.
    // Since we are removing K elements, the remaining array will have size (N-K)
    // We need to consider removing elements from both ends to minimize the difference.
    
    // Initialize the answer with a large value
    ll ans = LLONG_MAX;
    
    // We have two cases to consider for removing K elements:
    // 1. Remove K elements starting from the beginning
    // 2. Remove K elements starting from the end
    
    // Case 1: Remove K elements from the beginning
    // We then have the range [a[k], a[n-1]]
    ll max_val = a[n-1];
    ll min_val = a[k];
    ans = min(ans, max_val - min_val);
    
    // Case 2: Remove K elements from the end
    // We then have the range [a[0], a[n-k-1]]
    max_val = a[n-k-1];
    min_val = a[0];
    ans = min(ans, max_val - min_val);
    
    // Output the answer
    cout << ans << endl;
    
    return 0;
}