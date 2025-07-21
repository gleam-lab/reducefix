#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pb push_back
using ll = long long;
using P = pair<int, int>;
const int INF = 1001001001;
#define yes cout << "Yes\n"
#define no cout << "No\n"
#define yn {cout << "Yes\n";} else {cout << "No\n";}
#define dame cout << -1 << endl
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    vector<int> num(n);
    for (int i = 0; i < n; i++) {
        cin >> num[i];
    }
    sort(num.begin(), num.end());
    k = min(k, n - k); // Since minimum difference will always be between k elements and n-k elements.
    int st = k / 2;
    int gl = (n - k) / 2;
    int ans = num[gl] - num[st];
    if (k % 2 == 1) {
        ans = min(ans, num[gl - 1] - num[st + 1]); // When k is odd, we also need to consider removing an additional element from the edge.
    }
    cout << ans << endl;
}