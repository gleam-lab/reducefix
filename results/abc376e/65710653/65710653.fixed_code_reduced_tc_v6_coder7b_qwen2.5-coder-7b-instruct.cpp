#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define rep(i,n) for(int i=0;i<(n);i++)
#define rep1(i,n) for(int i=1;i<=(n);i++)
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<pair<int, int>> ab(n);
        rep(i, n) cin >> ab[i].first;
        rep(i, n) cin >> ab[i].second;
        
        sort(all(ab));
        priority_queue<int, vector<int>, greater<int>> pq;
        int sum = 0;
        rep(i, k) {
            pq.push(ab[i].second);
            sum += ab[i].second;
        }
        
        int ans = sum * ab[k-1].first;
        rep(i, n-k) {
            sum -= pq.top(); pq.pop();
            pq.push(ab[k+i].second);
            sum += ab[k+i].second;
            ans = min(ans, sum * ab[k+i].first);
        }
        
        cout << ans << "\n";
    }
    return 0;
}