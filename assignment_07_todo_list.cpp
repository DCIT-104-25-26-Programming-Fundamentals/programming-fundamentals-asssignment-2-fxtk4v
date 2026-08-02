// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 7
// =============================================================================
//
// TASK: Console-Based To-Do List Application
//
// Build a simple to-do list program that runs entirely in the console and
// allows the user to manage their tasks interactively using a menu.
//
// -----------------------------------------------------------------------------
// FEATURES YOUR PROGRAM MUST SUPPORT
// -----------------------------------------------------------------------------
//
//   1. Add a Task
//      - Prompt the user to type a task description.
//      - Add it to the list and confirm it was added.
//
//   2. View All Tasks
//      - Display all tasks currently in the list, numbered from 1.
//      - If the list is empty, print a friendly message saying so.
//
//   3. Delete a Task
//      - Show the list of tasks with their numbers.
//      - Ask the user which task number they want to remove.
//      - Remove the task and confirm the deletion.
//      - If the task number is invalid, print an error message.
//
//   4. Quit
//      - End the program with a farewell message.
//
// -----------------------------------------------------------------------------
// HOW THE MENU SHOULD LOOK
// -----------------------------------------------------------------------------
//
//   ============================
//        TO-DO LIST MENU
//   ============================
//   1. Add task
//   2. View tasks
//   3. Delete task
//   4. Quit
//   Enter your choice (1-4):
//
// -----------------------------------------------------------------------------
// EXPECTED INTERACTION EXAMPLE
// -----------------------------------------------------------------------------
//
//   Enter your choice (1-4): 1
//   Enter task: Buy groceries
//   Task added: "Buy groceries"
//
//   Enter your choice (1-4): 2
//   Your Tasks:
//   1. Buy groceries
//   2. Study for exams
//
//   Enter your choice (1-4): 3
//   Enter task number to delete: 1
//   Task "Buy groceries" has been removed.
//
//   Enter your choice (1-4): 4
//   Goodbye!
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Store tasks in a vector<string> (a dynamic list of text).
// - Use a loop to keep the menu running until the user chooses to quit.
// - Each feature MUST be implemented in its own function (see scaffold below).
// - Handle invalid menu choices gracefully (print an error, do not crash).
//

//
// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
#include <vector>
#include <string>
using namespace std;


vector<string> task_list;

void add_task(string task) {
    task_list.push_back(task);
}

void view_task() {
    for (int t = 1; t < (int)task_list.size() + 1; t++) {
        cout << t << ". " << task_list[t - 1] << endl;
    }
}

void delete_task(int n) {
    task_list.erase(task_list.begin() + (n - 1));
}

void quit() {
    cout << "Goodbye!" << endl;
}

int main() {
    int user_choice = 0;

    while (!(user_choice == 4)) {
        cout << "============================ \n      TO-DO LIST MENU\n============================ " << endl;
        cout << "1. Add task \n2. View tasks \n3. Delete task \n4. Quit" << endl;

        cout << "Enter your choice (1-4): ";
        cin >> user_choice;

        if (user_choice == 1) {
            string task;
            cout << "Enter task: ";
            cin.ignore();
            getline(cin, task);
            add_task(task);
            cout << "Task added: \"" << task << "\"" << endl;

        } else if (user_choice == 2) {
            view_task();
            cout << "[";
            for (size_t i = 0; i < task_list.size(); i++) {
                cout << "\"" << task_list[i] << "\"";
                if (i != task_list.size() - 1) {
                    cout << ", ";
                }
            }
            cout << "]" << endl;

        } else if (user_choice == 3) {
            int task_to_del;
            cout << "Enter task number to delete: ";
            cin >> task_to_del;
            cout << "Task \"" << task_list[task_to_del - 1] << "\" has been removed" << endl;
            delete_task(task_to_del);

        } else if (user_choice == 4) {
            quit();
        }
    }

    return 0;
}