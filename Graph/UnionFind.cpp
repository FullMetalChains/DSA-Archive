#include <bits/stdc++.h>

using namespace std;

class UnionFind{
public:
    vector<int>arr, rank;
    UnionFind(int n){
        arr.resize(n);
        rank.resize(n);
        for(int i =0;i<n;i++){
            arr[i] = i;
            rank[i] = 1;
        }
    }

    int find(int i){
        if(i !=arr[i]){
            arr[i] = find(arr[i]);
        }
        return arr[i];
    }

    void Union(int x1, int x2){
        int a = find(x1), b = find(x2);
        if(rank[a] > rank[b]){
            arr[b] = a;
        }
        else if(rank[b] > rank[a]){
            arr[a] = b;
        }
        else{
            arr[a] = b;
            rank[b]++;
        }
    }
};