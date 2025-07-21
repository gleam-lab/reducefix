#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;

int main() {
    int n;
    cin >> n;
    vector<int> data(n);
    rep(i, n) {
        cin >> data[i];
    }
    
    ll sum = 0;
    rep(i, n) {
        // Always add the current element
        sum += data[i];
        
        // If there's a next element and we can get a better sum by doubling
        if (i + 1 < n && data[i+1] > data[i]) {
            sum += data[i+1] - data[i];  // Add the difference
            i++;  // Skip the next element as we've already handled it
        }
    }
    
    cout << sum << endl;
    return 0;
}