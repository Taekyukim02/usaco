/*
ID: taekyuk1
TASK: fence
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int F;
vector <int> graph[501];
int path[4000];
int n=0;

/*
vector<int>::iterator find(vector<int> vec, vector<int>::iterator& it, int t) {
    it = vec.begin();
    while(it!=vec.end() && *it != t) {
        cout << "increment" << endl;
        it++;
    }
    if(it == vec.end()) {
        cout << "NOT FOUND" << endl;
        return vec.begin();
    }
    cout << "returned " << *it  << endl;
    return it;
}
*/

void find_path(int node, ofstream& fout) {
    if(graph[node].empty()) {
        path[n] = node;
        n++;
        return;
    }

	/*
    fout << node << endl;
    path[n] = node;
    n++;
	*/
    
    while(!graph[node].empty()) {
        int to = graph[node][0];
        //cout << "find" << find(graph[node], to) << endl;
        graph[node].erase(graph[node].begin());
        auto it = graph[to].begin();
        while(it != graph[to].end() && *it != node)
            ++it;
        if(it == graph[to].end())
            cout << "ERROR" << endl;
        graph[to].erase(it);
        find_path(to, fout);
    }
	path[n] = node;
	n++;
}

void print_path(ofstream& fout) {
    for(int i=n-1; i>=0; i--)
        fout << path[i] << endl;
}

int main() {
    ifstream fin ("fence.in");
    fin >> F;
    for(int i=0; i<F; i++) {
        int a, b;
        fin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    fin.close();

    // check for odd-degree vertices
    int oddStart = 0;
    for(int i=1; i<=500; i++)
        if(graph[i].size()%2) {
            oddStart = i;
            break;
        }
    
    for(int i=1; i<=500; i++) {
        sort(graph[i].begin(), graph[i].end());
    }

    ofstream fout ("fence.out");
    if(oddStart)
        find_path(oddStart, fout);
    else
        find_path(1, fout);
    
    print_path(fout);
    fout.close();

    cout << n << endl;
    return 0;
}
