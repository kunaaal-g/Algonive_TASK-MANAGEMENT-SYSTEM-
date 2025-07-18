#include <iostream>
#include <vector>
#include <algorithm>
struct Task 
{
    std::string description, type;
    int priority;
    std::string dueDate;
    bool completed;
};
std::vector<Task> tasks;
void addTask() 
{
    Task t;
    std::cout << "Enter task description: ";
    std::getline(std::cin, t.description);
    std::cout << "Enter task type (work/personal/etc): ";
    std::getline(std::cin, t.type);
    std::cout << "Enter priority (1-5): ";
    std::cin >> t.priority;
    std::cin.ignore();
    std::cout << "Enter due date (YYYY-MM-DD): ";
    std::getline(std::cin, t.dueDate);
    t.completed = false;
    tasks.push_back(t);
}
void showTasks() 
{
    std::sort(tasks.begin(), tasks.end(), [](Task a, Task b) 
    {
        return a.priority < b.priority;
    });
    for (auto &t : tasks) 
    {
        std::cout << (t.completed ? "[X] " : "[ ] ") << t.description 
                  << " | Priority: " << t.priority 
                  << " | Due: " << t.dueDate << "\n";
    }
}
int main() 
{
    int choice;
    do 
    {
        std::cout << "\n1. Add Task\n2. Show Tasks\n3. Exit\nChoice: ";
        std::cin >> choice;
        std::cin.ignore();
        if (choice == 1) addTask();
        else if (choice == 2) showTasks();
    } 
    while (choice != 3);
}