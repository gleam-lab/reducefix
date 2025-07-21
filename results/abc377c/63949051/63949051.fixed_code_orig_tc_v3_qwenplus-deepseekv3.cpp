#include <iostream>
#include <vector>
#include <set>
#include <tuple>

using namespace std;

#define i128 long long

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    i128 N, M;
    cin >> N >> M;

    set<pair<i128, i128>> unsafe;
    vector<pair<i128, i128>> pieces(M);

    for (i128 i = 0; i < M; ++i) {
        cin >> pieces[i].first >> pieces[i].second;
        unsafe.insert(pieces[i]);
    }

    for (const auto& p : pieces) {
        i128 i = p.first;
        i128 j = p.second;

        // Check all 8 possible attack positions
        if (i + 2 <= N && j + 1 <= N) unsafe.insert({i + 2, j + 1});
        if (i + 1 <= N && j + 2 <= N) unsafe.insert({i + 1, j + 2});
        if (i - 1 >= 1 && j + 2 <= N) unsafe.insert({i - 1, j + 2});
        if (i - 2 >= 1 && j + 1 <= N) unsafe.insert({i - 2, j + 1});
        if (i - 2 >= 1 && j - 1 >= 1) unsafe.insert({i - 2, j - 1});
        if (i - 1 >= 1 && j - 2 >= 1) unsafe.insert({i - 1, j - 2});
        if (i + 1 <= N && j - 2 >= 1) unsafe.insert({i + 1, j - 2});
        if (i + 2 <= N && j - 1 >= 1) unsafe.insert({i + 2, j - 1});
    }

    i128 total = N * N;
    i128 unsafe_count = unsafe.size();
    i128 safe = total - unsafe_count;

    cout << safe << '\n';

    return 0;
}