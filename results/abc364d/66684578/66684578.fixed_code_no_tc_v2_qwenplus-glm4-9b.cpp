#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i, n) for (int i = 0; i < (int)n; ++i)
#define vi vector<int>
#define vl vector<ll>
#define vd vector<double>
#define vb vector<bool>
#define vs vector<string>
#define vc vector<char>

int main() {
    ll n, q;
    cin >> n >> q;
    vl a(n), b(q);
    
    // Read all A_i values
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
    }
    
    // Read all B_j and k_j values
    for (ll j = 0; j < q; ++j) {
        cin >> b[j] >> a[j];
    }
    
    // Sort A values to use binary search
    sort(a.begin(), a.end());
    
    // Prepare to output the results
    vl results(q);
    
    // For each B_j, find the k_j-th closest A_i
    for (ll j = 0; j < q; ++j) {
        ll b_val = b[j];
        ll k_j = a[j] - 1; // Convert to zero-based index
        
        // Binary search to find the k_j-th closest A_i
        ll low = 0, high = n - 1;
        while (low < high) {
            ll mid = (low + high) / 2;
            if (a[mid] < b_val) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        
        // Calculate the distance to the k_j-th closest A_i
        ll closest_A = a[low];
        results[j] = abs(b_val - closest_A);
    }
    
    // Print all results
    for (ll j = 0; j < q; ++j) {
        cout << results[j] << endl;
    }
    
    return 0;
}