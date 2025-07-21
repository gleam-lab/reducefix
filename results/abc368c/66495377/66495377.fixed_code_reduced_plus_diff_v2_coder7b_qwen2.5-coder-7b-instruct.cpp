#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Enemy {
    ll health;
    int index;
};

bool operator<(const Enemy& a, const Enemy& b) {
    if (a.health != b.health) return a.health > b.health;
    return a.index > b.index;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<Enemy> enemies(n);
    priority_queue<Enemy> pq;

    for (int i = 0; i < n; ++i) {
        cin >> enemies[i].health;
        enemies[i].index = i + 1;
        pq.push(enemies[i]);
    }

    ll t = 0;
    while (!pq.empty()) {
        auto [health, index] = pq.top();
        pq.pop();

        if (health <= 0) continue;

        --health;
        ++t;

        if (t % 3 == 0 && health >= 3) {
            health -= 2;
            ++t;
        }

        pq.push({health, index});
    }

    cout << t << endl;

    return 0;
}