#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep2(i, s, n) for (ll i = (s); i < (ll)(n); i++)
#define all(x) x.begin(), x.end()

struct Event {
    int r, c, type; // type: 1 for left, -1 for right, 2 for up, -2 for down
    Event(int r, int c, int type) : r(r), c(c), type(type) {}

    // Compare two events based on row and column
    bool operator>(const Event& e) const {
        if (r == e.r) return c > e.c;
        return r > e.r;
    }
};

int main() {
    int H, W, Q;
    cin >> H >> W >> Q;
    vector<vector<int>> mp(H, vector<int>(W, 1)); // 1: wall, 0: no wall
    vector<Event> events;

    // Collect all events
    rep(i, H) rep(j, W) {
        events.push_back(Event(i, j, 1)); // left
        events.push_back(Event(i, j, -1)); // right
        events.push_back(Event(i, j, 2)); // up
        events.push_back(Event(i, j, -2)); // down
    }

    // Sort events by row and column
    sort(events.begin(), events.end());

    ll ans = H * W; // Initial count of walls
    ll q_idx = 0;

    // Process each event
    for (auto& e : events) {
        while (q_idx < Q && (e.r < R_q || (e.r == R_q && e.c < C_q))) {
            cin >> R_q >> C_q;
            --R_q; --C_q; // Convert to 0-based index
            if (mp[R_q][C_q]) {
                mp[R_q][C_q] = 0; // Bomb placed, remove the wall
                ans--;
            } else {
                // Remove walls in all four directions
                bool left = false;
                for (int j = C_q - 1; j >= 0; --j)
                    if (mp[e.r][j]) {
                        mp[e.r][j] = 0;
                        ans--;
                        left = true;
                    }
                if (!left) break;

                bool right = false;
                for (int j = C_q + 1; j < W; ++j)
                    if (mp[e.r][j]) {
                        mp[e.r][j] = 0;
                        ans--;
                        right = true;
                    }
                if (!right) break;

                bool up = false;
                for (int i = e.r - 1; i >= 0; --i)
                    if (mp[i][e.c]) {
                        mp[i][e.c] = 0;
                        ans--;
                        up = true;
                    }
                if (!up) break;

                bool down = false;
                for (int i = e.r + 1; i < H; ++i)
                    if (mp[i][e.c]) {
                        mp[i][e.c] = 0;
                        ans--;
                        down = true;
                    }
                if (!down) break;

                // Update the event with the new row and column
                e.r = e.r + down - up;
                e.c = e.c + right - left;
                e.type = e.type - down + up - right + left;
            }
            q_idx++;
        }
    }

    cout << ans << endl;
    return 0;
}