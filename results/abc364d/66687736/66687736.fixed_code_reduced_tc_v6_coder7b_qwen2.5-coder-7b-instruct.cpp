#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    int n, q; cin >> n >> q;
    vector<long long> a(n), distances;
    unordered_map<long long, int> count;
    
    // Read the coordinates of points A
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
        count[a[i]]++;
    }
    
    // Calculate all possible distances
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            distances.push_back(abs(a[i] - a[j]));
        }
    }
    
    // Sort the distances
    sort(distances.begin(), distances.end());
    
    // Process each query
    for(int i = 0; i < q; ++i) {
        long long b, k; cin >> b >> k;
        auto it = lower_bound(distances.begin(), distances.end(), abs(b - a[0]));
        int idx = it - distances.begin();
        
        long long result = 0;
        while(k > 0 && idx < distances.size()) {
            if(count[a[idx / n]] > 0) {
                --count[a[idx / n]];
                result = distances[idx];
                --k;
            } else {
                ++idx;
            }
        }
        
        cout << result << '\n';
    }
    
    return 0;
}