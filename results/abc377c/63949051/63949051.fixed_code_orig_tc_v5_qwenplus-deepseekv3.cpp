#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long N;
    int M;
    cin >> N >> M;

    set<pair<long long, long long>> attacked;

    for (int i = 0; i < M; ++i) {
        long long a, b;
        cin >> a >> b;
        attacked.insert({a, b});

        // All possible knight moves
        long long dx[] = {2, 1, -1, -2, -2, -1, 1, 2};
        long long dy[] = {1, 2, 2, 1, -1, -2, -2, -1};

        for (int j = 0; j < 8; ++j) {
            long long ni = a + dx[j];
            long long nj = b + dy[j];
            if (ni >= 1 && ni <= N && nj >= 1 && nj <= N) {
                attacked.insert({ni, nj});
            }
        }
    }

    long long total = N * N;
    long long unsafe = attacked.size();
    long long safe = total - unsafe;

    cout << safe << '\n';

    return 0;
}