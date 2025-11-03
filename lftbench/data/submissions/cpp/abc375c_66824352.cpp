#include <iostream>
#include <algorithm>
#include <iomanip>
#include <cmath>
#include <queue>
#include <map>
#include <set>
using namespace std;
int main() {
    int n,x=0,y=0;
    double c=0;
    cin >> n;
    pair <int,int> a[n];
    for (int i=0;i<n;i++) {
        cin >> a[i].first >> a[i].second;
    }
    for (int i=0;i<n;i++) {
        c+=sqrt(((x-a[i].first)*(x-a[i].first))+((y-a[i].second)*(y-a[i].second)));
        x=a[i].first;
        y=a[i].second;
    }
    c+=sqrt((x*x)+(y*y));
    cout << setprecision(10) << c <<endl;
}