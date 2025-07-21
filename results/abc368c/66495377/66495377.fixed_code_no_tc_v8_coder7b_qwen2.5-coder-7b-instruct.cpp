#include <iostream>
#include <vector>

using namespace std;

long long calculate_attacks(long long health) {
    long long attacks = 0;
    while (health > 0) {
        if ((attacks + 1) % 3 == 0) {
            health -= 3;
        } else {
            health -= 1;
        }
        attacks++;
    }
    return attacks;
}

int main() {
    int n;
    cin >> n;
    vector<long long> health(n);
    long long total_attacks = 0;

    for (int i = 0; i < n; ++i) {
        cin >> health[i];
        total_attacks += calculate_attacks(health[i]);
    }

    cout << total_attacks << endl;
    return 0;
}