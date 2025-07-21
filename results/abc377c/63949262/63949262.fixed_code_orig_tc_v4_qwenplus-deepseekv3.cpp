#include <iostream>
#include <vector>
#include <unordered_set>
#include <utility>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long N, M;
    cin >> N >> M;

    unordered_set<long long> unsafe_squares;
    for (long long k = 0; k < M; ++k) {
        long long a, b;
        cin >> a >> b;
        unsafe_squares.insert((a-1)*N + b); // Convert to 1-based linear index

        // Check all 8 possible knight moves
        const long long directions[8][2] = {
            {2, 1}, {1, 2}, {-1, 2}, {-2, 1},
            {-2, -1}, {-1, -2}, {1, -2}, {2, -1}
        };

        for (const auto& dir : directions) {
            long long new_a = a + dir[0];
            long long new_b = b + dir[1];
            if (new_a >= 1 && new_a <= N && new_b >= 1 && new_b <= N) {
                unsafe_squares.insert((new_a-1)*N + new_b);
            }
        }
    }

    cout << N * N - unsafe_squares.size() << endl;

    return 0;
}