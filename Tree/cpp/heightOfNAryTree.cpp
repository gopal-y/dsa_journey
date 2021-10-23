#define TESTING
#include "header.h"

int buildTree(int arr[],int n,vi *adj){
    int root_index;
    for (int i = 0;i<n;i++)
    {
        if(arr[i]==-1){
            root_index = i;
        } else {
            adj[arr[i]].push_back(i);
            adj[i].push_back(arr[i]);
        }
    }
    DEBUG;
    return root_index;
}

int bfs(int start, vi *adj){
    map<int, int> vis;
    queue<pair<int, int>> q;
    int level = 0;
    q.push({start, 0});
     while(!q.empty()){
         pair<int, int> t = q.front();
         vis[t.first] = 1;
         q.pop();
         level = max(level, t.second);
         for (auto n : adj[t.first])
         {
             if(vis[n]!=1){
                    q.push({n, t.second + 1});
             }
         }
     }
     return level;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("A.in", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n;
    cin>>n;
    int arr[n];
    REP(i,n){
        cin >> arr[i];
    }
    vi adj[n];
    int root = buildTree(arr, n, adj);
    cout << "level " << bfs(root, adj);
}