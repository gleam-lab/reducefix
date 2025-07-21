#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 5000010;

int parent[MAXN], rank[MAXN];

// å¹¶æ¥éåå§å
void init(int n) {
    for (int i = 0; i < n; ++i) {
        parent[i] = i;
        rank[i] = 0;
    }
}

// æ¥æ¾æ ¹èç¹
int find(int x) {
    if (parent[x] != x) {
        parent[x] = find(parent[x]);
    }
    return parent[x];
}

// åå¹¶
void union_set(int x, int y) {
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
}

int main() {
    int N, M;
    cin >> N >> M;

    init(4 * N * N);
    vector<pair<int, int>> pieces(M);
    for (int i = 0; i < M; ++i) {
        cin >> pieces[i].first >> pieces[i].second;
        int rootX = find((pieces[i].first - 1) * N + (pieces[i].second - 1));
        int rootY = find((pieces[i].first - 1) * N + (pieces[i].second - 1) + N * N);
        union_set(rootX, rootY);
    }

    int free_cells = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (find((i * N + j) % (N * N)) == find((i * N + j + N * N) % (N * N))) {
                free_cells++;
            }
        }
    }

    cout << free_cells << endl;

    return 0;
}