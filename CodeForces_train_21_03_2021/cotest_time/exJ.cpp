// Made by Lina Veltman
#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
 
using namespace std;
 
 
void dfs(vector<vector<int>>& graph, int from, int to, bool color, long long& left, long long& right)
{
    if (color)
        ++left;
    else
        ++right;
    for (int i = 0; i < graph[from].size(); ++i)
        if (graph[from][i] != to)
            dfs(graph, graph[from][i], from, !color, left, right);
}
 
 
int main()
{
    int n, u, v, edges;
    cin >> n;
    edges = n - 1;
    vector<vector<int>> graph(n);
    while (edges)
    {
        cin >> u >> v;
        graph[u - 1].push_back(v - 1);
        graph[v - 1].push_back(u - 1);
        --edges;
    }
    long long left = 0;
    long long right = 0;
    dfs(graph, 0, -1, true, left, right);
    cout << left * right - (n - 1) << endl;
    return 0;
}