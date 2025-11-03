#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
int n, q;
long long a[N];

// Function to find the k-th smallest distance from point b to any A_i
long long solve(long long b, int k) {
    // Binary search on the answer (distance)
    long long left = 0, right = 2e8;
    long long result = right;
    
    while (left <= right) {
        long long mid = (left + right) / 2;
        
        // Count how many points A_i are within distance 'mid' from b
        // i.e., |a[i] - b| <= mid
        // This means: b - mid <= a[i] <= b + mid
        
        int left_idx = lower_bound(a + 1, a + n + 1, b - mid) - a;
        int right_idx = upper_bound(a + 1, a + n + 1, b + mid) - a;
        int count = right_idx - left_idx;
        
        if (count >= k) {
            result = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    
    return result;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    
    sort(a + 1, a + n + 1);
    
    for (int i = 0; i < q; i++) {
        long long b;
        int k;
        cin >> b >> k;
        cout << solve(b, k) << '\n';
    }
    
    return 0;
}