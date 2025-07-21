#include <bits/stdc++.h>
using namespace std;

const int N = 200000;

int n, q;
int a[N + 1];

struct Query {
    int b, k, idx;
};

Query queries[200001];

bool check(int mid, int x, int y) {
    return a[min(n, x + mid)] - a[max(0, x - mid - 1)] >= y;
}

int solve() {
    for (int i = 0; i < q; ++i) {
        queries[i].idx = i + 1;
        queries[i].b = b[i];
        queries[i].k = k[i];
    }
    
    sort(queries, queries + q);
    
    // Prepare the positions array
    for (int i = 0; i <= n; ++i) {
        a[i] = i;
    }
    
    sort(a, a + n + 1);
    
    for (int i = 0; i < q; ++i) {
        int l = -1e9, r = 1e9;
        while (r - l > 1) {
            int mid = (l + r) / 2;
            if (check(mid, queries[i].b, queries[i].k)) {
                r = mid;
            } else {
                l = mid;
            }
        }
        cout << r << " ";
    }
    cout << endl;
    return 0;
}

int main() {
    cin >> n >> q;
    int b, k;
    for (int i = 0; i < q; ++i) {
        cin >> b >> k;
        b++;
        queries[i].b = b;
        queries[i].k = k;
    }
    solve();
    return 0;
}