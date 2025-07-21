#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

typedef long long ll;

int main() {
    ll N, M;
    cin >> N >> M;
    
    vector<pair<ll, ll>> pieces(M);
    set<pair<ll, ll>> unique_pieces;
    set<pair<ll, ll>> horizontal_lines;
    set<pair<ll, ll>> vertical_lines;
    set<pair<ll, ll>> diagonal_lines1;
    set<pair<ll, ll>> diagonal_lines2;

    for (ll i = 0; i < M; ++i) {
        ll a, b;
        cin >> a >> b;
        pieces[i] = {a, b};
        unique_pieces.insert({a, b});
        horizontal_lines.insert({a, b});
        vertical_lines.insert({a, b});
        diagonal_lines1.insert({a + b, a - b});
        diagonal_lines2.insert({a + b, b - a});
    }

    set<pair<ll, ll>> all_lines;
    setmerge(all_lines, horizontal_lines);
    setmerge(all_lines, vertical_lines);
    setmerge(all_lines, diagonal_lines1);
    setmerge(all_lines, diagonal_lines2);

    ll total_squares = N * N;
    ll occupied_squares = unique_pieces.size() + all_lines.size();

    cout << total_squares - occupied_squares << endl;

    return 0;
}