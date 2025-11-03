#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    int N, Q;
    cin >> N >> Q;
    
    vector<ll> a(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    
    sort(a.begin(), a.end());
    
    for (int j = 0; j < Q; j++) {
        ll b;
        int k;
        cin >> b >> k;
        
        // We want the k-th smallest distance from b to points in a
        // Instead of computing all distances, we can binary search on the answer
        // But simpler: use two pointers or binary search to find k-th closest
        
        // Binary search on the distance
        ll left = 0;
        ll right = 2e8 + 10;
        right *= 2; // maximum possible distance
        
        while (left < right) {
            ll mid = (left + right) / 2;
            
            // Count how many points are within distance `mid` from b
            ll low_bound = b - mid;
            ll high_bound = b + mid;
            
            auto it1 = lower_bound(a.begin(), a.end(), low_bound);
            auto it2 = upper_bound(a.begin(), a.end(), high_bound);
            int count = distance(it1, it2);
            
            if (count >= k) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        
        cout << left << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}