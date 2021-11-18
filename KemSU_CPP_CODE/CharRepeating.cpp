/**********************************************
* Автор:    Мустафаев И.Б                     *
* Дата:     10.11.2021                        *
* Название: Частота повторение букв			  *
***********************************************/

// https://onlinegdb.com/Duib-4f3E

// .лабу я скатал, смысл работы понял, я бы делал через map
// .честно сказал мало что понял, как будет время - разберу
// .не серьдитесь, правда времени на дел нет(


#include <string>
#include <iostream>
#include <fstream>

using namespace std;

const int alphabet = 26;

struct two_letter
{
	string letter_name;
	int	count_letter;
};

struct one_letter
{
	char letter_name;
	int	count_letter;
};

int main(void)
{
	setlocale(LC_ALL, "rus");
	char character;
	int ix = 0;
	string text = "Computer jsbdnjsbd Iuehfeu OPjhdsjbds ";
	ofstream information("information.txt");

	information << "A abbbbbaabbabababbaabba";
	information.close();
	ifstream show("information.txt");
	string str;
	getline(show, str);

	ofstream edit("edit.txt");

	while (str[ix])                           
	{
		character = str[ix];
		edit << (char)tolower(character);  
		ix++;                              
	}
	edit.close();

	ifstream show_edit_text("edit.txt");
	string str_edit_text;
	getline(show_edit_text, str_edit_text);
	const char* convert_to_char = str_edit_text.c_str();

	one_letter letter[26];
	const char* alphabet = "abcdefghijklmnopqrstuvwxyz";
	for (int l = 0; l < 26; ++l) {
		letter[l].count_letter = 0;
	}


	for (int i = 0; convert_to_char[i]; i++) {
		if (convert_to_char[i] != ' ') {
			for (int j = 0; alphabet[j]; ++j) {
				if (convert_to_char[i] == alphabet[j]) {
					int count = letter[j].count_letter;

					letter[j].letter_name = alphabet[j];
					letter[j].count_letter = count + 1;
					break;
				}
			};
		}

	};

	two_letter twoLetter[26 * 26];

	for (int n = 0; n < (26 * 26); ++n) {
		twoLetter[n].count_letter = 0;
		twoLetter[n].letter_name = "00";
	}
	int count_two_letter = 0;
	for (int m = 0; convert_to_char[m]; ++m) {
		if (convert_to_char[m] != ' ' && convert_to_char[m + 1] != ' ') {
			char two[2] = { convert_to_char[m],convert_to_char[m + 1] };
			for (int h = 1; h < (26 * 26); ++h) {
				if (twoLetter[h].letter_name != "00" && twoLetter[h].count_letter > 0) {
					if (twoLetter[h].letter_name == string(two)) {
						int count_letter_copy = twoLetter[h].count_letter;
						twoLetter[h].count_letter = count_letter_copy + 1;
						break;
					}
				}
				else if (twoLetter[h].letter_name == "00" && twoLetter[h].count_letter == 0) {
					int count_letter_copy = twoLetter[h].count_letter;
					twoLetter[h].letter_name = string(two);
					twoLetter[h].count_letter = count_letter_copy + 1;
					break;
				}
			}
		}
	}

	cout << "Частоту повторение однобуквенных значение: " << endl;

	for (int k = 0; k < 26; ++k) {
		if (letter[k].count_letter != 0 && letter[k].count_letter > 1) {
			cout << letter[k].letter_name << " = " << letter[k].count_letter << "; ";
		}
	};

	cout << endl << "Частоту повторение двухбуквенных значение: " << endl;

	for (int g = 0; g < (26 * 26); ++g) {
		if (twoLetter[g].letter_name != "00" && twoLetter[g].count_letter > 0) {
			cout << twoLetter[g].letter_name << " = " << twoLetter[g].count_letter << "; ";
		}
	}

	show_edit_text.close();
	show.close();
	system("pause");
	return 0;
}
