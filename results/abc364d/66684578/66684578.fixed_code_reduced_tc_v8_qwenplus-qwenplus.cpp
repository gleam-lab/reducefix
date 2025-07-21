#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define vi vector<int>
#define vll vector<ll>
#define pb push_back

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int N, Q;
    cin >> N >> Q;
    
    vi a(N);
    rep(i, N) cin >> a[i];
    
    // Sort the A points for binary search usage
    sort(a.begin(), a.end());
    
    while(Q--) {
        int b, k;
        cin >> b >> k;
        
        // Create array of distances to B from each A point
        vll distances;
        rep(i, N) {
            distances.pb(abs(1LL * a[i] - b));
        }
        
        // Find the k-th smallest distance using nth_element (O(N) average case)
        nth_element(distances.begin(), distances.begin() + k - 1, distances.end());
        cout << distances[k-1] << "\n";
    }
}