#include <iostream>
using namespace std;
int main() {
    int n, m;
    cin >> n >> m;
    if (n < m) {
        cout << 0;
        return 0;
    }
    int arr[200005];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = 1; j < n; j++) {
            sum = (sum + arr[(i + j) % n]) % m;
            if (sum == 0) {
                ans++;
            }
        }
    }
    cout << ans;
    return 0;
}