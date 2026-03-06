#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main(){
    fstream file("day3_level1.txt");
    string line;
    int answer = 0;

    while(getline(file, line))
    {
        vector<int> battery;
        battery.push_back(stoi(line.substr(0, 1)));

        int decimal = battery[0];
        int it = 0;
        int unit = 0; 

        for(int i = 1; i<line.length()-1; i++)
        {
            battery.push_back(stoi(line.substr(i, 1)));
            if(battery[battery.size()-1] > decimal)
            {
                decimal= battery[battery.size()-1];
                it = i; 
            }
        }
        battery.push_back(stoi(line.substr(battery.size(), 1)));

        for(int i = it+1; i < battery.size(); i++)
        {
            if(battery[i] > unit)
            {
                unit = battery[i];
            }
        }

        answer += decimal*10 + unit;
    }

    cout << answer << endl;
    return 0; 
}