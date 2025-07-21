#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<int>
#define vl vector<ll>
#define vb vector<bool>
#define ma make_pair
#define pb push_back
#define all(c) (c).begin(), (c).end()

int main() {
    ll h, w, y; cin >> h >> w >> y;
    vl room(h, vl(w));
    for (ll i = 0; i < h; i++)
        for (ll j = 0; j < w; j++)
            cin >> room[i][j];

    // Initialize the variables
    ll ans = h * w;
    vl min_height(h, vl(w, LLONG_MAX));
    vb visited(h, vb(w, false));

    // Fill min_height with the minimum height for each cell
    for (ll i = 0; i < h; i++) {
        min_height[i][0] = room[i][0];
        min_height[i][w - 1] = room[i][w - 1];
        visited[i][0] = visited[i][w - 1] = true;
    }
    for (ll j = 1; j < w - 1; j++) {
        min_height[0][j] = room[0][j];
        min_height[h - 1][j] = room[h - 1][j];
        visited[0][j] = visited[h - 1][j] = true;
    }
    for (ll i = 1; i < h; i++) {
        for (ll j = 1; j < w; j++) {
            min_height[i][j] = min({room[i][j], min_height[i - 1][j], min_height[i + 1][j], min_height[i][j - 1], min_height[i][j + 1]});
        }
    }

    // Output the area for each year
    for (ll i = 0; i < y; i++) {
        for (ll j = 0; j < w; j++) {
            for (ll i2 = 0; i2 < h; i2++) {
                if (room[i2][j] > i + 1) {
                    ans--;
                }
            }
        }
        cout << ans << endl;
    }
}