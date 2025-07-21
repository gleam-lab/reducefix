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

        s(p(long long, long long)) occupied;
        for (long long i = 0; i < M; i++) {
            long long a, b;
            cin >> a >> b;
            occupied.emplace(a, b);

            long long a1 = a + 1, a2 = a + 2, as1 = a - 1, as2 = a - 2;
            long long b1 = b + 1, b2 = b + 2, bs1 = b - 1, bs2 = b - 2;

            if (1 <= a2 && a2 <= N && 1 <= b1 && b1 <= N) occupied.emplace(a2, b1);
            if (1 <= a1 && a1 <= N && 1 <= b2 && b2 <= N) occupied.emplace(a1, b2);
            if (1 <= as1 && as1 <= N && 1 <= b2 && b2 <= N) occupied.emplace(as1, b2);
            if (1 <= as2 && as2 <= N && 1 <= b1 && b1 <= N) occupied.emplace(as2, b1);
            if (1 <= as2 && as2 <= N && 1 <= bs1 && bs1 <= N) occupied.emplace(as2, bs1);
            if (1 <= as1 && as1 <= N && 1 <= bs2 && bs2 <= N) occupied.emplace(as1, bs2);
            if (1 <= a1 && a2 <= N && 1 <= bs2 && bs2 <= N) occupied.emplace(a1, bs2);
            if (1 <= a2 && a2 <= N && 1 <= bs1 && bs1 <= N) occupied.emplace(a2, bs1);
        }

        long long total_empty = N * N - occupied.size();
        cout << total_empty << endl;

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