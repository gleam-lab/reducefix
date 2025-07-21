#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9 + 7;

int main() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n + 1);
    
    // Read points A
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    // For each query, perform the following steps:
    for (int j = 0; j < q; ++j) {
        int b, k;
        cin >> b >> k;
        
        // Linear search to find the k-th closest point from B
        int dist, mindist = INF;
        for (int i = 0; i < n; ++i) {
            dist = abs(a[i] - b);
            if (dist < mindist) {
                mindist = dist;
            } else if (dist > mindist) {
                break;
            }
            if (--k == 0) {
                cout << mindist << '\n';
                break;
            }
        }
        
        // If the loop completes without breaking, the k-th closest point is not found
        if (k > 0) {
            cout << "-1\n";
        }
    }
    
    return 0;
}