#include <bits/stdc++.h>
using namespace std;

int main() {
    long long N, M;
    cin >> N >> M;

    set<pair<int, int>> forbidden;
    vector<pair<int, int>> pieces(M);
    set<pair<int, int>> occupied;

    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        pieces[i] = {a, b};
        occupied.insert({a, b});
    }

    vector<pair<int, int>> moves = {{2, 1}, {1, 2}, {-1, 2}, {-2, 1}, {-2, -1}, {-1, -2}, {1, -2}, {2, -1}};

    for (auto [a, b] : pieces) {
        for (auto [dx, dy] : moves) {
            int x = a + dx;
            int y = b + dy;
            if (0 <= x && x < N && 0 <= y && y < N) {
                forbidden.insert({x, y});
            }
        }
    }

    long long total = N * N;
    long long forbidden_count = forbidden.size();
    long long occupied_count = occupied.size();

    // Need to subtract the forbidden positions and the occupied positions,
    // but positions that are both occupied and forbidden should not be double-counted.
    // So, total safe positions = total - (forbidden_count + occupied_count - intersection_count)
    // Since occupied positions are not in forbidden (because you can't place a piece there anyway),
    // the intersection is the overlap between forbidden and occupied, but since occupied pieces are already counted,
    // we just need to subtract the unique positions in forbidden and occupied.
    
    // However, in reality, the forbidden positions are positions under attack, which are empty squares.
    // The occupied squares are already not available, so the total unavailable squares are forbidden + occupied.
    // But since forbidden includes positions under attack (which are empty), and occupied are the pieces themselves,
    // they are disjoint sets (a position can't be both under attack and occupied, because a piece can't attack itself).
    
    // So, total safe positions = total - (forbidden_count + occupied_count)
    cout << total - forbidden_count - occupied_count << endl;
}