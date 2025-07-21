#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define vi vector<int>
#define vl vector<ll>
#define vb vector<bool>

// Function to calculate the Manhattan distance between two points
ll manhattan_distance(ll x1, ll y1, ll x2, ll y2) {
    return abs(x1 - x2) + abs(y1 - y2);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, q;
    cin >> n >> q;
    vi a(n), b(q), k(q);
    
    // Read coordinates of points A
    rep(i, n) cin >> a[i];
    
    // Read coordinates of points B and their corresponding k values
    rep(i, q) cin >> b[i] >> k[i];
    
    // Create a vector to store distances from all points A to a given point B
    vl distances;
    
    // For each point B, calculate the distances to all points A
    rep(j, q) {
        distances.clear();
        rep(i, n) {
            distances.push_back(manhattan_distance(a[i], 0, b[j], 0)); // Assuming both points lie on the same axis
        }
        
        // Sort the distances
        sort(distances.begin(), distances.end());
        
        // Output the k-th smallest distance
        cout << distances[k[j] - 1] << '\n';
    }
    
    return 0;
}