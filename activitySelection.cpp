#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Activity {
    string name;
    int start;
    int finish;
};

bool compareActivities(Activity a, Activity b) {
    return a.finish < b.finish;
}

void activitySelection(vector<Activity>& activities) {
    int n = activities.size();
    if (n == 0) return;

    sort(activities.begin(), activities.end(), compareActivities);

    cout << "Selected Activities: ";
    cout << activities[0].name << " ";

    int lastFinish = activities[0].finish;
    int totalSelected = 1;

    for (int i = 1; i < n; i++) {
        if (activities[i].start >= lastFinish) {
            cout << activities[i].name << " ";
            lastFinish = activities[i].finish;
            totalSelected++;
        }
    }
    cout << "\nTotal selected activities = " << totalSelected << endl;
}

int main() {
    vector<Activity> activities = {
        {"A1", 1, 4},
        {"A2", 3, 5},
        {"A3", 0, 6},
        {"A4", 5, 7},
        {"A5", 8, 9},
        {"A6", 5, 9}
    };

    activitySelection(activities);

    return 0;
}
