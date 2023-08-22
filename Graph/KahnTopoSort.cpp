/*
    -------- Kahn's  Topological Sort ----------
    A Topological sort or Topological ordering of a directed graph is a linear ordering of its vertices such that for every directed edge uv from vertex u to vertex v, u comes before v in the ordering. Topological order is possible if and only if the graph has no directed cycles, i.e. if the graph is directed acyclic graph.

    Steps:

    1)Find the indegree of all the vertices and store it in an array.
    2)Pick all the vertices having zero indegrees and push them into the queue.
    3)Pop a vertex from the front of the queue and push it into the result array.
        Increase the count of visited vertices by 1.
        Reduce the in-degree of neighboring vertices by 1.
        If the in-degree of any vertex becomes zero then push it into the queue.
    4)Repeat Step 3 until the queue is empty.
    5)If the count of visited nodes is not equal to the count of vertices in the graph, then there must be a cycle in the graph and topological ordering is not possible.
*/




#include <bits/stdc++.h>
using namespace std;

class Edges
{
public:
    int src;
    int dest;
};

class Graph
{
public:
    vector<vector<int>> adjlist;
    vector<int> indegree;

    Graph(vector<Edges> &edges, int n)
    {
        adjlist.resize(n);
        indegree.resize(n, 0);
        for (auto &x : edges)
        {
            adjlist[x.src].push_back(x.dest);
            indegree[x.dest]++;
        }
    }
};

vector<int> toposort(Graph &G)
{
    vector<int> L;
    int n = G.adjlist.size();
    vector<int> indegree = G.indegree;
    vector<int> S;

    for(int i=0;i<n;i++)
    {
        if(!indegree[i]){
            S.push_back(i);
        }
    }

    while(!S.empty())
    {
        int p=S.back();
        S.pop_back();

        L.push_back(p);
        
        for(auto x: G.adjlist[p]){
            indegree[x]--;

            if(!indegree[x]){
                S.push_back(x);
            }
        }
    }

    for(int i=0;i<n;i++){
        if(indegree[i]){
            return {};
        }
    }

    return L;
}
