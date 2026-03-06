#include <iostream>
#include <fstream>
#include <string>
#include <cmath>

using namespace std;

bool is_valid(string s)
{
    int len = s.length();
    if(len % 2 == 0)
    {
        int middle = len/2; 
        string s1 = s.substr(0, middle);
        string s2 = s.substr(middle);
        
        if(s1 == s2)
        {
            return true; 
        }
    }
    return false; 
}

int main(){

    long long answer = 0; 

    ifstream file("day2_level1.txt");
    string line; 

    while(getline(file, line, ','))
    {
        long long start = stoll(line.substr(0, line.find('-')));
        long long end = stoll(line.substr(line.find('-') + 1));

        if(start > end)
        {
            for(long long i = end; i <= start; i++)
            {
                if(is_valid(to_string(i)))
                {
                    answer+= i; 
                }
            }
        }else {
            for(long long i = start; i <= end; i++)
            {
                if(is_valid(to_string(i)))
                {
                    answer+= i; 
                }
            }
        }  

    }

    cout << answer << endl;

    return 0; 
}