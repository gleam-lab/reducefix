#include <iostream>
#include <vector>
#include <set>
#include <unordered_set>
#include <utility>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long N;
    int M;
    cin >> N >> M;

    set<pair<long long, long long>> pieces;
    set<pair<long long, long long>> threatened;

    for (int i = 0; i < M; ++i) {
        long long a, b;
        cin >> a >> b;
        pieces.insert({a, b});

        // All possible moves a knight can make
        const int dx[] = {2, 1, -1, -2, -2, -1, 1, 2};
        const int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};

        for (int j = 0; j < 8; ++j) {
            long long ni = a + dx[j];
            long long nj = b + dy[j];
            if (ni >= 1 && ni <= N && nj >= 1 && nj <= N) {
                threatened.insert({ni, nj});
            }
        }
    }

    // The total available squares are N*N minus the squares that are either occupied or threatened
    long long occupied = pieces.size();
    long long total_threatened = threatened.size();
    
    // But some threatened squares might be occupied, so we need to count unique squares in threatened and pieces
    set<pair<long long, long long>> all_forbidden;
    for (const auto& p : pieces) {
        all_forbidden.insert(p);
    }
    for (const auto& p : threatened) {
        all_forbidden.insert(p);
    }

    long long forbidden = all_forbidden.size();
    long long available = N * N - forbidden;

    cout << available << endl;

    return 0;
}