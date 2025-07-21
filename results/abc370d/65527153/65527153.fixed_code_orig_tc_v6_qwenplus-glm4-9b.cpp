#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;
using ll = long long;

const int N = 200020, INF = 0x3f3f3f3f;
int n, m, q;

vector<unordered_set<int>> st1(n + 1), st2(m + 1);

void erase_walls(int r, int c) {
    // åä¸æ¥æ¾
    for (int i = r - 1; i > 0; --i) {
        if (st1[i].find(c) == st1[i].end()) break;
        st1[i].erase(c);
        st2[c].erase(i);
    }
    // åä¸æ¥æ¾
    for (int i = r + 1; i <= n; ++i) {
        if (st1[i].find(c) == st1[i].end()) break;
        st1[i].erase(c);
        st2[c].erase(i);
    }
    // åå·¦æ¥æ¾
    for (int j = c - 1; j > 0; --j) {
        if (st2[j].find(r) == st2[j].end()) break;
        st2[j].erase(r);
        st1[r].erase(j);
    }
    // åå³æ¥æ¾
    for (int j = c + 1; j <= m; ++j) {
        if (st2[j].find(r) == st2[j].end()) break;
        st2[j].erase(r);
        st1[r].erase(j);
    }
}

int main() {
    cin >> n >> m >> q;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            st1[i].insert(j);
            st2[j].insert(i);
        }
    }

    while (q--) {
        int r, c;
        cin >> r >> c;
        if (!st1[r].count(c)) continue;
        erase_walls(r, c);
    }

    ll ans = 0;
    for (int i = 1; i <= n; ++i) ans += st1[i].size();
    cout << ans << endl;
    return 0;
}