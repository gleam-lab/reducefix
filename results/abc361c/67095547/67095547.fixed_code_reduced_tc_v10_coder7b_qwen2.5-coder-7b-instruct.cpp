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

    sort(a.begin(), a.end());
    
    // Calculate the minimum possible value of the difference between the maximum and minimum values of the resulting sequence
    long long min_diff = LLONG_MAX;
    for(int i = 0; i <= k; ++i) {
        long long diff = a[n - 1 - i] - a[k - i];
        min_diff = min(min_diff, diff);
    }
    
    cout << min_diff << endl;
    
    return 0;
}