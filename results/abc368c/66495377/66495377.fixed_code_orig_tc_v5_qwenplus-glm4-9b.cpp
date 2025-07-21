#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> health(n);
    long long total_attacks = 0;

    for (int i = 0; i < n; ++i) {
        cin >> health[i];
        long long attacks_needed = (health[i] + 2) / 3; // Divide by 3, then round up
        total_attacks += attacks_needed;
    }

    cout << total_attacks << endl;
    return 0;
}