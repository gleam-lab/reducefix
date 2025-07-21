#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e9 + 10;
long long n, m;
vector<int> row, col, up[2], down[2];

bool exist(vector<int>& vec, int x) {
    return binary_search(vec.begin(), vec.end(), x);
}

int count(vector<int>& vec, int l, int r) {
    return upper_bound(vec.begin(), vec.end(), r) - lower_bound(vec.begin(), vec.end(), l);
}

void add(vector<int>& vec, int x) {
    vec.push_back(x);
    sort(vec.begin(), vec.end());
    vec.erase(unique(vec.begin(), vec.end()), vec.end());
}

int main() {
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        long long x, y; cin >> x >> y;
        int d = (x + y) & 1;
        add(row, y); add(col, x);
        add(up[d], y - x); add(down[d], x + y);
    }
    long long ans = n * n - row.size() - col.size();
    for(auto& u : up[0]) ans -= count(up[1], u + 1, MAXN);
    for(auto& d : down[0]) ans -= count(down[1], 1LL, d - 1);
    cout << ans << endl;
    return 0;
}