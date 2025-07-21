#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 100005;
int a[N], b[N];

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n, q; cin >> n >> q;
    for(int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1);

    for(int i = 1; i <= q; i++) {
        int x, k; cin >> x >> k;
        auto it = lower_bound(a + 1, a + n + 1, x);
        int pos = it - a;
        if(pos == 0) cout << abs(x - a[1]) << '\n';
        else if(pos == n) cout << abs(x - a[n]) << '\n';
        else {
            int leftDist = abs(x - a[pos]);
            int rightDist = abs(x - a[pos + 1]);
            if(k == 1 && leftDist <= rightDist || k > 1 && leftDist < rightDist) cout << leftDist << '\n';
            else cout << rightDist << '\n';
        }
    }

    return 0;
}