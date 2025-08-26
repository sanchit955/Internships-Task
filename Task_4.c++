#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Task {
    string desc;
    bool done = false;
};

void showTasks(const vector<Task>& tasks) {
    if (tasks.empty()) {
        cout << "No tasks in the list.\n";
        return;
    }
    for (int i = 0; i < tasks.size(); i++) {
        cout << i + 1 << ". [" << (tasks[i].done ? 'x' : ' ') << "] " << tasks[i].desc << "\n";
    }
}

int main() {
    vector<Task> tasks;
    while (true) {
        cout << "\n1.Add Task 2.View Tasks 3.Mark Completed 4.Remove Task 5.Exit\nChoose: ";
        int choice; cin >> choice;
        cin.ignore(); // clear newline
        if (choice == 1) {
            cout << "Enter task description: ";
            string desc;
            getline(cin, desc);
            tasks.push_back({desc});
        } else if (choice == 2) {
            showTasks(tasks);
        } else if (choice == 3) {
            showTasks(tasks);
            cout << "Task number to mark as completed: ";
            int num; cin >> num;
            if (num > 0 && num <= tasks.size())
                tasks[num - 1].done = true;
            else
                cout << "Invalid task number.\n";
        } else if (choice == 4) {
            showTasks(tasks);
            cout << "Task number to remove: ";
            int num; cin >> num;
            if (num > 0 && num <= tasks.size())
                tasks.erase(tasks.begin() + num - 1);
            else
                cout << "Invalid task number.\n";
        } else if (choice == 5) {
            break;
        } else {
            cout << "Invalid option, try again.\n";
        }
    }
    return 0;
}
