//alibaba:dag-dfs.cpp
#include <iostream>
#include <vector>
using namespace std;
vector<int> dfs(int i,vector<int>t, vector<vector<int> >ap){
    vector<int>cost;
    if(ap[i].size()==0) {
        cost.push_back(t[i]);
        return cost;
    }
    for(int j=0;j<ap[i].size();j++){
        vector<int>ct=dfs(ap[i][j],t,ap);
        for(int k=0;k<ct.size();k++) cost.push_back(ct[k]+t[i]);
    }
    return cost;
    
}
int main(){
  int m,n;
  int link=0;
  int maxcost=0;
  cin>>m>>n;
  vector<int>t;
  for(int i=0;i<m;i++){
    int time;
    cin>>time;
    t.push_back(time);
  }
  vector<vector<int> >ap;
  vector<vector<int> >bp;
  for(int i=0;i<m;i++){
    vector<int>v;
    ap.push_back(v);
    bp.push_back(v);
  }
  for(int i=0;i<n;i++){
      int v1,v2;
      cin>>v1>>v2;
      ap[v1-1].push_back(v2-1);
      bp[v2-1].push_back(v1-1);
  }
  for(int i=0;i<m;i++){
    if(bp[i].size()==0){
        vector<int> cost=dfs(i,t,ap);
        link+=cost.size();
        for(int j=0;j<cost.size();j++) maxcost=max(maxcost,cost[j]);
    }
  }
  cout<<link<<" "<<maxcost<<endl;
  return 0;
}
