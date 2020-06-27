#include <bits/stdc++.h>

using namespace std;

class RunningMedian
{
public:
    RunningMedian() {}
    double Median() const
    {
        return median;
    }

    void addValue(int val)
    {
        if (maxPart.empty())
        {
            cout << "First\n";
            maxPart.push(val);
        }
        else if (minPart.empty())
        {
            if (val < maxPart.top())
            {
                cout << "Second\n";
                minPart.push(val);
            }
            else 
            {
                maxPart.push(val);
                auto t = maxPart.top();
                cout << "SecondELSE " << t << '\n';
                maxPart.pop();
                minPart.push(t);
            }
        }
        else
        {
            if (val < minPart.top())
            {
                cout << "Third\n";
                minPart.push(val);
                if (minPart.size() > maxPart.size() + 1)
                {
                    cout << "ThirdIF\n";
                    auto t = minPart.top();
                    minPart.pop();
                    maxPart.push(t);
                }
            }
            else
            {
                cout << "Forth\n";
                maxPart.push(val);
                if (maxPart.size() > minPart.size() + 1)
                {
                    cout << "ForthIF\n";
                    auto t = maxPart.top();
                    maxPart.pop();
                    minPart.push(t);
                }
            }
        }
        CalculateMedian();
    }
private:
    void CalculateMedian()
    {
        if (minPart.empty())
        {
            median = maxPart.top();
        }
        else if (maxPart.empty())
        {
            median = minPart.top();
        } 
        else if (maxPart.size() == minPart.size())
        {
            median = (minPart.top() + maxPart.top()) / 2.0;
        }
        else if (maxPart.size() > minPart.size())
        {
            median = maxPart.top();
        }
        else if (minPart.size() > maxPart.size()) {
            median = minPart.top();
        }
    }
private:
    priority_queue<int> minPart;
    priority_queue<int, vector<int>, greater<int>> maxPart;
    double median;
};

vector<double> runningMedian(vector<int> a) {
    vector<double> res;
    RunningMedian rm;

    for (int val : a)
    {
        rm.addValue(val);
        res.push_back(rm.Median());
    }
    return res;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int a_count;
    cin >> a_count;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<int> a(a_count);

    for (int a_itr = 0; a_itr < a_count; a_itr++) {
        int a_item;
        cin >> a_item;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        a[a_itr] = a_item;
    }

    vector<double> result = runningMedian(a);

    for (int result_itr = 0; result_itr < result.size(); result_itr++) {
        fout << result[result_itr];

        if (result_itr != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}
