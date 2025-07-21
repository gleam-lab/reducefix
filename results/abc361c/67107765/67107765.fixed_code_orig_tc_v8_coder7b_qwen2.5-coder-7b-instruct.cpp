#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    vector<long long> num(n);
    for (int i = 0; i < n; i++) {
        cin >> num[i];
    }
    sort(num.begin(), num.end());
    long long ans = LLONG_MAX;
    for(int i=0;i<=k;i++){
        long long mx = max(num[n-k+i-1],num[k-i]);
        long long mn = min(num[n-k+i-1],num[k-i]);
        ans = min(ans,mx-mn);
    }
    cout << ans << endl;
}