#include "Company.h"
#include "Driver.h"
#include "Line.h"
#include "Bus.h"
#include <fstream>
#include <iostream>
#include <iomanip>.


Company::Company(string name, string fileDrivers, string fileLines) {
	this->name = name;
	this->fileDrivers = fileDrivers;
	this->fileLines = fileLines;

}

const int hi = 8;
const int hf = 19;
////////////////////////////////
// get methods
///////////////////////////////
string Company::getCompanyName() const {
	return name;
}
vector <Driver> Company::getCompanyDrivers()const
{
	return drivers;
}
vector <Line> Company::getCompanyLines()const
{
	return lines;
}
//////////////////////////////
// set methods
/////////////////////////////


void Company::setCompanyName(string name)
{
	this->name = name;
}
void Company::setCompanyDrivers(vector<Driver> drivers)
{
	this->drivers = drivers;
}
void Company::setCompanyLines(vector<Line>lines)
{
	this->lines = lines;
}
void Company::setupDrivers() {
	ifstream file(fileDrivers);
	string driver;
	while (getline(file, driver))
	{
		drivers.push_back(Driver(driver));
	}

}
void Company::setupLines() {
	ifstream file(fileLines);
	string line;
	while (getline(file, line))
	{
		lines.push_back(Line(line));

	}

}

////////////////////////////
// other methods
///////////////////////////
void Company::clearScreenC()
{
	cout << string(50, '\n');
}
void Company::failC(int n)
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

void Company::saveDriver()
{
	string nomeficheirocondutores;
	cout << "Insira o nome do ficheiro dos condutores: " << endl << "::: ";
	cin >> nomeficheirocondutores;
	ofstream filedrivers;
	filedrivers.open(nomeficheirocondutores);
	for (int i = 0; i < drivers.size(); i++)
	{
		filedrivers << drivers.at(i).getId() << " ; " << drivers.at(i).getName() << " ; " << drivers.at(i).getShiftMaxDuration() << " ; ";
		filedrivers << drivers.at(i).getMaxWeekWorkingTime() << " ; " << drivers.at(i).getMinRestTime() << endl;
	}
}

void Company::viewLine()
{

	for (int i = 0; i < lines.size(); i++)
	{
		cout << " | ID: " << lines.at(i).getId() << " | " << endl << " | Frequência: " << lines.at(i).getFrequency() << " minutos | " << endl;
		cout << " | Paragens: ";
		for (int j = 0; j < lines.at(i).getBusStops().size(); j++)
		{
			cout << lines.at(i).getBusStops().at(j) << " | ";
		}
		cout << endl << " | Tempos: ";
		for (int k = 0; k < lines.at(i).getTimings().size(); k++)
		{
			cout << lines.at(i).getTimings().at(k) << " minutos" << " | ";
		}
		cout << string(3, '\n');
	}
	getchar(); getchar();
}
void Company::viewDriver()
{
	for (int i = 0; i< drivers.size(); i++)
	{
		cout << " | ID: " << drivers.at(i).getId() << " | " << endl;
		cout << " | Nome: " << drivers.at(i).getName() << endl;
		cout << " | Número de horas consecutivas por dia: " << drivers.at(i).getShiftMaxDuration() << endl;
		cout << " | Número máximo de horas semanais:  " << drivers.at(i).getMaxWeekWorkingTime() << endl;
		cout << " | Número mínimo de horas de descanso: " << drivers.at(i).getMinRestTime() << endl;
		cout << string(3, '\n');
	}
	getchar(); getchar();
}

void Company::changeDriver()
{
	int option;
	int temp = 0;
	int id, nid;
	int j = 0;
	int i = 0;
	int k = 0;
	string name;
	int dayh;
	int weekh;
	int resth;
	cout << "Insira o número de identificação do condutor" << endl;
	cout << "::: ";
	cin >> id;
	failC(id);
	clearScreenC();
	while (i < drivers.size())
	{
		if (id == drivers.at(i).getId())
		{
			temp = drivers.at(i).getId();
			cout << "1.Alterar ID" << endl;
			cout << "\n";
			cout << "2.Alterar nome" << endl;
			cout << "\n";
			cout << "3.Alterar número máximo de horas por turno" << endl;
			cout << "\n";
			cout << "4.Alterar número máximo de horas por semana" << endl;
			cout << "\n";
			cout << "5.Alterar número mínimo de horas de descanso" << endl;
			cout << "\n";
			cout << "0.Voltar atrás" << endl;
			cout << "\n";
			cout << "::: ";
			cin >> option;
			while (option != 1 && option != 2 && option != 3 && option != 4 && option != 5 && option != 0)
			{
				cout << "\n";
				cout << "Hipótese indisponível. Tente novamente" << endl;
				cout << "\n";
				cout << "::: ";
				cin >> option;
			}
			clearScreenC();
			switch (option) {
			case 1:
				cout << "Insira o novo ID" << endl;
				cout << "::: ";
				cin >> nid;
				failC(nid);
				while (j < drivers.size())
				{
					if (nid == drivers.at(j).getId())
					{
						cout << endl << "Número de identificação já existente. Introduza outro" << endl;
						cout << "::: ";
						cin >> nid;
					}
					j++;
				}
				while (k < drivers.size()) {
					if (nid == drivers.at(k).getId())
					{
						cout << endl << "Número de identificação já existente. Introduza outro." << endl;
						cout << "::: ";
						cin >> nid;

					}
					else
						k++;
				}
				drivers.at(i).setId(nid);
				break;
			case 2:
				cout << "Insira o nome do condutor" << endl;
				cout << ":::";
				getline(cin, name);
				drivers.at(i).setName(name);
				cin.ignore(1000, '\n');
				break;
			case 3:
				cout << "Insira o número máximo de horas por turno" << endl;
				cout << "::: ";
				cin >> dayh;
				failC(dayh);
				drivers.at(i).setmaxHours(dayh);
				break;
			case 4:
				cout << "Insira o número máximo de horas semanais" << endl;
				cout << "::: ";
				cin >> weekh;
				failC(weekh);
				drivers.at(i).setmaxWeekWorkingTime(weekh);
				break;
			case 5:
				cout << "Insira o número mínimo de horas de descanso" << endl;
				cout << "::: ";
				cin >> resth;
				failC(resth);
				drivers.at(i).setminRestTime(resth);
				break;
			case 0:
				exit;
				break;
			}
			break;
		}
		else
		{
			i++;
		}
	}
	clearScreenC();
	if (i == drivers.size() && id != temp)
	{
		cout << "<<< Condutor não encontrado >>>";
		getchar(); getchar();
	}
	else if (option != 0)
	{
		cout << "<<< Condutor alterado >>>";
		getchar(); getchar();
	}
}

void Company::deleteDriver()
{
	int id;
	int temp = 0;
	int i = 0;
	cout << "Insira o número de identificação do condutor a eliminar" << endl << "0. Voltar Atrás" << endl;
	cout << "::: ";
	cin >> id;
	failC(id);
	while (i < drivers.size())
	{
		if (drivers.at(i).getId() == id)
		{
			temp = drivers.at(i).getId();
			drivers.erase(drivers.begin() + i);
			i = i - 1;
			break;
		}
		else {
			i++;
		}
	}
	clearScreenC();
	if (id = 0)
	{
		clearScreenC();
		getchar(); getchar();
	}
	if (i == drivers.size() && id != temp)
	{
		cout << "<<< Condutor não encontrado >>>";
		getchar(); getchar();
	}
	else if (id != 0)
	{
		cout << "<<< Condutor eliminado >>>";
		getchar(); getchar();
	}
}

void Company::createDriver()
{
	int i = 0;
	int j = 0;
	unsigned int id;
	string name;
	unsigned int dayh;
	unsigned int weekh;
	unsigned int resth;
	vector<Shift> shift;
	cout << "Introduza o número de identificação do condutor" << endl;
	cout << "::: ";
	cin >> id;
	failC(id);
	while (j < drivers.size())
	{
		if (id == drivers.at(j).getId())
		{
			cout << endl << "Número de identificação já existente. Introduza outro" << endl;
			cout << "::: ";
			cin >> id;
		}
		j++;
	}
	while (i < drivers.size()) {
		if (id == drivers.at(i).getId())
		{
			cout << endl << "Número de identificação já existente. Introduza outro." << endl;
			cout << "::: ";
			cin >> id;

		}
		else
			i++;
	}
	cin.ignore(1000, '\n');
	cout << endl << "Introduza o nome do condutor" << endl;
	cout << "::: ";
	getline(cin, name);
	cout << endl<< "Introduza o número máximo de horas por turno" << endl;
	cout << "::: ";
	cin >> dayh;
	cout << endl << "Insira o número máximo de turnos por semana" << endl;
	cout << "::: ";
	cin >> weekh;
	cout << endl << "Insira o número mínimo de horas de descanso" << endl;
	cout << "::: ";
	cin >> resth;
	Driver D(id, name, dayh, weekh, resth, shift);
	drivers.push_back(D);
	clearScreenC();
	cout << "<<< Condutor Criado >>>";
	getchar(); getchar();
}

void Company::showScheduleLine()
{
	int i = 0;
	int n1;
	int hi1;
	int hi2;
	int hi3;
	int hf1;
	int temp = 0;
	int minutes = 0;
	int freqpart = 0;
	int freq;
	int id;
	int k = 0;
	int l = 1;
	int r = 0;
	vector<string> busStop;
	vector <int> busTime;
	int him = hi;
	hi1 = hi2 = hi3 = him;
	int hfm = hf;
	hf1 = hfm;
	cout << "Insira o número de identificação da linha onde pretende ver o horário" << endl;
	cout << "::: ";
	cin >> id;
	failC(id);
	clearScreenC();
	while (i < lines.size())
	{
		if (id == lines.at(i).getId())
		{
			temp = lines.at(i).getId();
			freq = lines.at(i).getFrequency();
			cout << " | Horário da Linha " << id << " | " << endl << " | Sentido: " << lines.at(i).getBusStops().at(0) << " - " << lines.at(i).getBusStops().at(lines.at(i).getBusStops().size() - 1) << " | " << endl;
			cout << endl;
			cout << endl;
			busTime = lines.at(i).getTimings();
			busStop = lines.at(i).getBusStops();
			cout << " | ";
			for (int j = 0; j < lines.at(i).getBusStops().size(); j++) 
			{
				int length = SizeStop(i, j);
				cout << setfill(' ') << setw(length) << " ";
				cout << busStop.at(j);
				cout << setfill(' ') << setw(length) << " " << " ";
			}

			cout << endl;

			while (him < hfm || (him == hfm &&minutes == 0))
			{
				int j = 0;
				while (minutes >= 60) {
					minutes = minutes - 60;
					him++;
				}
				l = 1;
				int length = SizeHours(i, 0);
				cout << " | ";
				cout << setfill(' ') << setw(length) << " ";
				cout << setfill('0') << setw(2) << him << ":" << setfill('0') << setw(2) << minutes;
				cout << setfill(' ') << setw(length) << "  | ";
				j++;

				while (k < busTime.size()) 
				{
					minutes = minutes + busTime.at(k);
					while (minutes >= 60) 
					{
						minutes = minutes - 60;
						him++;
					}
					int length = SizeHours(i, l);
					cout << setfill(' ') << setw(length) << " ";
					cout << setfill('0') << setw(2) << him << ":" << setfill('0') << setw(2) << minutes;
					cout << setfill(' ') << setw(length) << "    | ";
					k++;
					j++;
					l++;
				}
				k = 0;
				freqpart += freq;
				while (freqpart >= 60) {
					hi1++;
					freqpart = freqpart - 60;
				}
				minutes = freqpart;
				him = hi1;
				cout << endl;
			}
			freqpart = 0;
			minutes = 0;

			cout << endl << " | Horário da Linha " << id << " | " << endl << " | Sentido: " << lines.at(i).getBusStops().at(lines.at(i).getBusStops().size() - 1) << " - " << lines.at(i).getBusStops().at(0) << " | " << endl;
			cout << endl;
			cout << endl;

			for (int j = lines.at(i).getBusStops().size() - 1; j >= 0; j--) {
				int length = SizeStop(i, j);
				cout << setfill(' ') << setw(length) << " ";
				cout << busStop.at(j);
				cout << setfill(' ') << setw(length) << " " << " ";
			}

			cout << endl;
			k = busTime.size() - 1;
			while (hi2 < hf1 || (hi2 == hf1 && minutes == 0))
			{
				while (r < lines.at(i).getTimings().size())
				{
					minutes = minutes + lines.at(i).getTimings().at(r);
					r++;
				}

				int l = lines.at(i).getTimings().size() - 1;
				int j = busStop.size() - 1;
				while (minutes >= 60) 
				{
					minutes = minutes - 60;
					hi3++;
				}
				freqpart = minutes;
				int length = SizeHours(i, 0);
				cout << setfill(' ') << setw(length) << " ";
				cout << setfill('0') << setw(2) << hi3 << ":" << setfill('0') << setw(2) << minutes;
				cout << setfill(' ') << setw(length) << "  | ";
				j--;
				while (k >= 0) {
					minutes = minutes + busTime.at(k);
					while (minutes >= 60) {
						minutes = minutes - 60;
						hi2++;
					}
					int length = SizeHours(i, l);
					cout << setfill(' ') << setw(length) << " ";
					cout << setfill('0') << setw(2) << hi2 << ":" << setfill('0') << setw(2) << minutes;
					cout << setfill(' ') << setw(length) << "    | ";
					k--;
					j--;
					l--;
				}
				k = busTime.size() - 1;
				freqpart = freqpart + freq;
				while (freqpart >= 60) {
					hi3++;
					freqpart = freqpart - 60;
				}
				minutes = freqpart;
				hi2 = hi3;
				cout << endl;
			}
			break;
		}
		i++;
	}
	if (i == lines.size() && id != temp)
	{
		cout << "<<< Linha não encontrada >>>";
		getchar(); getchar();
	}
	else
	{
		cout << string(3, '\n');
		cout << "0. Voltar Atrás" << endl;
		cout << "::: ";
		cin >> n1;
		failC(n1);
		while (n1 != 0)
		{
			cout << "\n";
			cout << "Hipótese indisponivel. Tente novamente" << endl;
			cout << "\n";
			cout << "::: ";
			cin >> n1;
			failC(n1);
		}
	}
}
void Company::showScheduleStop() {
	string stop;
	int i = 0;
	int cont = 0;
	int him = hi;
	int hfm = hf;
	int minutes = 0;
	int j = 0;
	cout << "Insira a paragem onde pretende ver os horários" << endl;
	cout << "::: ";
	cin.ignore(1000, '\n');
	getline(cin, stop);
	clearScreenC();
	while (i < lines.size())
	{
		while (j < lines.at(i).getBusStops().size())
		{
			if (stop == lines.at(i).getBusStops().at(j))
			{
				int a = lines.at(i).getBusStops().size() - 1;
				int cont1 = cont;

				if (stop != lines.at(i).getBusStops().at(0))
				{
					cout << "<<< Horário na linha " << lines.at(i).getId() << " no sentido " << lines.at(i).getBusStops().at(0) << " - " << lines.at(i).getBusStops().at(a) << " >>>" << endl << endl;
					for (int k = 0; k < cont; k++)
					{
						minutes = minutes + lines.at(i).getTimings().at(k);
					}
					while (him < hfm || him == hfm && minutes == 0)
					{
						while (minutes >= 60) {
							minutes = minutes - 60;
							him++;
						}
						cout << " |  " << setfill('0') << setw(2) << him << ":" << setfill('0') << setw(2) << minutes << " | ";
						minutes = minutes + lines.at(i).getFrequency();
						cout << endl;
					}
					cout << endl;
				}

				if (stop != lines.at(i).getBusStops().at(a))
				{
					cout << "<<< Horário na linha " << lines.at(i).getId() << " no sentido " << lines.at(i).getBusStops().at(a) << " - " << lines.at(i).getBusStops().at(0) << " >>>" << endl << endl;
					minutes = 0;
					for (int k = a - 1; cont1 <= k; k--)
					{
						minutes = minutes + lines.at(i).getTimings().at(k);
					}
					him = hi;
					hfm = hf;
					while (him < hfm || him == hfm && minutes == 0)
					{
						while (minutes >= 60) {
							minutes = minutes - 60;
							him++;
						}
						cout << " | " << setfill('0') << setw(2) << him << ":" << setfill('0') << setw(2) << minutes << " | ";
						minutes = minutes + lines.at(i).getFrequency();
						cout << endl;
					}
					cout << endl;
				}
				break;
			}
			else
			{
				j++;
				cont++;
			}
		}
		i++;
		minutes = 0;
		j = 0;
		him = hi;
		hfm = hf;
		cont = 0;
	}
	getchar();
}
void Company::showLineswithxStop()
{
	string stop;
	int length = lines.size();
	int posline = 0;
	int posvec = 0;
	int cont = 0;
	cout << "Introduza a paragem que pretende pesquisar" << endl;
	cout << "::: ";
	cin.ignore(1000, '\n');
	getline(cin, stop);
	clearScreenC();
	while (posline < length)
	{
		while (posvec < lines.at(posline).getBusStops().size())
		{
			string a = lines.at(posline).getBusStops().at(posvec);
			if (stop == lines.at(posline).getBusStops().at(posvec))
			{
				cout << "<<< A linha " << lines.at(posline).getId() << " possui a paragem " << stop << " >>>" << endl;
				cont++;
				cout << endl;
				break;
			}
			else
			{
				posvec++;

			}
		}
		posvec = 0;
		posline++;
	}
	if (cont == 0)
	{
		cout << "<<< A paragem " << stop << " não está presente em nenhuma linha do ficheiro >>>" << endl;
	}
	getchar();
}

int Company::SizeStop(int i, int j)
{
	int size = 0;
	if (lines.at(i).getBusStops().at(j).length() <= 7)
	{
		size = (11 - lines.at(i).getBusStops().at(j).length()) / 2;
	}
	else if (lines.at(i).getBusStops().at(j).length() > 5)
	{
		size = 0;
	}
	return size;
}
int Company::SizeHours(int i, int j)
{
	int size = 0;
	if (lines.at(i).getBusStops().at(j).length() <= 8)
	{
		size = (9 - 5) / 2;
	}
	else if (lines.at(i).getBusStops().at(j).length() > 8)
	{
		size = (lines.at(i).getBusStops().at(j).length() - 5) / 2;
	}
	return size;
}

void Company::routeBetweenStops()
{
	int i = 0;
	int j = 0;
	int idi;
	int idf;
	int posi;
	int posf;
	int posil;
	int posfl;
	int posp = 0;
	int posl = 0;
	int time1 = 0;
	int time2 = 0;
	int totaltime;
	string wrong;
	string equalStop;
	string start;
	string finish;
	cout << "Introduza a paragem onde pretende iniciar o seu percurso " << endl;
	cout << "::: ";
	cin.ignore(1000, '\n');
	getline(cin, start);
	while (i < lines.size())    //Verificar se a paragem introduzida está em alguma linha
	{
		while (j < lines.at(i).getBusStops().size()) //Como as paragens estão guardadas em vetores é necessário percorrer cada vetor por cada linha e comparar cada uma com a introduzida
		{
			if (start == lines.at(i).getBusStops().at(j))
			{
				idi = lines.at(i).getId();
				posi = j;
				posil = i;
				break;
			}
			else
			{
				j++;
			}
		}
		if (j == lines.at(i).getBusStops().size())
		{
			i++;
			j = 0;
		}
		else
		{
			break;
		}
	}
	if (i == lines.size()) //Quando chega ao fim do vetor das linhas e  não encontra a paragem 
	{
		cout << "<<< A paragem inicial não está presente em nenhuma linha. >>>";
	}
	else
	{
		cout << endl << "Introduza a paragem onde pretende terminar o seu percurso " << endl;
		cout << "::: ";
		getline(cin, finish);
		i = 0;
		j = 0;
		while (i < lines.size()) // Percorrer o vetor linhas para encontrar a paragem final
		{
			while (j < lines.at(i).getBusStops().size())
			{
				if (finish == lines.at(i).getBusStops().at(j))
				{
					idf = lines.at(i).getId();
					posf = j;
					posfl = i;
					break;
				}
				else
				{
					j++;
				}
			}
			if (j == lines.at(i).getBusStops().size())
			{
				i++;
				j = 0;
			}
			else
			{
				break;
			}
		}
		if (i == lines.size()) // Se chegar ao fim e não encontrar a paragem final
		{
			cout << "<<< A paragem final não está presente em nenhuma linha. >>>";
		}
		else
		{
			i = 0;
			j = 0;

			while (i < lines.at(posil).getBusStops().size()) //Encontrar uma paragem comum entre o vetor de paragens onde se encontra a paragem inicial e o vetor onde está a paragem final
			{
				while (j < lines.at(posfl).getBusStops().size())
				{

					if (lines.at(posil).getBusStops().at(i) == lines.at(posfl).getBusStops().at(j))
					{
						equalStop = lines.at(posil).getBusStops().at(i);
						posp = j;
						posl = i;
						break;
					}
					else
					{
						j++;
					}

				}
				if (j == lines.at(posfl).getBusStops().size())
				{
					i++;
					j = 0;
				}
				else
				{
					break;
				}
			}

			if (i != lines.at(posil).getBusStops().size())
			{
				int posi1 = posi - 1;
				int posf1 = posf - 1;
				if (posi == 0) {
					posi1 = posi;
				}
				if (posf == 0)
				{
					posf1 = posf;
				}

				if (idi == idf)
				{
					clearScreenC();
					if (start == finish)
					{
						cout << "<<< As paragens inicial e final são as mesmas >>>";
					}

					else if (posi < posf) 
					{
						cout << "1. Percorrer a linha " << lines.at(posil).getId() << " de acordo com o seguinte percurso:" << endl;
						cout << endl << " | ";
						posi1 = posi;
						for (posi; posi <= posf; posi++)
						{
							cout << lines.at(posil).getBusStops().at(posi) << " | ";

						}
						cout << endl;
						for (posi1; posi1 <= posf1; posi1++) {
							time1 += lines.at(posil).getTimings().at(posi1);
						}

					}
					else
					{
						cout << "1. Percorrer a linha " << lines.at(posil).getId() << " de acordo com o seguinte percurso:" << endl;
						cout << endl << " | ";
						posf1 = posi - 1;
						for (posi; posf <= posi; posi--) {
							cout << lines.at(posil).getBusStops().at(posi) << " | ";
						}
						cout << endl;
						for (posf; posf <= posf1; posf++) {
							time1 += lines.at(posil).getTimings().at(posf);

						}
					}
				}
				else if (idi != idf)
				{
					if (posl <= posi)
					{
						clearScreenC();
						cout << "1. Percorrer a linha " << lines.at(posil).getId() << " de acordo com o seguinte percurso:" << endl;
						cout << endl << " | ";
						for (posi; posl <= posi; posi--) {
							cout << lines.at(posil).getBusStops().at(posi) << " | ";
						}
						cout << endl;
						for (posi1; posl <= posi1; posi1--) {
							time1 += lines.at(posil).getTimings().at(posi1);
						}
					}
					else if (posl > posi)
					{
						clearScreenC();
						cout << "1. Percorrer a linha " << lines.at(posil).getId() << " de acordo com o seguinte percurso:" << endl;
						cout << endl << " | ";
						for (posi; posi <= posl ; posi++) {
							cout << lines.at(posil).getBusStops().at(posi) << " | ";
						}
						cout << endl;
						for (posi1; posi1 < posl; posi1++) {
							time1 += lines.at(posil).getTimings().at(posi1);
						}
					}
					if (posp < posf)
					{
						cout << endl << "2. Trocar para a linha " << lines.at(posfl).getId() << " na paragem " << equalStop << " e seguir o percurso seguinte: " << endl;
						cout << endl << " | ";
						for (posp; posp <= posf; posp++) {
							cout << lines.at(posfl).getBusStops().at(posp) << " | ";
						}
						cout << endl;
						for (posf1; posl <= posf1; posf1--) {
							time2 += lines.at(posfl).getTimings().at(posf1);
						}
					}
					else if (posp > posf)
					{
						cout << endl << "2. Trocar para a linha " << lines.at(posfl).getId() << " na paragem " << equalStop << " e seguir o percurso seguinte: " << endl;
						cout << endl << " | ";
						posf1 = posp;
						for (posp; posf <= posp; posp--)
						{
							cout << lines.at(posfl).getBusStops().at(posp) << " | ";
						}
						cout << endl;
						if (posp < 0)
						{
							posp = 0;
						}
						for (posp; posp < posf1; posp++) {
							time2 = time2 + lines.at(posfl).getTimings().at(posp);
						}
					}
				}
				totaltime = time1 + time2;
				cout << endl;
				cout << "Estima-se que a viagem tenha uma duração de " << totaltime << " minutos." << endl;
			}
			else
			{
				cout << "<<< Não é possível ligar " << start << " a " << finish << " >>>" << endl;
			}
		}
	}
	getchar(); 
}
bool Company::findStop(string stop)
{
	int i = 0;
	int j = 0;
	bool find = false;
	while (i < lines.size())
	{
		while (j < lines.at(i).getBusStops().size())
		{
			if (stop == lines.at(i).getBusStops().at(j))
			{
				find = true;
				break;
			}
			j++;
		}
		j = 0;
		i++;
	}
	return find;
}

void Company::showWorkDriver()
{
	int i = 0;
	int j = 0;
	int k = 0;
	int temp = 0;
	int id;
	cout << " Introduza o id do motorista a pesquisar" << endl;
	cout << "::: ";
	cin >> id;
	failC(id);
	clearScreenC();
	while (i < bus.size())
	{
		while (j < bus.at(i).getSchedule().size())
		{
			if (id == bus.at(i).getSchedule().at(j).getDriverId())
			{
				temp = bus.at(i).getSchedule().at(j).getDriverId();
				cout << "<<< Condutor " << bus.at(i).getSchedule().at(j).getDriverId() << " >>>" << endl << endl;
				cout << "| Linha: " << bus.at(i).getLineId() << endl;
				cout << "| Dia da Semana: ";
				switch (k)
				{
				case 0:
					cout << "Segunda-feira" << endl;
				case 1:
					cout << "Terça-Feira" << endl;
				case 2:
					cout << "Quarta-Feira" << endl;
				case 3:
					cout << "Quinta-Feira" << endl;
				case 4:
					cout << "Sexta-Feira" << endl;
				case 5:
					cout << "Sábado" << endl;
				case 6:
					cout << "Domingo" << endl;
				}
				cout << "| Hora de início: " << bus.at(i).getSchedule().at(j).getStartTime() << endl;
				cout << "| Hora de fim: " << bus.at(i).getSchedule().at(j).getEndTime() << endl;
				cout << endl;
				k++;
				break;
			}
			else
			{
				j++;
			}
		}
		i++;
		j = 0;
	}
	if (i != temp)
	{
		cout << "<<< Não há nenhum trabalho atribuído ao condutor com número de identificação " << id << " >>>" << endl;
	}
	getchar(); getchar();
}
void Company::showBus()
{
	int ni;
	int i = 0;
	int j = 0;
	cout << "Introduza o número de ordem do autocarro" << endl;
	cout << "::: ";
	cin >> ni;
	failC(ni);
	while (i < bus.size())
	{
		if (ni == bus.at(i).getBusOrderInLine())
		{
			cout << "| Número de ordem na linha: " << ni << endl;
			cout << "| Número de identificação da linha: " << bus.at(i).getLineId() << endl;
			cout << "| Turnos: " << endl;
			cout << endl;
			while (j < bus.at(i).getSchedule().size())
			{
				cout << "   | Turno : " << j + 1 << endl;
				cout << "   | Número de identificação do condutor: " << bus.at(i).getSchedule().at(j).getDriverId() << endl;
				cout << "   | Hora de início do turno: " << bus.at(i).getSchedule().at(j).getStartTime() << endl;
				cout << "   | Hora de terminar do turno: " << bus.at(i).getSchedule().at(j).getEndTime() << endl;
				cout << endl << endl;
				j++;
			}
			break;

		}
		else
		{
			i++;
		}
	}
	if (i == bus.size())
	{
		cout << "<<< O número de ordem " << ni << " não existe >>>" << endl;
	}
	getchar(); getchar();
}
void Company::showTimeswithoutDriver()
{
	int i = 0;
	int j = 0;
	int h = 0;
	int length;
	while (i < bus.size())
	{
		while (j < bus.at(i).getSchedule().size())
		{
			length = bus.at(i).getSchedule().size();
			if (bus.at(i).getSchedule().at(j).getEndTime() < hf)
			{
				if (bus.at(i).getSchedule().at(j).getEndTime() > h)
				{
					h = bus.at(i).getSchedule().at(j).getEndTime();
				}
			}
			j++;
		}
		if (h != 0)
		{
			cout << "<<< AUTOCARRO " << bus.at(i).getBusOrderInLine() << " >>>" << endl;
			cout << "::: Período sem autocarros " << endl;
			cout << setfill('0') << setw(2) << h << ":00" << "--" << hf << endl;
			cout << endl;
		}
		else
		{
			cout << "<<< AUTOCARRO " << bus.at(i).getBusOrderInLine() << " >>>" << endl;
			cout << "::: Período sem autocarros " << endl;
			cout << setfill('0') << setw(2) << hi << ":00" << "--" << hf << endl;
			cout << endl;
		}
		j = 0;
		i++;
	}
}

void Company::showDriverWithoutService()
{
	int i = 0;
	int j = 0;
	int k = 0;
	int id;
	int hours = 0;

	while (i < drivers.size())
	{
		id = drivers.at(i).getId();
		while (j < bus.size())
		{
			while (k < bus.at(j).getSchedule().size())
			{
				if (id == bus.at(j).getSchedule().at(k).getDriverId())
				{
					int shifts = bus.at(j).getSchedule().at(k).getEndTime() - bus.at(j).getSchedule().at(k).getStartTime();
					hours = hours + shifts;
				}
				k++;
			}
			j++;
		}
		i++;
		j = 0;
		k = 0;
		if (hours < drivers.at(i).getMaxWeekWorkingTime())
		{
			cout << " | " << drivers.at(i).getName() << endl;
			cout << " | Horas sem serviço: " << drivers.at(i).getMaxWeekWorkingTime() - hours << endl;
			break;
		}
	}
	getchar(); getchar();
}

int Company::NumberOfBus(int id)
{
	int i = 0;
	unsigned int numberofbus = 0;
	double time = 0;
	while (i < lines.size())
	{
		if (id == lines.at(i).getId())
		{
			for (int j = 0; j < lines.at(i).getTimings().size(); j++)
			{
				time = time + lines.at(i).getTimings().at(j);
			}
			time = time * 2;
			numberofbus = (time / lines.at(i).getFrequency() + 1.0);
		}
		i++;
	}
	return numberofbus;
}

void Company::busAux() { //colocar no vetor Bus todos os autocarros necessários por linha
	int i = 0;
	int j = 0;
	int iBus;
	int nBus;
	vector <Shift> f;
	while (i < lines.size())
	{
		iBus = lines.at(i).getId();
		nBus = NumberOfBus(iBus);
		while (j <= nBus)
		{
			j++;
			Bus B(j, iBus, f);
			bus.push_back(B);

		}
		i++;
		j = 0;
	}
}
void Company::ServiceDistribution()
{

	unsigned int id;
	unsigned int lineNumber;
	unsigned int busline;
	unsigned int i = 0;
	unsigned int day;
	unsigned int k = 0;
	unsigned int j = 0;
	unsigned int total = 0;
	unsigned int  fh = 0;
	unsigned int rest;
	unsigned int buslength = 0;
	unsigned int shiftlength = 0;
	int posid;
	string startTime;
	string finishTime;
	cout << "Insira o número de identificação do condutor" << endl << "::: ";
	cin >> id;
	failC(id);
	while (i < drivers.size()) //Verificar se existe o id introduzido
	{
		if (id == drivers.at(i).getId())
		{
			break;
		}
		else
			i++;
	}
	while (i == drivers.size())
	{
		i = 0;
		cout << endl << "Número de identificação inexistente. Insira outro." << "::: ";
		cin >> id;
		failC(id);
		while (i < drivers.size()) //Verificar se existe o id introduzido
		{
			if (id == drivers.at(i).getId())
			{
				break;
			}
			else
				i++;
		}
	}
	i = 0;
	cout << endl << "Insira o número de identificação da linha" << endl << "::: ";
	cin >> lineNumber;
	failC(lineNumber);

	while (i < lines.size()) //Verificar se existe o autocarro introduzido
	{
		if (lineNumber == lines.at(i).getId())
		{
			break;

		}

		else
			i++;
	}

	while (i == lines.size())
	{
		cout << endl << "Número de identificação do autocarro inexistente. Insira outro" << endl << "::: ";
		cin >> lineNumber;
		failC(lineNumber);
		i = 0;
		while (i < lines.size()) //Verificar se existe o autocarro introduzido
		{
			if (lineNumber == lines.at(i).getId())
			{
				break;

			}

			else
				i++;
		}
	}
	cout << endl << "Insira o número de ordem do autocarro" << endl << "::: ";
	cin >> busline;
	failC(busline);
	while (NumberOfBus(lineNumber) < busline)
	{
		cout << endl << "A linha " << id << " apenas possui " << NumberOfBus(lineNumber) << endl;
		cout << "Número de ordem inexistente. Insira outro" << endl << "::: ";
		cin >> busline;
		failC(busline);
	}
	cout << endl << "Insira a hora de ínicio do turno (hh:mm) " << endl << "::: ";
	cin.ignore(1000, '\n');
	getline(cin, startTime);

	while (startTime.length() != 5 || 2 != startTime.find_first_of(':'))
	{
		cout << endl << "Insira de novo a hora de ínicio do turno (hh:mm) " << endl << "::: ";
		getline(cin, startTime);
	}
	unsigned int startH = stoi(startTime.substr(0, 2));
	unsigned int startM = stoi(startTime.substr(3, 5));
	while (60 <= startM)
	{
		startH++;
		startM = startM - 60;

	}
	while (startH < hi || hf <startH)
	{
		cout << endl << "Os serviços apenas se iniciam às " << hi << "h. Insira outra hora." << endl;
		getline(cin, startTime);
		startH = stoi(startTime.substr(0, 2));

	}
	while (startTime.length() != 5 || 2 != startTime.find_first_of(':'))
	{
		cout << endl << "Insira de novo a hora de ínicio do turno (hh:mm) " << endl << "::: ";
		cin.clear();
		getline(cin, startTime);

	}
	startH = stoi(startTime.substr(0, 2));
	startM = stoi(startTime.substr(3, 5));
	while (60 <= startM)
	{
		startH++;
		startM = startM - 60;

	}
	cout << endl << "Insira a hora de fim do turno (hh:mm) " << endl << "::: ";
	getline(cin, finishTime);
	while (finishTime.length() != 5 || 2 != finishTime.find_first_of(':'))
	{
		cout << endl << "Insira de novo a hora de ínicio do turno (hh:mm) " << endl << "::: ";
		cin.clear();
		getline(cin, finishTime);

	}

	int finishH = stoi(finishTime.substr(0, 2));
	int finishM = stoi(finishTime.substr(3, 5));
	while (60 <= finishM)
	{
		finishH++;
		finishM = finishM - 60;

	}
	while (hf < finishH) {

		cout << endl << "Os serviços encerram às " << hf << "h. " << endl;
		getline(cin, finishTime);
		finishH = stoi(finishTime.substr(0, 2));
		finishM = stoi(finishTime.substr(3, 5));
		while (60 <= finishM)
		{
			finishH++;
			finishM = finishM - 60;

		}
	}
	while (finishTime.length() != 5 || 2 != finishTime.find_first_of(':'))
	{
		cout << endl << "Insira de novo a hora de ínicio do turno (hh:mm) " << endl << "::: ";
		getline(cin, finishTime);
	}
	while (finishH > hf) {
		cout << endl << "Os serviços encerram às " << hf << "h. Insira outra hora." << endl << "::: ";
		getline(cin, finishTime);
		int finishH = stoi(finishTime.substr(0, 2));

	}
	finishM = stoi(finishTime.substr(3, 5));

	cout << endl << "Insira o dia da semana (0 (Segunda-feira) - 6 (Domingo) )" << endl;
	cin >> day;
	while (7 < day)
	{
		cout << endl << "Dia inválido.Insira outro." << endl << "::: ";
		cin >> day;
	}
	int time = (finishH - startH) * 60 + (finishM - startM); //Tempo total do turno em minutos
	int finishHM = finishH * 60 + finishM; //Hora final em minutos
	int startHM = startH * 60 + startM; //Hora inicial em minutos
	rest = finishHM - fh;
	rest = rest / 60;
	j = 0;
	while (k < drivers.size())
	{
		while (j < drivers.at(k).getShifts().size()) //Verificar se o condutor tem algum serviço atribuído e calcular o tempo total desses serviços
		{
			if (id == drivers.at(k).getShifts().at(j).getDriverId())
			{
				total += drivers.at(k).getShifts().at(j).getEndTime() - drivers.at(k).getShifts().at(j).getStartTime();
				if (drivers.at(k).getShifts().at(j).getEndTime() > fh)
				{
					fh = drivers.at(k).getShifts().at(j).getEndTime(); // Verificar a hora a que termina o último serviço do condutor

				}
			}
			j++;
		}
		j = 0;
		k++;
	}
	while (i < drivers.size())
	{
		if (id == drivers.at(i).getId())
		{
			posid = i;
			if ((drivers.at(i).getShiftMaxDuration()) * 60 < time) //verificar se o tempo total ultrapassa o numero de horas do turno
			{
				cout << endl << "O turno atribuído é superior ao número máximo de horas que o condutor pode trabalhar seguidas " << endl;
				break;
			}
			else if (drivers.at(i).getMaxWeekWorkingTime() <= total) // Verificar se o condutor já tem as horas semanais todas completas
			{
				total += time;
				cout << endl << "O condutor já tem as horas semanais completas " << endl;

				break;
			}

			else if (rest < drivers.at(i).getMinRestTime()) //Verificar se o condutor descansa o tempo necessário entre o turno anterior e o que se pretende inserir
			{
				cout << endl << "O condutor não tem as horas de descanso mínimas" << endl;
				break;
			}
			else if (fh >(startHM + (day - 1) * 24 * 60))
			{
				cout << endl << "O condutor já tem serviço atribuído nesse intervalo" << endl;
				break;
			}
			i++;
		}
		else
		{
			i++;
		}
	}
	if (i == drivers.size())
	{
		while (buslength < bus.size()) // Verificar se o autocarro está ocupado no período atribuído
		{
			if (lineNumber == bus.at(buslength).getLineId())
			{
				if (busline == bus.at(buslength).getBusOrderInLine())
				{
					while (shiftlength < bus.at(buslength).getSchedule().size())
					{
						if (bus.at(buslength).getSchedule().at(shiftlength).getStartTime() <= startHM && startHM <= bus.at(buslength).getSchedule().at(shiftlength).getEndTime())
						{
							cout << endl << "O autocarro encontra-se ocupado no período introduzido." << endl;
							break;
						}
						shiftlength++;
					}
				}
				else
				{
					buslength = buslength + 1;
				}
				break;
			}
		}
		if (buslength == bus.size() || shiftlength == 0)
		{
			const Shift S(lineNumber, id, busline, startH, finishH);
			i = 0;
			while (i < bus.size())
			{

				if (lineNumber == bus.at(i).getLineId() && busline == bus.at(i).getBusOrderInLine())
				{
					drivers.at(posid).service(S);
					bus.at(i).serviceB(S);
					break;
				}

				else
				{
					i++;
				}
			}
		}
	}
	getchar(); getchar();
}
