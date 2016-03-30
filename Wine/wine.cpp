
#include "wine.h"



using std::cin;
using std::cout;
using std::endl;
using std::cerr;

const string & Wine::Label() const {
    return (name_);
}



int Wine::sum() const {
    return brew_year_and_total_bottles_.second.sum();
}

void Wine::GetBottles() {
    cout << "Enter " << name_ << "data for "<< year_ << "year(s)----\n";
    for(unsigned i=0;i< year_;i++) {
        unsigned brew_year;
        cout << "Enter year: ";
        cin >> brew_year;
        if(!cin){
            exit(EXIT_FAILURE);
        }
        brew_year_and_total_bottles_.first[i] = brew_year;

        unsigned bottles_total;
        cout << "Enter bottles for that year: ";
        cin >> bottles_total;
        if(!cin){

            exit(EXIT_FAILURE);
        }
        brew_year_and_total_bottles_.second[i] = bottles_total;

    }
}

void Wine::show() const {
    cout << "Wine: " << name_ << endl;
    cout << '\t' << "Year" << '\t' << "Bottles" << endl;
    for(unsigned i=0;i<year_;i++) {
        cout << '\t' << brew_year_and_total_bottles_.first[i] << '\t' <<
                brew_year_and_total_bottles_.second[i] << endl;
    }
}

