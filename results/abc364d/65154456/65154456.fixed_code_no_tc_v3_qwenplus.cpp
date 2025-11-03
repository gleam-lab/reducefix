#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAX_N = 1e5 + 5;

int n, q;
ll a[MAX_N];

// Function to find the k-th smallest distance from point b to any A_i
ll solve_query(ll b, int k) {
    // Create vector of distances from b to each a[i]
    vector<ll> distances;
    for (int i = 0; i < n; i++) {
        distances.push_back(abs(a[i] - b));
    }
    
    // Partially sort to get k-th smallest element
    nth_element(distances.begin(), distances.begin() + k - 1, distances.end());
    
    return distances[k - 1];
}

void solve() {
    cin >> n >> q;
    
    // Read coordinates of points A
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    // Process each query
    for (int i = 0; i < q; i++) {
        ll b;
        int k;
        cin >> b >> k;
        
        cout << solve_query(b, k) << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
    
    return 0;
}