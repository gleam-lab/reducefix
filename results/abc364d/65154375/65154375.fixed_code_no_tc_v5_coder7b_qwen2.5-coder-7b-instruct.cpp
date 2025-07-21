#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
typedef long long ll;

const int INF = 0x3f3f3f3f;
const int N = 2 * 1e5 + 5;

vector<ll> a(N);

void solve(void) {
    int n, q; cin >> n >> q;
    vector<pair<ll, int>> points(n);
    for(int i = 0; i < n; i++){
        cin >> points[i].first;
        points[i].second = i + 1;
    }
    sort(points.begin(), points.end());
    for(int i = 0; i < q; i++){
        ll x; int k; cin >> x >> k;
        int pos = lower_bound(points.begin(), points.end(), make_pair(x, 0)) - points.begin();
        cout << abs(points[(pos + k - 1) % n].first - x) << endl;
    }
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1; //cin >> t;
    while (t--) solve();
    return 0;
}