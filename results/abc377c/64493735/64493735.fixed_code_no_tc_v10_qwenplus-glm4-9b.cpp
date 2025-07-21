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

        s<p(int, int)> ans;
        for (int i = 0; i < M; i++) {
            int a, b;
            scanf("%d %d", &a, &b);
            ans.emplace(a, b);

            // Directions the piece can be captured from
            int directions[][2] = {{1, 2}, {2, 1}, {2, -1}, {-2, 1}, {-2, -1}, {-1, 2}, {-1, -2}, {1, -2}};
            for (int dir = 0; dir < 8; dir++) {
                int x = a + directions[dir][0];
                int y = b + directions[dir][1];
                if (1 <= x && x <= N && 1 <= y && y <= N) {
                    ans.emplace(x, y);
                }
            }
        }

        // Calculate the number of free cells
        long long total_cells = (long long)N * N;
        long long captured_cells = ans.size();
        long long free_cells = total_cells - captured_cells;
        print(free_cells);

        return 0;
    }

private:
    // Function to print out results
    void print() {
        cout << '\n';
    }
    // Function to print out single values
    template <class T>
    void print(const T& v) {
        cout << v;
        print();
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    Sub sub;
    sub.solve();
    return 0;
}