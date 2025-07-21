#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    
    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    
    // Sort the array
    sort(a.begin(), a.end());
    
    // The optimal strategy is to remove the K largest and K smallest elements
    long long min_value = a[k];
    long long max_value = a[n - k - 1];
    
    // Calculate the minimum possible difference
    long long result = max_value - min_value;
    
    cout << result << endl;
    
    return 0;
}