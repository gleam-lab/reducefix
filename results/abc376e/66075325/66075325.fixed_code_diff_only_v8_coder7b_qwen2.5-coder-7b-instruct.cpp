#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define int long long
const int N = 2e5 + 9, inf = 0x3f3f3f3f3f3f3f3f;
int n, m,t,ans,k;
int s;
pair<int, int>a[N], b[N];
bool vis[N];
signed main() {
    cin >> t;
    while (t--) {
        cin >> n  >> k;
        for (int i = 1; i <= n; i++) {
            cin >> a[i].first;
            a[i].second = i;
        }
        for (int i = 1; i <= n; i++) {
            cin >> b[i].first;
            b[i].second = i;
        }
        sort(a + 1, a + n + 1);
        sort(b + 1, b + n + 1);
        ans=inf;
        s=0;
        priority_queue<int,vector<int>,greater<int>>q;
        for (int i = 1; i <= n; i++) {
            q.push(b[i]);
            s += b[i];            
            while (q.size() > k) {
                s -= q.top(); 
                q.pop();
            }      
            if(q.size()==k)      
            ans = min(ans, (s+a[i].first) * a[i].first);
        }

        cout << ans << endl;
    }
    return 0;
}