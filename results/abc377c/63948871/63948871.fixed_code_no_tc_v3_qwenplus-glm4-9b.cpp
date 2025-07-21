#include <iostream>
#include <vector>
#include <set>

using namespace std;

#define MAX_N 1000000000

int main() {
    int N, M;
    cin >> N >> M;

    vector<pair<int, int>> pieces(M);
    for (int i = 0; i < M; ++i) {
        cin >> pieces[i].first >> pieces[i].second;
    }

    set<pair<int, int>> attackable_positions;

    // Calculate all attackable positions for each piece
    for (const auto& p : pieces) {
        int x = p.first, y = p.second;
        int dx[] = {-2, -2, -1, -1, 1, 1, 2, 2};
        int dy[] = {-1, 1, -2, 2, -2, 2, -1, 1};

        for (int i = 0; i < 8; ++i) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx >= 1 && nx <= N && ny >= 1 && ny <= N) {
                attackable_positions.insert({nx, ny});
            }
        }
    }

    // Calculate the number of empty positions that are not attackable
    long long total_positions = (long long)N * N;
    long long attackable_count = attackable_positions.size();
    long long empty_count = total_positions - attackable_count;

    cout << empty_count << endl;

    return 0;
}