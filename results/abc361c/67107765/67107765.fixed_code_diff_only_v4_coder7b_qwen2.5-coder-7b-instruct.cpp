#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, k;
    cin >> n >> k;
    vector<int> num(n);
    for(int i = 0; i < n; ++i) {
        cin >> num[i];
    }

    sort(num.begin(), num.end());

    // The optimal strategy is to remove the smallest k elements or the largest k elements
    // to minimize the difference between the maximum and minimum values of the resulting sequence B.
    int ans = min(num[n-k-1] - num[0], num[n-1] - num[k]);

    cout << ans << '\n';
    
    return 0;
}