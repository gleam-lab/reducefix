#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long N, M;
    cin >> N >> M;

    vector<pair<long long, long long>> pieces(M);
    set<pair<long long, long long>> threatened;

    for (auto &p : pieces) {
        cin >> p.first >> p.second;
        threatened.insert(p);

        const long long di[] = {2, 1, -1, -2, -2, -1, 1, 2};
        const long long dj[] = {1, 2, 2, 1, -1, -2, -2, -1};

        for (int k = 0; k < 8; ++k) {
            long long ni = p.first + di[k];
            long long nj = p.second + dj[k];
            if (ni >= 1 && ni <= N && nj >= 1 && nj <= N) {
                threatened.insert({ni, nj});
            }
        }
    }

    long long total_squares = N * N;
    long long safe_squares = total_squares - threatened.size();
    cout << safe_squares << '\n';

    return 0;
}