/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: thapab
 *
 * Created on March 23, 2018, 11:34 PM
 */

#include <cstdlib>
#include <iostream>
#include <vector>

#include"PQueue.h"

bool solve(Node& Goal, PQueue& Q);

int main(int argc, char** argv) {
    PQueue Q;
    int size;
    vector <Node> exp;
    cout << "Please enter the size of the board (3-8) :  ";
    cin >> size;
    
   
    Node start;
    cout << "Please enter the values for initial state: " << endl;
    start.initNode(size);
    
    cout << "Please enter the values for the goal state: " << endl;
    Node goal;
    goal.initNode(size);
    
    Q.push(start);
    
    if (solve(goal, Q))
        cout << "Successful!"<< endl;
    else cout << "Failed !" << endl;
    
    return 0;
}
void tracePath(Node* current);
void expandNode(Node* current, PQueue& Q);
void addToExplored(Node* current);
bool checkGoal(Node* current, Node& goal);

bool solve(Node& Goal, PQueue& Q){
    if (Q.isEmpty())
    return false;
    
    Node* Current = Q.pop();
    bool gTest = checkGoal(Current, Goal);
    
    if (gTest){
        tracePath(Current);
        return true;
    }
    else{
        addToExplored(Current);
        expandNode(Current,Q); // expand the parent and push each child in the queue
           
    }
    return (solve(Goal, Q));
    }
    
 void expandNode(Node* current,PQueue& Q){
     for (int i =1; i<=4; i++){
     if (current->isSafe(i)){
         Node newNode;
         newNode(*current, i);
        Q.push(newNode); 
     }   
     }
     addToExplored(current);
 }
 
  

