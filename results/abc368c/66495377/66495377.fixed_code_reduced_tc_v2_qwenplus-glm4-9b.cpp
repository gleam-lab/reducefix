#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> health(n);
    for (int &h : health) cin >> h;

    int ans = 0;
    for (int h : health) {
        if (h % 3 == 0) {
            ans += h / 3;
        } else if (h % 3 == 1) {
            ans += h + 2; // 1 -> 3, then 3 -> 6
        } else { // h % 3 == 2
            ans += h + 1; // 2 -> 3, then 3 -> 6
        }
    }
    cout << ans << endl;
    return 0;
}