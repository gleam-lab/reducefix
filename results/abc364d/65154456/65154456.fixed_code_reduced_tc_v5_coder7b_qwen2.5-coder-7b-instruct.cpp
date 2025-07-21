#include<bits/stdc++.h>
using namespace std;

const int MAXN = 100005;
const int MAXQ = 100005;

int a[MAXN], b[MAXQ], k[MAXQ];
vector<int> dist(MAXN * 2);

void solve() {
    int n, q; cin >> n >> q;
    
    // Read coordinates of points A_i
    for(int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    
    // Read coordinates of points B_j and their corresponding k_j
    for(int i = 1; i <= q; ++i) {
        cin >> b[i] >> k[i];
    }
    
    // Calculate distances from each point B_j to all points A_i
    for(int j = 1; j <= q; ++j) {
        for(int i = 1; i <= n; ++i) {
            int d = abs(a[i] - b[j]);
            dist[d]++;
        }
        
        // Calculate prefix sum of distances to find cumulative counts
        for(int i = 1; i <= MAXN * 2; ++i) {
            dist[i] += dist[i - 1];
        }
        
        // Find the k_j-th smallest distance
        int target = k[j];
        int ans = 0;
        for(int i = 1; i <= MAXN * 2; ++i) {
            if(dist[i] >= target) {
                ans = i;
                break;
            }
        }
        
        cout << ans << '\n';
        
        // Reset the distance array for the next query
        fill(dist.begin(), dist.end(), 0);
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t = 1; // Uncomment this line if there are multiple test cases
    // cin >> t;
    while(t--) solve();
    return 0;
}