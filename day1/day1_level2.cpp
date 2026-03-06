#include <iostream>
#include <fstream>
#include <string>
#include <cmath>

using namespace std;

int main(){
    int pos = 50;
    int password = 0;
    int end = pos; 
    int i = 0; 

    ifstream file("day1_level2.txt");
    string line;

    while(getline(file, line)){
        char dir = line[0]; 
        int step = stoi(line.substr(1));

        int full_turn = step / 100;
        int modulo = step % 100;

        password += full_turn;

        if(dir == 'L'){
            end -= modulo;
            end = (end + 100) % 100;
            if(end > pos and end!=0 and pos!=0){
                password ++; 
            }
        }else {
            end += modulo;
            end = (end + 100) % 100;
            if(end < pos and end!=0 and pos!=0){
                password ++; 
            }
        }

        if(end == 0)
        {
            password++;
        }

        pos = end; 

    }
    cout << password << endl;
    return 0; 
}