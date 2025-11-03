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
    
    // We remove exactly K elements, so we keep (n - k) elements.
    // To minimize (max - min) of the remaining sequence,
    // we should consider contiguous segments of length (n - k) in the sorted array.
    // Because rearrangement isn't allowed but sorting doesn't change the relative differences,
    // and optimal solution will always be a contiguous block after sorting.
    
    int min_diff = a[n - 1] - a[0]; // worst case: keep everything
    int keep = n - k;
    
    // Try all possible contiguous segments of length 'keep'
    for (int i = 0; i + keep - 1 < n; i++) {
        int j = i + keep - 1;
        min_diff = min(min_diff, a[j] - a[i]);
    }
    
    cout << min_diff << endl;
    
    return 0;
}