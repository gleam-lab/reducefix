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

    set<pair<i32, i32>> anti_dup;

    FOR_U(_, 0, piece_num, 1) {
        i32 a, b;
        cin >> a >> b;
        anti_dup.insert({a, b});

        FOR(i, -2, 3) {
            FOR(j, -2, 3) {
                if (abs(i) + abs(j) == 3) {
                    i32 nx = a + i, ny = b + j;
                    if (nx >= 1 && nx <= N && ny >= 1 && ny <= N) {
                        anti_dup.insert({nx, ny});
                    }
                }
            }
        }
    }

    i128 safe_squares = static_cast<i128>(N * N) - static_cast<i128>(anti_dup.size());

    cout << safe_squares << endl;

    return 0;
}