#include<bits/stdc++.h>
using namespace std;

unordered_map<string, string> h;

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

bool cmp (const string a, const string b)	{
	return stoi(h[a]) < stoi(h[b]);
}

void readGraphFromFile(unordered_map<string, vector<string>> &graph, string &start, string &dest) {
//	string inp;
//	cout << "Nhap ten file input: "; cin >> inp;
//	ifstream cin(inp);

	ifstream cin("input.txt");
	
	string line;
	while(getline(cin, line)) {
		vector<string> str = split(line, " ");
		if(str[0] == ">") {
			start = str[1];
			dest = str[2];
			break;
		}
		
		string v;
		for(int i=0; i<str.size(); i++) {
			vector<string> s = split(str[i], "-");
			h[s[0]] = s[1];
			if(i == 0) {
				v = s[0];
				continue;
			}
			graph[v].push_back(s[0]);
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

void BestFirstSearch(unordered_map<string, vector<string>> graph, string start, string dest) {
//	string out;
//	cout << "Nhap ten file output: "; cin >> out;
//	ofstream cout(out);

	ofstream cout("output.txt");
	
	deque<string> adj; // Danh sach cac dinh ke chua duoc tham
	unordered_map<string, string> father; // Danh sach cac dinh cha
	set<string> visited; // Danh sach cac dinh da duoc tham
	
	for(int i=0; i<85; i++) cout << "-"; cout << "\n"; cout << left << setw(15) << "|Phat trien TT" << setw(30) << "| Trang thai ke" << setw(40) << "| Danh sach L" << "|\n"; for(int i=0; i<85; i++) cout << "-"; cout << "\n";
	
	// Danh dau dinh bat dau la dinh da duoc tham
	adj.push_back(start);
	visited.insert(start);
	
	while(!adj.empty()){
        string u = adj.front();
		adj.pop_front();
		
		cout << "| " << setw(13) << u + h[u] << "| ";
        
		if(u == dest)
			break;
		
		string vList = ""; // In ra cac trang thai ke
        for(string v : graph[u]){
        	vList += v + h[v] + ", ";
            if(visited.find(v) != visited.end())
				continue;
            visited.insert(v);
            adj.push_back(v);
            father[v] = u;
        }
        vList.resize(vList.size() != 0 ? vList.size()-2 : 0); cout << setw(28) << vList << "| ";
		
		sort(adj.begin(), adj.end(), cmp);
        string lList = ""; // In ra danh sach L
        for(string c : adj) {
        	lList += c + h[c] + ", ";
		}
		lList.resize(lList.size() != 0 ? lList.size()-2 : 0); cout << setw(38) << lList << "|\n"; for(int i=0; i<85; i++) cout << "-"; cout << "\n";
    }
    
	if (visited.find(dest) == visited.end()) {
		cout << "\nKhong tim thay duong di tu " << start << " den " << dest;
	}
	else {
		cout << "TTKT/DUNG" << setw(61) << right << "|\n"; for(int i=0; i<85; i++) cout << "-"; cout << "\n";
		cout << findPath(start, dest, father);
	}
    cout.close();
}

int main() {
	unordered_map<string, vector<string>> graph;
	string start, dest;
	
	readGraphFromFile(graph, start, dest);
	BestFirstSearch(graph, start, dest);
	
	return 0;
}
