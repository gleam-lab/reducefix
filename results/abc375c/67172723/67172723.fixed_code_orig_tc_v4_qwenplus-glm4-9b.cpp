#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    
    long double ans = 0.0;
    long double px = 0, py = 0;
    int x, y;
    
    for(int i = 0; i < n; i++){
        cin >> x >> y;
        ans += sqrt((x - px) * (x - px) + (y - py) * (y - py));
        px = x;
        py = y;
    }
    
    // Add the distance from the last point to the origin
    ans += sqrt((px - 0) * (px - 0) + (py - 0) * (py - 0));
    
    // Also add the distance from the origin to the first point
    ans += sqrt((0 - px) * (0 - px) + (0 - py) * (0 - py));
    
    printf("%.10Lf\n", ans);
    return 0;
}