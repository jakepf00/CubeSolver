#include<string>
#include<unordered_map>
#include<queue>
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

class Cube {
public:
	const string SOLVED_CUBE = "WWWWOOOOGGGGRRRRBBBBYYYY";
	string cubeRepresentation;

	Cube(string scrambleString) {
		// need more input validation: 4 of each color, contains only WGORYB chars
		if (scrambleString.length() != 24) {
			cubeRepresentation = SOLVED_CUBE;
		}
		else {
			cubeRepresentation = scrambleString;
		}
	}

	bool isSolved() {
		return cubeRepresentation == SOLVED_CUBE;
	}

	void displayCube() {
		string a = cubeRepresentation;
		cout << "  " << a[0] << a[1] << endl;
		cout << "  " << a[2] << a[3] << endl;
		cout << a[4] << a[5] << a[8] << a[9] << a[12] << a[13] << a[16] << a[17] << endl;
		cout << a[6] << a[7] << a[10] << a[11] << a[14] << a[15] << a[18] << a[19] << endl;
		cout << "  " << a[20] << a[21] << endl;
		cout << "  " << a[22] << a[23] << endl;
	}

	void R() {
		string a = cubeRepresentation;
		cubeRepresentation = "";
		vector<int> v = { 0, 9, 2, 11, 4, 5, 6, 7, 8, 21, 10, 23, 14, 12, 15, 13, 3, 17, 1, 19, 20, 18, 22, 16 };
		if (v.size() != 24) cout << "Error in R" << endl;
		for (auto i : v) {
			cubeRepresentation.push_back(a[i]);
		}
	}
	void Ri() {
		R();
		R();
		R();
	}
	void R2() {
		R();
		R();
	}

	void U() {
		string a = cubeRepresentation;
		cubeRepresentation = "";
		vector<int> v = { 2, 0, 3, 1, 8, 9, 6, 7, 12, 13, 10, 11, 16, 17, 14, 15, 4, 5, 18, 19, 20, 21, 22, 23 };
		if (v.size() != 24) cout << "Error in U" << endl;
		for (auto i : v) {
			cubeRepresentation.push_back(a[i]);
		}
	}
	void Ui() {
		U();
		U();
		U();
	}
	void U2() {
		U();
		U();
	}

	void F() {
		string a = cubeRepresentation;
		cubeRepresentation = "";
		vector<int> v = { 0, 1, 7, 5, 4, 20, 6, 21, 10, 8, 11, 9, 2, 13, 3, 15, 16, 17, 18, 19, 14, 12, 22, 23 };
		if (v.size() != 24) cout << "Error in F" << endl;
		for (auto i : v) {
			cubeRepresentation.push_back(a[i]);
		}
	}
	void Fi() {
		F();
		F();
		F();
	}
	void F2() {
		F();
		F();
	}

	void L() {
		string a = cubeRepresentation;
		cubeRepresentation = "";
		vector<int> v = { 19, 1, 17, 3, 6, 4, 7, 5, 0, 9, 2, 11, 12, 13, 14, 15, 16, 22, 18, 20, 8, 21, 10, 23 };
		if (v.size() != 24) cout << "Error in L" << endl;
		for (auto i : v) {
			cubeRepresentation.push_back(a[i]);
		}
	}
	void Li() {
		L();
		L();
		L();
	}
	void L2() {
		L();
		L();
	}

	void D() {
		string a = cubeRepresentation;
		cubeRepresentation = "";
		vector<int> v = { 0, 1, 2, 3, 4, 5, 18, 19, 8, 9, 6, 7, 12, 13, 10, 11, 16, 17, 14, 15, 22, 20, 23, 21 };
		if (v.size() != 24) cout << "Error in D" << endl;
		for (auto i : v) {
			cubeRepresentation.push_back(a[i]);
		}
	}
	void Di() {
		D();
		D();
		D();
	}
	void D2() {
		D();
		D();
	}

	void B() {
		string a = cubeRepresentation;
		cubeRepresentation = "";
		vector<int> v = { 13, 15, 2, 3, 1, 5, 0, 7, 8, 9, 10, 11, 12 ,23, 14, 22, 18, 16, 19, 17, 20, 21, 4, 6 };
		if (v.size() != 24) cout << "Error in B" << endl;
		for (auto i : v) {
			cubeRepresentation.push_back(a[i]);
		}
	}
	void Bi() {
		B();
		B();
		B();
	}
	void B2() {
		B();
		B();
	}

	void applyMove(string move) {
		if (move == "R ") R();
		else if (move == "Ri") Ri();
		else if (move == "R2") R2();
		else if (move == "U ") U();
		else if (move == "Ui") Ui();
		else if (move == "U2") U2();
		else if (move == "F ") F();
		else if (move == "Fi") Fi();
		else if (move == "F2") F2();
		else if (move == "L ") L();
		else if (move == "Li") Li();
		else if (move == "L2") L2();
		else if (move == "D ") D();
		else if (move == "Di") Di();
		else if (move == "D2") D2();
		else if (move == "B ") B();
		else if (move == "Bi") Bi();
		else if (move == "B2") B2();
		else cout << "Illegal move: " << move << endl;
	}
};

class CubeSolver {
public:
	unordered_map<string, string> memo;

	string Solve(Cube cube) {
		memo.clear();
		string path = BFS(cube, "WWWWOOOOGGGGRRRRBBBBYYYY");
		if (path != "") return formatAlg(path);
		else return formatAlg(backBFS());
	}

	string formatAlg(string alg) {
		string newAlg = "";
		for (int x = 0; x < alg.length(); x += 2) {
			newAlg.push_back(alg[x]);
			if (alg[x + 1] == 'i') {
				newAlg.push_back('i');
				newAlg.push_back(' ');
			}
			else if (alg[x + 1] == ' ') {
				newAlg.push_back(' ');
			}
			else if (alg[x + 1] == '2') {
				newAlg.push_back('2');
				newAlg.push_back(' ');
			}
			else {
				cout << "Error in format alg" << endl;
				return newAlg;
			}
		}
		return newAlg;
	}

	string invertAlg(string alg) {
		reverse(alg.begin(), alg.end());
		string newAlg = "";
		for (int x = 0; x < alg.length(); x += 2) {
			newAlg.push_back(alg[x+1]);
			if (alg[x] == 'i') {
				newAlg.push_back(' ');
				//newAlg = newAlg + alg[x + 1] + " ";
			}
			else if (alg[x] == ' ') {
				//newAlg = newAlg + alg[x + 1] + "i";
				newAlg.push_back('i');
			}
			else if (alg[x] == '2') {
				//newAlg = newAlg + alg[x + 1] + "2";
				newAlg.push_back('2');
			}
			else {
				cout << "Error in invert alg" << endl;
				return newAlg;
			}
		}
		return newAlg;
	}

	string BFS(Cube cube, string goalState) {
		cout << "In front bfs" << endl;

		queue<string> path;
		queue<string> q;
		q.push(cube.cubeRepresentation);
		path.push("");
		// move 'moves' into a  variable?
		// moves = ["U ", "Ui", "U2", "L ", "Li", "L2", "F ", "Fi", "F2", "R ", "Ri", "R2", "B ", "Bi", "B2", "D ", "Di", "D2"]
		vector<string> moves = { "U ", "Ui", "L ", "Li", "F ", "Fi", "R ", "Ri", "B ", "Bi", "D ", "Di" };
		//vector<string> moves = { "U ", "L ", "F ", "R ", "B ", "D " };
		int count = 0;

		while (!q.empty()) {
			string current = q.front();
			string currentPath = path.front();
			q.pop();
			path.pop();

			count = count + 1;
			if (count % 10000 == 0) {
				cout << count << " " << currentPath << endl;
			}

			if (memo.count(current)) continue;
			memo[current] = currentPath;

			if (isGoalReached(goalState, current)) {
				return currentPath;
			}
			else if (currentPath.length() > 9) { // each move is 2 chars, so it will do n/2 moves
				continue;
			}
			else {
				for (auto move : moves) {
					cube.cubeRepresentation = current;
					cube.applyMove(move);
					string nextState = cube.cubeRepresentation;
					if (!memo.count(nextState)) {
						string nextPath = currentPath + move;
						q.push(cube.cubeRepresentation);
						path.push(nextPath);
					}
				}
			}
		}
		return "";
	}

	string backBFS() {
		cout << "In back bfs" << endl;
		Cube c("WWWWOOOOGGGGRRRRBBBBYYYY");
		queue<string> path;
		queue<string> q;
		q.push(c.cubeRepresentation);
		path.push("");
		// move 'moves' into a  variable?
		// moves = ["U ", "Ui", "U2", "L ", "Li", "L2", "F ", "Fi", "F2", "R ", "Ri", "R2", "B ", "Bi", "B2", "D ", "Di", "D2"]
		vector<string> moves = { "U ", "Ui", "L ", "Li", "F ", "Fi", "R ", "Ri", "B ", "Bi", "D ", "Di" };
		int count = 0;

		while (!q.empty()) {

			string current = q.front();
			string currentPath = path.front();
			q.pop();
			path.pop();

			count = count + 1;
			if (count % 10000 == 0) {
				cout << count << " " << currentPath << endl;
			}

			if (memo.count(current)) {
				string answer = "";
				answer.append(memo[current]);
				answer.append(invertAlg(currentPath));
				return answer;
			}

			for (auto move : moves) {
				c.cubeRepresentation = current;
				c.applyMove(move);
				string nextPath = currentPath + move;
				q.push(c.cubeRepresentation);
				path.push(nextPath);


			}
		}
	}

	bool isGoalReached(string goal, string current) {
		bool solved = true;
		int count = 0;
		for (auto i : goal) { // change to regular for loop to get rid of count variable
			if (i == 'x') {
				count = count + 1;
				continue;
			}
			else {
				if (i != current[count]) {
					solved = false;
					break;
				}
				count = count + 1;
			}
		}
		return solved;
	}
};

int main() {
	Cube thing("RBOBGBYGYOORWRYBYWRGWGOW"); // scramble
	//thing = Cube("WGWWOGOYRORRGOWRYBYBBBYG"); # scramble: R F' R' U' F R U R' U' R2 U'
	//                                           solution: U R2 U L U B U' F' L' U L'
	//thing = Cube("WOWBOOYYGWGWRBRGYBYBRGRO"); # 1 turn first side
	//Cube thing("WBWBOOOOGWGWRRRRYBYBYGYG"); // R'
	//thing = Cube("BBWWYBOOOOGWGWRRRRYBYGYG"); # R'U'
	//thing = Cube("BYWRYBOOOBGWWRGRGRGBYOYW"); # R'U'R'
	//thing = Cube("BYWGYROWBWOGORYRGRGBBOYW"); # R'U'R'F'
	//thing = Cube("BYWGYROGBWYRORGBGROWOWBY"); # R'U'R'F'D'
	//thing = Cube("OYWGBRYGBWYROBGYRWGOOWBR"); # R'U'R'F'D'B'
	//thing = Cube("WWGRGYGBRBOYWBRGOOYRYBWO"); # scramble R2 U F' D

	thing.displayCube();
	CubeSolver solver;
	cout << solver.Solve(thing) << endl;
}