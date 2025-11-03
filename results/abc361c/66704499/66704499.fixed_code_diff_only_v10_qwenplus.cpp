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
    
    // We need to remove exactly K elements, leaving (n - k) elements
    // To minimize (max - min) of the remaining sequence,
    // we should consider contiguous segments of length (n - k) in the sorted array
    int min_diff = a[n - 1] - a[0];
    int remaining = n - k;
    
    for (int i = 0; i + remaining - 1 < n; i++) {
        int j = i + remaining - 1;
        min_diff = min(min_diff, a[j] - a[i]);
    }
    
    cout << min_diff << endl;
    
    return 0;
}