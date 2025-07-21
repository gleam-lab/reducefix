#include <bits/stdc++.h>

using namespace std;

const int MAXN = 4e5 + 10;

int H, W, Q;
bool coo[MAXN][MAXN];

vector<int> row[MAXN], col[MAXN];

auto erase = [&](int i, int j){
    if(i == 0 || j == 0) return;
    row[i].erase(find(row[i].begin(), row[i].end(), j));
    col[j].erase(find(col[j].begin(), col[j].end(), i));
    coo[i][j] = false;
};

auto bin = [&](int r, int c){
    auto& r_set = row[r];
    auto& c_set = col[c];
    auto rit = lower_bound(r_set.begin(), r_set.end(), c);
    if(rit != r_set.begin()) erase(r, *(--rit));
    if(rit != r_set.end()) erase(r, *rit);
    auto cit = lower_bound(c_set.begin(), c_set.end(), r);
    if(cit != c_set.begin()) erase(*(--cit), c);
    if(cit != c_set.end()) erase(*cit, c);
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> H >> W >> Q;
    memset(coo, 0, sizeof(coo));
    for(int i = 1; i <= H; i++) {
        row[i].push_back(0);
        row[i].push_back(W + 1);
    }
    for(int j = 1; j <= W; j++) {
        col[j].push_back(0);
        col[j].push_back(H + 1);
    }

    int r, c;
    while(Q--) {
        cin >> r >> c;
        if(!coo[r][c]) {
            bin(r, c);
        } else {
            erase(r, c);
        }
    }

    int ans = 0;
    for(int i = 1; i <= H; i++)
        for(int j = 1; j <= W; j++)
            if(coo[i][j])
                ans++;

    cout << ans << '\n';
    return 0;
}