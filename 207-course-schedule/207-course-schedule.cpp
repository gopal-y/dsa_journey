class Graph{
    int V;
    list<int> *adj;
    bool isCyclicHelper(int v, bool visited[], bool *rs){
        if(!visited[v]){
            visited[v]=true;
            rs[v] = true;
            
            for(auto itr=adj[v].begin();itr!=adj[v].end();++itr){
                if(!visited[*itr] && isCyclicHelper(*itr,visited,rs)){
                    return true;
                }
                else if(rs[*itr]){
                    return true;
                }
            }
            
        }
        
        rs[v]=false;
        return false;
    }
    
    public:
        Graph(int v){
            this->V=v;
            adj = new list<int>[v];
        }
    
        void addEdge(int u, int v){
            adj[u].push_back(v);
        }
    
        bool isCyclic(){
            bool *visited = new bool[V];
            bool *rs = new bool[V];
            
            for(int i=0;i<V;i++){
                visited[i] = false;
                rs[i]=false;
            }
            
            for(int i=0;i<V;i++){
                if(isCyclicHelper(i, visited, rs)) return true;
            }
            return false;
        }
};

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // build graph
        Graph g = Graph(numCourses);
        for(auto v: prerequisites){
            g.addEdge(v[0],v[1]);
        }
        
        return !g.isCyclic();
      
    }
    
};