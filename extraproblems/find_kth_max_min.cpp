/*  // //  
   // //        
   \\//       
    \>>      
    //\\    
   //  \\
Author: Shadab Eqbal 
Created on: "29-05-2021" 
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
    vi vec = {7, 1, 2, 5, 8, 10, 3};
    int k = 3;
    priority_queue<int> pq_max;
    for (auto i : vec)
        pq_max.push(i);

    for (int i = 0; i < k - 1; i++)
        pq_max.pop();

    cout << pq_max.top();

    priority_queue<int, vector<int>, greater<int>> pq_min;

    for (auto i : vec)
        pq_min.push(i);

    for (int i = 0; i < k - 1; i++)
        pq_min.pop();
    
    cout<<pq_min.top();
    return 0;
}