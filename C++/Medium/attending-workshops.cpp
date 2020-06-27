#include<bits/stdc++.h>

using namespace std;

#include <vector>
#include<algorithm>
#include<iterator>
#include<math.h>
#include<set>
#include<stack>

using namespace std;

struct Workshop
{
  int startTime;
  int duration;
  int endTime;

  friend bool operator<(const Workshop& a, const Workshop& b);
  friend bool operator==(const Workshop &a, const Workshop &b);
};

bool operator<(const Workshop &a, const Workshop &b)
{
    return a.startTime < b.startTime;
}

bool operator==(const Workshop &a, const Workshop &b) {
  return a.startTime == b.startTime && a.duration == b.duration &&
         a.endTime == b.endTime;
}

struct Available_Workshops
{
    int numberOfWorkshops;
    Workshop* arr;
};

Available_Workshops *initialize(int start_time[], int duration[], int n) {
  Available_Workshops *workshops = new Available_Workshops;
  workshops->numberOfWorkshops = n;
  workshops->arr = new Workshop[n];

  for (int i = 0; i < n; ++i) {
    auto ws = workshops->arr[i];
    auto st = start_time[i];
    auto d = duration[i];
    auto et = st + d;

    workshops->arr[i].startTime = st;
    workshops->arr[i].duration = d;
    workshops->arr[i].endTime = et;
  }

  return workshops;
}

int CalculateMaxWorkshops(Available_Workshops *ptr) {
  int maxWorkshops = 0;

  int last_end = INT_MAX;

  sort(ptr->arr, ptr->arr + ptr->numberOfWorkshops);

  stack<Workshop> shops;

  for (int i = 0; i < ptr->numberOfWorkshops; ++i) {
    auto curr_start = ptr->arr[i].startTime;
    auto curr_end = ptr->arr[i].endTime;

    last_end = INT_MAX;
    if (!shops.empty()) {
      last_end = shops.top().endTime;
    }

    if (curr_end < last_end) {
      if (!shops.empty()) {
        shops.pop();
      }
      shops.push(ptr->arr[i]);
    } else {
      if (curr_start >= last_end) {
        shops.push(ptr->arr[i]);
      }
    }
  }
  return shops.size();
}

int main(int argc, char *argv[]) {
    int n; // number of workshops
    cin >> n;
    // create arrays of unknown size n
    int* start_time = new int[n];
    int* duration = new int[n];

    for(int i=0; i < n; i++){
        cin >> start_time[i];
    }
    for(int i = 0; i < n; i++){
        cin >> duration[i];
    }

    Available_Workshops * ptr;
    ptr = initialize(start_time,duration, n);
    cout << CalculateMaxWorkshops(ptr) << endl;
    return 0;
}
