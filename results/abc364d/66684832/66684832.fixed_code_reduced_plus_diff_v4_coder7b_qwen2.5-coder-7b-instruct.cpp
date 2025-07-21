#include <iostream>
#include<algorithm>
#include<queue>
#include<map>
#include<vector>
#include<cstring>
using namespace std;
#define int long long
#define endl '\n'
const int N = 2e5 + 9, inf = 0x3f3f3f3f3f3f3f3f;
int n, q;
vector<int> a;

bool check(int p, int dx, int k) {
    int ln = lower_bound(a.begin(), a.end(), p - dx) - a.begin();
    int rn = upper_bound(a.begin(), a.end(), p + dx) - a.begin();
    return rn - ln >= k;
}

int findans(int pos, int k) {
    int l = 0, r = 1e8;
    while (l < r) {
        int mid = (l + r) >> 1;
        if (check(pos, mid, k)) r = mid;
        else l = mid + 1;
    }
    return l;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> q;
    a.resize(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());

    while (q--) {
        int x, k;
        cin >> x >> k;
        cout << findans(x, k) << endl;
    }

    return 0;
}