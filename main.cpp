#include<iostream>
#include <chrono>
#include <thread>
#include <string>
void timer();
char checkv1(int min);
char checkv2(int lvl, int lastlvl);
std::string checkv1info(int min);
std::string checkv2info(int lvl, int lastlvl);
bool checklvl(int min);
bool checkh2o(int lvl, int set, bool print);
std::string checkh2oshow(int lvl, int set);

int main() {

	int min = 0;
	int lvl = -1;
	int lastlvl = 0;




	while (true) {
		min++;
		if (checkv2(lvl, lastlvl)== 'o'){
			lvl = lvl - 5;
		}
		else if (checklvl(min) == 1) {
			lastlvl = lvl;
			lvl++;
		}
		std::cout << "tempo:" << min << "min \n";
		std::cout << "nivel:" << lvl << "L \n";
		std::cout << "\n";
		std::cout << "     " << checkv1(min) << "-----------v1" << checkv1info(min) << "      | (abre de 20 em 20 min)\n";
		std::cout << "    +" << checkv1(min) << "+                           |\n";
		std::cout << "    | |                           |\n";
		std::cout << "    | |                           |\n";
		std::cout << "  +-----+                         |\n";
		std::cout << "  |" << checkh2oshow(lvl, 10) << "|" << "-----------LH            |\n";
		std::cout << "  |" << checkh2oshow(lvl, 8) << "|                         |\n";
		std::cout << "  |" << checkh2oshow(lvl, 6) << "|                         |\n";
		std::cout << "  |" << checkh2oshow(lvl, 4) << "|                         |\n";
		std::cout << "  |" << checkh2oshow(lvl, 2) << "|" << "-----------LL            |\n";
		std::cout << "  +-----+                         |\n";
		std::cout << "    | |                           |\n";
		std::cout << "    | |                           |\n";
		std::cout << "    +" << checkv2(lvl, lastlvl) << "+                           |\n";
		std::cout << "     " << checkv2(lvl, lastlvl) << "-----------v2" << checkv2info(lvl,lastlvl) << "      | (abre se nivel = LH)\n";
		timer();

	}

	return 0;
}

void timer() {
	std::this_thread::sleep_for(std::chrono::milliseconds(200));
	system("cls");
}
char checkv1(int min) {
	if ((min % 20 == 0) or (min % 20 < 2)) {


		return 'o';
	}
	else {

		return 'I';

	}
}


bool checklvl(int min) {

	if (checkv1(min) == 'o') {
		return 1;
	}
	else return 0;
}


std::string checkv1info(int min) {

	switch (checkv1(min)) {
	case 'I':
		return("(fechado)");
		break;
	case'o':
		return("\033[1;32m(aberto) \033[0m");
		break;
	}
}
bool checkh2o(int lvl, int set) {
	if (lvl == set) {
		std::cout << "-----";
		return 1;
	}

	else return 0;
}


std::string checkh2oshow(int lvl, int set) {
	if (lvl >= set){
		return "\033[1;44m     \033[0m";

	}
	else return "     ";;

}

char checkv2(int lvl,int lastlvl)
{
	if (lvl == 10 or lvl ==5 and lastlvl !=4 )
	{
		return 'o';
	}
	else
	{
		return 'I';
	}
}
std::string checkv2info(int lvl, int lastlvl)
{
	switch (checkv2(lvl, lastlvl)) {
	case 'I':
		return("(fechado)");
		break;
	case'o':
		return("\033[1;32m(aberto) \033[0m");
		break;
	}
}

