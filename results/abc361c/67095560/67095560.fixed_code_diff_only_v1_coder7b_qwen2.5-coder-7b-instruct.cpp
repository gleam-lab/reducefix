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
    
    // Sort the array
    sort(a.begin(), a.end());
    
    // The minimum possible value of max(B) - min(B) occurs when we remove the smallest k elements
    // and keep the rest in their original order.
    int result = a[n - 1] - a[k];
    
    cout << result << endl;
    
    return 0;
}