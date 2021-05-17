/*  // //  
   // //        
   \\//       
    \>>      
    //\\    
   //  \\
Author: Shadab Eqbal 
Created on: "17-05-2021" 
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
    vvi vec = {{10, 30, 50, 70, 90},
               {20, 35, 51, 78, 100},
               {33, 54, 55, 79, 120},
               {35, 56, 80, 85, 130},
               {38, 58, 87, 90, 150}};

    int row = 0;
    int col = vec[0].size() - 1;
    int element = 38;
    int flag = 0;
    while (row < (int)vec.size() && col < (int)vec[0].size())
    {
        if (vec[row][col] == element)
        {
            cout << row << " " << col << "\n";
            flag = 1;
            break;
        }
        else if (element > vec[row][col])
        {
            row++;
        }
        else
        {
            col--;
        }
    }

    if (flag == 0)
        cout << "Element Not Found\n";
    return 0;
}