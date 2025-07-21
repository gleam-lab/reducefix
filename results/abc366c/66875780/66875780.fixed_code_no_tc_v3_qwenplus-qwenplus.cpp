#include <iostream>
#include <unordered_map>

using namespace std;

typedef long long ll;

void fastIO() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

void Solve() {
    fastIO();
    ll Q;
    cin >> Q;

    unordered_map<ll, int> countMap; // Tracks how many balls of each number are in the bag
    int uniqueCount = 0; // Number of distinct integers in the bag

    while (Q--) {
        ll type;
        cin >> type;

        if (type == 1) {
            ll x;
            cin >> x;
            if (countMap[x] == 0) {
                uniqueCount++;
            }
            countMap[x]++;
        } else if (type == 2) {
            ll x;
            cin >> x;
            countMap[x]--;
            if (countMap[x] == 0) {
                uniqueCount--;
            }
        } else { // type == 3
            cout << uniqueCount << "\n";
        }
    }
}

int main() {
    Solve();
    return 0;
}