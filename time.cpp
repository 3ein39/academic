#include<bits/stdc++.h>
using namespace std;
#define ll long long

struct Time {
    int hours {};
    int minutes {};
    int seconds {};
    ll secondsSum {};

    Time(int _hrs, int _mins, int _seconds){
        hours = _hrs, minutes = _mins, seconds = _seconds;
        secondsSum = _seconds + _mins * 60 + _hrs * 60 * 60;
    }
    void showSecondsSum() {
        cout << "sum here = " << secondsSum << endl;
    }
};

int main() {
  int hrs, mins, seconds;
  cout << "Enter first time in 12:59:59 format..\n";
  cin >> hrs >> mins >> seconds;
  Time firstTime(hrs, mins, seconds);

  cout << "Enter second time in 12:59:59 format..\n";
  cin >> hrs >> mins >> seconds;
  Time secondTime(hrs, mins, seconds);


  cout << "First time "; firstTime.showSecondsSum();
  cout << "Second time "; secondTime.showSecondsSum();
  cout << "Total seconds sum = " << firstTime.secondsSum + secondTime.secondsSum << endl;


    return 0;
}

/*
 * statement
 * create time structure
 * obtain 2 time values from user in hours mins secs format
 * store them in the struct
 * convert them to seconds
 * add these quantites in seconds and in time format
 */


