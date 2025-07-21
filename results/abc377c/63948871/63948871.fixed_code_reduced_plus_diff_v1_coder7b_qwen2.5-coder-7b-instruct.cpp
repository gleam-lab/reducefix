#include <iostream>
#include <vector>
#include <set>
#include <utility>

using namespace std;

const int MAX_N = 1000000000;
const int D[] = {-2, -2, -1, -1, 1, 1, 2, 2};
const int DD[] = {1, -1, 2, -2, 2, -2, 1, -1};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long N, M;
    cin >> N >> M;

    set<pair<long long, long long>> anti_dup;

    for (long long i = 0; i < M; ++i) {
        long long a, b;
        cin >> a >> b;
        anti_dup.insert({a, b});

        for (int d = 0; d < 8; ++d) {
            long long x = a + D[d], y = b + DD[d];
            if (x >= 1 && x <= N && y >= 1 && y <= N) {
                anti_dup.insert({x, y});
            }
        }
    }

    long long total_positions = N * N;
    long long available_positions = total_positions - anti_dup.size();
    
    cout << available_positions << endl;

    return 0;
}