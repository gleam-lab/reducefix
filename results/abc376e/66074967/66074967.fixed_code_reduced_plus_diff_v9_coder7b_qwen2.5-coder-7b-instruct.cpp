#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

#define int long long

int n, k;
vector<pair<int,int>> a, b;

void solve() {
    cin >> n >> k;
    a.clear(), b.clear();
    a.resize(n), b.resize(n);

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

    int ans = LLONG_MAX;
    int sum = 0;
    priority_queue<int> pq;
    for(int i = 0; i < n; ++i) {
        pq.push(-b[i].first);
        sum += b[i].first;
        if(pq.size() > k) {
            sum += pq.top();
            pq.pop();
        }
        if(i >= k - 1)
            ans = min(ans, sum * a[i + 1].first);
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    while(T--)
        solve();
    return 0;
}