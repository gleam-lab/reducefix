#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

#define int long long

const int inf = 0x3f3f3f3f3f3f3f3f;

signed main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<pair<int, int>> a(n), b(n);
        for(int i = 0; i < n; ++i){
            cin >> a[i].first;
            a[i].second = i;
        }
        for(int i = 0; i < n; ++i){
            cin >> b[i].first;
            b[i].second = i;
        }
        
        // Sort based on A values to maximize A_i for any subset S
        sort(a.begin(), a.end());
        // Sort based on B values to minimize sum(B_i) for any subset S
        sort(b.begin(), b.end());

        int ans = inf, sum_b = 0;
        priority_queue<int, vector<int>, greater<int>> pq;

        for(int i = 0; i < n; ++i){
            pq.push(b[i].first);
            sum_b += b[i].first;
            if(pq.size() > k){
                sum_b -= pq.top();
                pq.pop();
            }
            if(i >= k - 1){
                ans = min(ans, (long long)a[i].first * sum_b);
            }
        }
        cout << ans << '\n';
    }
    return 0;
}