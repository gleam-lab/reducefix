#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Binary search to find the k-th smallest distance from b to elements in a
int find_kth_distance(const vector<int>& a, int b, int k) {
    int left = 0;
    int right = max(abs(a[0] - b), abs(a.back() - b));
    
    while (left < right) {
        int mid = (left + right) / 2;
        // Find first position where a[i] >= b - mid
        int l = lower_bound(a.begin(), a.end(), b - mid) - a.begin();
        // Find first position where a[i] > b + mid
        int r = upper_bound(a.begin(), a.end(), b + mid) - a.begin();
        
        if (r - l >= k)
            right = mid;
        else
            left = mid + 1;
    }
    return left;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, Q;
    cin >> N >> Q;
    
    vector<int> a(N);
    for (int i = 0; i < N; ++i)
        cin >> a[i];
    
    sort(a.begin(), a.end());
    
    for (int q = 0; q < Q; ++q) {
        int b, k;
        cin >> b >> k;
        cout << find_kth_distance(a, b, k) << "\n";
    }
    
    return 0;
}