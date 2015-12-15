
//
//  Header.h
//  CProject
//
//  Created by Sanika Kulkarni on 11/28/14.
//  Copyright (c) 2014 Sanika Kulkarni. All rights reserved.
//

#ifndef H_Header
#define H_Header

#include<iostream>
#include<vector>
#include<map>
#include<queue>
using namespace std;

template <class C_Type>
class Solver{
    
public:
    
    map< vector<C_Type>, vector<C_Type> > visited;
    vector< vector<C_Type> > vectr;
    typename vector< vector<C_Type> >::iterator it;
    virtual vector<C_Type> initConfig() = 0;
    virtual vector< vector<C_Type> > nextConfig(vector<C_Type>) = 0;
    virtual bool isItGoal(vector<C_Type>) = 0;
    virtual void printResult(vector<C_Type>) = 0;
    void solve();
};

template <class C_Type>
void Solver<C_Type>::solve(){
    
    queue<vector<C_Type> > Q;
    vector<C_Type> vTemp;
    vTemp = initConfig();
    Q.push(vTemp);
    
    while(!Q.empty() && !isItGoal(Q.front()))
    {
        vTemp = Q.front();
        Q.pop();
        
        vectr = nextConfig(vTemp);
        
        for(it = vectr.begin(); it != vectr.end(); ++it)
        {
            if(visited.count(*it)==0)
            {
                Q.push(*it);
                visited[*it] = vTemp;
            }
        }
    }
    
    if(Q.empty())
        cout<<"\n No soution found for given problem \n";
    else
        printResult(Q.front());
}						

#endif
