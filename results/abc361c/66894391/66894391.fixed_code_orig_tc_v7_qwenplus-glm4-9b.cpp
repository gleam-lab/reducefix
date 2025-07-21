#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    sort(a.begin(), a.end());
    int left = 0, right = n;
    
    while (left < right) {
        int mid = (left + right + 1) / 2;
        int count = 0;
        // Count how many elements can be removed from the left end
        count += upper_bound(a.begin(), a.begin() + mid, mid) - a.begin();
        
        // Adjust count because we need to leave enough elements to consider the right side
        count -= (mid - count >= k) ? mid - count : 0;
        
        // Count how many elements can be removed from the right end
        count += n - lower_bound(a.begin() + n - mid, a.end(), mid);
        
        // If the total number of elements we can remove is at least k, try a larger mid
        if (count >= k) {
            left = mid;
        } else {
            right = mid - 1;
        }
    }
    
    // Output the minimum possible value of max(B) - min(B)
    cout << a[0] - (n - left) << endl;
    
    return 0;
}