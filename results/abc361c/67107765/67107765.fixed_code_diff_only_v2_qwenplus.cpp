#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pb push_back
#define chmin(x, y) x = min(x, y)
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    sort(a.begin(), a.end());
    
    // We need to remove exactly K elements, leaving (n - k) elements
    // The remaining elements must be contiguous in the sorted array to minimize range
    // Try all possible contiguous subarrays of length (n - k)
    
    int min_range = a[n - 1] - a[0]; // worst case: no removal benefit
    int remaining = n - k;
    
    for (int i = 0; i + remaining - 1 < n; i++) {
        int j = i + remaining - 1;
        chmin(min_range, a[j] - a[i]);
    }
    
    cout << min_range << endl;
    
    return 0;
}