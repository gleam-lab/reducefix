#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<long long> a(n);
    
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    
    // Sort the array
    sort(a.begin(), a.end());
    
    // Calculate the minimum possible difference
    long long min_diff = LLONG_MAX;
    for(int i = 0; i <= n - k; ++i) {
        min_diff = min(min_diff, a[i + k - 1] - a[i]);
    }
    
    cout << min_diff << endl;
    
    return 0;
}