#include <iostream>
#include <string>
#include <fstream>
#include <windows.h>
#include <vector>
#include <iomanip>
#include "Company.h"
#include "Line.h"
#include "Driver.h"
#include "Bus.h"
#include "Shift.h"
using namespace std;
void Menu1( Company C);
void Menu2( Company C);
void MenuPri( Company C);

void clearScreen()
{
	cout << string(50, '\n');
}
void fail(int &n)
{
	while (cin.fail())
	{
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "\n";
		cout << "Hipótese indisponível. Tente novamente" << endl;
		cout << "\n";
		cout << "::: ";
		cin >> n;
	}
}

int main() {
	SetConsoleCP(1252); SetConsoleOutputCP(1252);
	string nomeempresa;
	cout << "Insira o nome da empresa" << endl;
	cout << "::: ";
	cin >> nomeempresa;

	string nomeficheirocondutores;
	cout << endl << "Insira o nome do ficheiro dos condutores" << endl;
	cout << "::: ";
	cin >> nomeficheirocondutores;
	ifstream ficheirocond(nomeficheirocondutores);
	while (!ficheirocond)
	{
		cout << "\n";
		cout << "Ficheiro indisponível. Tente novamente" << endl;;
		cout << "::: ";
		cin >> nomeficheirocondutores;
		ficheirocond.open(nomeficheirocondutores);
	}
	
	
	string nomeficheirolinhas;
	cout << endl << "Insira o nome do ficheiro das linhas" << endl;
	cout << "::: ";
	cin >> nomeficheirolinhas;
	ifstream ficheirolinhas(nomeficheirolinhas);
	while (!ficheirolinhas)
	{
		cout << "\n";
		cout << "Ficheiro indisponível. Tente novamente" << endl;
		cout << "::: ";
		cin >> nomeficheirolinhas;
		ficheirolinhas.open(nomeficheirolinhas);
	}

	clearScreen();
	Company C(nomeempresa, nomeficheirocondutores, nomeficheirolinhas);
	C.setupDrivers();
	C.setupLines();
	cout << "<<< " << nomeempresa << " >>>" << endl;

	C.busAux();
	MenuPri(C);
}
void MenuPri(Company C)
{
	 int n1;
	
	cout << "\n";
	cout << "1. Gerir Condutores" << endl;
	cout << "\n";
	cout << "2. Visualizar informação: Horários, Linhas, Condutores e Percursos" << endl;
	cout << "\n";
	cout << "0. Terminar Programa" << endl;
	cout << "\n";
	cout << "::: ";
	cin >> n1;
	fail(n1);
	while (n1 != 1 && n1 != 2 && n1 != 0)
	{
		cout << "\n";
		cout << "Hipótese indispónivel. Tente novamente" << endl;
		cout << "\n";
		cout << "::: ";
		cin >> n1;
		fail(n1);
	}
	switch (n1)
	{
	case 1:
		clearScreen();
		Menu1(C);
		break;
	case 2:
		clearScreen();
		Menu2(C);
	case 0:
		exit;
		break;
	}

}
void Menu1(Company C)
{
	int n3;
	cout << "1. Criar Condutor" << endl;
	cout << "\n";
	cout << "2. Alterar Condutor" << endl;
	cout << "\n";
	cout << "3. Remover Condutor" << endl;
	cout << "\n";
	cout << "4. Salvar Ficheiro" << endl;
	cout << "\n";
	cout << "0. Voltar Atrás" << endl;
	cout << "\n";
	cout << "::: ";
	cin >> n3;
	fail(n3);
	while (n3 != 1 && n3 != 2 && n3 != 0 && n3 != 3 && n3 != 4)
	{
		cout << "\n";
		cout << "Hipótese indisponível. Tente novamente" << endl;
		cout << "\n";
		cout << "::: ";
		cin >> n3;
		fail(n3);
	}
	switch (n3)
	{
	case 1:
		clearScreen();
		C.createDriver();
		break;
	case 2:
		clearScreen();
		C.changeDriver();
		break;
	case 3:
		clearScreen();
		C.deleteDriver();
		break;
	case 4:
		clearScreen();
		C.saveDriver();
		clearScreen();
		cout << "<<< Salvo >>>";
		cout << string(3, '\n');
		Menu1(C);
		break;
	case 0:
		clearScreen();
		MenuPri(C);
		break;
	}
}
void Menu2(Company C)
{

	int n2, n3;
	cout << "1. Visualizar horários" << endl;
	cout << "\n";
	cout << "2. Visualizar linhas" << endl;
	cout << "\n";
	cout << "3. Visualizar percursos" << endl;
	cout << "\n";
	cout << "4. Visualizar condutores" << endl;
	cout << "\n";
	cout << "5. Visualizar linhas que possuem determinada paragem" << endl;
	cout << "\n";
	cout << "6. Visualizar o trabalho atribuído a um condutor" << endl;
	cout << "\n";
	cout << "7. Visualizar a informação de um autocarro" << endl;
	cout << "\n";
	cout << "8. Visualizar períodos de condutores sem o serviço completo atribuído" << endl;
	cout << "\n";
	cout << "9. Visualizar períodos de autocarros sem condutor atribuído" << endl;
	cout << "\n";
	cout << "10. Atribuir serviço a um condutor" << endl;
	cout << "\n";
	cout << "0. Voltar Atrás" << endl;
	cout << "\n";
	cout << "::: ";
	cin >> n2;
	fail(n2);
	while (n2 != 1 && n2 != 2 && n2 != 3 && n2 != 4 && n2 != 0 && n2 != 5 && n2 != 6 && n2 != 7 && n2 != 8 && n2 != 9 && n2 != 10)
	{
		cout << "\n";
		cout << "Hipótese indisponível. Tente novamente" << endl;
		cout << "::: ";
		cout << "\n";
		cin >> n2;
		fail(n2);
	}
	switch (n2)
	{
	case 1:
		clearScreen();
		cout << "1. Visualizar horários de uma linha" << endl;
		cout << "\n";
		cout << "2. Visualizar horários de um paragem" << endl;
		cout << "\n";
		cout << "0. Voltar Atrás" << endl;
		cout << "\n";
		cout << "::: ";
		cin >> n3;
		fail(n3);
		while (n3 != 1 && n3 != 2 && n3 != 0)
		{
			cout << "\n";
			cout << "Hipótese indisponível. Tente novamente" << endl;
			cout << "::: ";
			cout << "\n";
			cin >> n3;
			fail(n3);
		}
		switch (n3)
		{
		case 1:
			clearScreen();
			C.showScheduleLine();
			break;
		case 2:
			clearScreen();
			C.showScheduleStop();
			break;
		}
		clearScreen();
		Menu2(C);
		break;
	case 2:
		clearScreen();
		C.viewLine();
		clearScreen();
		Menu2(C);
		break;
	case 3:
		clearScreen();
		C.routeBetweenStops();
		clearScreen();
		Menu2(C);
		break;
	case 4:
		clearScreen();
		C.viewDriver();
		clearScreen();
		Menu2(C);
		break;
	case 5:
		clearScreen();
		C.showLineswithxStop();
		clearScreen();
		Menu2(C);
		break;
	case 6:
		clearScreen();
		C.showWorkDriver();
		clearScreen();
		Menu2(C);
		break;
	case 7:
		clearScreen();
		C.showBus();
		clearScreen();
		Menu2(C);
		break;
	case 8:
		clearScreen();
		C.showDriverWithoutService();
		clearScreen();
		Menu2(C);
		break;
	case 9:
		clearScreen();
		C.showTimeswithoutDriver();
		clearScreen();
		Menu2(C);
		break;
	case 10:
		clearScreen();
		C.ServiceDistribution();
		clearScreen();
		Menu2(C);
		break;
	case 0:
		clearScreen();
		MenuPri(C);
	}
}