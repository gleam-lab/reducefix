#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>

using namespace std;

struct Query {
    int r, c;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int h, w, q;
    cin >> h >> w >> q;

    vector<unordered_set<int>> rows(h);
    vector<unordered_set<int>> cols(w);

    queue<pair<int, int>> todo;

    for (int i = 0; i < q; ++i) {
        int r, c;
        cin >> r >> c;
        --r, --c;

        if (!rows[r].empty()) {
            for (int cc : rows[r]) {
                cols[cc].erase(r);
            }
            rows[r].clear();
        }

        if (!cols[c].empty()) {
            for (int rr : cols[c]) {
                rows[rr].erase(c);
            }
            cols[c].clear();
        }

        rows[r].insert(c);
        cols[c].insert(r);

        todo.push({r, c});
    }

    int walls = h * w;

    while (!todo.empty()) {
        int r = todo.front().first;
        int c = todo.front().second;
        todo.pop();

        walls--;

        if (rows[r].size() == 1 && !cols[*rows[r].begin()].empty()) {
            walls--;
            cols[*rows[r].begin()].erase(r);
            rows[r].clear();
        }

        if (cols[c].size() == 1 && !rows[*cols[c].begin()].empty()) {
            walls--;
            rows[*cols[c].begin()].erase(c);
            cols[c].clear();
        }
    }

    cout << walls << endl;

    return 0;
}