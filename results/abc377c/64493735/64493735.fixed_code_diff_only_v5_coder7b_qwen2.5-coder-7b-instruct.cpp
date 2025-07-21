#include <bits/stdc++.h>
using namespace std;
#define v(type) vector<type>
#define p(ate,bte) pair<ate,bte>
#define m(ate,bte) map<ate,bte>
#define s(type) set<type>
class Sub {
public:
    int solve() {
        long long N, M;
        cin >> N >> M;

        s(p(long long, long long)) ans;
        for (long long i = 0; i < M; i++) {
            long long a, b;
            cin >> a >> b;
            ans.emplace(a, b);

            // Check all possible moves
            vector<p(long long, long long)> moves = {{2, 1}, {1, 2}, {-1, 2}, {-2, 1}, {-2, -1}, {-1, -2}, {1, -2}, {2, -1}};
            for (auto &move : moves) {
                long long x = a + move.first, y = b + move.second;
                if (x >= 1 && x <= N && y >= 1 && y <= N) {
                    ans.emplace(x, y);
                }
            }
        }

        cout << N * N - ans.size() << endl;
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