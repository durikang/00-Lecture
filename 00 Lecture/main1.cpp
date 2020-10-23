#include "iostream"
#include "time.h"
#include "random"
#include "array"
#include "numeric"
#include <conio.h>


using namespace std;

namespace dr {
	class NumberGame {
		array<int, 25> res;
		int initStartArea= 24;



	public:
		NumberGame(){
			iota(res.begin(), res.end() - 1, 1);
			srand((unsigned int)time(0));
			res.at(24) = INT_MAX;

		}
		void shuffleNumber() {
			int tmp;
			int idx1;
			int idx2;
			for (int i = 0; i < 100; i++) {
				idx1 = rand() % 24;
				idx2 = rand() % 24;
				tmp = res.at(idx1);
				res.at(idx1) = res.at(idx2);
				res.at(idx2) = tmp;
			}
		}

		bool ParityErrorCheck() {
			auto Inversion = 0;
			bool Solved = true;

			while (Solved) {
				for (int i = 0; i < 25; i++) {
					for (int j = i; j < 25; j++) {
						if ((res.at(i) > res.at(j)) && res.at(i) != INT_MAX) {
							Inversion++;
						}
					}
				}
				if (Inversion % 2 == 0) {
					Solved = false;
					Inversion = 0;
				}
				else {
					Inversion = 0;
					shuffleNumber();
				}
			}

			return Solved;

		}

		void keyboard(char cinput) {
			switch (cinput) {
			case 'w':
			case 'W':
				if (initStartArea > 4) {
					// 가장 윗줄일 때는 w를 눌렀을때 동작 x
					res.at(initStartArea) = res.at(initStartArea - 5);
					res.at(initStartArea - 5) = INT_MAX;
					initStartArea -= 5;
				}
				break;
			case 's':
			case 'S':
				if (initStartArea <= 19) {
					// 가장 윗줄일 때는 w를 눌렀을때 동작 x
					res.at(initStartArea) = res.at(initStartArea + 5);
					res.at(initStartArea + 5) = INT_MAX;
					initStartArea += 5;
				}
				break;
			case 'a':
			case 'A':
				if (initStartArea % 5 != 0) {
					// 가장 윗줄일 때는 w를 눌렀을때 동작 x
					res.at(initStartArea) = res.at(initStartArea - 1);
					res.at(initStartArea - 1) = INT_MAX;
					initStartArea -= 1;
				}
				break;
			case 'd':
			case 'D':
				if (initStartArea % 5 != 4) {
					// 가장 윗줄일 때는 w를 눌렀을때 동작 x
					res.at(initStartArea) = res.at(initStartArea + 1);
					res.at(initStartArea + 1) = INT_MAX;
					initStartArea += 1;
				}
				break;
			}
			if (cinput == 'q' || cinput == 'Q') {
				cout << "종료\n";
				exit(0);
			}
		}
		void draw() {
			for (int i = 0; i < 5; i++) {
				for (int j = 0; j < 5; j++) {
					if (res.at(i * 5 + j) == INT_MAX) 
						cout << "*\t";
					else 
						cout << res.at(i * 5 + j) << "\t";

				}cout << "\n";
			}
		}

		bool gameWin() {
			for (int i = 0; i < 24; i++) {
				if (res[i] != i + 1) {
					return false;
					break;
				}
			}
			return true;
		}


	};
}

int main() {
	dr::NumberGame game;
	bool Inversion = true;
	game.shuffleNumber();
	bool over = false;

	while (true) {
		system("cls");

		while (Inversion) {
			Inversion=game.ParityErrorCheck();
		}
		game.draw();
		cout << "w : 위\ts: 아래\ta : 왼쪽\td : 오른쪽\tq : 종료 \n";
		over = game.gameWin();

		if (over)
			break;
		char cinput = _getch();
		game.keyboard(cinput); ///내일 여기 테스트 해보야함

	}
	cout << "숫자를 모두 정렬 하였습니다. 추카합니다.\n";
}