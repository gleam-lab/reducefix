#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i, n) for (ll i = 0; i < n; i++)
#define vi vector<int>
#define vl vector<ll>
#define vb vector<bool>
#define vs vector<string>
#define vc vector<char>
#define ull unsigned long long
#define chmax(a, b) a = max(a, b)
#define chmin(a, b) a = min(a, b)

int main() {
    ll h, w, y;
    cin >> h >> w >> y;
    vector<vector<ll>> A(h, vector<ll>(w));
    rep(i, h) rep(j, w) cin >> A[i][j];

    // Find the maximum height to calculate the width of the area that remains above sea level after each year
    ll max_height = 0;
    rep(i, h) rep(j, w) chmax(max_height, A[i][j]);

    // Output the area of the island that remains above sea level for each year
    rep(year, y) {
        ll area = 0;
        rep(i, h) rep(j, w) {
            // If the current height is greater than the sea level for this year, count it as part of the area
            if (A[i][j] > year) {
                // Check the width of the area
                bool is_connected = false;
                rep(k, 4) {
                    ll ni = i + dx[k], nj = j + dy[k];
                    if (ni >= 0 && ni < h && nj >= 0 && nj < w && A[ni][nj] > year) {
                        is_connected = true;
                        break;
                    }
                }
                if (is_connected) {
                    area++;
                }
            }
        }
        cout << area << endl;
    }

    return 0;
}