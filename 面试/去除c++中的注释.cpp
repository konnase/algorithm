//
// Created by 李青坪 on 2019/3/5.
//
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <string>
#define MAXN 10000
#define NIL -1
using namespace std;

int n;

string extractCode(string s) {
    vector<string> lines;
    string line;
    for (int i = 0; i < s.length(); ++i) {
        if (s[i] == '\n'){
            lines.push_back(line);
            line = "";
        } else {
            line += s[i];
        }
    }
    string result;
    int first = 0, second = 0; // 记录是否找到注解的标识：/ 或者 *
    int which = 0; // 记录是哪种类型的注解：0 -- // ;  1 -- /* */
    bool isMultiLine = false;
    for (int i = 0; i < lines.size(); ++i) {
        line = lines[i];
        string tempLine;
        for (int j = 0; j < line.length(); ++j) {
            tempLine += line[j];
            if (which == 0) {
                if (first == 0 && line[j] == '/') {
                    first = 1;
                }
                else if (first == 1 && line[j] == '/') {
                    first = 0;
                    which = 0;
                    tempLine.pop_back();
                    break;
                }
                else if (first == 1 && line[j] == '*') {
                    first = 0;
                    second = 0;
                    which = 1;
                    tempLine.pop_back();
                    tempLine.pop_back();
                    result += tempLine;
                }
            } else {
                if (second == 0 && line[j] == '*') {
                    second = 1;
                }
                else if (second == 1 && line[j] == '/') {
                    which = 0;
                    second = 0;
                    tempLine = "";
                    if (isMultiLine) {
                        result += '\n';
                        isMultiLine = false;
                    }
                }
            }
        }
        if (which == 0) {
            result += tempLine;
            result += '\n';
        }
        else if (which == 1) {
            isMultiLine = true;
        }
    }
    return result;
}

int main(){

    string s = "int c;/* this is a test\n"
               "really\n"
               "*/ float b;\n"
               "}\n";
    cout << extractCode(s);
}