#include<iostream>
#include <algorithm>
#include<vector>
#include<queue>
using namespace std;

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int freq[26] = {0};
        for (char &ch : tasks) {
            freq[ch - 'A']++;
        }
        priority_queue<int> pq;
        for (int i = 0; i < 26; i++) {
            if (freq[i] > 0) {
                pq.push(freq[i]);
            }
        }
        int time = 0;
        while (!pq.empty()) {
            int cycle = n + 1;
            vector<int> store;
            int taskCount = 0;
            while (cycle-- && !pq.empty()) {
                if (pq.top() > 1) {
                    store.push_back(pq.top() - 1);
                }
                pq.pop();
                taskCount++;
            }
            for (int &x : store) {
                pq.push(x);
            }
            time += (pq.empty() ? taskCount : n + 1);
        }
        return time;
    }
};
int main() {
    Solution solution;

    int numberOfTasks, n;
    cout << "Enter the number of tasks: ";
    cin >> numberOfTasks;

    vector<char> tasks(numberOfTasks);
    cout << "Enter the tasks: ";
    for (int i = 0; i < numberOfTasks; i++) {
        cin >> tasks[i];
    }

    cout << "Enter period (n): ";
    cin >> n;

    int result = solution.leastInterval(tasks, n);
    cout << "The minimum number of CPU intervals is: " << result << endl;

    return 0;
}
