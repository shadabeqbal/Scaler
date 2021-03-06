/*  // //  
   // //        
   \\//       
    \>>      
    //\\    
   //  \\
Author: Shadab Eqbal 
Created on: "11-08-2021" 
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
    vi vec = {1,8,11,3,5,16};
    int min = 0, max = 0;
    max = accumulate(vec.begin(), vec.end(), max);
    int painters = 3; 
    int tp = painters;
    int ans = 0;
    while(min < max){
        int mid = ceil(min + (max - min)/2);

        int sum = 0;
        for(int i=0;i<vec.size();i++){
            if(sum+vec[i] <= mid){
                sum+=vec[i];
            }else{
                sum=0;
                sum+=vec[i];
                tp--;
            }
        }
        tp--;
        if(tp == 0){
            ans = mid;
            max = mid - 1;
        }else{
            min = mid + 1;
        }

        tp = painters;
    }


    cout<<ans<<"\n";

    return 0;
}