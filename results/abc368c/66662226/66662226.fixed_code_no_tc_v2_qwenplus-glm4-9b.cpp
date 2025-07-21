#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

int main() {
    int n;
    cin >> n;
    vector<int> health(n);
    ll total_attacks = 0;

    for (int i = 0; i < n; ++i) {
        cin >> health[i];
    }

    for (int i = 0; i < n; ++i) {
        while (health[i] > 0) {
            ll attacks_in_cycle = (health[i] + 2) / 3; // This will cover the case when health[i] is not a multiple of 3
            total_attacks += attacks_in_cycle;
            health[i] -= attacks_in_cycle * 3;
        }
    }

    cout << total_attacks << endl;
}