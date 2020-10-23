#include <iostream>
#include <time.h>
#include <random>
#include <numeric>
#include <array>

using namespace std;

array<int, 9> randomNumber() {
	array<int,9> number; //1~9 랜덤숫자
	int tmp;
	int idx1;
	int idx2;
	iota(number.begin(), number.end(), 1);

	srand((unsigned int)time(0));

	
	for (int i = 0; i < 100; i++) {
		idx1 = rand() % 9;
		idx2 = rand() % 9;
		tmp = number.at(idx1);
		number.at(idx1) = number.at(idx2);
		number.at(idx2) = tmp;
	}

	return number;
}



int main()
{
	array<int,3> n;
	array<int,3> vari; //랜덤하게 섞은 숫자들중 3가지
	int v=0;
	int strike=0;
	int ball = 0;
	int cnt = 1;

	bool exit = false;

	
	//섞은 값을 vari에 push
	for (int i = 0; i < 3; i++) {
		vari[i] = randomNumber().at(i);
	}

	cout << "\n";
	while (true) {

		cout << "===================시작=============================\n";
		cout << "회차 : " << cnt <<"\n";
		
		cout << "공 세개를 던져주세요.\n";
		cout << "입력값 : ";
		for (int i = 0; i < 3; i++)
		{
			cin >> v;
			n[i]=v;
		}
		cout << "\n";
		cout << "=====경계선====\n";

		for (int i = 0; i < 3; i++) {
			if (n[i] < 1 || n[i]>9) {
				exit = true;
			}
		}
		if (exit == true) {
			cout << "1~9이외의 숫자를 입력시 종료합니다.\n";
			break;
		}




		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				if (vari[i] == n[j]) {
					if (i == j) {
						strike++;
					}
					else {
						ball++;
					}
				}
			}
		}

		cout <<"회차 : "<<cnt<< "회\n";
		cout <<"결과-> \t스트라이크 : " << strike << "\t 볼 : " << ball << "\n";
		cnt++;
		if (strike == 3) {
			copy(vari.begin(), vari.end(), ostream_iterator<int>(cout,", "));
			cout << "\n";
			cout << "3진아웃";
			break;
		}
		else {
			cout << "3진아웃 잡으셔야 게임이 끝납니다. 다시 던져주세요\n\n\n";
			strike = 0;
			ball = 0;
		}
	}



}
