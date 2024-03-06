#include<bits/stdc++.h>
using namespace std;

unordered_map<string, int> h;
map<pair<string, string>, int> d;
unordered_map<string, int> f;
unordered_map<string, int> g;

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
		vector<string> str = split(line, " ");
		if(str[0] == ">") {
			start = str[1];
			dest = str[2];
			g[start] = 0;
			break;
		}
		
		string v;
		for(int i=0; i<str.size(); i++) {
			vector<string> s = split(str[i], "-");
			h[s[0]] = stoi(s[1]);
			if(i == 0) {
				v = s[0];
				continue;
			}
			d[{v, s[0]}] = stoi(s[2]);
			graph[v].push_back(s[0]);
		}
	}
	
	cin.close();
}

string findPath(string start, string dest, map<pair<int, string>, pair<int, string>> father) {
	if(start == dest) {
		return "\nDuong di: " + start;
	}
	else {
		string path = findPath(start, father[{f[dest], dest}].second, father);
		path += " -> " + dest;
		return path;
	}
}

void AStar(unordered_map<string, vector<string>> graph, string start, string dest) {
//	string out;
//	cout << "Nhap ten file output: "; cin >> out;
//	ofstream cout(out);

	ofstream cout("output.txt");

	set<pair<int, string>> adj; // Danh sach cac dinh ke chua duoc tham
	map<pair<int, string>, pair<int, string>> father; // Danh sach cac dinh cha
	
	for(int i=0; i<105; i++) cout << "-"; cout << "\n"; cout << left << setw(10) << "| TT" << setw(10) << "| TTK" << setw(15) << "| k(u, v)" << setw(10) << "| h(v)" << setw(10) << "| g(v)" << setw(10) << "| f(v)" << setw(40) << "| Danh sach L" << "|\n"; for(int i=0; i<105; i++) cout << "-"; cout << "\n";
	
	// Danh dau dinh bat dau la dinh da duoc tham
	adj.insert({h[start], start});
	
	while(!adj.empty()){
		pair<int, string> curr = *(adj.begin());
		adj.erase(adj.begin());
		
		string u = curr.second;
		
		cout << "| " << setw(8) << u;
        
		if(u == dest)
			break;
		
        for(string v : graph[u]){
        	g[v] = g[u] + d[{u, v}];
        	f[v] = g[v] + h[v];
        	cout << "| " << setw(8) << v << "| " << setw(13) << d[{u, v}] << "| " << setw(8) << h[v] << "| " << setw(8) << g[v] << "| " << setw(8) << f[v] << "| " << right << setw(40) << "| " << left << setw(11) << "\n| ";

			pair<int, string> next = {f[v], v};
			
            adj.insert(next);
            father[next] = curr;
        }
        string lList = ""; // In ra danh sach L
        for(auto p : adj) {
        	string c = p.second;
        	lList += c + to_string(p.first) + ", ";
		}
		lList.resize(lList.size() != 0 ? lList.size()-2 : 0); cout << right << setw(57) << "| " << left << setw(38) << lList << "|\n"; for(int i=0; i<105; i++) cout << "-"; cout << "\n";
    }
    
	if (adj.empty()) {
		cout << "\nKhong tim thay duong di tu " << start << " den " << dest;
	}
	else {
		cout << "| TTKT/DUNG" << setw(86) << right << "|\n"; for(int i=0; i<105; i++) cout << "-"; cout << "\n";
		cout << findPath(start, dest, father);
		cout << "\nDo dai: " << f[dest];
	}
	cout.close();
}

int main() {
	unordered_map<string, vector<string>> graph;
	string start, dest;
	
	readGraphFromFile(graph, start, dest);
	AStar(graph, start, dest);
	
	return 0;
}
