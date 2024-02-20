#include <iostream>
#include <string>
using namespace std;

class EmployeeNode {
public:
    string name;
    int papersToPrint;
    int timeAssigned;
    int timeTaken;
    EmployeeNode* next;

    EmployeeNode(string n, int papers) {
        name = n;
        papersToPrint = papers;
        timeAssigned = 0;
        timeTaken = 0;
        next = nullptr;
    }
};

class RoundRobinScheduler {
private:
    EmployeeNode* head;
    EmployeeNode* current;
    int totalTime;

public:
    RoundRobinScheduler(int time) {
        head = nullptr;
        current = nullptr;
        totalTime = time;
    }

    void addEmployee(string name, int papers) {
        EmployeeNode* newNode = new EmployeeNode(name, papers);
        if (head == nullptr) {
            head = newNode;
            head->next = head; 
            current = head;
        } else {
            newNode->next = head->next;
            head->next = newNode;
        }
    }

    void runScheduler(int numEmployees) {
        if (head == nullptr) {
            cout << "No employees in the scheduler.\n";
            return;
        }

        int timePerEmployee = totalTime / numEmployees;

        EmployeeNode* start = current;
        while (totalTime > 0) {
            if (current->papersToPrint > 0) {
                current->timeAssigned += timePerEmployee;
                if (current->papersToPrint <= timePerEmployee) {
                    current->timeTaken += current->papersToPrint;
                    totalTime -= current->papersToPrint;
                    cout << "Task for " << current->name << " completed in " << current->timeAssigned << " units of time.\n";
                    current->papersToPrint = 0;
                } else {
                    current->timeTaken += timePerEmployee;
                    current->papersToPrint -= timePerEmployee;
                    totalTime -= timePerEmployee;
                }
            }
            current = current->next;
            if (current == start) {
                break;
            }
        }

        if (totalTime == 0) {
            cout << "All tasks completed within the allotted time.\n";
        } else {
            cout << "Total time exhausted. Tasks left incomplete:\n";
            EmployeeNode* temp = head;
            do {
                if (temp->papersToPrint > 0) {
                    cout << temp->name << ": " << temp->papersToPrint << " papers\n";
                }
                temp = temp->next;
            } while (temp != head);
        }
    }

    void displayEmployees() {
        if (head == nullptr) {
            cout << "No employees in the scheduler.\n";
            return;
        }

        EmployeeNode* start = head;
        EmployeeNode* temp = head;
        do {
            cout << "Employee: " << temp->name << ", Papers to print: " << temp->papersToPrint << "\n";
            temp = temp->next;
        } while (temp != start);
    }
};

int main() {
    int totalTime, numEmployees;
    cout << "Enter the total time available for printing: ";
    cin >> totalTime;
    cout << "Enter the number of employees: ";
    cin >> numEmployees;

    RoundRobinScheduler scheduler(totalTime);

    for (int i = 0; i < numEmployees; i++) {
        string name;
        int papers;
        cout << "Enter employee name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter number of papers to print: ";
        cin >> papers;
        scheduler.addEmployee(name, papers);
    }

    cout << "\nEmployees in the scheduler:\n";
    scheduler.displayEmployees();

    cout << "\nRunning the scheduler...\n";
    scheduler.runScheduler(numEmployees);

    return 0;
}