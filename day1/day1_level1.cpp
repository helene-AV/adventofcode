#include <iostream>
#include <fstream>
#include <string>
#include <cmath>

using namespace std;

int main(){
    int pos = 50;
    int password = 0;

    ifstream file("day1_level1.txt");
    string line;

    while(getline(file, line)){
        char dir = line[0]; 
        int step = stoi(line.substr(1));

        if(dir == 'L'){
            pos -= step;
        }else {
            pos += step;
        }

        pos = (pos + 100) % 100;

        if(pos == 0)
        {
            password++;
        }

    }
    cout << password << endl;
    return 0; 
}