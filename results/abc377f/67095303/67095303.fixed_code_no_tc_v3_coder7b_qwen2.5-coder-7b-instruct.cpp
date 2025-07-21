#include<bits/stdc++.h>
#define int long long
#define PII pair<int,int>

using namespace std;

bool isValid(int n, int i, int j, set<PII>& pieces) {
    for(auto& p : pieces) {
        int x = p.first, y = p.second;
        if(i == x || j == y || i + j == x + y || i - j == x - y) return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n, m;
    cin >> n >> m;
    set<PII> pieces;

    for(int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        pieces.insert({x, y});
    }

    int result = 0;
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= n; ++j) {
            if(isValid(n, i, j, pieces)) {
                ++result;
            }
        }
    }

    cout << result << '\n';

    return 0;
}