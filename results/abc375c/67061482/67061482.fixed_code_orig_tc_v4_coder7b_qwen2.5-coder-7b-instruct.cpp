#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    long long x = 0, y = 0;
    double ans = 0;

    for(int i = 0; i < N; ++i){
        long long nx, ny;
        cin >> nx >> ny;
        ans += hypot(x - nx, y - ny);
        x = nx;
        y = ny;
    }

    ans += hypot(x, y);
    printf("%.10f\n", ans);

    return 0;
}