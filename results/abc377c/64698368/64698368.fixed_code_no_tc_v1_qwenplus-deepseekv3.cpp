#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int N, M;
set<pair<int, int>> attack_positions;
set<pair<int, int>> existing_pieces;

void mark_attack_positions(int a, int b) {
    vector<pair<int, int>> moves = {
        {2, 1}, {1, 2}, {-1, 2}, {-2, 1},
        {-2, -1}, {-1, -2}, {1, -2}, {2, -1}
    };
    for (auto [dx, dy] : moves) {
        int x = a + dx;
        int y = b + dy;
        if (1 <= x && x <= N && 1 <= y && y <= N) {
            attack_positions.insert({x, y});
        }
    }
}

int main() {
    cin >> N >> M;
    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        existing_pieces.insert({a, b});
        mark_attack_positions(a, b);
    }

    ll total_squares = N * 1LL * N;
    ll under_attack = attack_positions.size();
    ll occupied = existing_pieces.size();

    // The valid positions are total squares minus those under attack and those already occupied,
    // but need to subtract the intersection of under_attack and occupied separately.
    // However, since existing_pieces are already occupied, they can't be used anyway.
    // So, the answer is total_squares - (under_attack + occupied - existing_pieces under attack).
    // But to simplify, since existing_pieces are already in occupied, and we can't place on them,
    // the answer is total_squares - (under_attack + occupied - count of existing_pieces in under_attack).
    // But since existing_pieces are not included in under_attack unless they are attackable by others,
    // which is not the case here (pieces don't attack each other), we can simply subtract under_attack and occupied.
    // However, some existing pieces might be in attack_positions, but they are already occupied.
    // So the correct formula is total_squares - under_attack - occupied + the count of existing_pieces that are also in under_attack.
    // But since existing_pieces are already in occupied, and under_attack includes some of them,
    // the total invalid positions are under_attack + occupied - existing_pieces in under_attack.
    // Wait, no. The total invalid positions are:
    // - positions under attack (including existing pieces if they are attackable by others, but since pieces don't attack each other, existing pieces are not in under_attack)
    // - existing pieces themselves (since they are occupied)
    // So the total invalid positions is under_attack + occupied, but existing pieces can be in under_attack, so we need to subtract the overlap.
    // So the answer is total_squares - (under_attack + occupied - overlap).
    // To compute overlap: the number of existing_pieces that are in attack_positions.
    int overlap = 0;
    for (auto [a, b] : existing_pieces) {
        if (attack_positions.count({a, b})) {
            overlap++;
        }
    }
    ll invalid = under_attack + occupied - overlap;
    ll answer = total_squares - invalid;
    cout << answer << endl;

    return 0;
}