#include<bits/stdc++.h>
#define ll long long
#define yes cout<<"YES\n"
#define no cout<<"NO\n"
#define sp ' '
using namespace std;


void solve(){
ll N;
cin>>N;
ll a[N],b[N-1];
for(int i=0;i<N;i++){
  cin>>a[i];
}
for(int i=0;i<N-1;i++){
  cin>>b[i];
}
bool x[N-1]={false};
sort(a,a+N,greater<int>());
sort(b,b+N-1,greater<int>());
ll m=0,y=N-1;
for(int i=0;i<N-1;i++){
  if(a[i]<=b[m]){
    x[m]=true;
    m++;
   
  }
  else if(a[i+1]<=b[m]){
    x[m]=true;
    m++;
    y=i;
    i++;
    
  }
  else{
    cout<<-1<<endl;
    return;
  }
}

  if(a[N-1]>b[N-2]){
    cout<<-1<<endl;
    return;
  }

cout<<a[y]<<endl;

}

int main(){
ios::sync_with_stdio(0);
cin.tie(0);

 solve();

return 0;
}