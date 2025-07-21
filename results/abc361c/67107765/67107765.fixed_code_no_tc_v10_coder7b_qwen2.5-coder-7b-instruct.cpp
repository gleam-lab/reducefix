#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, k;
    cin >> n >> k;
    vector<int> num(n);
    for (int i = 0; i < n; i++) {
        cin >> num[i];
    }
    
    // Sort the array to easily find the minimum and maximum values after removal
    sort(num.begin(), num.end());
    
    // The optimal strategy is to remove the smallest 'k' elements or the largest 'k' elements
    // This way, we minimize the difference between the maximum and minimum values of the resulting sequence
    int min_diff = min(num[n-k-1] - num[0], num[n-1] - num[k]);
    
    cout << min_diff << endl;
    
    return 0;
}