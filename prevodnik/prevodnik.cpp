
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <fstream>

using namespace std;

int convertBinaryToDecimal(long long n)
{
	int decimalNumber = 0, i = 0, remainder;
	while (n != 0)
	{
		remainder = n % 10;
		n /= 10;
		decimalNumber += remainder * pow(2, i);
		++i;
	}
	return decimalNumber;
}

void decToHexa(int n)
{
	char hexaDeciNum[100];

	int i = 0;
	while (n != 0)
	{
		int temp = 0;

		temp = n % 16;

		if (temp < 10)
		{
			hexaDeciNum[i] = temp + 48;
			i++;
		}
		else
		{
			hexaDeciNum[i] = temp + 55;
			i++;
		}

		n = n / 16;
	}

	for (int j = i - 1; j >= 0; j--)
		cout << hexaDeciNum[j];
}

void decToHexaSave(int n, ofstream* subor)
{
	char hexaDeciNum[100];

	int i = 0;
	while (n != 0)
	{
		int temp = 0;

		temp = n % 16;

		if (temp < 10)
		{
			hexaDeciNum[i] = temp + 48;
			i++;
		}
		else
		{
			hexaDeciNum[i] = temp + 55;
			i++;
		}

		n = n / 16;
	}

	for (int j = i - 1; j >= 0; j--)
		*subor << hexaDeciNum[j];
}

int hexadecimalToDecimal(char hexVal[])
{
	int len = strlen(hexVal);

	int base = 1;

	int dec_val = 0;

	for (int i = len - 1; i >= 0; i--)
	{
		if (hexVal[i] >= '0' && hexVal[i] <= '9')
		{
			dec_val += (hexVal[i] - 48) * base;

			base = base * 16;
		}

		else if (hexVal[i] >= 'A' && hexVal[i] <= 'F')
		{
			dec_val += (hexVal[i] - 55) * base;


			base = base * 16;
		}
	}

	return dec_val;
}

void HexToBin(string n)
{
	long int i = 0;

	while (n[i])
	{
		switch (n[i])
		{
		case '0':
			cout << "0000";
			break;
		case '1':
			cout << "0001";
			break;
		case '2':
			cout << "0010";
			break;
		case '3':
			cout << "0011";
			break;
		case '4':
			cout << "0100";
			break;
		case '5':
			cout << "0101";
			break;
		case '6':
			cout << "0110";
			break;
		case '7':
			cout << "0111";
			break;
		case '8':
			cout << "1000";
			break;
		case '9':
			cout << "1001";
			break;
		case 'A':
		case 'a':
			cout << "1010";
			break;
		case 'B':
		case 'b':
			cout << "1011";
			break;
		case 'C':
		case 'c':
			cout << "1100";
			break;
		case 'D':
		case 'd':
			cout << "1101";
			break;
		case 'E':
		case 'e':
			cout << "1110";
			break;
		case 'F':
		case 'f':
			cout << "1111";
			break;
		default:
			cout << "\nNespravne cislo "
				<< n[i];
		}
		i++;
	}
}

void HexToBinSave(string n, ofstream* subor)
{
	long int i = 0;

	while (n[i])
	{
		switch (n[i])
		{
		case '0':
			*subor << "0000";
			break;
		case '1':
			*subor << "0001";
			break;
		case '2':
			*subor << "0010";
			break;
		case '3':
			*subor << "0011";
			break;
		case '4':
			*subor << "0100";
			break;
		case '5':
			*subor << "0101";
			break;
		case '6':
			*subor << "0110";
			break;
		case '7':
			*subor << "0111";
			break;
		case '8':
			*subor << "1000";
			break;
		case '9':
			*subor << "1001";
			break;
		case 'A':
		case 'a':
			*subor << "1010";
			break;
		case 'B':
		case 'b':
			*subor << "1011";
			break;
		case 'C':
		case 'c':
			*subor << "1100";
			break;
		case 'D':
		case 'd':
			*subor << "1101";
			break;
		case 'E':
		case 'e':
			*subor << "1110";
			break;
		case 'F':
		case 'f':
			*subor << "1111";
			break;
		default:
			*subor << "\nNespravne cislo "
				<< n[i];
		}
		i++;
	}
}

enum Vyber
{
	DECIMALNE,
	HEXADECIMALNE,
	BINARNE
};

int main()
{
	system("color 0A");
	int savei;
	long long saven;
	char savechar[25];
	long long n;
	int vyber;
	int hex = 0, mul = 1, chk = 1, rem, i = 0;
	char hexDecNum[50];
	int a[100]{};
	bool running = true;
	int running2;
	int saving;
	Vyber x;

	while (running)
	{
		system("CLS");


		cout <<
			"Napis v akej sustave ides pisat cislo \n 1 = v dvojkovej\n 2 = v desiatkovej\n 3 = v sestnastkovej\n 4 = v random sustave"
			<< endl;
		cin >> vyber;
		switch (vyber)
		{
		case 1:
			x = BINARNE;
			break;
		case 2:
			x = DECIMALNE;
			break;
		case 3:
			x = HEXADECIMALNE;
			break;
		case 4:
			srand(time(NULL));

			int random = rand() % 3 + 1;
			switch (random)
			{
			case 1:
				x = BINARNE;
				break;
			case 2:
				x = DECIMALNE;
				break;
			case 3:
				x = HEXADECIMALNE;
				break;
			}
			break;
		}
		switch (x)
		{
		case BINARNE:

			cout << "Napis cislo v dvojkovej sustave: ";
			cin >> n;
			saven = n;

			cout << n << " v dvojkovej sustave \n= " << convertBinaryToDecimal(n) << " v desiatkovej sustave";


			while (n != 0)
			{
				rem = n % 10;
				hex = hex + (rem * mul);
				if (chk % 4 == 0)
				{
					if (hex < 10)
						hexDecNum[i] = hex + 48;
					else
						hexDecNum[i] = hex + 55;
					mul = 1;
					hex = 0;
					chk = 1;
					i++;
				}
				else
				{
					mul = mul * 2;
					chk++;
				}
				n = n / 10;
			}
			if (chk != 1)
				hexDecNum[i] = hex + 48;
			if (chk == 1)
				i--;
			cout << "\n= ";

			savei = i;

			for (i = i; i >= 0; i--)
				cout << hexDecNum[i];
			cout << " v sestnastkovej sustave";

			cout << "\nChces vysledok ulozit do subora?\n Ak ano stlac 1\n Ak nie stlac 2\n";
			cin >> saving;
			if (saving == 1)
			{
				ofstream subor("vysledok.txt");
				subor << saven << " v dvojkovej sustave \n= " << convertBinaryToDecimal(saven) << " v desiatkovej sustave\n= ";
				for (i = savei; i >= 0; i--)
					subor << hexDecNum[i];
				subor << " v sestnastkovej sustave";
				subor << "\n";
				subor.close();
			}
			break;

		case DECIMALNE:

			cout << "Napis cislo v desiatkovej sustave: ";
			cin >> n;
			saven = n;
			cout << "= ";
			decToHexa(n);
			cout << " v sestnastkovej sustave";
			cout << "\n= ";
			for (i = 0; n > 0; i++)
			{
				a[i] = n % 2;
				n = n / 2;
			}

			savei = i;

			for (i = i - 1; i >= 0; i--)
			{
				cout << a[i];
			}

			cout << " v dvojkovej sustave";

			cout << "\nChces vysledok ulozit do subora?\n Ak ano stlac 1\n Ak nie stlac 2\n";
			cin >> saving;
			if (saving == 1)
			{
				ofstream subor("vysledok.txt");
				subor << saven << " v desiatkovej sustave \n= ";
				decToHexaSave(saven, &subor);
				subor << " v sestnastkovej sustave\n= ";
				for (i = savei - 1; i >= 0; i--)
				{
					subor << a[i];
				}
				subor << " v dvojkovej sustave";
				subor.close();
			}

			break;


		case HEXADECIMALNE:
			char n[25];
			cout << "Napis cislo v sestnastkovej sustave" << endl;
			cin >> n;
			cout << "v sestnastkovej sustave\n= ";
			cout << hexadecimalToDecimal(n) << " v desiatkovej sustave" << endl;

			cout << "= ";
			HexToBin(n);
			cout << " v dvojkovej sustave";


			cout << "\nChces vysledok ulozit do subora?\n Ak ano stlac 1\n Ak nie stlac 2\n";
			cin >> saving;
			if (saving == 1)
			{
				ofstream subor("vysledok.txt");
				subor << n << " v sestnastkovej \n= ";
				subor << hexadecimalToDecimal(n) << " v desiatkovej sustave\n= ";
				HexToBinSave(n, &subor);
				subor << " v dvojkovej sustave";
				subor.close();
			}
			break;

		}


		cout << "\nChces pokracovat?\n Ak ano stlac 1\n Ak nie stlac 2\n";

		cin >> running2;
		if (running2 == 2)
		{
			running = false;
		}
	}
}
