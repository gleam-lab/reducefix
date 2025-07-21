#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long N, M;
    cin >> N >> M;

    set<pair<long long, long long>> unsafe;
    vector<pair<long long, long long>> knights(M);

    for (long long i = 0; i < M; ++i) {
        cin >> knights[i].first >> knights[i].second;
        unsafe.insert(knights[i]);
    }

    for (const auto& knight : knights) {
        long long x = knight.first;
        long long y = knight.second;

        // Check all 8 possible knight moves
        if (x + 2 <= N && y + 1 <= N) unsafe.insert({x + 2, y + 1});
        if (x + 1 <= N && y + 2 <= N) unsafe.insert({x + 1, y + 2});
        if (x - 1 >= 1 && y + 2 <= N) unsafe.insert({x - 1, y + 2});
        if (x - 2 >= 1 && y + 1 <= N) unsafe.insert({x - 2, y + 1});
        if (x - 2 >= 1 && y - 1 >= 1) unsafe.insert({x - 2, y - 1});
        if (x - 1 >= 1 && y - 2 >= 1) unsafe.insert({x - 1, y - 2});
        if (x + 1 <= N && y - 2 >= 1) unsafe.insert({x + 1, y - 2});
        if (x + 2 <= N && y - 1 >= 1) unsafe.insert({x + 2, y - 1});
    }

    long long total = N * N;
    long long unsafe_count = unsafe.size();
    long long safe = total - unsafe_count;

    cout << safe << endl;

    return 0;
}