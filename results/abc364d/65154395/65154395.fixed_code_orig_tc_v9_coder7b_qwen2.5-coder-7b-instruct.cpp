#include <bits/stdc++.h>

#define endl '\n'
#define lowbit(x) (x & (-x))

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef double db;

const int INF = 0x3f3f3f3f;
const db eps = 1e-9;
const ll mod = 1e9 + 7;

int a[100005], b[100005], k[100005];
int n, q;

bool check(int mid, int b_val) {
    int cnt = 0;
    for(int i = 0; i < n; ++i) {
        if(abs(a[i] - b_val) <= mid) {
            cnt++;
        }
    }
    return cnt >= k[b_val];
}

int find_kth_closest(int b_val) {
    int l = 0, r = 2e8;
    while(l < r) {
        int mid = (l + r) / 2;
        if(check(mid, b_val)) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    return l;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    cin >> n >> q;
    for(int i = 0; i < n; ++i) cin >> a[i];
    for(int i = 0; i < q; ++i) cin >> b[i] >> k[i];

    for(int i = 0; i < q; ++i) {
        cout << find_kth_closest(b[i]) << endl;
    }

    return 0;
}