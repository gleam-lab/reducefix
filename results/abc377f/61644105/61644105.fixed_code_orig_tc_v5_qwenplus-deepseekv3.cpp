#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ll N, M;
    cin >> N >> M;

    vector<ll> rows, cols, diags, anti_diags;
    for (int i = 0; i < M; ++i) {
        ll a, b;
        cin >> a >> b;
        rows.push_back(a);
        cols.push_back(b);
        diags.push_back(a + b);
        anti_diags.push_back(a - b);
    }

    // Sort and remove duplicates
    sort(rows.begin(), rows.end());
    rows.erase(unique(rows.begin(), rows.end()), rows.end());
    sort(cols.begin(), cols.end());
    cols.erase(unique(cols.begin(), cols.end()), cols.end());
    sort(diags.begin(), diags.end());
    diags.erase(unique(diags.begin(), diags.end()), diags.end());
    sort(anti_diags.begin(), anti_diags.end());
    anti_diags.erase(unique(anti_diags.begin(), anti_diags.end()), anti_diags.end());

    ll R = rows.size();
    ll C = cols.size();
    ll D = diags.size();
    ll A = anti_diags.size();

    // Total squares under attack
    ll attacked = 0;

    // Rows and columns
    attacked += R * N + C * N - R * C;

    // Diagonals (a + b = s)
    for (ll s : diags) {
        ll min_a = max(1LL, s - N);
        ll max_a = min(N, s - 1);
        if (min_a > max_a) continue;
        attacked += (max_a - min_a + 1);
    }

    // Anti-diagonals (a - b = d)
    for (ll d : anti_diags) {
        ll min_a = max(1LL, 1 + d);
        ll max_a = min(N, N + d);
        if (min_a > max_a) continue;
        attacked += (max_a - min_a + 1);
    }

    // Subtract intersections between rows/columns and diagonals/anti-diagonals
    for (ll a : rows) {
        for (ll s : diags) {
            ll b = s - a;
            if (b >= 1 && b <= N) attacked--;
        }
        for (ll d : anti_diags) {
            ll b = a - d;
            if (b >= 1 && b <= N) attacked--;
        }
    }

    for (ll b : cols) {
        for (ll s : diags) {
            ll a = s - b;
            if (a >= 1 && a <= N) attacked--;
        }
        for (ll d : anti_diags) {
            ll a = b + d;
            if (a >= 1 && a <= N) attacked--;
        }
    }

    // Add intersections between diagonals and anti-diagonals
    for (ll s : diags) {
        for (ll d : anti_diags) {
            ll a = (s + d) / 2;
            ll b = (s - d) / 2;
            if ((s + d) % 2 == 0 && (s - d) % 2 == 0 && a >= 1 && a <= N && b >= 1 && b <= N) {
                attacked++;
            }
        }
    }

    // Total safe squares
    ll total = N * N - attacked;
    cout << total << endl;

    return 0;
}