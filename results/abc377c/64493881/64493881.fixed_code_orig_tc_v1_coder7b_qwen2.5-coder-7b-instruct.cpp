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

        s(p<int, int>> occupied;
        for (int i = 0; i < M; i++) {
            int a, b;
            scanf("%d %d", &a, &b);
            occupied.emplace(a, b);
        }

        long long count = 0;
        for (int i = 1; i <= N; ++i) {
            for (int j = 1; j <= N; ++j) {
                bool isValid = true;
                // Check all possible positions to see if placing a piece here captures an existing one
                vector<p<int, int>> directions = {{2, 1}, {1, 2}, {-1, 2}, {-2, 1}, {-2, -1}, {-1, -2}, {1, -2}, {2, -1}};
                for (auto& dir : directions) {
                    int ni = i + dir.first, nj = j + dir.second;
                    if (ni >= 1 && ni <= N && nj >= 1 && nj <= N && occupied.count(p(ni, nj))) {
                        isValid = false;
                        break;
                    }
                }
                if (isValid) {
                    count++;
                }
            }
        }

        printf("%lld\n", count);
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