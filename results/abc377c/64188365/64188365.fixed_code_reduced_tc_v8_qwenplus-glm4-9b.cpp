#include <iostream>
#include <vector>
#include <set>
using namespace std;

const int moves[8][2] = {{2,1}, {1,2}, {-1,2}, {-2,1}, {-2,-1}, {-1,-2}, {1,-2}, {2,-1}};

int main() {
    long long n, m;
    cin >> n >> m;

    vector<pair<long long, long long>> points;
    for (long long i = 0; i < m; ++i) {
        long long x, y;
        cin >> x >> y;
        points.emplace_back(x - 1, y - 1);
    }

    set<pair<long long, long long>> visited;
    for (auto& p : points) {
        visited.insert(p);
        for (auto& move : moves) {
            long long nx = p.first + move[0], ny = p.second + move[1];
            if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
                visited.insert({nx, ny});
            }
        }
    }

    // Calculate the number of reachable cells by existing pieces
    long long reachable = 0;
    for (const auto& p : visited) {
        for (const auto& move : moves) {
            long long nx = p.first + move[0], ny = p.second + move[1];
            if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
                reachable++;
            }
        }
    }

    // Total cells are n*n, we subtract the number of cells taken by existing pieces
    cout << n * n - reachable << endl;

    return 0;
}