#ifndef TodoList_h
#define Todolist_h

#include <string>
#include <vector>
#include "TodoListInterface.h"
using namespace std;

class TodoList : public TodoListInterface {
    public:
        TodoList();
        ~TodoList();
        void add(string _duedate, string _task);
        int remove(string _task);
        void printTodoList();
        void printDaysTasks(string _date);
        
    private:
        string date;
        string task;
        vector<string> dates;
        vector<string> tasks;
        
};

#endif