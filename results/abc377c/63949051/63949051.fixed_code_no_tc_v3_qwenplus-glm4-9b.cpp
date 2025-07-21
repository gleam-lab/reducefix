#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

#define MAXN 1000000000

int main() {
    int N, M;
    cin >> N >> M;

    vector<pair<int, int>> pieces(M);
    for (int i = 0; i < M; ++i) {
        cin >> pieces[i].first >> pieces[i].second;
    }

    set<pair<int, int>> attackable;
    for (int i = 0; i < M; ++i) {
        int x = pieces[i].first;
        int y = pieces[i].second;

        // Add all attackable positions for the current piece
        attackable.insert({x, y});
        if (x + 2 <= N && y + 1 <= N) attackable.insert({x + 2, y + 1});
        if (x + 1 <= N && y + 2 <= N) attackable.insert({x + 1, y + 2});
        if (x - 1 >= 1 && y + 2 <= N) attackable.insert({x - 1, y + 2});
        if (x - 2 >= 1 && y + 1 <= N) attackable.insert({x - 2, y + 1});
        if (x - 2 >= 1 && y - 1 >= 1) attackable.insert({x - 2, y - 1});
        if (x - 1 >= 1 && y - 2 >= 1) attackable.insert({x - 1, y - 2});
        if (x + 1 <= N && y - 2 >= 1) attackable.insert({x + 1, y - 2});
        if (x + 2 <= N && y - 1 >= 1) attackable.insert({x + 2, y - 1});
    }

    // Calculate the number of safe positions
    long long safe_positions = 0;
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            if (find(attackable.begin(), attackable.end(), {i, j}) == attackable.end()) {
                safe_positions++;
            }
        }
    }

    // Output the number of safe positions
    cout << safe_positions << endl;

    return 0;
}