/*
    ------ Floyd Warshall ------

    The Floyd-Warshall algorithm is a DP algorithm used to discover the shortest paths in a weighted graph, which includes negative weight cycles.

    Steps:

    1) First of all make a distance matrix where dist[i][j] is the shortest distance between i and j.
    2) We set diagonal elements to 0 ,other elements to infinity(i.e. INT_MAX) and elements having weight not equal to 0 as dist[i][j] =weight[i][j].
    3) Then for every vertex we update the dist[i][j] to be the minimum of dist[i][j] and sum of dist[i][k] and dist[k][j].

    Thus we will get dist matrix showing the shortest distances between all pairs of the graph
*/

#include <bits/stdc++.h>
using namespace std;

void floydWarshall(vector<vector<int>> &weight, vector<vector<int>> &dist)
{
    int n = weight.size();

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
            {
                dist[i][j] = 0;
            }
            else if (weight[i][j] == 0)
            {
                dist[i][j] = INT_MAX;
            }
            else
            {
                dist[i][j] = weight[i][j];
            }
        }
    }
    

    for (int k = 0; k < n; k++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int i = 0; i < n; i++)
            {

                if (dist[i][k] < INT_MAX && dist[k][j] < INT_MAX)
                {
                    if(dist[i][j]>dist[i][k]+dist[k][j]){
                        dist[i][j] = dist[i][k] + dist[k][j];
                    }
                }
            }
        }
    }

}
