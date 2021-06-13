/*  // //  
   // //        
   \\//       
    \>>      
    //\\    
   //  \\
Author: Shadab Eqbal 
Created on: "13-06-2021" 
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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int> vec = {0,0,0,1, 0, 34, 0, 234, 543};
    int zeroidx = -1,zerocount=0;
    for (int i = 0; i < vec.size(); i++)
    {
        if (vec[i] == 0){
            zerocount++;

            if(zerocount==1)
                zeroidx = i;
            
            
            continue;
        }
        
        if(zeroidx == -1)
            continue;
        
        if(zerocount==1){
            vec[zeroidx]=vec[i];
            vec[i]=0;
            zeroidx=i;
        }else{
            vec[zeroidx]=vec[i];
            vec[i]=0;
            zeroidx++;
        }
        
    }

    for (auto i : vec)
        cout << i << " ";
    
    return 0;
}