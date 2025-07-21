for(auto [v,d]:G.at(x)){
  if(seen.at(v)) continue;
  ans.at(v)=min(ans.at(v),c+d+A.at(v));
  q.push({v,c+d+A.at(v)});
}