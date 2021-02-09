#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "TodoList.h"

using namespace std;

int main(int argc, char *argv[]) {
    string dueDate;
    string task;
    
    TodoList todo;
    
    if (argc > 1) {
    
        string command = argv[1];
            
        if(command == string("add")) {
            
            if (argc > 3) {
                string dueDate = argv[2];
                string task = argv[3];
                todo.add(dueDate, task);
            }
        } 
        
        else if(command == string("remove")) {
            if (argc > 2) {
                string task = argv[2];
                todo.remove(task);
            }
        }
        
        else if(command == string("printList")) {
            todo.printTodoList();
        }
        
        else if(command == string("printDay")) {
            if (argc > 2) {
                string dueDate = argv[2];
                
                todo.printDaysTasks(dueDate);
                
            }
        }
    
    }
    
    return 0;
}