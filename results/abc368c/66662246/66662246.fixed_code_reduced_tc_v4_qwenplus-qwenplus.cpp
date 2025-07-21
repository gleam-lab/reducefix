#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;

// Function to compute ceiling of division
ll ceil_div(ll a, ll b) {
    return (a + b - 1) / b;
}

int main()
{
    int n;
    cin >> n;
    vector<ll> H(n);
    rep(i, n) cin >> H[i];

    // Priority queue to simulate the attack process
    // We'll use a min-heap with tuples (next time it can be attacked with triple damage, current health)
    priority_queue<tuple<ll, ll, ll>, vector<tuple<ll, ll, ll>>, greater<>> pq;

    // Initialize the queue with all enemies
    rep(i, n) {
        if (H[i] > 0) {
            // First triple attack will happen at T = 3
            pq.emplace(3, 1, H[i]);  // (triple attack time, damage per attack, remaining health)
        }
    }

    ll T = 0;

    while (!pq.empty()) {
        auto [triple_time, damage, health] = pq.top();
        pq.pop();

        T++;

        // If this enemy can receive triple damage now
        if (T == triple_time) {
            health -= 3;
            // Schedule next triple damage
            pq.emplace(triple_time + 3, damage, health);
        } 
        // If not triple time yet, apply single damage
        else if (T < triple_time) {
            health -= 1;
            // If we still need to attack this enemy
            if (health > 0) {
                // Put it back in the queue, possibly updating triple attack time if needed
                if (T + 1 == triple_time - 1) {
                    // When single attack happens right before triple time, triple time doesn't change
                    pq.emplace(triple_time, damage, health);
                } else {
                    // Otherwise, update triple time to the next possible triple attack time
                    ll next_triple = T + (T % 3 == 2 ? 1 : (T % 3 == 1 ? 2 : 3));
                    pq.emplace(next_triple, damage, health);
                }
            }
        }
        // This case shouldn't happen with our logic, but included for completeness
        else {
            // T has surpassed triple_time, reset triple attack schedule
            ll next_triple = T + (T % 3 == 0 ? 3 : (T % 3 == 1 ? 2 : 1));
            pq.emplace(next_triple, damage, health - 1);
        }
    }

    cout << T << endl;
}