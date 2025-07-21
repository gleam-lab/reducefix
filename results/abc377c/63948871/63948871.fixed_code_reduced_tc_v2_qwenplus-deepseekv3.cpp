#include <iostream>
#include <vector>
#include <set>
#include <utility>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long N, M;
    cin >> N >> M;

    set<pair<long long, long long>> prohibited;
    vector<pair<long long, long long>> pieces(M);

    for (long long i = 0; i < M; ++i) {
        cin >> pieces[i].first >> pieces[i].second;
        prohibited.insert(pieces[i]);
    }

    for (const auto &piece : pieces) {
        long long i = piece.first;
        long long j = piece.second;

        // All 8 possible knight moves
        if (i + 2 <= N && j + 1 <= N) prohibited.insert({i + 2, j + 1});
        if (i + 1 <= N && j + 2 <= N) prohibited.insert({i + 1, j + 2});
        if (i - 1 >= 1 && j + 2 <= N) prohibited.insert({i - 1, j + 2});
        if (i - 2 >= 1 && j + 1 <= N) prohibited.insert({i - 2, j + 1});
        if (i - 2 >= 1 && j - 1 >= 1) prohibited.insert({i - 2, j - 1});
        if (i - 1 >= 1 && j - 2 >= 1) prohibited.insert({i - 1, j - 2});
        if (i + 1 <= N && j - 2 >= 1) prohibited.insert({i + 1, j - 2});
        if (i + 2 <= N && j - 1 >= 1) prohibited.insert({i + 2, j - 1});
    }

    long long total = N * N;
    long long ans = total - prohibited.size();

    cout << ans << endl;

    return 0;
}