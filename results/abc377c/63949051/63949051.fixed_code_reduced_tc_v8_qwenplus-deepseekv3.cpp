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
    set<pair<long long, long long>> unsafe;

    for (auto &p : pieces) {
        cin >> p.first >> p.second;
        unsafe.insert(p);
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

    long long total = N * N;
    long long unsafe_count = unsafe.size();
    cout << total - unsafe_count << endl;

    return 0;
}