#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define int long long
const int N = 1e5 + 9;

int n, q;
int a[N];

// Function to check if there are at least k points within distance 'dist' from position 'pos'
bool check(int pos, int dist, int k) {
    // Count number of A_i such that |a_i - pos| <= dist
    int left_bound = pos - dist;
    int right_bound = pos + dist;
    
    int left_idx = lower_bound(a + 1, a + n + 1, left_bound) - a;
    int right_idx = upper_bound(a + 1, a + n + 1, right_bound) - a - 1;
    
    int count = right_idx - left_idx + 1;
    return count >= k;
}

// Binary search on the answer (distance)
int findans(int pos, int k) {
    int l = 0, r = 2e8; // Maximum possible distance is 2*10^8
    
    while (l < r) {
        int mid = (l + r) / 2;
        if (check(pos, mid, k)) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    return l;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    
    sort(a + 1, a + n + 1);
    
    while (q--) {
        int x, k;
        cin >> x >> k;
        cout << findans(x, k) << '\n';
    }
    
    return 0;
}