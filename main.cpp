#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <math.h>

using namespace std;

string vectorToString(vector<string> tableau)
{
	string resultat;

	for (int i(0); i < tableau.size(); i++)
	{
		resultat += tableau[i];
	}

	return resultat;
}

int main()
{
	int nombreCaracteres(0);
	int nombreCaracteresConnus(0);

	cout << "Ce programme vous permet de calculer le nombre de mots de passe possibles en fonction d'indices et de les lister dans un fichier texte.\n\n";

	cout << "Veuillez d'abord entrer le nombre de caracteres du mot de passe en question : ";
	cin >> nombreCaracteres;

	while (nombreCaracteres < 1) // Vérifie que l'utilisateur a entré au moins un caractère
	{
		cout << "\nLe nombre de caracteres du mot de passe en question doit obligatoirement etre plus grand que 0, veuillez recommencer : ";
		cin >> nombreCaracteres;
	}

	cout << "\nVeuillez maintenant entrer le nombre de caracteres connus dans le mot de passe (entrez 0 si vous n'en connaissez aucun) : ";
	cin >> nombreCaracteresConnus;

	while (nombreCaracteresConnus < 0 || nombreCaracteresConnus > nombreCaracteres) // Vérifie que le nombre de caractères connus est compris entre 1 et le nombre de caractères
	{
		cout << "\nLe nombre de caracteres que vous connaissez ne peut pas etre plus petit que 0 ou plus grand que le nombre de caracteres du mot de passe (A savoir " << nombreCaracteres << "). Veuillez recommencer : ";
		cin >> nombreCaracteresConnus;
	}

	system("cls");

	vector<string> motDePasse;

	for (int i(0); i < nombreCaracteres; i++)
	{
		motDePasse.push_back("*");
	}

	cout << "Voici l'apparence du mot de passe en fonction des indices recueillis :" << endl;
	cout << "\n		" << vectorToString(motDePasse) << endl;

	if (nombreCaracteresConnus > 1) // Traitement du cas ou l'utilisateur connait plus d'un caractère du mot de passe
	{
		vector<int> positionsCaracteresConnus;
		vector<string> valeursCaracteresConnus;
		int positionTemporaire;
		string valeurTemporaire;

		cout << "\nVous devez maintenant renseigner la position des " << nombreCaracteresConnus << " caracteres que vous connaissez dans le mot de passe.";
		cout << "\nVous allez devoir entrer la position et la valeur de chaque caractere." << endl << "\nEntrez la position du 1er caractere connu : ";
		cin >> positionTemporaire;
		positionsCaracteresConnus.push_back(positionTemporaire);

		while (positionsCaracteresConnus[0] < 1 || positionsCaracteresConnus[0] > nombreCaracteres) // Vérifie que la position du caractère connu est comprise entre 1 et le nombre de caractères
		{
			cout << "\nLa position du caractere connu doit etre comprise entre 1 et " << nombreCaracteres << ", veuillez recommencer : ";
			cin >> positionTemporaire;
			positionsCaracteresConnus.pop_back();
			positionsCaracteresConnus.push_back(positionTemporaire);
		}

		cout << "\nVeuillez maintenant entrer sa valeur : ";
		cin >> valeurTemporaire;
		valeursCaracteresConnus.push_back(valeurTemporaire);

		while (valeursCaracteresConnus[0].size() > 1) // Vérifie que l'utilisateur n'entre qu'un seul caractère
		{
			cout << "\nVous ne pouvez entrer qu'un seul caractere, veuillez recommencer : ";
			cin >> valeurTemporaire;
			valeursCaracteresConnus.pop_back();
			valeursCaracteresConnus.push_back(valeurTemporaire);
		}

		motDePasse[positionsCaracteresConnus[0]-1] = valeursCaracteresConnus[0];

		for (int i(1); i < nombreCaracteresConnus; i++)
		{
			int positionTemporaire;
			string valeurTemporaire;

			cout << "\nEntrez la position du " << i + 1 << "eme caractere connu : ";
			cin >> positionTemporaire;
			positionsCaracteresConnus.push_back(positionTemporaire);
			
			while (positionsCaracteresConnus[i] < 1 || positionsCaracteresConnus[i] > nombreCaracteres) // Vérifie que la position du caractère connu est comprise entre 1 et le nombre de caractères
			{
				cout << "\nLa position du caractere connu doit etre comprise entre 1 et " << nombreCaracteres << ", veuillez recommencer : ";
				cin >> positionTemporaire;
				positionsCaracteresConnus.pop_back();
				positionsCaracteresConnus.push_back(positionTemporaire);
			}

			cout << "\nVeuillez maintenant entrer sa valeur : ";
			cin >> valeurTemporaire;
			valeursCaracteresConnus.push_back(valeurTemporaire);

			while (valeursCaracteresConnus[i].size() > 1) // Vérifie que l'utilisateur n'entre qu'un seul caractère
			{
				cout << "\nVous ne pouvez entrer qu'un seul caractere, veuillez recommencer : ";
				valeursCaracteresConnus.pop_back();
				valeursCaracteresConnus.push_back(valeurTemporaire);
			}

			motDePasse[positionsCaracteresConnus[i]-1] = valeursCaracteresConnus[i];
		}
	}
	else if (nombreCaracteresConnus == 1) // Traitement du cas ou l'utilisateur ne connait qu'un caractère du mot de passe
	{
		int positionCaractereConnu;
		string valeurCaractereConnu("");
	
		cout << "\nVous devez maintenant renseigner la position du caractere que vous connaissez dans le mot de passe : ";
		cin >> positionCaractereConnu;

		while (positionCaractereConnu < 1 || positionCaractereConnu > nombreCaracteres) // Vérifie que la position du caractère connu est comprise entre 1 et le nombre de caractères
		{
			cout << "\nLa position du caractere connu doit etre comprise entre 1 et " << nombreCaracteres << ", veuillez recommencer : ";
			cin >> positionCaractereConnu;
		}
		positionCaractereConnu--;

		cout << "\nVeuillez maintenant entrer sa valeur : ";
		cin >> valeurCaractereConnu;

		while (valeurCaractereConnu.size() > 1) // Vérifie que l'utilisateur n'entre qu'un seul caractère
		{
			cout << "\nVous ne pouvez entrer qu'un seul caractere, veuillez recommencer : ";
			cin >> valeurCaractereConnu;
		}

		motDePasse[positionCaractereConnu] = valeurCaractereConnu;
	}

	system("cls");

	int tailleMotDePasse(motDePasse.size());

	cout << "Voici l'apparence du mot de passe en fonction des nouveaux indices recueillis :" << endl;
	cout << "\n		" << vectorToString(motDePasse) << endl;
	cout << "Il y a " << pow(26, tailleMotDePasse) << " mots de passe potentiels." << endl;
	cout << "\nLe listage va debuter.\n" << endl;

	system("PAUSE");

	vector<string> minuscules;minuscules.push_back("a");minuscules.push_back("b");minuscules.push_back("c");minuscules.push_back("d");minuscules.push_back("e");minuscules.push_back("f");minuscules.push_back("g");minuscules.push_back("h");minuscules.push_back("i");minuscules.push_back("j");minuscules.push_back("k");minuscules.push_back("l");minuscules.push_back("m");minuscules.push_back("n");minuscules.push_back("o");minuscules.push_back("p");minuscules.push_back("q");minuscules.push_back("r");minuscules.push_back("s");minuscules.push_back("t");minuscules.push_back("u");minuscules.push_back("v");minuscules.push_back("w");minuscules.push_back("x");minuscules.push_back("y");minuscules.push_back("z");
	vector<string> majuscules;majuscules.push_back("A");majuscules.push_back("B");majuscules.push_back("C");majuscules.push_back("D");majuscules.push_back("E");majuscules.push_back("F");majuscules.push_back("G");majuscules.push_back("H");majuscules.push_back("I");majuscules.push_back("J");majuscules.push_back("K");majuscules.push_back("L");majuscules.push_back("M");majuscules.push_back("N");majuscules.push_back("O");majuscules.push_back("P");majuscules.push_back("Q");majuscules.push_back("R");majuscules.push_back("S");majuscules.push_back("T");majuscules.push_back("U");majuscules.push_back("V");majuscules.push_back("W");majuscules.push_back("X");majuscules.push_back("Y");majuscules.push_back("Z");
	vector<string> chiffres;chiffres.push_back("0");chiffres.push_back("1");chiffres.push_back("2");chiffres.push_back("3");chiffres.push_back("4");chiffres.push_back("5");chiffres.push_back("6");chiffres.push_back("7");chiffres.push_back("8");chiffres.push_back("9");
	
	for (int i(0);i < motDePasse.size();i++)
	{
		motDePasse[i] = minuscules[0];
	}
	
	int var1(0);

	for (int i(0); i < minuscules.size();i++)
	{
		for (int i(0);i < minuscules.size();i++)
		{
			for (int i(0);i < minuscules.size();i++)
			{
				for (int i(0);i < minuscules.size();i++)
				{
					var1++;
					motDePasse[3] = minuscules[i];
					cout << var1 << ". " << vectorToString(motDePasse) << endl;
				}
				
				motDePasse[2] = minuscules[i];
				cout << var1 << ". " << vectorToString(motDePasse) << endl;
			}

			motDePasse[1] = minuscules[i];
			cout << var1 << ". " << vectorToString(motDePasse) << endl;
		}

		motDePasse[0] = minuscules[i];
		cout << var1 << ". " << vectorToString(motDePasse) << endl;
	}

	/*int x(-1);
	int y(-1);
	for (int i(0);i < pow(26, tailleMotDePasse);i++)
	{
		x++;
		if (x > 25)
		{
			x = 0;
			y++;
			motDePasse[motDePasse.size() - 1] = minuscules[x];
			motDePasse[motDePasse.size() - 2] = minuscules[y];
		}
		else
		{
			motDePasse[motDePasse.size()-1] = minuscules[x];
		}
		cout << "x = " << x << " | y = " << y << ". " << vectorToString(motDePasse) << endl;
	}*/

	system("PAUSE");
	return 0;
}