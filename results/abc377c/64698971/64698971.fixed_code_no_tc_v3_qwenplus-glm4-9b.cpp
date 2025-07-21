#include <iostream>
#include <vector>
#include <set>

using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repi(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
#define rrep(i, n) for (int i = n-1; i >= (int)(0); i--)
#define rrepi(i, a, b) for (int i = (int)(a); i > (int)(b); i--)
#define ALL(a) (a).begin(),(a).end()
#define IF_T if (true)

#define ll long long
using namespace std;

int N, M;

int main() {
    cin >> N >> M;
    vector<pair<int, int>> pieces(M);
    vector<vector<bool>> attack(N, vector<bool>(N, false));

    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        pieces[i] = {a, b};
        // Check all possible attack positions and mark them as true
        for (int dx = -2; dx <= 2; dx++) {
            for (int dy = -2; dy <= 2; dy++) {
                if (dx != 0 || dy != 0) {
                    int nx = a + dx;
                    int ny = b + dy;
                    if (0 <= nx && nx < N && 0 <= ny && ny < N) {
                        attack[nx][ny] = true;
                    }
                }
            }
        }
    }

    // Calculate the number of valid positions to place a new piece
    ll result = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (!attack[i][j]) {
                result++;
            }
        }
    }

    cout << result << endl;

    return 0;
}