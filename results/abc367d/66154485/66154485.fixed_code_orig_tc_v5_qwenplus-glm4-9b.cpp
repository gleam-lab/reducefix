#include <iostream>
using namespace std;
int main() {
    int n, m, ans = 0, arr[200005];
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = 0; j < n; j++) {
            sum += arr[(i + j) % n];
            if (sum % m == 0)
                ans++;
        }
    }
    cout << ans;
    return 0;
}