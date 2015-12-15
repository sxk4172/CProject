//
//  Solution.h
//  CProject
//
//  Created by Sanika Kulkarni on 12/1/14.
//  Copyright (c) 2014 Sanika Kulkarni. All rights reserved.
//

#ifndef CProject_Solution_h
#define CProject_Solution_h


#include<iostream>
#include<map>
#include<queue>
#include<vector>

using namespace std;

template <class tempT>

class ProblemSolver {
    
public:
    virtual vector< vector<tempT> > getNextNodes(vector<tempT>) = 0;
    virtual bool desiredOutput(vector<tempT>) = 0;
    virtual void displayOutput(vector<tempT>) = 0;
    virtual vector<tempT> rootNode() = 0;
    void bfs();
    map< vector<tempT>, vector<tempT> > nodeVMap;
    
};

template <class tempT>

void ProblemSolver<tempT>::bfs() {
    
    vector< vector<tempT> > nextNodes;
    vector<tempT> nextNodesVector;
    vector<tempT> vectorT;
    vectorT = rootNode();
    queue<vector<tempT> > nodeQueue;
    nodeQueue.push(vectorT);
    vector<tempT> finalResult;
    while(!nodeQueue.empty()) {
        vectorT = nodeQueue.front();
        nodeQueue.pop();
        if(!desiredOutput(vectorT)){
            nextNodes = getNextNodes(vectorT);
            for(int i=0;i<nextNodes.size();i++) {
                nextNodesVector = nextNodes[i];
                if(nodeVMap.count(nextNodesVector)==0) {
                    nodeVMap[nextNodesVector] = vectorT;
                    nodeQueue.push(nextNodesVector);
                }
                
            }
        }
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
