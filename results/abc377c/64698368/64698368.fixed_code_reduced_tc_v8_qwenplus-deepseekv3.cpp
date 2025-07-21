#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll N; int M;
    cin >> N >> M;

    set<pair<ll, ll>> forbidden;
    vector<pair<int, int>> moves = {
        {2, 1}, {1, 2}, {-1, 2}, {-2, 1},
        {-2, -1}, {-1, -2}, {1, -2}, {2, -1}
    };

    for (int i = 0; i < M; ++i) {
        ll a, b;
        cin >> a >> b;
        a--; b--;

        for (auto [dx, dy] : moves) {
            ll x = a + dx;
            ll y = b + dy;
            if (x >= 0 && x < N && y >= 0 && y < N) {
                forbidden.insert({x, y});
            }
        }
    }

    ll total = N * N;
    ll forbidden_count = forbidden.size();
    ll answer = total - forbidden_count - M;

    // Check if any existing pieces are in forbidden positions
    // Since existing pieces are already occupied, they are not in forbidden set
    // So, answer is total squares - (forbidden squares + existing squares)
    // Existing squares are already not in forbidden set as per problem statement
    cout << answer << endl;

    return 0;
}