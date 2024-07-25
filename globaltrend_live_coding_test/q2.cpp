// Problem Statement
// Write a function to find the shortest path from a source vertex to all other vertices in a graph using Dijkstra's algorithm.


#include <iostream>
#include<vector>
#include<bits/stdc++.h>
// #include<priority_quque>
using namespace std;
int main() {
    int nodes;
    cout<<"Enter number of nodes : "<<endl;
    cin>>nodes;
    vector<vector<vector<int>>> adj(nodes);
    for(int i=0;i<nodes;i++){
        int adjNodes=0;
        cout<<"enter number of nodes adj to node "<<i<<endl;
        cin>>adjNodes;
        cout<<"enter all the neighbours of node "<<i<<" with weight"<<endl;
        for(int j=0;j<adjNodes;j++){
            int ngh;
            int wt;
            cin>>ngh>>wt;
            adj[i].push_back({wt,ngh});
        }
    }
    cout<<"enter the src node between(0,"<<nodes-1<<")"<<endl;
    int src;
    cin>>src;
    vector<int> dist(nodes,1e9);
    priority_queue<pair<int,int>> pq;
    pq.push({0,src});
    dist[src]=0;
    while(!pq.empty()){
        int wt=pq.top().first;
        int node=pq.top().second;
        pq.pop();
        for(auto ngh : adj[node]){
            if(wt+ngh[0]<dist[ngh[1]]){
                dist[ngh[1]]=wt+ngh[0];
                pq.push({dist[ngh[1]],ngh[1]});
            }
        }
    }
    cout<<"the distance of all other vertices from "<<src<<" is :"<<endl;
    for(auto i : dist){
        cout<<i<<" ";
    }
    
}