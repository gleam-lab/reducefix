#include <bits/stdc++.h>
#define int long long
#define f first
#define s second
using namespace std;
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; cin >> t;
    while(t--) {
        int n, k; cin >> n >> k;
        vector<pair<int,int>> v(n);
        for(int i=0;i<n;i++) cin >> v[i].f;
        for(int i=0;i<n;i++) cin >> v[i].s;

        sort(v.begin(), v.end(), [&](const pair<int,int>& a, const pair<int,int>& b) {
            return a.f * b.s > b.f * a.s;
        });

        priority_queue<int> pq;
        int totalSum = 0;
        for(int i=0;i<k;i++) {
            pq.push(v[i].s);
            totalSum += v[i].s;
        }

        int result = INT_MAX;
        for(int i=k;i<n;i++) {
            result = min(result, (totalSum + v[i].s) * v[i].f);
            if(pq.top() > v[i].s) {
                totalSum -= pq.top();
                totalSum += v[i].s;
                pq.pop();
                pq.push(v[i].s);
            }
        }

        cout << result << '\n';
    }
}