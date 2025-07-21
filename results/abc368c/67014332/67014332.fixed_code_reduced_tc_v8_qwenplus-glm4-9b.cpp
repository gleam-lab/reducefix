#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll n, ans = 0;
    cin >> n;
    vector<pair<ll, ll>> enemies(n);
    for (ll i = 0; i < n; ++i) {
        cin >> enemies[i].first;
        enemies[i].second = i;
    }
    
    // Sort enemies by their health in descending order
    sort(enemies.begin(), enemies.end(), [](const pair<ll, ll>& a, const pair<ll, ll>& b) {
        return a.first > b.first;
    });
    
    ll current_time = 0;
    for (const auto& enemy : enemies) {
        ll health = enemy.first;
        ll index = enemy.second;
        
        // Calculate how many full rounds are needed for current enemy
        ll full_rounds = health / 3;
        health %= 3;
        
        // Add the full rounds to the answer
        ans += full_rounds;
        
        // Process remaining health
        if (health == 0) {
            continue;
        } else if (health == 1) {
            ans += 1; // Only one action is needed if remaining health is 1
        } else { // health == 2
            ans += 2; // Two actions are needed if remaining health is 2
        }
    }
    
    cout << ans;
}