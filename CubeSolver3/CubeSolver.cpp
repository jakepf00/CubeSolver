// things to do:
//	Input validation in cube constructor
//	Optimize inverse and half turns
//	Split into separate files
//	Change things to private
//	Move corner parity table generation to CubeSolver constructor
//	Change Cube.applyMove to a switch statement
//	Make Solve() and SolveWithDetails()

#include<string>
#include<unordered_map>
#include<queue>
#include<vector>
#include<iostream>
#include<algorithm>
#include<chrono>
using namespace std;

class Cube {
public:
	const string SOLVED_CUBE = "WWWWWWWWWOOOOOOOOOGGGGGGGGGRRRRRRRRRBBBBBBBBBYYYYYYYYY";
	string cubeRepresentation;

	Cube(string scrambleString) {
		// need more input validation: 9 of each color, contains only WGORYB chars, centers correct color
		if (scrambleString.length() != 54) {
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
		cout << "\t   " << a[0] << a[1] << a[2] << endl;
		cout << "\t   " << a[3] << a[4] << a[5] << endl;
		cout << "\t   " << a[6] << a[7] << a[8] << endl;
		cout << "\t" << a[9]  << a[10] << a[11] << a[18] << a[19] << a[20] << a[27] << a[28] << a[29] << a[36] << a[37] << a[38] << endl;
		cout << "\t" << a[12] << a[13] << a[14] << a[21] << a[22] << a[23] << a[30] << a[31] << a[32] << a[39] << a[40] << a[41] << endl;
		cout << "\t" << a[15] << a[16] << a[17] << a[24] << a[25] << a[26] << a[33] << a[34] << a[35] << a[42] << a[43] << a[44] << endl;
		cout << "\t   " << a[45] << a[46] << a[47] << endl;
		cout << "\t   " << a[48] << a[49] << a[50] << endl;
		cout << "\t   " << a[51] << a[52] << a[53] << endl;
	}

	void R() {
		string a = cubeRepresentation;
		cubeRepresentation = "";
		vector<int> v = { 0,1,20,3,4,23,6,7,26,9,10,11,12,13,14,15,16,17,18,19,47,21,22,50,24,25,53,33,30,27,34,31,28,35,32,29,8,37,38,5,40,41,2,43,44,45,46,42,48,49,39,51,52,36 };
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
		vector<int> v = { 6,3,0,7,4,1,8,5,2,18,19,20,12,13,14,15,16,17,27,28,29,21,22,23,24,25,26,36,37,38,30,31,32,33,34,35,9,10,11,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53 };
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
		vector<int> v = { 0,1,2,3,4,5,17,14,11,9,10,45,12,13,46,15,16,47,24,21,18,25,22,19,26,23,20,6,28,29,7,31,32,8,34,35,36,37,38,39,40,41,42,43,44,33,30,27,48,49,50,51,52,53 };
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
		vector<int> v = { 44,1,2,41,4,5,38,7,8,15,12,9,16,13,10,17,14,11,0,19,20,3,22,23,6,25,26,27,28,29,30,31,32,33,34,35,36,37,51,39,40,48,42,43,45,18,46,47,21,49,50,24,52,53 };
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
		vector<int> v = { 0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,42,43,44,18,19,20,21,22,23,15,16,17,27,28,29,30,31,32,24,25,26,36,37,38,39,40,41,33,34,35,51,48,45,52,49,46,53,50,47 };
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
		vector<int> v = { 29,32,35,3,4,5,6,7,8,2,10,11,1,13,14,0,16,17,18,19,20,21,22,23,24,25,26,27,28,53,30,31,52,33,34,51,42,39,36,43,40,37,44,41,38,45,46,47,48,49,50,9,12,15 };
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

	void applyAlg(string alg) {
		for (int i = 0; i < alg.length(); i += 2) {
			string move;
			move.push_back(alg[i]);
			move.push_back(alg[i+1]);
			applyMove(move);
		}
	}
};

class CubeSolver {
public:
	unordered_map<string, string> memo;
	vector<string> cornerParityTable;
	vector<string> movesG0 = { "L ", "R ", "F ", "B ", "U ", "D " };
	vector<string> movesG1 = { "L ", "R ", "F2", "B2", "U ", "D " };
	vector<string> movesG2 = { "L2", "R2", "F2", "B2", "U ", "D " };
	vector<string> movesG3 = { "L2", "R2", "F2", "B2", "U2", "D2" };

	string Solve(Cube cube) {
		if (cornerParityTable.size() == 0) { // just move this into the constructor?
			cout << "Generating corner parity table..." << endl;
			memo.clear();
			auto t1 = chrono::high_resolution_clock::now();
			generateCornerParityTable();
			auto t2 = chrono::high_resolution_clock::now();
			chrono::duration<double, std::milli> stepTime = t2 - t1;
			cout << "Finished table generation in " << stepTime.count() << " milliseconds" << endl;
			cout << "Table size: " << cornerParityTable.size() << endl << endl;
		}

		cout << "Scramble:" << endl;
		cube.displayCube();
		cout << endl;
		
		string solution = "";
		string step = "";
		
		auto t1 = chrono::high_resolution_clock::now();
		for (int i = 0; i < 4; i++) {
			step = completeStep(cube, i);
			cube.applyAlg(step);
			solution += step;
		}
		auto t2 = chrono::high_resolution_clock::now();
		chrono::duration<double, std::milli> totalTime = t2 - t1;
		cout << "Total time: " << totalTime.count() << " milliseconds" << endl;
		
		return solution;
	}
	
	string completeStep(Cube cube, int step) {
		memo.clear();
		auto t1 = chrono::high_resolution_clock::now();
		string path = BFS(cube, step);
		auto t2 = chrono::high_resolution_clock::now();
		chrono::duration<double, std::milli> stepTime = t2 - t1;
		cube.applyAlg(path);
		cout << "Step " << step << ": " << path << endl;
		cout << "\t" << stepTime.count() << " milliseconds" << endl;
		cube.displayCube();
		cout << endl;
		return path;
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

	string BFS(Cube cube, int phase) {
		vector<string> moves;
		switch (phase) {
		case 0: moves = movesG0; break;
		case 1: moves = movesG1; break;
		case 2: moves = movesG2; break;
		case 3: moves = movesG3; break;
		default: cout << "Illegal phase: " << phase << endl;
		}
		queue<string> path;
		queue<string> q;
		q.push(cube.cubeRepresentation);
		path.push("");

		if (isGoalReached(cube.cubeRepresentation, phase)) return "";

		while (!q.empty()) {
			string current = q.front();
			string currentPath = path.front();
			q.pop();
			path.pop();

			if (memo.count(current)) continue;
			memo[current] = currentPath;

			for (int i = 0; i < moves.size(); i++) {
				cube.cubeRepresentation = current;
				cube.applyMove(moves[i]);
				string nextState = cube.cubeRepresentation;
				if (!memo.count(nextState)) {
					string nextPath = currentPath + moves[i];
					if (isGoalReached(nextState, phase)) return nextPath;
					q.push(cube.cubeRepresentation);
					path.push(nextPath);
				}
			}
		}
		return "";
	}

	void generateCornerParityTable() {
		Cube cube(""); // default to solved cube
		vector<string> moves = movesG3;
		queue<string> path;
		queue<string> q;
		q.push(cube.cubeRepresentation);
		path.push("");
		vector<int> v = { 0, 2, 6, 8, 9, 11, 15, 17, 18, 20, 24, 26, 27, 29, 33, 35, 36, 38, 42, 44, 45, 47, 51, 53 };


		while (!q.empty()) {
			string current = q.front();
			string currentPath = path.front();
			q.pop();
			path.pop();

			if (memo.count(current)) continue;
			memo[current] = currentPath;

			string currentCorners = "";
			for (auto i : v) {
				currentCorners.push_back(current[i]);
			}
			bool alreadyThere = false;
			for (int i = 0; i < cornerParityTable.size(); i++) {
				if (cornerParityTable[i] == currentCorners) {
					alreadyThere = true;
					break;
				}
			}
			if (!alreadyThere) {
				cornerParityTable.push_back(currentCorners);
			}
			else continue;

			for (int i = 0; i < moves.size(); i++) {
				cube.cubeRepresentation = current;
				cube.applyMove(moves[i]);
				string nextState = cube.cubeRepresentation;
				if (!memo.count(nextState)) {
					string nextPath = currentPath + moves[i];
					q.push(cube.cubeRepresentation);
					path.push(nextPath);
				}
			}
		}
	}

	bool cornerParityCorrect(string current) {
		vector<int> corners = { 0, 2, 6, 8, 9, 11, 15, 17, 18, 20, 24, 26, 27, 29, 33, 35, 36, 38, 42, 44, 45, 47, 51, 53 };
		for (int i = 0; i < cornerParityTable.size(); i++) {
			for (int j = 0; j < corners.size(); j++) {
				if (current[corners[j]] != cornerParityTable[i][j]) {
					break;
				}
				if (j == corners.size() - 1) return true;
			}
		}
		return false;
	}

	bool isGoalReached(string current, int phase) {
		vector<pair<int, int>> pieces;
		vector<int> colors;
		switch(phase) {
		case 0:
			// Edges are correctly oriented - no F or B moves to solve each edge
			pieces = { {1,37},{3,10},{5,28},{7,19},{46,25},{48,16},{50,34},{52,43},{21,14},{23,30},{39,32},{41,12} };
			for (int i = 0; i < pieces.size(); i++) {
				if (current[pieces[i].first] == 'O' || current[pieces[i].first] == 'R') return false;
				if (current[pieces[i].first] == 'G' || current[pieces[i].first] == 'B') {
					if (current[pieces[i].second] == 'W' || current[pieces[i].second] == 'Y') return false;
				}
			}	
			return true;
		case 1:
			// Top and bottom only have top/bottom colors
			for (int i = 0; i < 9; i++) { // Top
				if (current[i] != 'W' && current[i] != 'Y') return false;
			}
			for (int i = 45; i < 54; i++) { // Down
				if (current[i] != 'W' && current[i] != 'Y') return false;
			}
			return true;
		case 2:
			// make sure each face only has its own color or the color of the opposite side
			for (int i = 9; i < 18; i++) { // Left
				if (current[i] != 'O' && current[i] != 'R') return false;
			}
			for (int i = 18; i < 27; i++) { // Front
				if (current[i] != 'B' && current[i] != 'G') return false;
			}
			for (int i = 27; i < 36; i++) { // Right
				if (current[i] != 'O' && current[i] != 'R') return false;
			}
			for (int i = 36; i < 45; i++) { // Back
				if (current[i] != 'B' && current[i] != 'G') return false;
			}
			if (!cornerParityCorrect(current)) {
				return false;
			}
			return true;
		case 3:
			return current == "WWWWWWWWWOOOOOOOOOGGGGGGGGGRRRRRRRRRBBBBBBBBBYYYYYYYYY";
		}
		return false;
	}
};

int main() {
	Cube thing("");
	thing.applyAlg("BiR LiU2DiF2BiU F2RiD2B2DiF2L2U R2L2F2Ui");
	CubeSolver solver;
	solver.Solve(thing);
}
