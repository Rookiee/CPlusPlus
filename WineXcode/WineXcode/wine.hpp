#pragma once

#include <iostream>
#include <valarray>

using namespace std;

class Wine {
private:
    typedef valarray<int> ArrayInt;
    typedef pair<ArrayInt, ArrayInt> PairArray;
    
    string name_;
    int year_;
    PairArray brew_year_and_total_bottles_;
private:
    
public:
    Wine() {}
    Wine(const string &l, int y,  int yr[], int bot[])
    : name_(l),
    year_(y),
    brew_year_and_total_bottles_(ArrayInt(yr,y),ArrayInt(bot,*yr)) {}
    
    
    
    Wine(const string l, int y)
    : name_(l),
    year_(y),
    brew_year_and_total_bottles_(ArrayInt(y),ArrayInt(y)) {}
    ~Wine () {}
    void GetBottles();
    string & Label() const ;
    int sum() const;
    void show() const;
};
