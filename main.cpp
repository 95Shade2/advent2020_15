#include <iostream>
#include <vector>
#include <map>
#include <iomanip>

#define coutfixed cout << fixed << setprecision(0)

using namespace std;

void Calculate(vector<double> numbers, double nth_num) {
    map<double, vector<double>> num_spoken;
    double prev_num;
    double num;
    int perc;
    int last_perc = 0;

    for (double n = 1; n <= nth_num; n++) {
        prev_num = num;

        //Original number
        if (n <= numbers.size()) {
            num = numbers[n-1];
        }
        else {
            //if the last number was spoken for the first time
            if (num_spoken[prev_num].size() == 1) {
                num = 0;
            }
            //age
            else {
                //difference between the last two times the number was spoken
                num = num_spoken[prev_num][num_spoken[prev_num].size()-1] - num_spoken[prev_num][num_spoken[prev_num].size()-2];
            }
        }
        //cout << n << "\t" << num << endl;

        perc = (int)((n / nth_num) * 100);
        if (perc > last_perc) {
            cout << perc << "%" << endl;
            last_perc = perc;
        }

        num_spoken[num].push_back(n);
    }

    coutfixed << num << endl;
}

int main()
{
    vector<double> numbers = {2,0,6,12,1,3};
    vector<double> numbers_test = {0,3,6};

    Calculate(numbers, 30000000);

    return 0;
}
