#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (auto& val : v) {
        cin >> val;
    }
    
    sort(v.begin(), v.end());
    
    // We are removing exactly K elements, so we keep (n - k) elements.
    // The optimal strategy is to remove some number of elements from the left and right ends
    // because the array is sorted. We try all possible ways: remove i elements from the left
    // and (k - i) elements from the right, for i from 0 to k.
    
    int min_diff = v[n - 1] - v[0]; // worst case: no improvement
    
    for (int i = 0; i <= k; i++) {
        int left_index = i;           // remove i elements from the left
        int right_index = n - 1 - (k - i); // remove (k-i) elements from the right
        if (left_index <= right_index) {
            int diff = v[right_index] - v[left_index];
            min_diff = min(min_diff, diff);
        }
    }
    
    cout << min_diff << endl;
    
    return 0;
}