#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    string S;
    cin >> N >> S;

    vector<int> last(3, -1); // Last occurrence of P, R, S
    int ans = 0;

    for(int i = 0; i < N; ++i) {
        char c = S[i];
        int id = c == 'P' ? 0 : c == 'R' ? 1 : 2;

        // Calculate the distance from the last occurrence of the current character's next in cycle
        int dist = (id + 1) % 3;
        while(last[dist] != -1 && last[dist] >= i) {
            dist = (dist + 1) % 3;
        }

        // If we found a valid position, update answer and last occurrence
        if(dist != id) {
            ans += i - last[dist];
            last[id] = i;
        }
    }

    cout << ans << endl;
    return 0;
}