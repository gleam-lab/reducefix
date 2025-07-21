#include <iostream>
#include <string>
using namespace std;

int main() {
    int N;
    string S;
    cin >> N >> S;
    int ans = 0;
    for (char c : S) {
        if (c == 'P') {
            ans++;
        }
    }
    cout << ans;
    return 0;
}