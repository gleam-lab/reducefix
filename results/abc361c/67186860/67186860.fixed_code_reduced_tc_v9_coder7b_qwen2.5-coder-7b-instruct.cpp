#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    
    vector<long long> v(n);
    for(int i = 0; i < n; ++i) {
        cin >> v[i];
    }

    sort(v.begin(), v.end());

    // The optimal strategy is to remove k smallest elements and k largest elements
    // This way, the difference between the maximum and minimum values in the resulting array will be minimized
    long long ans = v[n-k-1] - v[k];

    cout << ans << '\n';

    return 0;
}