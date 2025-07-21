#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    
    for (int &x : a) cin >> x;
    
    // Sort both parts
    sort(a.begin(), a.begin() + n - k);
    sort(a.begin() + n - k, a.end());
    
    // Find the minimum of the smallest part and the maximum of the largest part
    int min1 = *min_element(a.begin(), a.begin() + n - k);
    int max1 = *max_element(a.begin() + n - k, a.end());
    
    // Find the minimum of the largest part and the maximum of the smallest part
    int min2 = *min_element(a.begin() + n - k, a.end());
    int max2 = *max_element(a.begin(), a.begin() + n - k);
    
    // Output the minimum difference
    cout << min(max1 - min1, max2 - min2) << endl;
    
    return 0;
}