#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Task {
    string name;
    bool completed;
};

vector<Task> tasks;

void addTask(string taskName) {
    tasks.push_back({taskName, false});
}

void viewTasks() {
    if (tasks.empty()) {
        cout << "No tasks available.\n";
        return;
    }
    for (int i = 0; i < tasks.size(); i++) {
        cout << i + 1 << ". " << tasks[i].name << " - " 
             << (tasks[i].completed ? "Completed" : "Pending") << endl;
    }
}

void markCompleted(int index) {
    if (index >= 0 && index < tasks.size()) {
        tasks[index].completed = true;
    }
}

void removeTask(int index) {
    if (index >= 0 && index < tasks.size()) {
        tasks.erase(tasks.begin() + index);
    }
}

int main() {
    int choice;
    string taskName;
    int index;
    while (true) {
        cout << "\n1. Add Task\n2. View Tasks\n3. Mark Task Completed\n4. Remove Task\n5. Exit\nEnter choice: ";
        cin >> choice;
        cin.ignore();
        if (choice == 1) {
            cout << "Enter task: ";
            getline(cin, taskName);
            addTask(taskName);
        } else if (choice == 2) {
            viewTasks();
        } else if (choice == 3) {
            cout << "Enter task number to mark completed: ";
            cin >> index;
            markCompleted(index - 1);
        } else if (choice == 4) {
            cout << "Enter task number to remove: ";
            cin >> index;
            removeTask(index - 1);
        } else if (choice == 5) {
            break;
        }
    }
    return 0;
}
