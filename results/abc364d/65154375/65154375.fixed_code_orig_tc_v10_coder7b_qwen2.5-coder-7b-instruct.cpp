#include <bits/stdc++.h>

#define endl "\n"

using namespace std;

const int MAXN = 1e5 + 10;

vector<int> a[MAXN], b[MAXN];

void preprocess() {
    for (int i = 1; i <= 100000; ++i) {
        for (int j = 1; j <= 100000; ++j) {
            a[i].push_back(abs(i - j));
            b[j].push_back(abs(j - i));
        }
        sort(a[i].begin(), a[i].end());
        sort(b[j].begin(), b[j].end());
    }
}

int query(int x, int k) {
    int res = 0;
    for (int i = 1; i <= 100000; ++i) {
        if (k <= a[i].size()) {
            res = a[i][k - 1];
            break;
        } else {
            k -= a[i].size();
        }
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    preprocess();

    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; ++i) {
        int x;
        cin >> x;
        a[x].push_back(0);
    }

    for (int i = 1; i <= m; ++i) {
        int x, k;
        cin >> x >> k;
        b[x].push_back(k);
    }

    for (int i = 1; i <= 100000; ++i) {
        sort(a[i].begin(), a[i].end());
        sort(b[i].begin(), b[i].end());
    }

    for (int i = 1; i <= m; ++i) {
        int x = b[i][0];
        cout << query(x, b[i][1]) << endl;
    }

    return 0;
}