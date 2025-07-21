#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    string s;
    cin >> n >> s;

    int ans = 0;
    char prev = 'A';

    for (int i = 0; i < n; ++i) {
        if (prev != s[i]) {
            ++ans;
            prev = s[i];
        }
    }

    cout << ans;
    return 0;
}