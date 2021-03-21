// Made by Max Bronnikov
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <map>

using namespace std;


int bfs(int s, int t, vector<int>& parent, const vector<vector<int>>& adj, const vector<vector<int>>& capacity) {
    fill(parent.begin(), parent.end(), -1);
    parent[s] = -2;
    queue<pair<int, int>> q;
    q.push({s, INT32_MAX});

    while (!q.empty()) {
        int cur = q.front().first;
        int flow = q.front().second;
        q.pop();

        for (int next : adj[cur]) {
            if (parent[next] == -1 && capacity[cur][next]) {
                parent[next] = cur;
                int new_flow = min(flow, capacity[cur][next]);
                if (next == t)
                    return new_flow;
                q.push({next, new_flow});
            }
        }
    }

    return 0;
}

int maxflow(int s, int t, const vector<vector<int>>& adj, const vector<vector<int>>& source_cap) {
    int flow = 0;
    vector<int> parent(adj.size());
    vector<vector<int>> capacity(adj.size());
    int new_flow;

    for(int i = 0; i < adj.size(); ++i){
        capacity[i] = source_cap[i];
    }

    while (new_flow = bfs(s, t, parent, adj, capacity)) {
        flow += new_flow;
        int cur = t;
        while (cur != s) {
            int prev = parent[cur];
            capacity[prev][cur] -= new_flow;
            capacity[cur][prev] += new_flow;
            cur = prev;
        }
    }

    return flow;
}

int idx(int i, int j, int n, int m){
    return i * m + j;
}

// do graph smaller
void transform_graph(vector<vector<int>>& graph, vector<vector<int>>& capacity){
    int size = 0;

    map<int, int> table;

    for(int i = 0; i < graph.size(); ++i){
        if(graph[i].size()){
            table[i] = size;
            graph[size++] = graph[i]; 
        }
    }

    graph.resize(size);
    capacity.assign(size, vector<int>(size, 0));

    for(int i = 0; i < size; ++i){
        for(int j = 0; j < graph[i].size(); ++j){
            graph[i][j] = table[graph[i][j]];
            capacity[i][graph[i][j]] = 1;
        }
    }
}

int main(){
    // read data
    int n, m;
    cin >> n >> m;

    vector<string> space(n);

    for(auto& line : space){
        cin >> line;
    }

    vector<vector<int>> graph(n*m);
    vector<vector<int>> capacity;

    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            if(space[i][j] != '#'){
                continue;
            }
            
            if(i > 0 && space[i - 1][j] == '#'){
                graph[idx(i, j, n, m)].push_back(idx(i - 1, j, n, m));
            }
            if(i < n - 1 && space[i + 1][j] == '#'){
                graph[idx(i, j, n, m)].push_back(idx(i + 1, j, n, m));
            }

            if(j > 0 && space[i][j - 1] == '#'){
                graph[idx(i, j, n, m)].push_back(idx(i, j - 1, n, m));
            }
            if(j < m - 1 && space[i][j + 1] == '#'){
                graph[idx(i, j, n, m)].push_back(idx(i, j + 1, n, m));   
            }
        }
    }

    // for(int i = 0; i < graph.size(); ++i){
    //     cout << i << " node connected: ";
    //     for(int j = 0; j < graph[i].size(); ++j){
    //         cout << graph[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    // cout << "transform" << endl;

    transform_graph(graph, capacity);

    // for(int i = 0; i < graph.size(); ++i){
    //     cout << i << " node connected: ";
    //     for(int j = 0; j < graph[i].size(); ++j){
    //         cout << graph[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    int min_flow = 5;
    for(int i = 0; i < graph.size(); ++i){
        for(int j = i + 1; j < graph.size(); ++j){
            int flow = maxflow(i, j, graph, capacity);
            min_flow = flow > min_flow ? min_flow : flow;
        }
    }

    cout << min_flow << endl;

    return 0;
}

////////////////
/*
using namespace std;
int c[10][10];
int flowPassed[10][10];
vector<int> g[10];
int parList[10];
int currentPathC[10];
int bfs(int sNode, int eNode)//breadth first search
{
   memset(parList, -1, sizeof(parList));
   memset(currentPathC, 0, sizeof(currentPathC));
   queue<int> q;//declare queue vector
   q.push(sNode);
   parList[sNode] = -1;//initialize parlist’s source node
   currentPathC[sNode] = 999;//initialize currentpath’s source node
   while(!q.empty())// if q is not empty
   {
      int currNode = q.front();
      q.pop();
      for(int i=0; i<g[currNode].size(); i++)
      {
         int to = g[currNode][i];
         if(parList[to] == -1)
         {
            if(c[currNode][to] - flowPassed[currNode][to] > 0)
            {
               parList[to] = currNode;
               currentPathC[to] = min(currentPathC[currNode],
               c[currNode][to] - flowPassed[currNode][to]);
               if(to == eNode)
               {
                  return currentPathC[eNode];
               }
               q.push(to);
            }
         }
      }
   }
   return 0;
}
int edmondsKarp(int sNode, int eNode)
{
   int maxFlow = 0;
   while(true)
   {
      int flow = bfs(sNode, eNode);
      if (flow == 0)
      {
         break;
      }
      maxFlow += flow;
      int currNode = eNode;
      while(currNode != sNode)
      {
         int prevNode = parList[currNode];
         flowPassed[prevNode][currNode] += flow;
         flowPassed[currNode][prevNode] -= flow;
         currNode = prevNode;
      }
   }
return maxFlow;
}
int main()
{
   int nodCount, edCount;
   cout<<"enter the number of nodes and edges\n";
   cin>>nodCount>>edCount;
   int source, sink;
   cout<<"enter the source and sink\n";
   cin>>source>>sink;
   for(int ed = 0; ed < edCount; ed++)
   {
      cout<<"enter the start and end vertex along with capacity\n";
      int from, to, cap;
      cin>>from>>to>>cap;
      c[from][to] = cap;
      g[from].push_back(to);
      g[to].push_back(from);
   }
   int maxFlow = edmondsKarp(source, sink);
   cout<<endl<<endl<<"Max Flow is:"<<maxFlow<<endl;
}
*/