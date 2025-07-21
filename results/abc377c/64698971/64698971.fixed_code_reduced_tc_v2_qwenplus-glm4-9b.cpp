#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) begin(x), end(x)

using namespace std;

struct attack {
    int x, y;
    int range;
    vector<pair<int, int>> directions;
};

bool can_attack(int x, int y, int ax, int ay, int n) {
    for (auto& a : attack_map) {
        int dx = a.x - x;
        int dy = a.y - y;
        if (dx == 0 && dy == 0) continue;
        int r = a.range * n / a.x;
        if (abs(dx) + abs(dy) <= 2 * r) return true;
        if (abs(dx) > abs(dy)) {
            int d = (dx > 0 ? 1 : -1) * (dy > 0 ? 1 : -1);
            if (abs(dy) == r && (dx - 2 * r) % 2 == d) return true;
            if (abs(dx) == 2 * r && (dx - 2 * r) % 2 == d) return true;
        } else {
            int d = (dy > 0 ? 1 : -1) * (dx > 0 ? 1 : -1);
            if (abs(dx) == r && (dy - 2 * r) % 2 == d) return true;
            if (abs(dy) == 2 * r && (dy - 2 * r) % 2 == d) return true;
        }
    }
    return false;
}

int N, M;
vector<attack> attack_map;

int main() {
    cin >> N >> M;
    int a, b;
    while (M--) {
        cin >> a >> b;
        if (can_attack(a, b, a, b, N)) {
            attack_map.emplace_back(a, b, 1, {{2, 0}, {0, 2}, {-2, 0}, {0, -2}, {2, 2}, {2, -2}, {-2, 2}, {-2, -2}});
        } else if (can_attack(a, b, a + 2, b + 1, N)) {
            attack_map.emplace_back(a, b, 1, {{2, 0}});
        } else if (can_attack(a, b, a + 1, b + 2, N)) {
            attack_map.emplace_back(a, b, 1, {{0, 2}});
        } else if (can_attack(a, b, a - 1, b + 2, N)) {
            attack_map.emplace_back(a, b, 1, {{-1, 2}});
        } else if (can_attack(a, b, a - 2, b + 1, N)) {
            attack_map.emplace_back(a, b, 1, {{-2, 0}});
        } else if (can_attack(a, b, a - 2, b - 1, N)) {
            attack_map.emplace_back(a, b, 1, {{-2, 0}});
        } else if (can_attack(a, b, a - 1, b - 2, N)) {
            attack_map.emplace_back(a, b, 1, {{-1, -2}});
        } else if (can_attack(a, b, a + 1, b - 2, N)) {
            attack_map.emplace_back(a, b, 1, {{0, -2}});
        } else if (can_attack(a, b, a + 2, b - 1, N)) {
            attack_map.emplace_back(a, b, 1, {{2, -1}});
        }
    }
    cout << N * N - (int)attack_map.size();
}