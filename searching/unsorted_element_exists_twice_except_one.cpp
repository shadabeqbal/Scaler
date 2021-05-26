/*  // //  
   // //        
   \\//       
    \>>      
    //\\    
   //  \\
Author: Shadab Eqbal 
Created on: "26-05-2021" 
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
    vi vec = {20,20, 1, 1, 7, 7, 100, 100, 9,9,102,102,8};
    int start = 0;
    int end = vec.size() - 1;
    int ans = 0;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (vec[mid] != vec[mid - 1] && vec[mid] != vec[mid + 1])
        {
            ans = mid;
            break;
        }
        else if (mid % 2 == 0)
        {
            if (vec[mid] == vec[mid + 1])
                start = mid + 2;

            if (vec[mid] == vec[mid - 1])
                end = mid - 2;
        }
        else
        {
            if (vec[mid] == vec[mid - 1])
                start = mid + 1;

            if (vec[mid] == vec[mid + 1])
                end = mid - 1;
        }
    }

    cout << ans;
    return 0;
}