//
//  main.cpp
//  CS144Assignment4
//
//  Created by Jerry Garcia on 2/20/19.
//  Copyright © 2019 Jerry Garcia. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <sstream>

using namespace std;

const string INPUT_FILE_NAME = "students.txt";

int findNums(string line);

/**
 * Main.
 */
int main()
{
    ifstream input;
    input.open(INPUT_FILE_NAME);
    if (input.fail())
    {
        cout << "Failed to open " << INPUT_FILE_NAME << endl;
        return -1;
    }
    //line created to help skip first line
    string line, dummy;
    getline(input, dummy);//skip first line
    dummy = dummy.substr(dummy.find(" "), dummy.length());//get the number of students
    int num = stoi(dummy);//convert string into an integer
    
    string *names = new string[num];//array that will hold names
    int** scores = new int*[num];
    int *scoreLen = new int[num];
    
//    while(getline(input, line)){
//        num++;
//    }
//
//    input.seekg(0, ios_base::beg);//return stream to the beginning

    

    for(int i = 0; getline(input, line); i++){
        size_t temp = line.find(" ");
        temp = line.find_first_of(" ", temp + 1);
        names[i] = line.substr(0, temp);
        
        int nums = findNums(line);
        scoreLen[i] = nums;
        if(nums > 0)
            scores[i] = new int[nums];
        else
            scores[i] = nullptr;
        
        for(int j = 0; j < nums; j++){
            size_t temp2 = line.find_first_of(" ", temp + 1);
            if(temp2 < 0) continue;
            else{
                scores[i][j] = stoi(line.substr(temp + 1, temp2));
                temp = temp2;
            }
        }
    }
    
    cout << "STUDENT SCORES for C++\n" << endl;
    
    for(int i = 0; i < num; i++){
        cout << names[i] << endl;
        if(scores[i] == nullptr) cout << "   (none)";
        for(int j = 0; j < scoreLen[i]; j++){
            cout << setw(5) << scores[i][j];
        }
        cout << "\n" << endl;
    }

//    for(int i = 0; i < num; i++){
//        cout << names[i] << endl;
//    }
}

int findNums(string line){
    if(line.empty()) return 0;
    int nums = 0;
    for(int i = 0; i < line.length(); i++){
        if(line[i] == ' ') nums++;
    }
    return nums - 1;
}
