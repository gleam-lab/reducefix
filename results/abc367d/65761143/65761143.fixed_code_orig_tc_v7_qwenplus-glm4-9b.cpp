#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);

    int sum = 0;
    for (int &x : a) {
        cin >> x;
        x %= m;
        sum = (sum + x) % m;
    }

    if (sum == 0) {
        cout << -1 << '\n';
        return 0;
    }

    map<int, int> map[2];
    map[0][0] = 1;  // Start with 1 to account for the prefix sum of 0
    map[1][0] = 1;  // Start with 1 to account for the prefix sum of 0

    int pre = 0;
    LL res = 0;
    for (int x : a) {
        pre = (pre + x) % m;
        res += map[0][pre - sum];
        res += map[1][((pre - sum) % m + m) % m];
        map[0][pre]++;
        map[1][pre]++;
    }

    cout << res << '\n';
    return 0;
}