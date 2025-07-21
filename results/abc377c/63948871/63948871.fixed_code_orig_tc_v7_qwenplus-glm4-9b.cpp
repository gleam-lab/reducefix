#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

const int dx[8] = {2, 2, 1, 1, -1, -1, -2, -2};
const int dy[8] = {1, -1, 2, -2, 2, -2, 1, -1};

int N, M;
vector<pair<int, int>> pieces;

bool in_bounds(int x, int y) {
    return 1 <= x && x <= N && 1 <= y && y <= N;
}

bool is_safe(int x, int y) {
    for (auto& p : pieces) {
        int px = p.first;
        int py = p.second;
        for (int i = 0; i < 8; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (in_bounds(nx, ny) && (nx == px || ny == py)) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    cin >> N >> M;
    for (int i = 0; i < M; ++i) {
        int x, y;
        cin >> x >> y;
        pieces.push_back({x, y});
    }

    int safe_count = 0;
    for (int x = 1; x <= N; ++x) {
        for (int y = 1; y <= N; ++y) {
            if (is_safe(x, y)) {
                safe_count++;
            }
        }
    }

    cout << safe_count << endl;

    return 0;
}