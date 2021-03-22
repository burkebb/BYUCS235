#include <fstream>
#include <iostream>
#include "TodoList.h"
using namespace std;

TodoList::TodoList() {
    
    ifstream istream("TodoList.txt");
        
    if(istream) {
        while(!istream.eof()) {
            if (task.length() > 0) {
                dates.push_back(date);
                tasks.push_back(task);
            }
            
            istream >> date;
            istream.ignore();
            getline(istream, task);
        }
        
        istream.close();
    }
}

TodoList::~TodoList() {
    ofstream ostream;
    ostream.open("TodoList.txt");
    
    int length = tasks.size();
    
    for (int i = 0; i < length; i++) {
        ostream << dates[i] << " " <<tasks[i] << endl;
    }
    
    ostream.close();
}

void TodoList::add(string _duedate, string _task) {
    dates.push_back(_duedate);
    tasks.push_back(_task);
};

int TodoList::remove(string _task) {
    int length = tasks.size();
    for (int i = 0; i < length; i++) {
        if (_task == tasks[i]) {
            dates.erase(dates.begin() + i);
            tasks.erase(tasks.begin() + i);
        }
        
    }
};

void TodoList::printTodoList() {
    int length = dates.size();
    
    for (int i = 0; i < length; i++) {
        cout << dates[i] << " " << tasks[i] << endl;
    }
};

void TodoList::printDaysTasks(string _date) {
    int length = dates.size();
    
    for (int i = 0; i < length; i++) {
        
        if (dates[i] == _date) {
            cout << tasks[i] << endl;
        }
    }
};