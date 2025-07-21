#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;

    int px = 0, py = 0;
    double ans = 0;
    int x, y;

    // Loop through all points except the last one
    for(int i = 0; i < n - 1; i++){
        cin >> x >> y;
        ans += sqrt((x - px) * (x - px) + (y - py) * (y - py));
        px = x;
        py = y;
    }

    // Compute the distance from the last point to the origin
    cin >> x >> y;
    ans += sqrt((x - px) * (x - px) + (y - py) * (y - py));

    printf("%.10f\n", ans);
    return 0;
}