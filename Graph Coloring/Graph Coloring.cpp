#include<bits/stdc++.h>
using namespace std;

int V;
vector<int>ve[10000];

void graph_coloring(){
    int result[V+1];
    int available[V+1];

    for(int i = 0;i<=V;i++)
    {
        result[i] = -1;
        available[i] = 0;
    }
    result[0] = 0;


    ////////////////
    for(int i = 1;i<V;i++){

        for(int j = 0;j<ve[i].size();j++){
            if(result[ve[i][j]] != -1){
                available[result[ve[i][j]]] = 1;
            }
        }


        for(int k = 0;k<V;k++){
            if(available[k] == 0){
                result[i] = k;
                break;
            }
        }
        for(int j = 0;j<ve[i].size();j++){
            if(result[ve[i][j]] != -1){
                available[result[ve[i][j]]] = 0;
            }
        }
    }

    for (int u = 0; u < V; u++)
        cout << "Vertex " << u << " --->  Color "
             << result[u] << endl;



}



int main(){
    int n;
    cin>>V>>n;
    for(int i = 0;i<n;i++){
        int u,v;
        cin>>u>>v;
        ve[u].push_back(v);
        ve[v].push_back(u);
    }

    graph_coloring();

}
