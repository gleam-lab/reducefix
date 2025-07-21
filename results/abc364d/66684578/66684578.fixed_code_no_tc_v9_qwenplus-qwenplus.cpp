#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>
#define vll vector<ll>
#define pb push_back
#define rep(i, n) for (int i = 0; i < (int)n; ++i)

// Function to compute k-th smallest distance from b to elements in a
ll kth_smallest_distance(vi& a, int b, int k) {
    // Create a list of absolute distances
    vector<ll> distances;
    for (int x : a) {
        distances.pb(abs((ll)x - (ll)b));
    }
    
    // Quick select to find the k-th smallest distance in O(N) average time
    nth_element(distances.begin(), distances.begin() + k - 1, distances.end());
    return distances[k - 1];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int N, Q;
    cin >> N >> Q;
    
    vi A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    
    rep(i, Q) {
        int b, k;
        cin >> b >> k;
        cout << kth_smallest_distance(A, b, k) << "\n";
    }
}