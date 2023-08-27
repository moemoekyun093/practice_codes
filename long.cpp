#include <bits/stdc++.h>
#include <vector>
#include <string>

using namespace std;

int longestValidParentheses(string s)
{

  // if (argc < 2)
  // {
  //   cout << "Give a sequence of paranthesses!\n"
  //        << endl;
  //   return 1;
  // }
  // auto s = string(argv[1]);
  // int matched_length = 0;

  stack<char> s1;
  vector<int> v;
  v.push_back(0);
  int i = 0;
  while (s[i] != 0)
  {
    if (s[i] == '(')
      break;
    i++;
  }
  while (s[i] != 0)
  {
    if (s[i] == '(')
      s1.push(s[i]);
    else if (s1.size() != 0)
    {
      s1.pop();
    }
    // if (v.back() != 0 || s[i] != ')')
      v.push_back(s1.size());
    i++;
  }

  int max = 0;
  int curr_val = 0;
  int c = 0;
  vector<int> u;
  u.push_back(0);

  for (size_t i = 1; i < v.size() - 1; i++)
  {   if(v[i]==v[i+1])
      {
        u.clear();
        curr_val=-1;
        continue;
      }  

    if (v[i] > v[i - 1] && v[i] > v[i + 1])
    {
      u.back() += 2;
      continue;
    }
    if (v[i] == curr_val)
    {

      if (u.back() > max)
        max = u.back();
      if (v[i] > v[i + 1])
      { 
        int temp=u.back()+2;
        u.pop_back();
        u.back()+=temp;
        curr_val--;
      }
      continue;
    }

    curr_val++;
    u.push_back(0);
  }
  if (u.back() > max)
    max = u.back();
  // for (size_t i = 0; i < v.size(); i++)
  // {
  //   cout << v[i] << endl;
  // }
  //cout << s << " " << max << endl;
  return max;
}
