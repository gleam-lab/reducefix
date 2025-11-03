#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    sort(a.begin(), a.end());
    
    // We are removing exactly K elements, so we keep (n - k) elements
    int keep = n - k;
    long long min_diff = LLONG_MAX;
    
    // Try all possible contiguous segments of length 'keep'
    // The optimal solution will always be a contiguous segment in the sorted array
    for (int i = 0; i + keep - 1 < n; i++) {
        int j = i + keep - 1;
        min_diff = min(min_diff, (long long)(a[j] - a[i]));
    }
    
    cout << min_diff << endl;
    
    return 0;
}