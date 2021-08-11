/*  // //  
   // //        
   \\//       
    \>>      
    //\\    
   //  \\
Author: Shadab Eqbal 
Created on: "02-08-2021" 
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
    vi vec = {4,8,11,15,18,24};
    int cows = 3;
    cows--;
    int current_cow_idx = 0;
    int t_cows = cows;
    int low = INT_MAX;
    int high = vec[vec.size()-1] - vec[0];
    
    //For checking the lower bound
    for(int i=0;i<vec.size()-1;i++){
        if(abs(vec[i]-vec[i+1]) < low)
            low = abs(vec[i]-vec[i+1]);
    }

    //cout<<low<<" "<<high<<" ";
    int ans =INT_MIN;
    while(low < high){
        int best_distance = INT_MIN;
        int mid = low + (high-low)/2;
        for(int i=1;i<vec.size();i++){
            if(mid <= vec[i]-vec[current_cow_idx]){
                cows--;
                best_distance = max(best_distance,vec[i]-vec[current_cow_idx]);
                current_cow_idx = i;
            }
        }
        if(cows <= 0){
            ans = max(ans,best_distance);
            low = mid + 1;
            cows = t_cows;
            current_cow_idx = 0;
        }else{
            high = mid - 1;
            cows = t_cows;
            current_cow_idx = 0;
        }
    }
    
    cout << ans;

    return 0;
}