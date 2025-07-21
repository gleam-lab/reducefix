#include <iostream>
#include <vector>
#include <deque>

using namespace std;
using ll = long long;

int main() {
    int n;
    cin >> n;
    vector<int> health(n);
    ll total_attacks = 0;

    for (int i = 0; i < n; ++i) {
        cin >> health[i];
        // Use a deque to simulate the process of attacking the frontmost enemy
        deque<int> q;
        q.push_back(health[i]);
        while (!q.empty()) {
            int h = q.front();
            q.pop_front();
            if (h > 0) {
                total_attacks++;
                if (total_attacks % 3 == 0) {
                    h -= 3;
                    if (h > 0) q.push_front(h);
                } else {
                    h -= 1;
                    if (h > 0) q.push_front(h);
                }
            }
        }
    }

    cout << total_attacks << endl;
}