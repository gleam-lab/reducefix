#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Sub {
public:
    int solve() {
        int N, M;
        cin >> N >> M;

        vector<pair<int, int>> pieces(M);
        for (int i = 0; i < M; ++i) {
            cin >> pieces[i].first >> pieces[i].second;
        }

        vector<int> parent(N * N + 1);
        vector<int> rank(N * N + 1);
        iota(parent.begin(), parent.end(), 1);
        fill(rank.begin(), rank.end(), 0);

        auto find = [&](int x) {
            if (parent[x] != x) {
                parent[x] = find(parent[x]);
            }
            return parent[x];
        };

        auto unionSet = [&](int x, int y) {
            int rootX = find(x);
            int rootY = find(y);
            if (rootX != rootY) {
                if (rank[rootX] > rank[rootY]) {
                    parent[rootY] = rootX;
                } else if (rank[rootX] < rank[rootY]) {
                    parent[rootX] = rootY;
                } else {
                    parent[rootY] = rootX;
                    rank[rootX]++;
                }
            }
        };

        // Connect pieces based on their capturing area
        for (auto &p : pieces) {
            int a = p.first, b = p.second;
            int dx[] = {2, 1, 1, 2, -2, -1, -1, -2};
            int dy[] = {1, 2, -2, -1, 1, 2, -2, -1};

            for (int i = 0; i < 8; ++i) {
                int nextA = a + dx[i], nextB = b + dy[i];
                if (nextA > 0 && nextA <= N && nextB > 0 && nextB <= N) {
                    int nextIndex = nextA * N + nextB;
                    unionSet(p.first * N + p.second, nextIndex);
                }
            }
        }

        // Calculate the number of safe squares
        vector<int> size(N * N + 1, 0);
        for (int i = 1; i <= N * N; ++i) {
            if (find(i) == i && count(pieces.begin(), pieces.end(), make_pair(i / N, i % N)) == 0) {
                int root = find(i);
                size[root]++;
            }
        }

        int totalEmpty = N * N;
        for (int s : size) {
            if (s > 0) {
                totalEmpty -= s;
            }
        }

        cout << totalEmpty << endl;
        return 0;
    }
};

int main() {
    Sub sub;
    sub.solve();
    return 0;
}