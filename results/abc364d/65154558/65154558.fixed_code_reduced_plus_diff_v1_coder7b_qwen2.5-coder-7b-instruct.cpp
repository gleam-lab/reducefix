#include<bits/stdc++.h>

using namespace std;

typedef long long LL;
const int maxn = 1e5 + 10;

vector<int> a[maxn], b[maxn];

LL query(vector<int>& arr, int k) {
    LL sum = 0, ans = 0;
    for(auto it : arr) {
        sum += it;
        if(sum >= k) {
            ans = it;
            break;
        }
    }
    return ans;
}

int main() {
    int n, q;
    scanf("%d %d", &n, &q);
    for(int i = 1; i <= n; ++i) {
        int x;
        scanf("%d", &x);
        a[x].push_back(i);
    }
    for(int i = 1; i <= q; ++i) {
        int x, k;
        scanf("%d %d", &x, &k);
        b[x].push_back(k);
    }

    for(int i = 1; i <= n; ++i) sort(a[i].begin(), a[i].end());
    for(int i = 1; i <= q; ++i) sort(b[i].begin(), b[i].end());

    vector<vector<int>> res(n + 1);
    for(int i = 1; i <= n; ++i) {
        for(auto it : b[a[i][0]]) {
            res[it].push_back(a[i][0]);
        }
    }

    for(int i = 1; i <= q; ++i) {
        printf("%lld\n", query(res[b[i][0]], b[i][1]));
    }

    return 0;
}