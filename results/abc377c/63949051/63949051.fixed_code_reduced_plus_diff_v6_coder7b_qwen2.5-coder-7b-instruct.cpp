#include <iostream>
#include <vector>
#include <set>
#include <utility>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    i32 N;
    cin >> N;

    i32 piece_num;
    cin >> piece_num;

    vector<pair<i32, i32>> pieces(piece_num);
    for (auto &piece : pieces) {
        cin >> piece.first >> piece.second;
    }

    set<pair<i32, i32>> anti_dup;

    FOR_R(p, pieces) {
        int x = p.first, y = p.second;

        if (x + 2 <= N && y + 1 <= N) {
            anti_dup.insert({x + 2, y + 1});
        }
        if (x + 1 <= N && y + 2 <= N) {
            anti_dup.insert({x + 1, y + 2});
        }
        if (x - 1 >= 1 && y + 2 <= N) {
            anti_dup.insert({x - 1, y + 2});
        }
        if (x - 2 >= 1 && y + 1 <= N) {
            anti_dup.insert({x - 2, y + 1});
        }
        if (x - 2 >= 1 && y - 1 >= 1) {
            anti_dup.insert({x - 2, y - 1});
        }
        if (x - 1 >= 1 && y - 2 >= 1) {
            anti_dup.insert({x - 1, y - 2});
        }
        if (x + 1 <= N && y - 2 >= 1) {
            anti_dup.insert({x + 1, y - 2});
        }
        if (x + 2 <= N && y - 1 >= 1) {
            anti_dup.insert({x + 2, y - 1});
        }
    }

    out<i128>((i128)pow(N, 2) - (i128)anti_dup.size());
    return 0;
}