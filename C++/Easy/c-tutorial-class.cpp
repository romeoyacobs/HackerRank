#include <iostream>
#include <sstream>
using namespace std;

class Student
{
private:
    int age;
    string first_name;
    string last_name;
    int standard;
public:
  int get_age() { return age; }
  void set_age(int _age) { age = _age; }

  string get_first_name() { return first_name; }
  void set_first_name(string f_name) { first_name = f_name; }

  string get_last_name() { return last_name; }
  void set_last_name(string l_name) { last_name = l_name; }

  int get_standard() { return standard; }
  void set_standard(int stdrd) { standard = stdrd; }

  string to_string() const;
};

string Student::to_string() const
{
    ostringstream strm;
    char comma = ',';
    strm << age << comma << first_name << comma << last_name << comma << standard;
    return strm.str();
}
int main() {
    int age, standard;
    string first_name, last_name;
    
    cin >> age >> first_name >> last_name >> standard;
    
    Student st;
    st.set_age(age);
    st.set_standard(standard);
    st.set_first_name(first_name);
    st.set_last_name(last_name);
    
    cout << st.get_age() << "\n";
    cout << st.get_last_name() << ", " << st.get_first_name() << "\n";
    cout << st.get_standard() << "\n";
    cout << "\n";
    cout << st.to_string();
    
    return 0;
}