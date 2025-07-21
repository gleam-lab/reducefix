#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;
        vector<pair<int,int>> a(n), b(n);
        for(int i = 0; i < n; ++i) {
            cin >> a[i].first;
            a[i].second = i;
        }
        for(int i = 0; i < n; ++i) {
            cin >> b[i].first;
            b[i].second = i;
        }
        
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        
        int ans = 1e18;
        for(int i = 0; i <= n-k; ++i) {
            ans = min(ans, a[k+i-1].first * accumulate(b.begin()+i, b.begin()+k+i, 0LL));
        }
        
        cout << ans << "\n";
    }
    return 0;
}