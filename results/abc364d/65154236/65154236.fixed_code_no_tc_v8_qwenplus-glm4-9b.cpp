#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

const int INF = 1e9 + 7;
const int N = 200005;

int a[N], cnt[N];

void add(int x) {
    for (int i = x; i <= N - 5; i += i & -i) cnt[i]++;
}

void remove(int x) {
    for (int i = x; i; i -= i & -i) cnt[i]--;
}

int query(int x) {
    int ans = 0;
    for (int i = x; i; i -= i & -i) ans += cnt[i];
    return ans;
}

int solve(int l, int r, int k) {
    int ans = INF;
    for (int i = l; i <= r; i++) {
        int dist = a[i] - (k - query(i));
        if (dist < 0) dist = -dist;
        ans = min(ans, dist);
    }
    return ans;
}

int main() {
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        add(a[i]);
    }
    for (int j = 1; j <= q; j++) {
        int b, k;
        cin >> b >> k;
        int low = b - N + 5;
        int high = b + N - 5;
        int result = solve(low, high, k);
        cout << result << endl;
    }
    return 0;
}