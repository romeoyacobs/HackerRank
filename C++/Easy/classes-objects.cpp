
#include <array>

class Student {
private: 
  array<int, 5> scores;
private:
    constexpr size_t size() const { return 5; }
public:
    void input();
    int calculateTotalScore();
};

void Student::input() 
{
    for (int i = 0; i < size(); ++i)
    {
        cin >> scores[i];
    }
}

int Student::calculateTotalScore() {
    int res {0};
    for (int i = 0; i < scores.size(); ++i) {
        res += scores[i];
    }
    return res;
}