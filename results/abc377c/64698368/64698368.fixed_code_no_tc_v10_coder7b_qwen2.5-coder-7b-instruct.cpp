#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long N, M;
    cin >> N >> M;

    unordered_set<long long> attacked;

    for (long long i = 0; i < M; ++i) {
        long long a, b;
        cin >> a >> b;
        --a, --b; // Convert to 0-based index

        // Check all 8 directions
        for (int di = -2; di <= 2; ++di) {
            for (int dj = -2; dj <= 2; ++dj) {
                if (abs(di) + abs(dj) == 3) {
                    long long ni = a + di, nj = b + dj;
                    if (ni >= 0 && ni < N && nj >= 0 && nj < N) {
                        attacked.insert(ni * N + nj);
                    }
                }
            }
        }
    }

    long long total_squares = N * N;
    long long empty_squares = total_squares - attacked.size();

    cout << empty_squares << endl;

    return 0;
}