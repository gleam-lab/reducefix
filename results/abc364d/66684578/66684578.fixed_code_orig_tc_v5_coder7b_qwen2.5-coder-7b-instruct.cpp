#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

vector<int> A, B;

// Function to perform binary search to find the k-th closest point
int binarySearch(int target, int k) {
    int left = 0, right = A.size() - 1;
    int ans = INT_MAX;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        int dist = abs(A[mid] - target);
        
        if (dist < ans) {
            ans = dist;
        }
        
        if (dist == ans) {
            --k;
        }
        
        if (k == 0) break;
        
        if (dist > ans) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, q;
    cin >> n >> q;
    
    A.resize(n);
    B.resize(q);
    
    rep(i, n) cin >> A[i];
    rep(j, q) {
        cin >> B[j].first >> B[j].second;
    }
    
    sort(A.begin(), A.end());
    
    for (auto& [b, k] : B) {
        int ans = binarySearch(b, k);
        cout << ans << '\n';
    }
    
    return 0;
}