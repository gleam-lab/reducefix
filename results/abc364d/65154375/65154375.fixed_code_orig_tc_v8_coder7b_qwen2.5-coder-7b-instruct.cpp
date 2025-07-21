#include <bits/stdc++.h>
#define endl "\n"
#define lowbit(x) (x & (-x))
using namespace std;

typedef long long ll;

const int INF = 0x3f3f3f3f;
const int MAXN = 2e5 + 5;

int n, q;
vector<int> a, b;
int bit[MAXN];

void update(int idx, int val) {
    while (idx < MAXN) {
        bit[idx] += val;
        idx += lowbit(idx);
    }
}

int query(int idx) {
    int sum = 0;
    while (idx > 0) {
        sum += bit[idx];
        idx -= lowbit(idx);
    }
    return sum;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    cin >> n >> q;
    a.resize(n);
    b.resize(q);

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        a[i] += (MAXN / 2); // Shift to positive range
    }

    for (int i = 0; i < q; ++i) {
        cin >> b[i];
        b[i] += (MAXN / 2); // Shift to positive range
    }

    sort(a.begin(), a.end());

    vector<vector<int>> pos(MAXN);
    for (int i = 0; i < n; ++i) {
        pos[a[i]].push_back(i);
    }

    for (int i = 0; i < q; ++i) {
        int k = b[i], cnt = 0;
        int ans = 0;
        for (int j = 0; j < MAXN; ++j) {
            if (!pos[j].empty()) {
                int size = pos[j].size();
                if (cnt + size >= k) {
                    ans = j - (k - cnt - 1);
                    break;
                }
                cnt += size;
            }
        }
        cout << ans << endl;
    }

    return 0;
}