#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

#define int long long
#define ll long long

const int MAXN = 2e5 + 9, INF = 0x3f3f3f3f3f3f3f3f;
int n, m, t, ans, k;
ll s;
pair<ll, ll> a[MAXN], b[MAXN];

signed main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    cin >> t;
    while (t--) {
        cin >> n >> k;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i].first;
            a[i].second = i;
        }
        for (int i = 1; i <= n; ++i) {
            cin >> b[i].first;
            b[i].second = i;
        }
        
        sort(a + 1, a + n + 1);
        sort(b + 1, b + n + 1);
        
        priority_queue<ll> pq;
        ll current_sum = 0;
        
        for (int i = 0; i < k; ++i) {
            pq.push(-b[i].first);
            current_sum += b[i].first;
        }
        
        ans = INF;
        for (int i = k; i < n; ++i) {
            pq.push(-b[i].first);
            current_sum += b[i].first;
            current_sum += b[i-k+1].first;
            pq.pop();
            ans = min(ans, (current_sum - pq.top()) * a[i-k+2].first);
        }
        
        cout << ans << '\n';
    }
    
    return 0;
}