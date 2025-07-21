#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>
#define vll vector<ll>
#define vpi vector<pair<ll, ll>>
#define pb push_back
#define fi first
#define se second

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int N, Q;
    cin >> N >> Q;
    
    vll a(N);
    for (ll i = 0; i < N; ++i) {
        cin >> a[i];
    }
    
    // Sort the A points for binary search usage
    sort(a.begin(), a.end());
    
    // Prepare prefix sums for binary indexed tree or cumulative counts
    vll prefixSum(2 * N + 2, 0); // Placeholder if needed
    
    // Process each query
    while (Q--) {
        ll b, k;
        cin >> b >> k;
        
        // Create array of distances and sort them
        vll distances;
        for (ll i = 0; i < N; ++i) {
            distances.pb(abs(a[i] - b));
        }
        
        // Find the k-th smallest distance using quick-select
        nth_element(distances.begin(), distances.begin() + k - 1, distances.end());
        cout << distances[k - 1] << "\n";
    }
    
    return 0;
}