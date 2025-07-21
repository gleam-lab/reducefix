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

            int a1 = a + 1;
            int a2 = a + 2;
            int as1 = a - 1;
            int as2 = a - 2;
            int b1 = b + 1;
            int b2 = b + 2;
            int bs1 = b - 1;
            int bs2 = b - 2;

            if ((1 <= a2 && a2 <= N) && (1 <= b1 && b1 <= N)) {
                ans.emplace(a2, b1);
            }
            if ((1 <= a1 && a1 <= N) && (1 <= b2 && b2 <= N)) {
                ans.emplace(a1, b2);
            }
            if ((1 <= as1 && as1 <= N) && (1 <= b2 && b2 <= N)) {
                ans.emplace(as1, b2);
            }
            if ((1 <= as2 && as2 <= N) && (1 <= b1 && b1 <= N)) {
                ans.emplace(as2, b1);
            }
            if ((1 <= as2 && as2 <= N) && (1 <= bs1 && bs1 <= N)) {
                ans.emplace(as2, bs1);
            }
            if ((1 <= as1 && as1 <= N) && (1 <= bs2 && bs2 <= N)) {
                ans.emplace(as1, bs2);
            }
            if ((1 <= a1 && a2 <= N) && (1 <= bs2 && bs2 <= N)) {
                ans.emplace(a1, bs2);
            }
            if ((1 <= a2 && a2 <= N) && (1 <= bs1 && bs1 <= N)) {
                ans.emplace(a2, bs1);
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