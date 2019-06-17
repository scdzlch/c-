#include<iostream>
#include<vector>
#include<string>
using namespace std;
class Cell {
public:
	Cell() = default;
	Cell(string con) : content(con) {}
	~Cell() = default;
	void show() const;
	void set(string con);
private:
	string content = "       ";
};
class Table {
public:
	Table() {
		vector<Cell> tcol;
		tcol.push_back(Cell());
		cells.push_back(tcol);
	}
	Table(int x, int y) :por(x), row(y) {
		for (int i = 0; i < row; i++) {
			vector<Cell> *trow = new vector<Cell>(por);
			for (int j = 0; j < por; j++) {
				trow->push_back(Cell());
			}
			cells.push_back(*trow);
		}

	}
	~Table() {
		for (int i = 0; i < row; i++)
			//	delete &cells[i];
			;
	}
	void show();
	int addRow();
	void delRow(int n);
	int addColumn();
	void delColumn(int n);
	void set(int, int, string);
	void set(int, int, int);
private:
	vector<vector<Cell> > cells;
	int por = 1;
	int row = 1;
};
void Table::show() {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < por; j++) {
			cells[i][j].show();
		}
		cout << endl;
	}
}
int Table::addRow() {
	vector<Cell> *trow = new vector<Cell>(por);
	for (int i = 0; i < por; i++) {
		trow->push_back(Cell());
	}
	cells.push_back(*trow);
	row += 1;
	return row;
}
void Table::delRow(int n) {
	//delete &cells[n-1];
	cells.erase(cells.begin() + n - 1);
	row--;
}
int Table::addColumn() {
	for (int i = 0; i < row; i++) {
		cells[i].push_back(Cell());
	}
	por += 1;
	return por;
}
void Table::delColumn(int n) {
	for (int i = 0; i < row; i++) {
		cells[i].erase(cells[i].begin() + n - 1);
	}
	por--;
}
void Table::set(int y, int x, string con) {
	cells[y - 1][x - 1].set(con);
}
void Table::set(int y, int x, int con) {
	string scon = to_string(con);
	cells[y - 1][x - 1].set(scon);
}
void Cell::show() const {
	cout << content << " ";
}
void Cell::set(string con) {
	content = con;
}
int main() {
	Table tb;
	tb.show();
	tb.addRow();
	tb.show();
	tb.addColumn();
	tb.show();
	Table tb1(5, 5);
	tb1.show();
	tb1.set(1, 1, 30);
	tb1.set(2, 2, "hello");
	tb1.show();
	tb1.delRow(1);
	tb1.show();
	tb1.delColumn(1);
	tb1.show();
	return 0;
}
