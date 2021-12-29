#include <bits/stdc++.h>

using namespace std;

typedef tuple<int, int, int> tiii;

int A, B, C;
int vis[201][201][201];
vector<int> ans;

// A -> B
// B -> A
// A -> C
// C -> A
// B -> C
// C -> B

pair<int, int> fill_water(int fromMax, int toMax, int from, int to)
{
   if (from + to > toMax)
   {
      return make_pair(from + to - toMax, toMax);
   }

   return make_pair(0, from + to);
}

void bfs()
{
   queue<tiii> q;

   q.emplace(0, 0, C);
   vis[0][0][C] = 1;

   while (!q.empty())
   {

      tiii t = q.front();
      q.pop();

      auto [a, b, c] = t; // structured binding

      if (!a)
      {
         ans.push_back(c);
      }

      pair<int, int> atob = fill_water(A, B, a, b);
      if (!vis[atob.first][atob.second][c])
      {
         q.emplace(atob.first, atob.second, c);
         vis[atob.first][atob.second][c] = 1;
      }
      pair<int, int> btoa = fill_water(B, A, b, a);
      if (!vis[btoa.second][btoa.first][c])
      {
         q.emplace(btoa.second, btoa.first, c);
         vis[btoa.second][btoa.first][c] = 1;
      }

      pair<int, int> atoc = fill_water(A, C, a, c);
      if (!vis[atoc.first][b][atoc.second])
      {
         q.emplace(atoc.first, b, atoc.second);
         vis[atoc.first][b][atoc.second] = 1;
      }
      pair<int, int> ctoa = fill_water(C, A, c, a);
      if (!vis[ctoa.second][b][ctoa.first])
      {
         q.emplace(ctoa.second, b, ctoa.first);
         vis[ctoa.second][b][ctoa.first] = 1;
      }

      pair<int, int> btoc = fill_water(B, C, b, c);
      if (!vis[a][btoc.first][btoc.second])
      {
         vis[a][btoc.first][btoc.second] = 1;
         q.emplace(a, btoc.first, btoc.second);
      }
      pair<int, int> ctob = fill_water(C, B, c, b);
      if (!vis[a][ctob.second][ctob.first])
      {
         vis[a][ctob.second][ctob.first] = 1;
         q.emplace(a, ctob.second, ctob.first);
      }
   }

   sort(ans.begin(), ans.end());
   ans.erase(unique(ans.begin(), ans.end()), ans.end());

   for (int n : ans)
   {
      cout << n << ' ';
   }
}

int main()
{
   cin.tie(NULL);
   cout.tie(NULL);

   cin >> A >> B >> C;

   bfs();

   return 0;
}