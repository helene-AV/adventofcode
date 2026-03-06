#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <vector>

using namespace std;

bool is_valid(string s)
{
    int len = s.length();
    vector<int> dividers;
    for(int i = 1; i < len; i++)
    {
        if(len%i==0)
        {
            dividers.push_back(i);
        }
    }

    for(int i = 0; i < dividers.size(); i++)
    {
        vector<string> parts;
        int divider = dividers[i];
        for(int j = 0; j < len/divider; j++)
        {
            parts.push_back(s.substr(j*divider, divider));
        }
        for(int k = 0; k < parts.size()-1; k++)
        {
            if(parts[k] != parts[k+1])
            {
                break;
            }else if (k + 1 == parts.size()-1)
            {
                return true;

            }
        }
    }
    return false; 
}

int main(){

    long long answer = 0; 

    ifstream file("day2_level2.txt");
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