#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <sstream>
#include <stdio.h>
#include <algorithm>
#include <cstring>
using namespace std;
struct team{
    int correct,penalty;
    int incorrect[9] = {0,0,0,0,0,0,0,0,0};
    bool c[9];
};
map<int,team> m;
vector<int> v;
bool cmp(int a,int b){
    if(m[a].correct != m[b].correct) return m[a].correct > m[b].correct;
    else if(m[a].penalty != m[b].penalty) return m[a].penalty < m[b].penalty;
    else return a < b;
}
int main(){
    stringstream ss;
    string line;
    getline(cin, line);
    int cases;
    ss.clear();
    ss << line;
    ss >> cases;
    getline(cin,line);
    int j = 0;
    while(cases--){
        if(j++) cout << endl;
        m.clear();
        int tn, problem, time;
        char status;
        m.clear();
        v.clear();
        while(getline(cin,line)){
            if(line.empty()) break;
            ss.clear();
            ss << line;
            ss >> tn >> problem >> time >> status;

            if(m.find(tn) == m.end()){
                team t;
                memset(t.incorrect,0,sizeof t.incorrect);
                memset(t.c,false,sizeof t.c);
                t.correct = 0;
                t.penalty = 0;
                v.push_back(tn);
                m[tn] = t;
            }
            if(status == 'C' && !m[tn].c[problem-1]){
                m[tn].correct++;
                m[tn].penalty += (time + (m[tn].incorrect[problem-1] * 20));
                m[tn].c[problem-1] = true;
            }
            else if(status == 'I'){
                m[tn].incorrect[problem-1]++;
            }
        }
        sort(v.begin(),v.end(),cmp);
        for(int i = 0; i < v.size();i++){
            printf("%d %d %d\n",v[i],m[v[i]].correct,m[v[i]].penalty);
        }
    }
    return 0;
}
