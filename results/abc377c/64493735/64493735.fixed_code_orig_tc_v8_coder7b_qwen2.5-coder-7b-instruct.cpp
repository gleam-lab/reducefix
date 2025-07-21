#include <iostream>
#include <set>
#include <utility>
using namespace std;

class Sub {
public:
    int solve() {
        long long N, M;
        cin >> N >> M;

        set<pair<long long, long long>> ans;
        for (long long i = 0; i < M; i++) {
            long long a, b;
            cin >> a >> b;
            ans.emplace(a, b);

            // Check all possible directions
            long long a1 = a + 1;
            long long a2 = a + 2;
            long long as1 = a - 1;
            long long as2 = a - 2;
            long long b1 = b + 1;
            long long b2 = b + 2;
            long long bs1 = b - 1;
            long long bs2 = b - 2;

            if (1 <= a2 && a2 <= N && 1 <= b1 && b1 <= N) {
                ans.emplace(a2, b1);
            }
            if (1 <= a1 && a1 <= N && 1 <= b2 && b2 <= N) {
                ans.emplace(a1, b2);
            }
            if (1 <= as1 && as1 <= N && 1 <= b2 && b2 <= N) {
                ans.emplace(as1, b2);
            }
            if (1 <= as2 && as2 <= N && 1 <= b1 && b1 <= N) {
                ans.emplace(as2, b1);
            }
            if (1 <= as2 && as2 <= N && 1 <= bs1 && bs1 <= N) {
                ans.emplace(as2, bs1);
            }
            if (1 <= as1 && as1 <= N && 1 <= bs2 && bs2 <= N) {
                ans.emplace(as1, bs2);
            }
            if (1 <= a1 && a2 <= N && 1 <= bs2 && bs2 <= N) {
                ans.emplace(a1, bs2);
            }
            if (1 <= a2 && a2 <= N && 1 <= bs1 && bs1 <= N) {
                ans.emplace(a2, bs1);
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