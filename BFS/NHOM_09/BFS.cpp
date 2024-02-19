#include <bits/stdc++.h>
using namespace std;

//vector<string> split(string str, char delimiter) { // Ham de tach chuoi
//	stringstream ss(str);
//	string token;
//	vector<string> tokens;
//	
//	while(getline(ss, token, delimiter)) {
//		tokens.push_back(token);
//	}
//	return tokens;
//}

vector<string> split(string str, string delimiters) { // Ham de tach chuoi
    vector<string> tokens;
    string::size_type lastPos = str.find_first_not_of(delimiters, 0);
    string::size_type pos = str.find_first_of(delimiters, lastPos);

    while (string::npos != pos || string::npos != lastPos) {
        tokens.push_back(str.substr(lastPos, pos - lastPos));
        lastPos = str.find_first_not_of(delimiters, pos);
        pos = str.find_first_of(delimiters, lastPos);
    }

    return tokens;
}

void readGraphFromFile(unordered_map<string, vector<string>> &graph, string &start, string &dest) {
//	string inp;
//	cout << "Nhap ten file input: "; cin >> inp;
//	ifstream cin(inp);

	ifstream cin("input.txt");
	
	string line;
	while(getline(cin, line)) {
		vector<string> s = split(line, " ");
		if(s[0] == ">") {
			start = s[1];
			dest = s[2];
			break;
		}
		for(int i=1; i<s.size(); i++) {
			graph[s[0]].push_back(s[i]);
		}
	}
	
	cin.close();
}


string findPath(string start, string dest, unordered_map<string, string> father) {
	if(start == dest) {
		return "\nKet qua bai toan: " + start;
	}
	else {
		string path = findPath(start, father[dest], father);
		path += " -> " + dest;
		return path;
	}
}

void BreadthFirstSearch(unordered_map<string, vector<string>> graph, string start, string dest) {
//	string out;
//	cout << "Nhap ten file output: "; cin >> out;
//	ofstream cout(out);

	ofstream cout("output.txt");

	deque<string> adj; // Danh sach cac dinh ke chua duoc tham
	unordered_map<string, string> father; // Danh sach cac dinh cha
	set<string> visited; // Danh sach cac dinh da duoc tham
	
	for(int i=0; i<115; i++) cout << "-"; cout << "\n"; cout << left << setw(15) << "|Phat trien TT" << setw(20) << "| Trang thai ke" << setw(40) << "| Danh sach Q" << setw(40) << "| Danh sach L" << "|\n"; for(int i=0; i<115; i++) cout << "-"; cout << "\n";
	
	// Danh dau dinh bat dau la dinh da duoc tham
	adj.push_back(start);
	visited.insert(start);
	
	while(!adj.empty()){
        string u = adj.front();
		adj.pop_front();
		
		cout << "| " << setw(13) << u << "| ";
        
		if(u == dest)
			break;
		
		string vList = ""; // In ra cac trang thai ke
        for(string v : graph[u]){
        	vList += v + ", ";
            if(visited.find(v) != visited.end())
				continue;
            visited.insert(v);
            adj.push_back(v);
            father[v] = u;
        }
        vList.resize(vList.size() != 0 ? vList.size()-2 : 0); cout << setw(18) << vList << "| ";
        
        string qList = ""; // In ra danh sach Q
        for(string c : visited) {
        	qList += c + ", ";
		}
		qList.resize(qList.size() != 0 ? qList.size()-2 : 0); cout << setw(38) << qList << "| ";
		
        string lList = ""; // In ra danh sach L
        for(string c : adj) {
        	lList += c + ", ";
		}
		lList.resize(lList.size() != 0 ? lList.size()-2 : 0); cout << setw(38) << lList << "|\n"; for(int i=0; i<115; i++) cout << "-"; cout << "\n";
    }
    
	if (visited.find(dest) == visited.end()) {
		cout << "\nKhong tim thay duong di tu " << start << " den " << dest;
	}
	else {
		cout << "TTKT/DUNG" << setw(91) << right << "|\n"; for(int i=0; i<115; i++) cout << "-"; cout << "\n";
		cout << findPath(start, dest, father);
	}
    cout.close();
}


int main() {
	unordered_map<string, vector<string>> graph;
	string start, dest;
	
	readGraphFromFile(graph, start, dest);
	BreadthFirstSearch(graph, start, dest);
	
	return 0;
}
