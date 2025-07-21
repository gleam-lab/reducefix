#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
int n, m, k, sum, cnt, a[N];

void solve() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    vector<int> distances(n);
    
    // Read all points A_i
    for(int i = 0; i < n; ++i) 
        cin >> a[i];
    
    sort(a, a + n);

    while(m--) {
        int b, k;
        cin >> b >> k;
        
        // Calculate distances from point B to all points A_i
        for(int i = 0; i < n; ++i) 
            distances[i] = abs(b - a[i]);
        
        // Sort the distances
        sort(distances.begin(), distances.end());
        
        // Output the k-th smallest distance
        cout << distances[k - 1] << "\n";
    }
}

int main() {
    solve();
    return 0;
}