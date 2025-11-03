#include<iostream>
#include<vector>
#include<queue>

using namespace std;
using ll = long long;

int main()
{
    int N;
    cin >> N;
    vector<ll> H(N);
    for (int i = 0; i < N; i++) {
        cin >> H[i];
    }

    ll T = 0;
    queue<ll> enemies;
    for (int i = 0; i < N; i++) {
        enemies.push(H[i]);
    }

    while (!enemies.empty()) {
        T++;
        ll& health = enemies.front();
        if (T % 3 == 0) {
            health -= 3;
        } else {
            health -= 1;
        }
        
        if (health <= 0) {
            enemies.pop();
        }
    }

    cout << T << endl;
    return 0;
}