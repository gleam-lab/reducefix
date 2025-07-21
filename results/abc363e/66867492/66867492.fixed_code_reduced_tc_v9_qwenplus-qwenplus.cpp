#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
using Pii = pair<int, int>;
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define pb push_back

struct Init {
    Init() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.precision(12);
    }
} init;

int H, W, Y;
vector<vector<int>> A;
vector<vector<bool>> used;
int ans;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

// Priority queue comparing the first element of vector<int> (custom comparator)
template<typename T>
struct cmp { bool operator()(T l, T r){ return l[0] > r[0]; }};
using pq_t = priority_queue<vector<int>, vector<vector<int>>, cmp<vector<int>>>;

void processYear(pq_t& pq, int year) {
    while (!pq.empty() && pq.top()[0] <= year) {
        auto top = pq.top();
        pq.pop();
        int h = top[0], i = top[1], j = top[2];
        if (!used[i][j]) {
            used[i][j] = true;
            ans--;
        }
        for (int d = 0; d < 4; ++d) {
            int ni = i + dx[d], nj = j + dy[d];
            if (ni >= 0 && nj >= 0 && ni < H && nj < W && !used[ni][nj]) {
                pq.push({A[ni][nj], ni, nj});
            }
        }
    }
}

int main() {
    cin >> H >> W >> Y;
    A.resize(H, vector<int>(W));
    used.resize(H, vector<bool>(W, false));
    for (auto &row : A) cin >> row;

    pq_t pq;
    // Push boundary cells into the priority queue
    for (int i = 0; i < H; ++i) {
        for (int j : {0, W - 1}) {
            if (!used[i][j]) {
                used[i][j] = true;
                pq.push({A[i][j], i, j});
            }
        }
    }
    for (int j = 1; j < W - 1; ++j) {
        for (int i : {0, H - 1}) {
            if (!used[i][j]) {
                used[i][j] = true;
                pq.push({A[i][j], i, j});
            }
        }
    }

    ans = H * W;
    // Preprocess all years
    vector<int> res(Y);
    for (int year = 1; year <= Y; ++year) {
        processYear(pq, year);
        res[year - 1] = ans;
    }

    for (int year = 0; year < Y; ++year) {
        cout << res[year] << '\n';
    }

    return 0;
}