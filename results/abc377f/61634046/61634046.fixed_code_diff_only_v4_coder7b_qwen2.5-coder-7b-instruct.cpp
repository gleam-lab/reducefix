#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1e3;

int n, m;
vector<int> row, col, up[2], down[2];

bool exist(vector<int>& arr, int x) {
    return binary_search(arr.begin(), arr.end(), x);
}

int count(vector<int>& arr, int l, int r) {
    return upper_bound(arr.begin(), arr.end(), r) - lower_bound(arr.begin(), arr.end(), l);
}

int main() {
    cin >> n >> m;
    for(int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        row.push_back(y);
        col.push_back(x);
        up[(x+y)%2].push_back(y-x);
        down[(x-y+n)%2].push_back(x+y);
    }

    sort(row.begin(), row.end());
    sort(col.begin(), col.end());
    sort(up[0].begin(), up[0].end());
    sort(up[1].begin(), up[1].end());
    sort(down[0].begin(), down[0].end());
    sort(down[1].begin(), down[1].end());

    long long ans = 1LL * n * n;
    ans -= 1LL * m * (n + m);
    for(auto& u : up[0]) ans -= m - abs(u);
    for(auto& d : down[1]) ans -= m - abs(m + 1 - d);
    for(auto& u : up[1]) ans -= m - abs(u);
    for(auto& d : down[0]) ans -= m - abs(m + 1 - d);
    for(auto& y : row) ans += count(up[0], y-m, y-1) + count(down[0], y+1, y+m);
    for(auto& x : col) ans += count(up[1], 1-x, m-x) + count(down[1], x+1, x+m);
    for(int i = 0; i < 2; ++i) for(int j = 0; j < 2; ++j) if((i+j)&1) {
        int x = (j-i)/2, y = (i+j)/2;
        if(1<=x&&x<=m && 1<=y&&y<=m) ans -= exist(row, y) + exist(col, x);
    }
    cout << ans << endl;
    return 0;
}