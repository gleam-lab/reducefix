#include <iostream>
#include <vector>
#include <set>
#include <utility>

using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll N, M;
    cin >> N >> M;

    set<pair<ll, ll>> dangerous;
    set<pair<ll, ll>> occupied;

    for (ll i = 0; i < M; ++i) {
        ll a, b;
        cin >> a >> b;
        occupied.insert({a, b});
        dangerous.insert({a, b});

        // Check all 8 possible moves
        if (a + 2 <= N && b + 1 <= N) dangerous.insert({a + 2, b + 1});
        if (a + 1 <= N && b + 2 <= N) dangerous.insert({a + 1, b + 2});
        if (a - 1 >= 1 && b + 2 <= N) dangerous.insert({a - 1, b + 2});
        if (a - 2 >= 1 && b + 1 <= N) dangerous.insert({a - 2, b + 1});
        if (a - 2 >= 1 && b - 1 >= 1) dangerous.insert({a - 2, b - 1});
        if (a - 1 >= 1 && b - 2 >= 1) dangerous.insert({a - 1, b - 2});
        if (a + 1 <= N && b - 2 >= 1) dangerous.insert({a + 1, b - 2});
        if (a + 2 <= N && b - 1 >= 1) dangerous.insert({a + 2, b - 1});
    }

    ll total_squares = N * N;
    ll unsafe_squares = dangerous.size();
    ll safe_squares = total_squares - unsafe_squares;

    cout << safe_squares << endl;

    return 0;
}