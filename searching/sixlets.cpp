/*  // //  
   // //        
   \\//       
    \>>      
    //\\    
   //  \\
Author: Shadab Eqbal 
Created on: "19-12-2021" 
Name: 
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

vi arr = {400,500,300,800,100};
int B = 3;
int solve(int idx, int sum,int size){
    if(size == B) return 1;
    int ans=0; 
    for(int i=idx;i<arr.size();i++){
        if(sum+arr[i] > 1000) continue;

        ans+=solve(i+1,sum+arr[i],size+1);
    }

    return ans; 
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout<<solve(0,0,0);
    return 0;
}