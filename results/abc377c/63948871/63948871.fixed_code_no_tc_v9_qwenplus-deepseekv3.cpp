#include <iostream>
#include <vector>
#include <set>
#include <unordered_set>
#include <utility>

using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll N, M;
    cin >> N >> M;

    set<pair<ll, ll>> unsafe_squares;

    for (ll i = 0; i < M; ++i) {
        ll a, b;
        cin >> a >> b;
        unsafe_squares.insert({a, b});

        // Check all 8 possible attack positions
        if (a + 2 <= N && b + 1 <= N) unsafe_squares.insert({a + 2, b + 1});
        if (a + 1 <= N && b + 2 <= N) unsafe_squares.insert({a + 1, b + 2});
        if (a - 1 >= 1 && b + 2 <= N) unsafe_squares.insert({a - 1, b + 2});
        if (a - 2 >= 1 && b + 1 <= N) unsafe_squares.insert({a - 2, b + 1});
        if (a - 2 >= 1 && b - 1 >= 1) unsafe_squares.insert({a - 2, b - 1});
        if (a - 1 >= 1 && b - 2 >= 1) unsafe_squares.insert({a - 1, b - 2});
        if (a + 1 <= N && b - 2 >= 1) unsafe_squares.insert({a + 1, b - 2});
        if (a + 2 <= N && b - 1 >= 1) unsafe_squares.insert({a + 2, b - 1});
    }

    ll total_squares = N * N;
    ll safe_squares = total_squares - unsafe_squares.size();

    cout << safe_squares << '\n';

    return 0;
}