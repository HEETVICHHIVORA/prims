#include <bits/stdc++.h> 
vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g)
{
   unordered_map<int,list<pair<int,int>>>mp;
   for(int i=0;i<g.size();i++){
       int u = g[i].first.first;
       int v = g[i].first.second ;
       int w =g[i].second;
       mp[u].push_back(make_pair(v,w));
       mp[v].push_back(make_pair(u,w));
   }
   vector<int> parent(n+1);
   vector<bool>mst(n+1);
   vector<int>key (n+1);
   for(int i=0;i<=n;i++){
      mst[i]=false;
      parent[i]=-1;
      key[i]=INT_MAX;

   }
   key[1]=0;
   parent[1]=-1;
   for(int i=0;i<n;i++){
       int mini = INT_MAX;
       int u ;
        for(int v=1;v<=n;v++){
            if(mst[v]==false && key[v]<mini){
                mini=key[v];
                u=v;
            }
        }
        mst[u]=true ;
        for(auto it :mp[u]){
            int v = it.first ;
            int  w = it.second;
            if(mst[v]==false && w<key[v]){
                parent[v]=u ;
                key[v]=w ;
            }
        }
   }
   vector<pair<pair<int, int>, int>>result ;
   for(int i=2;i<=n;i++){
       result.push_back({{parent[i],i},key[i]});
   }
   return result ;

}