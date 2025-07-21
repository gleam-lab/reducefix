#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    
    sort(a.begin(), a.end());
    
    int min_diff1 = INT_MAX, min_diff2 = INT_MAX, i = 0, j = n - 1;
    
    while (k--) {
        min_diff1 = min(min_diff1, a[j] - a[i]);
        
        if (j - 1 >= i) {
            min_diff1 = min(min_diff1, a[j - 1] - a[i]);
            j--;
        }
        
        min_diff2 = min(min_diff2, a[j] - a[i + 1]);
        
        if (i + 1 < j) {
            min_diff2 = min(min_diff2, a[j] - a[i + 1]);
            i++;
        }
        
        if (min_diff1 < min_diff2) {
            min_diff2 = min_diff1;
        }
    }
    
    cout << min_diff2 << endl;
    
    return 0;
}