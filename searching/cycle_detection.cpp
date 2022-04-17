/*  // //  
   // //        
   \\//       
    \>>      
    //\\    
   //  \\
Author: Shadab Eqbal 
Created on: "17-04-2022" 
Name: Graph Cycle Detection
Link: 
*/

#include <bits/stdc++.h>

using namespace std;

#define MAX 1e18
#define MIN -1e18
#define MOD 1000000007
#define PI 3.141592653589793238

#define pb push_back
#define mp make_pair
#define ll long long int

#define all(x) x.begin(), x.end()

#define clr(x) memset(&x, 0, sizeof(x))

#define srt(x) sort(all(x))
#define search(x, y) binary_search(all(x), y)

#define fr(x, n) for (ll i = x; i < n; i++)
#define frk(x, n, k) for (ll i = x; i < n; i += k)
#define frit(x) for (auto i = x.begin(); i != x.end(); ++i)

typedef pair<int, int> pi;
typedef vector<pi> vpi;
typedef vector<vpi> vvpi;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<ll, ll> pll;
typedef vector<pll> vpl;
typedef vector<ll> vll;
typedef vector<vll> vvll;

list<int> *adj;
void graph_init(int V){
    adj = new list<int>[V];
}
void graph_addEdge(int x,int y){
    adj[x].push_back(y);
    adj[y].push_back(x);
}
bool graph_isCyclicUtil(int x,bool visited[],int p){
    visited[x] = true;

    list<int>::iterator i;
    for(i = adj[x].begin(); i != adj[x].end();++i){
        if(!visited[*i]){
            if(graph_isCyclicUtil(*i,visited,x))
                return true;
        }else if(*i != p) return true;
    }

    return false;
}
bool graph_isCyclic(int V){
    bool *visited = new bool[V];
    for(int i=0;i<V;i++)
        visited[i] = false;

    //DFS
    for(int x=0;x<V;x++){
        if(!visited[x])
            if(graph_isCyclicUtil(x,visited,-1))
                return true;
    }
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int V = 5;
    graph_init(V);
    graph_addEdge(0,0);
    graph_addEdge(0,1);
    graph_addEdge(1,0);
    graph_addEdge(1,3);
    graph_addEdge(1,4);
    graph_addEdge(2,1);
    graph_addEdge(2,2);
    graph_addEdge(2,3);
    graph_addEdge(2,4);
    graph_addEdge(3,2);
    if(graph_isCyclic(V))
        cout<<"Graph contain cycle.";
    else
        cout<<"Graph do not contain any cycle.";

    return 0;
}