// PriorityQueuePractice.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;
class PriorityQueue {
private:
    vector<pair<int, int>> elem;
public:
    PriorityQueue() {}
    bool empty() {
        return elem.empty();
    }
    size_t size() {
        return elem.size();
    }
    void push(int value, int priority) {
        //elem.emplace_back(value, priority);
        elem.push_back(make_pair(value, priority));
    }
    int top() {
        if (empty()) {
            throw out_of_range("Priority Queue is empty");
        }
        int maxPriority = elem[0].second;
        int maxIndex = 0;
        for (size_t i = 1; i < elem.size(); ++i) {
            if (elem[i].second > maxPriority) {
                maxPriority = elem[i].second;
                maxIndex = static_cast<int>(i);
            }
        }
        return elem[maxIndex].first;
    }
    int pop() {
        if (empty()) {
            throw out_of_range("Priority Queue is empty");
        }
        int maxPriority = elem[0].second;
        int maxIndex = 0;
        for (size_t i = 1; i < elem.size(); ++i) {
            if (elem[i].second > maxPriority) {
                maxPriority = elem[i].second;
                maxIndex = static_cast<int>(i);
            }
        }
        elem.erase(elem.begin() + maxIndex);
    }
    void changePriority(int value, int newPriority) {
        bool found = false;
        for (size_t i = 0; i < elem.size(); ++i) {
            if (elem[i].first == value) {
                elem[i].second = newPriority;
                found = true;
            }
        }
        if (!found) {
            cout << "Value " << value << " not found in the priority queue.\n";
        }
    }
};
int findMaxIndex(int n[], int s) {
    int max = n[0];
    int index = 0;
    for (int i = 1; i < s; i++) {
        if (n[i] > max) {
            max = n[i];
            index = i;
        }
    }
    return index;
}

int main()
{
    pair<int, int> point = make_pair(5, 19);
    cout << "x-coord = " << point.first << endl;
    cout << "y-coord = " << point.second << endl;
    point.first = 11;
    cout << "x-coord = " << point.first << endl;

    size_t count, index, size;

    int n[10] = { 6,8,5,7,9,4,1,3,2,0 };
    PriorityQueue pq;
    pq.push(30, 3);
    pq.push(10, 1);
    pq.push(50, 5);
    pq.push(20, 2);
    pq.push(40, 4);
    cout << "Priority Queue elem:";
    while (!pq.empty()) {
        cout << pq.top() << " ";
        pq.pop();
    }
    cout << endl;
    return 0;

}

