#include <iostream>
#include <vector>
#include <set>
using namespace std;

const int directions[8][2] = {
    {2, 1}, {1, 2}, {-1, 2}, {-2, 1},
    {-2, -1}, {-1, -2}, {1, -2}, {2, -1}
};

bool isSafe(int x, int y, int n) {
    return x >= 0 && x < n && y >= 0 && y < n;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> pieces(m);
    set<pair<int, int>> occupied;

    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        pieces[i] = {a - 1, b - 1};
        occupied.insert({a - 1, b - 1});

        for (auto& dir : directions) {
            int dx = pieces[i].first + dir[0], dy = pieces[i].second + dir[1];
            if (isSafe(dx, dy, n)) {
                occupied.insert({dx, dy});
            }
        }
    }

    int count = n * n - occupied.size();
    cout << count << endl;
}