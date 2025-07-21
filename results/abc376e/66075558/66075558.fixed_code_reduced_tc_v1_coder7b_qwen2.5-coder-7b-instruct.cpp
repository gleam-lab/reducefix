#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

const int N = 2e5 + 9, inf = 0x3f3f3f3f3f3f3f3f;
int n, k, ans;
vector<pair<int, int>>a, b;

bool cmp(const pair<int, int>&pa, const pair<int, int>&pb) {
    return pa.first == pb.first ? b[pa.second] < b[pb.second] : pa.first < pb.first;
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        a.clear(), b.clear();
        cin >> n >> k;
        for (int i = 0; i < n; i++) {
            int ai, bi;
            cin >> ai >> bi;
            a.emplace_back(ai, i);
            b.emplace_back(bi, i);
        }
        sort(a.begin(), a.end(), cmp);
        sort(b.begin(), b.end());
        int sum = 0, max_a = 0;
        for (int i = 0; i < k; i++) {
            max_a = max(max_a, a[i].first);
            sum += b[a[i].second].first;
        }
        ans = max_a * sum;
        for (int i = k; i < n; i++) {
            max_a = max(max_a, a[i].first);
            sum -= b[a[i - k].second].first;
            sum += b[a[i].second].first;
            ans = min(ans, max_a * sum);
        }
        cout << ans << '\n';
    }
    return 0;
}