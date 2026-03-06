#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

int main(){
    fstream file("day3_level2.txt");
    string line;
    long long answer = 0;

    while(getline(file, line))
    {
        int len = 11;
        vector<int> battery;
        battery.push_back(stoi(line.substr(0, 1)));
        int bigger = battery[0]; 
        int it = 0; 

        while(len >= 0)
        {
          for(int i = it+1; i<line.length()-len; i++)
            {
                if(battery.size()<=i)
                {
                    battery.push_back(stoi(line.substr(i, 1)));
                }
                if(battery[i] > bigger)
                {
                    bigger = battery[i];
                    it = i; 
                }
            }
            answer += bigger*pow(10, len);
            bigger = 0; 
            len --; 
        }
    }

    cout << answer << endl;
    return 0; 
}