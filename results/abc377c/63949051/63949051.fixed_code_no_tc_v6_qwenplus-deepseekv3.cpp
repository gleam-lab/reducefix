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

    set<pair<long long, long long>> unsafe;
    vector<pair<long long, long long>> pieces(M);

    for (int i = 0; i < M; ++i) {
        cin >> pieces[i].first >> pieces[i].second;
        unsafe.insert(pieces[i]);
    }

    for (const auto &p : pieces) {
        long long i = p.first;
        long long j = p.second;

        if (i + 2 <= N && j + 1 <= N) {
            unsafe.insert({i + 2, j + 1});
        }
        if (i + 1 <= N && j + 2 <= N) {
            unsafe.insert({i + 1, j + 2});
        }
        if (i - 1 >= 1 && j + 2 <= N) {
            unsafe.insert({i - 1, j + 2});
        }
        if (i - 2 >= 1 && j + 1 <= N) {
            unsafe.insert({i - 2, j + 1});
        }
        if (i - 2 >= 1 && j - 1 >= 1) {
            unsafe.insert({i - 2, j - 1});
        }
        if (i - 1 >= 1 && j - 2 >= 1) {
            unsafe.insert({i - 1, j - 2});
        }
        if (i + 1 <= N && j - 2 >= 1) {
            unsafe.insert({i + 1, j - 2});
        }
        if (i + 2 <= N && j - 1 >= 1) {
            unsafe.insert({i + 2, j - 1});
        }
    }

    cout << N * N - unsafe.size() << '\n';

    return 0;
}