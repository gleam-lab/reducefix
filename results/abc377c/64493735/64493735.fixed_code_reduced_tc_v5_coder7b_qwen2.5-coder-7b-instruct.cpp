#include <bits/stdc++.h>
using namespace std;
#define v(type) vector<type>
#define p(ate,bte) pair<ate,bte>
#define m(ate,bte) map<ate,bte>
#define s(type) set<type>
class Sub {
public:
    
int solve() {
    int N, M;
    cin >> N >> M;

    s(p<int, int>> ans;
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        ans.emplace(a, b);

        // Check all possible positions the knight can move to
        vector<pair<int, int>> moves = {{2, 1}, {1, 2}, {-1, 2}, {-2, 1}, {-2, -1}, {-1, -2}, {1, -2}, {2, -1}};
        for (auto &move : moves) {
            int x = a + move.first, y = b + move.second;
            if (x >= 1 && x <= N && y >= 1 && y <= N) {
                ans.emplace(x, y);
            }
        }
    }

    cout << static_cast<long long>(N) * N - ans.size();

    return 0;
}

private:
// No additional helper functions required
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    Sub *sub = new Sub();
    int back = sub->solve();
    delete sub;
    return back;
}