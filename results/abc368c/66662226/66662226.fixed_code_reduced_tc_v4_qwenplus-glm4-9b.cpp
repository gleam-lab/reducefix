#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> health(n);
    long long attack_count = 0;

    for (int i = 0; i < n; ++i) {
        cin >> health[i];
        while (health[i] > 0) {
            if (attack_count % 3 == 0 && health[i] >= 3) {
                health[i] -= 3;
            } else {
                health[i]--;
            }
            attack_count++;
        }
    }

    cout << attack_count << endl;
    return 0;
}