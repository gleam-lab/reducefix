#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

#define ll long long

struct Element {
    ll a, b;
};

bool compareA(const Element &a, const Element &b) {
    return a.a > b.a;
}

bool compareB(const Element &a, const Element &b) {
    return a.b < b.b;
}

ll solve(vector<Element> &elements, int k) {
    sort(elements.begin(), elements.end(), compareA); // Sort based on A in descending order
    sort(elements.begin(), elements.end(), compareB); // Sort based on B in ascending order
    
    ll maxA = elements[k-1].a;
    ll sumB = 0;
    for(int i=0; i<k; ++i) {
        sumB += elements[i].b;
    }
    
    return maxA * sumB;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;
        
        vector<Element> elements(n);
        for(int i=0; i<n; ++i) {
            cin >> elements[i].a >> elements[i].b;
        }
        
        ll result = solve(elements, k);
        cout << result << '\n';
    }
    
    return 0;
}