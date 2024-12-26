#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int minimumCPUinterval(vector<char>& tasks, int n) {
    unordered_map<char, int> taskCount;
    for (char task : tasks) {
        taskCount[task]++;
    }
    int maxCount = 0;
    for (auto& entry : taskCount) {
        maxCount = max(maxCount, entry.second);
    }
    int tasksWithMaxCount = 0;
    for (auto& entry : taskCount) {
        if (entry.second == maxCount) {
            tasksWithMaxCount++;
        }
    }
    int requiredSlots = (maxCount - 1) * (n + 1) + tasksWithMaxCount;
    return max((int)tasks.size(), requiredSlots);
}

int main() {

    int n;
    int numberoftasks;
    cout<<"Enter the number of tasks: ";
    cin>> numberoftasks;
    vector<char> tasks(numberoftasks);
    cout<<"Enter the tasks: ";
    for (int i = 0; i < numberoftasks; i++) {
        cin>>tasks[i];
    }
    cout<<"Enter n: ";
    cin>>n;
    cout<<"The minimum numer of CPU intervals is: "<<minimumCPUinterval(tasks, n);
}
