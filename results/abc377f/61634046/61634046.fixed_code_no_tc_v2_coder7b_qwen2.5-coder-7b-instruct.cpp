#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> row(n+1), col(n+1), diag1(n+1), diag2(n+1);

    for(int i=1; i<=m; i++){
        int x, y;
        cin >> x >> y;
        row[y]++;
        col[x]++;
        diag1[x+y]++;
        diag2[x-y+n]++;
    }

    ll res = 0;

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(!row[j] && !col[i] && !diag1[i+j] && !diag2[i-j+n]){
                res++;
            }
        }
    }

    cout << res << endl;

    return 0;
}