/*  // //  
   // //        
   \\//       
    \>>      
    //\\    
   //  \\
Author: Shadab Eqbal 
Created on: "24-05-2021" 
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
    vi vec = {14, 18, 21, 53, 3, 6, 8, 9, 12};
    int mn = 0;

    //O(n)
    // for (int i = 0; i < vec.size(); i++)
    // {
    //     if (vec[i] < vec[mn])
    //         mn = i;
    // }

    // cout << vec.size() - mn;

    //O(logn)
    int start = 0;
    int end = vec.size() - 1;
    int pivot = -1;
    while (start < end)
    {
        int mid = start + (end - start) / 2;
        if (vec[mid] > vec[mid - 1] && vec[mid] > vec[mid + 1])
        {
            pivot = mid;
            break;
        }
        else if (vec[mid] > vec[end])
        {
            start = mid;
        }
        else if (vec[start] > vec[mid])
        {
            end = mid;
        }
    }
    cout << pivot;
    return 0;
}