#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

int main() {
    int n;
    cin >> n;
    vector<ll> health(n);
    for (int i = 0; i < n; ++i) {
        cin >> health[i];
    }
    ll total_operations = 0;

    for (int i = 0; i < n; ++i) {
        while (health[i] > 0) {
            if (total_operations % 3 == 0) {
                health[i] -= 3;
            } else {
                health[i] -= 1;
            }
            total_operations++;
        }
    }

    cout << total_operations << endl;
    return 0;
}