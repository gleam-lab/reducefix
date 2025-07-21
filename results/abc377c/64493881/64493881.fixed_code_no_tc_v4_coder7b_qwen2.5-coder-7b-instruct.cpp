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
        scanf("%d %d", &N, &M);

        s(p<int, int>> ans;
        for (int i = 0; i < M; i++) {
            int a, b;
            scanf("%d %d", &a, &b);
            ans.emplace(a, b);

            // Check all possible positions a knight can move to
            vector<p<int, int>> moves = {{2, 1}, {1, 2}, {-1, 2}, {-2, 1}, {-2, -1}, {-1, -2}, {1, -2}, {2, -1}};
            for (auto& move : moves) {
                int x = a + move.first;
                int y = b + move.second;
                if (1 <= x && x <= N && 1 <= y && y <= N) {
                    ans.emplace(x, y);
                }
            }
        }

        printf("%lld\n", static_cast<long long>(N) * N - ans.size());

        return 0;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    Sub *sub = new Sub();
    int back = sub->solve();
    delete sub;
    return back;
}