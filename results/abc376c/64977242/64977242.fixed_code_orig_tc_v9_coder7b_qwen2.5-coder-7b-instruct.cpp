#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> A(N), B(N-1);
    for(int i=0;i<N;i++)cin>>A[i];
    for(int i=0;i<N-1;i++)cin>>B[i];
    
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    
    int i=0, j=0;
    while(i<N && j<N-1){
        if(A[i]<=B[j]){
            i++;
        }else{
            j++;
        }
    }
    
    if(i==N)return cout<<-1<<endl,0;
    else return cout<<A[i]<<endl,0;
}