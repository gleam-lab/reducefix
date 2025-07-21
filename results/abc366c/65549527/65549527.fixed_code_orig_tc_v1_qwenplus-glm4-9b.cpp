#include <iostream>
#include <set>
#include <unordered_map>

using namespace std;

void solve() {
    int q;
    cin >> q;
    set<int> uniqueIntegers;
    unordered_map<int, bool> addedIntegers;
    int countUnique = 0;

    for (int i = 0; i < q; i++) {
        int a;
        cin >> a;
        if (a == 1) {
            int x;
            cin >> x;
            if (!addedIntegers[x]) {
                uniqueIntegers.insert(x);
                countUnique++;
                addedIntegers[x] = true;
            }
        } else if (a == 2) {
            int y;
            cin >> y;
            if (addedIntegers[y]) {
                countUnique--;
                addedIntegers.erase(y);
                uniqueIntegers.erase(y);
            }
        } else if (a == 3) {
            cout << countUnique << endl;
        }
    }
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
}