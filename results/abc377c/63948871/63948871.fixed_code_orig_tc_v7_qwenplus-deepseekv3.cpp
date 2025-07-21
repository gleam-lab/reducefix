#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long N, M;
    cin >> N >> M;

    set<pair<long long, long long>> anti_dup;
    vector<pair<long long, long long>> pieces(M);

    for (long long i = 0; i < M; ++i) {
        cin >> pieces[i].first >> pieces[i].second;
        anti_dup.insert(pieces[i]);
    }

    for (const auto &p : pieces) {
        long long i = p.first;
        long long j = p.second;

        if (i + 2 <= N && j + 1 <= N) {
            anti_dup.insert({i + 2, j + 1});
        }
        if (i + 1 <= N && j + 2 <= N) {
            anti_dup.insert({i + 1, j + 2});
        }
        if (i - 1 >= 1 && j + 2 <= N) {
            anti_dup.insert({i - 1, j + 2});
        }
        if (i - 2 >= 1 && j + 1 <= N) {
            anti_dup.insert({i - 2, j + 1});
        }
        if (i - 2 >= 1 && j - 1 >= 1) {
            anti_dup.insert({i - 2, j - 1});
        }
        if (i - 1 >= 1 && j - 2 >= 1) {
            anti_dup.insert({i - 1, j - 2});
        }
        if (i + 1 <= N && j - 2 >= 1) {
            anti_dup.insert({i + 1, j - 2});
        }
        if (i + 2 <= N && j - 1 >= 1) {
            anti_dup.insert({i + 2, j - 1});
        }
    }

    long long ans = N * N - anti_dup.size();
    cout << ans << '\n';

    return 0;
}