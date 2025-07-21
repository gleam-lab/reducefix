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

        unordered_set<long long> ans;
        for (long long i = 0; i < M; i++) {
            long long a, b;
            cin >> a >> b;
            long long idx = (a - 1) * N + b;
            ans.insert(idx);

            // Check all possible moves
            vector<long long> dx = {2, 2, -2, -2, 1, 1, -1, -1};
            vector<long long> dy = {1, -1, 1, -1, 2, -2, 2, -2};
            for (long long k = 0; k < 8; k++) {
                long long nx = a + dx[k];
                long long ny = b + dy[k];
                if (nx > 0 && nx <= N && ny > 0 && ny <= N) {
                    long long nidx = (nx - 1) * N + ny;
                    ans.insert(nidx);
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
    sub->solve();
    delete sub;
    return 0;
}