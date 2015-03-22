/*fflknelnernfernferneroneronero*/

#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <math.h>
#include <string>
#include <utility>
#include <vector>
#include <map>
using namespace std;


map <string, int> daynum;
map <string, int> monthnum;
string numday[8];
int numofdays[2][13] = {{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}, {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}};
int months[2][13][32];


int main()
{
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout); 

  int n, year, flag = 0;
  cin >> n >> year;

  

  if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))
    flag = 1;
  
  char * days[] = {
    "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday";
  };

  for (int i = 0; i < 7; i++) {
    daynum[days[i]] = i + 1;
  }

  monthnum["January"] = 1;
  monthnum["February"] = 2;
  monthnum["March"] = 3;
  monthnum["April"] = 4;
  monthnum["May"] = 5;
  monthnum["June"] = 6;
  monthnum["July"] = 7;
  monthnum["August"] = 8;
  monthnum["September"] = 9;
  monthnum["October"] = 10;
  monthnum["November"] = 11;
  monthnum["December"] = 12;

  numday[1] = "Monday";
  numday[2] = "Tuesday";
  numday[3] = "Wednesday";
  numday[4] = "Thursday";
  numday[5] = "Friday";
  numday[6] = "Saturday";
  numday[7] = "Sunday";        


  for (int i = 0; i < n; i++)
  {
    int k;
    string s;
    cin >> k >> s;
    months[flag][monthnum[s]][k] = 1;
  }

  string s;
  cin >> s;
  int firstday = daynum[s];
  int nowday = firstday;
  int maxday = 0, maxsum = -1, minday = 0, minsum = 1000;


  for (int k = 1; k < 8; k++)
  {
    int sum = 0;
    nowday = firstday;
    for (int i = 1; i < 13; i++)
      for (int j = 1; j <= numofdays[flag][i]; j++)
      {
        if (nowday == 8)
          nowday = 1;
        if (months[flag][i][j] == 0 && nowday == k)
          sum++;
        nowday++;
      } 

    cout << k << " " << sum << endl; 
    //cout << sum << " " << maxsum << endl;
    if (sum > maxsum)
    {
      maxsum = sum;
      maxday = k;
    }

    if (sum < minsum)
    {
      minsum = sum;
      minday = k;
    }          
  }    

  cout << numday[maxday] << " " << numday[minday];

  return 0;
}
