#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int N;
    cin >> N;
    
    double nowX = 0, nowY = 0, ans = 0;
    
    for(int i = 0; i < N; ++i) {
        int nextX, nextY;
        cin >> nextX >> nextY;
        
        // Calculate the distance from current position to the next point
        double dx = nextX - nowX, dy = nextY - nowY;
        double distance = sqrt(dx * dx + dy * dy);
        
        ans += distance;
        
        // Update the current position
        nowX = nextX;
        nowY = nextY;
    }
    
    // Return to the origin
    double backToOrigin = sqrt(nowX * nowX + nowY * nowY);
    ans += backToOrigin;
    
    cout << fixed << setprecision(10) << ans << endl;
    
    return 0;
}