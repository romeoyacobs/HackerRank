#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#include <array>
#include <numeric>

class Person
{
public:
  Person() {};
  virtual void getdata() {};
  virtual void putdata() const {};
protected:
    string name;
    int age;
};

class Professor : public Person
{
private:
    int publications;
    int curr_id;
    static int ids;
public:
    Professor() : curr_id{ids++} {}
    void getdata() override
    {
        cin >> name >> age >> publications;
    }
    void putdata() const override
    {
        cout << name << " " << age << " " << publications << " " << curr_id << endl;
    }
};

int Professor::ids = 1;

class Student : public Person
{
private:
  array<int, 6> marks;
  int curr_id;
  static int ids;

private : 
int sumOfMarks() const {
    return accumulate(marks.begin(), marks.end(), 0);
}

public:
  Student() : curr_id{ids++} {}
  void getdata() override {
    cin >> name >> age >> marks[0] >> marks[1] >> marks[2] >> marks[3] >>
        marks[4] >> marks[5];
  }
  void putdata() const override {
    cout << name << " " << age << " " << sumOfMarks() << " " << curr_id << endl;
  }
};

int Student::ids = 1;

int main(){

    int n, val;
    cin>>n; //The number of objects that is going to be created.
    Person *per[n];

    for(int i = 0;i < n;i++){

        cin>>val;
        if(val == 1){
            // If val is 1 current object is of type Professor
            per[i] = new Professor;

        }
        else per[i] = new Student; // Else the current object is of type Student

        per[i]->getdata(); // Get the data from the user.

    }

    for(int i=0;i<n;i++)
        per[i]->putdata(); // Print the required output for each object.

    return 0;

}
