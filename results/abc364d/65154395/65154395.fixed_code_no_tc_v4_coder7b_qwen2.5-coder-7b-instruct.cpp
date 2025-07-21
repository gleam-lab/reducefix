#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;
const int MAXQ = 100005;

vector<int> a(MAXN);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, q;
    cin >> n >> q;
    
    // Read coordinates of points A_i
    for(int i = 1; i <= n; ++i) {
        int ai;
        cin >> ai;
        a[ai]++;
    }
    
    // Compute prefix sums
    partial_sum(a.begin(), a.end(), a.begin());
    
    // Process each query
    for(int i = 1; i <= q; ++i) {
        int bi, kj;
        cin >> bi >> kj;
        
        // Binary search to find the k_j-th smallest distance
        int left = 0, right = 2000000000; // Upper bound for the distance
        while(left < right) {
            int mid = left + (right - left) / 2;
            if(a[bi + mid] >= kj) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        
        // Calculate the actual distance
        int distance = abs(bi - (left - 1));
        cout << distance << '\n';
    }
    
    return 0;
}