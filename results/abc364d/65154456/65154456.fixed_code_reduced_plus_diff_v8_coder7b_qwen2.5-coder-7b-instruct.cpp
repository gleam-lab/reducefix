#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<ll> A, B;

// Function to calculate the minimum distance to the nearest point
ll min_distance(ll x, vector<ll>& points) {
    auto it = lower_bound(points.begin(), points.end(), x);
    if(it == points.end()) return x - points.back(); // Distance to last element if x is greater than all elements
    if(it == points.begin()) return points.front() - x; // Distance to first element if x is smaller than all elements
    ll dist_left = *it - x;
    ll dist_right = x - *(it - 1);
    return min(dist_left, dist_right); // Return the minimum distance to the closest point
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, q;
    cin >> n >> q;
    
    A.resize(n);
    B.resize(q);
    
    for(ll i = 0; i < n; ++i) {
        cin >> A[i];
    }
    
    sort(A.begin(), A.end()); // Sort points A
    
    for(ll i = 0; i < q; ++i) {
        cin >> B[i];
    }
    
    for(ll i = 0; i < q; ++i) {
        ll ans = min_distance(B[i], A);
        cout << ans << '\n'; // Print the minimum distance for each B[i]
    }

    return 0;
}