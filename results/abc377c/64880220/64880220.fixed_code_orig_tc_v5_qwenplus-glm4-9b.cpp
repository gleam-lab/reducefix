#include <iostream>
using namespace std;

int main() {
    long long n, m;
    cin >> n >> m;
    long long ans = n * n;
    int dx[8] = {2, 1, -1, -2, -2, -1, 1, 2};
    int dy[8] = {1, 2, 2, 1, -1, -2, -2, -1};

    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        for (int j = 0; j < 8; ++j) {
            int x = a + dx[j];
            int y = b + dy[j];
            if (x >= 1 && x <= n && y >= 1 && y <= n) {
                ans--;
            }
        }
    }

    cout << ans << endl;
    return 0;
}