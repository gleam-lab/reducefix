#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
    unordered_set<int> us;
    int q;
    cin >> q;

    int ans = 0;
    for (int i = 0; i < q; i++) {
        int n, x;
        cin >> n;

        if (n == 1) {
            cin >> x;
            us.insert(x);
            ans++;
        } else if (n == 2) {
            cin >> x;
            us.erase(x);
            ans--;
        } else {
            cout << us.size() << endl;
        }
    }
    return 0;
}