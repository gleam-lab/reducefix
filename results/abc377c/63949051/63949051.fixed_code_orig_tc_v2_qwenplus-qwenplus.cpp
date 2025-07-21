// C - Avoid Knight Attack

#include <iostream>
#include <vector>
#include <unordered_set>
#include <tuple>
#include <cmath>

using namespace std;

#define i128 long long

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    i128 N;
    i128 M;
    cin >> N >> M;

    // Using a hash function to store pairs in unordered_set
    auto pair_hash = [](const pair<i128, i128>& p) {
        return (p.first * 1000000007LL + p.second);
    };

    unordered_set<pair<i128, i128>, decltype(pair_hash)> attacked(1024, pair_hash);
    vector<pair<i128, i128>> knights(M);

    for (i128 i = 0; i < M; ++i)
    {
        i128 a, b;
        cin >> a >> b;
        knights[i] = {a, b};
    }

    // These are the relative positions a knight can attack
    const vector<pair<i128, i128>> directions = {
        {2, 1}, {1, 2}, {-1, 2}, {-2, 1},
        {-2, -1}, {-1, -2}, {1, -2}, {2, -1}
    };

    // First add all occupied squares and their attacked squares
    for (auto [x, y] : knights)
    {
        attacked.insert({x, y});

        for (auto [dx, dy] : directions)
        {
            i128 nx = x + dx;
            i128 ny = y + dy;
            if (nx >= 1 && nx <= N && ny >= 1 && ny <= N)
            {
                attacked.insert({nx, ny});
            }
        }
    }

    // The total number of safe squares is total squares - attacked squares
    cout << (N * N - (i128)attacked.size()) << "\n";

    return 0;
}