// C - Avoid Knight Attack

#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long N;
    cin >> N;

    int piece_num;
    cin >> piece_num;

    vector<pair<int, int>> pieces(piece_num);
    for (auto &p : pieces) {
        cin >> p.first >> p.second;
    }

    set<pair<int, int>> forbidden;

    for (const auto &p : pieces) {
        forbidden.insert({p.first, p.second});

        auto add = [&](int i, int j) {
            if (i >= 1 && i <= N && j >= 1 && j <= N) {
                forbidden.insert({i, j});
            }
        };

        add(p.first + 2, p.second + 1);
        add(p.first + 1, p.second + 2);
        add(p.first - 1, p.second + 2);
        add(p.first - 2, p.second + 1);
        add(p.first - 2, p.second - 1);
        add(p.first - 1, p.second - 2);
        add(p.first + 1, p.second - 2);
        add(p.first + 2, p.second - 1);
    }

    cout << (N * N - forbidden.size()) << endl;

    return 0;
}