#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int n;
    ll h;
    cin >> n;
    ll total_turns = 0;

    for (int i = 0; i < n; ++i) {
        cin >> h;
        ll full_sets = h / 3;
        ll remaining_health = h % 3;

        // Add the number of full sets times 3 since each full set takes 3 turns
        total_turns += full_sets * 3;

        // If there is any remaining health, we need to add more turns
        if (remaining_health > 0) {
            total_turns += remaining_health; // If remaining health is 1 or 2, we need 1 turn more
        }
    }

    cout << total_turns;
    return 0;
}