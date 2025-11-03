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
    // The optimal strategy is to remove some number of elements from the left
    // and the rest from the right, because the array is sorted.
    // Try all possible splits: remove i elements from the left and (k-i) from the right.
    
    int min_diff = INT_MAX;
    for (int i = 0; i <= k; i++) {
        int left_index = i;
        int right_index = n - 1 - (k - i);
        
        if (left_index <= right_index) {
            min_diff = min(min_diff, a[right_index] - a[left_index]);
        }
    }
    
    cout << min_diff << endl;
    
    return 0;
}