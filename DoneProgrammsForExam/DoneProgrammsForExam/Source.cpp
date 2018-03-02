#include <iostream>
#include <fstream>

using namespace std;

class Force {
	//protected:
public:
	unsigned int F;

	Force(const unsigned int _F = 0) : F(_F) {}

	virtual bool operator==(const Force &) = 0;

	virtual void print(ostream & = cout) = 0;

	virtual bool delta_less_then_1(const Force &) = 0;
};

class left_armed_robot : public Force {
	friend class right_armed_robot;

public:

	left_armed_robot(const unsigned int _F = 0) : Force(_F) {}

	bool operator==(const Force &a) {
		return F == a.F;
	}

	void print(ostream &out = cout) {
		out << "left armed robot, F = " << F << '\n';
	}

	bool delta_less_then_1(const Force &a) {
		return 0;
	}
};

class right_armed_robot : public Force {
public:
	right_armed_robot(const unsigned int _F = 0) : Force(_F) {}

	bool operator==(const Force &a) {
		return F == a.F;
	}

	bool delta_less_then_1(const Force &a) {
		int f1 = F, f2 = a.F;
		if (abs(f1 - f2) <= 1 && dynamic_cast<const left_armed_robot *>(&a)) {
			return 1;
		}
		return 0;
	}

	void print(ostream &out = cout) {
		out << "right armed robot, F = " << F << '\n';
	}
};

int main() {
	int n;
	cout << "enter size:\n";
	cin >> n;
	Force **arr = new Force *[n];
	for (int i = 0; i < n; i++) {
		char flag = 0;//'r' for right-hand robot, 'l' for left-hand
		cout << "enter 'r' for right-hand robot, 'l' for left-hand\n";
		cin >> flag;
		cout << "enter force\n";
		unsigned int f;
		cin >> f;
		switch (flag) {
		case 'r':
			arr[i] = new right_armed_robot(f);
			break;
		case 'l':
			arr[i] = new left_armed_robot(f);
			break;
		default:
			return 0;
		}
	}
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		if (dynamic_cast<left_armed_robot *>(arr[i])) {
			for (int j = i + 1; j < n; j++) {
				if (dynamic_cast<right_armed_robot *>(arr[j]) &&
					(*dynamic_cast<left_armed_robot *>(arr[i])) == (*dynamic_cast<right_armed_robot *>(arr[j])))
					cnt++;
			}
		}
		if (dynamic_cast<right_armed_robot *>(arr[i])) {
			for (int j = i + 1; j < n; j++) {
				if (dynamic_cast<left_armed_robot *>(arr[j]) &&
					(*dynamic_cast<right_armed_robot *>(arr[i])) == (*dynamic_cast<left_armed_robot *>(arr[j])))
					cnt++;
			}
		}
	}
	cout << "result is: " << cnt << '\n';
	ofstream fout("output.txt");
	for (int i = 0; i < n; i++) {
		if (dynamic_cast<right_armed_robot *>(arr[i])) {
			arr[i]->print(fout);
			int cnt = 0;
			for (int j = 0; j < n; j++) {
				if (arr[i]->delta_less_then_1(*arr[j])) {
					fout << '\t';
					arr[j]->print(fout);
					cnt++;
				}
			}
			fout << "cnt = " << cnt << "\n\n";
		}
	}
	for (int i = 0; i < n; i++) arr[i]->print(fout);

	return 0;
}
