#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    
    for(int i = 0; i < n; ++i) 
        cin >> a[i];
    
    sort(a.begin(), a.end());
    
    long long min_diff = LLONG_MAX;
    
    for(int i = 0; i <= k; ++i) {
        long long diff = a[min(n - 1, i + k)] - a[max(0, i - 1)];
        min_diff = min(min_diff, diff);
    }
    
    cout << min_diff << endl;
    
    return 0;
}