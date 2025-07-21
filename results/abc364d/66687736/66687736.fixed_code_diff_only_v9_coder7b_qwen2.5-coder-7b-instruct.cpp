#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n, q;
    cin >> n >> q;

    vector<int> a(n), b(q);
    vector<pair<int, int>> queries(q);
    
    // Read coordinates of points A_i
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    // Read coordinates of points B_j and corresponding k_j
    for (int i = 0; i < q; ++i) {
        cin >> b[i] >> queries[i].first;
        queries[i].second = i;
    }

    // Sort points A_i
    sort(a.begin(), a.end());

    // Process each query
    for (auto &query : queries) {
        int x = query.first;
        int k = query.second;
        
        // Find the k-th smallest distance
        int lo = 0, hi = 1e8 + 7;
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            int count = 0;
            
            // Count how many points A_i are within distance mid of x
            for (int ai : a) {
                if (abs(ai - x) <= mid) {
                    count++;
                }
            }
            
            if (count >= k) {
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }
        
        cout << lo << '\n';
    }

    return 0;
}