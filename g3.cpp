#include <bits/stdc++.h>
#define int long long
using namespace std;

const int MAX_N = 300010;

struct Job {
    int id;        
    int duration;  
    int deadline; 
    int start;     
};

bool compareJobs(const Job& a, const Job& b) {
    if (a.deadline != b.deadline)
        return a.deadline < b.deadline;
    if (a.duration != b.duration)
        return a.duration < b.duration;
    return a.id < b.id;
}

void solve() {
    int n;
    cin >> n;
    
    vector<Job> jobs(n + 1);
    
    for (int i = 1; i <= n; i++) {
        int s, t;
        cin >> s >> t;
        jobs[i] = {i, t, s + t, s};
    }
    
 
    sort(jobs.begin() + 1, jobs.end(), compareJobs);
    
    priority_queue<int> pq;
    int currentTime = 0;
    int completedJobs = 0;
    

    for (int i = 1; i <= n; i++) {
        currentTime += jobs[i].duration;
        pq.push(jobs[i].duration);
        completedJobs++;
        
        if (currentTime > jobs[i].deadline) {
            currentTime -= pq.top();
            pq.pop();
            completedJobs--;
        }
    }
    
    cout << completedJobs << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int testCases;
    cin >> testCases;
    
    while (testCases--) {
        solve();
    }
    
    return 0;
}