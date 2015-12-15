//
//  problemSolver.h
//  CProject
//
//  Created by Sanika Kulkarni on 11/28/14.
//  Copyright (c) 2014 Sanika Kulkarni. All rights reserved.
//

#ifndef CProject_problemSolver_h
#define CProject_problemSolver_h

#include<iostream>
#include<map>
#include<queue>
#include<vector>

using namespace std;

template <class tempT>

class ProblemSolver{
    
public:
    
    
    vector< vector<tempT> > nextNodes;
    virtual vector< vector<tempT> > getNextNodes(vector<tempT>) = 0;
    virtual bool desiredOutput(vector<tempT>) = 0;
    virtual void displayOutput(vector<tempT>) = 0;
    virtual vector<tempT> rootNode() = 0;
    void bfs();
    typename vector< vector<tempT> >::iterator vIterator;
    map< vector<tempT>, vector<tempT> > nodeVMap;
    
};

template <class tempT>

void ProblemSolver<tempT>::bfs(){
    
    vector<tempT> vectorT;
    vectorT = rootNode();
    queue<vector<tempT> > nodeQueue;
    nodeQueue.push(vectorT);
    vector<tempT> finalResult;
    while(!nodeQueue.empty())
    {
        vectorT = nodeQueue.front();
        nodeQueue.pop();
        if(!desiredOutput(vectorT)){
            nextNodes = getNextNodes(vectorT);
            for(vIterator = nextNodes.begin(); vIterator != nextNodes.end(); vIterator++)
            {
                if(nodeVMap.count(*vIterator)==0)
                {
                    nodeVMap[*vIterator] = vectorT;
                    nodeQueue.push(*vIterator);
                }
            
            }}
        else {
            finalResult = vectorT;
        }
  
    }
    
    if(!finalResult.empty())
        displayOutput(finalResult);
    else
        cout<<"\n No solution!!! \n";
   
        }

#endif
