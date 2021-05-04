/*  // //  
   // //        
   \\//       
    \>>      
    //\\    
   //  \\
Author: Shadab Eqbal 
Created on: "04-05-2021" 
Name: Shortest Unique Prefix
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

struct TrieNode
{
    char ch;
    map<char, TrieNode *> m;
    int score;
};

TrieNode *createTrie(vector<string> &A)
{

    TrieNode *root = new TrieNode();
    TrieNode *temp = new TrieNode();
    root->ch = '$';
    root->score = 0;
    temp = root;
    for (int i = 0; i < (int)A.size(); i++)
    {
        for (int j = 0; j < (int)A[i].size(); j++)
        {
            if (temp->m[A[i][j]] == 0)
            {
                TrieNode *newNode = new TrieNode();
                newNode->ch = A[i][j];
                newNode->score = 1;
                temp->m[A[i][j]] = newNode;
                temp = temp->m[A[i][j]];
            }
            else
            {
                temp = temp->m[A[i][j]];
                temp->score++;
            }
        }
        temp = root;
    }

    return root;
}

vector<string> traversal(TrieNode *root, vector<string> &A)
{
    TrieNode *temp = new TrieNode();
    temp = root;
    vector<string> ans;
    string str = "";
    for (int i = 0; i < (int)A.size(); i++)
    {
        temp = temp->m[A[i][0]];
        str += A[i][0];
        for (int j = 1; j <= (int)A[i].size(); j++)
        {
            if (temp->score == 1)
            {
                ans.push_back(str);
                str = "";
                break;
            }
            else
            {
                str += A[i][j];
                temp = temp->m[A[i][j]];
            }
        }
        temp = root;
    }

    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<string> A = {"zebra", "dog", "duck", "dove"};
    TrieNode *root = createTrie(A);
    vector<string> ans = traversal(root, A);

    for (auto i : ans)
        cout << i << "\n";
    return 0;
}