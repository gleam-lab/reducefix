#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;

int main()
{
    int n;
    cin >> n;
    vector<ll> H(n);
    rep(i, n) cin >> H[i];

    ll T = 0;

    // We will use a priority queue to process enemies
    // Since we always attack the frontmost enemy with health > 0,
    // we need to simulate this behavior efficiently

    // We'll use a queue to maintain enemies in order
    queue<ll> enemies;
    rep(i, n) enemies.push(H[i]);

    while (!enemies.empty())
    {
        T++;
        ll h = enemies.front();
        enemies.pop();

        if (h <= 0)
            continue;

        if (T % 3 == 0)
            h -= 3;
        else
            h -= 1;

        if (h > 0)
            enemies.push(h);
    }

    cout << T << endl;
}