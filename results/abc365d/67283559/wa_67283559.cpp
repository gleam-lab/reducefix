#include <bits/stdc++.h>
using namespace std;
int main(){
  int N;
  cin>>N;
  string S;
  cin>>S;
  vector<char> next,hand={'R','P','S'};
  next.push_back('R');
  next.push_back('P');
  next.push_back('S');
  int total=0;
  for(int i=0;i<N;i++){
    int score=0;
    char use;
    for(int j=0;j<next.size();j++){
      char n=next[j];
      if(n=='R'&&S[i]=='S'){
        score++;
        use='R';
        break;
      }
      if(n=='P'&&S[i]=='R'){
        score++;
        use='P';
        break;
      }
      if(n=='S'&&S[i]=='P'){
        score++;
        use='S';
        break;
      }
    }
    if(score==0) use=S[i];
    next.clear();
    total+=score;
    for(auto d : hand){
      if(d!=use) next.push_back(d);
    }
  }
  next.clear();
  int total2=0;
  for(auto d : hand){
    if(d!=S[0]) next.push_back(d);
  }
  for(int i=1;i<N;i++){
    int score=0;
    char use;
    for(int j=0;j<next.size();j++){
      char n=next[j];
      if(n=='R'&&S[i]=='S'){
        score++;
        use='R';
        break;
      }
      if(n=='P'&&S[i]=='R'){
        score++;
        use='P';
        break;
      }
      if(n=='S'&&S[i]=='P'){
        score++;
        use='S';
        break;
      }
    }
    if(score==0) use=S[i];
    next.clear();
    total2+=score;
    for(auto d : hand){
      if(d!=use) next.push_back(d);
    }
  }
  cout<<max(total,total2);
}