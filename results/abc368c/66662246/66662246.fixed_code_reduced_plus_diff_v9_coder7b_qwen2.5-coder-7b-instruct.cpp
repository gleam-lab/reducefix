#include <iostream>
#include <vector>

using namespace std;

long long solve(vector<int>& a) {
    long long ans = 0;
    int n = a.size();
    for (int i = 0; i < n; ++i) {
        int x = a[i];
        while (x > 0) {
            ++ans;
            if (ans % 3 == 0) {
                x -= 3;
            } else {
                --x;
            }
        }
    }
    return ans;
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    cout << solve(a) << endl;
    return 0;
}