#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define vi vector<int>
#define vl vector<ll>
#define vd vector<double>
#define vb vector<bool>
#define vs vector<string>
#define vc vector<char>

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    int n, q;
    cin >> n >> q;
    
    vi a(n), distances(n);
    vl sorted_distances;
    
    rep(i, n) {
        cin >> a[i];
    }
    
    rep(j, q) {
        int b, k;
        cin >> b >> k;
        
        // Calculate all distances from B_j to A_i
        rep(i, n) {
            distances[i] = abs(a[i] - b);
            sorted_distances.push_back(distances[i]);
        }
        
        // Sort the distances
        sort(sorted_distances.begin(), sorted_distances.end());
        
        // Find the k_j-th smallest distance
        cout << sorted_distances[k - 1] << '\n';
        
        // Clear vectors for next query
        distances.clear();
        sorted_distances.clear();
    }
    
    return 0;
}