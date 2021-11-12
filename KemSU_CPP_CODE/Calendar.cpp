/**********************************************
* �����:    ��������� �. �.                   *
* ����:     10.11.2021                        *
* ��������: �������� � �������                *
***********************************************/
// https://onlinegdb.com/_nxG2PHvx

#include <iostream>
#include <stdio.h>
#include <fstream>
#include <time.h>
#include <string.h>

using namespace std;

int main()
{
	time_t now;
	struct tm* timeinfo;
	int year, m, i, j;
	const char* month[] = { "������","�������", "����","������", "���","����",
			"����", "������","��������","�������", "������","�������" };

	cout << "���: ";
	cin >> year;
	time(&now);
	timeinfo = localtime(&now);

	timeinfo->tm_year = year - 1900;

	timeinfo->tm_mon = 0;

	m = -1;
	while (m < 12) {

		for (i = 1; i < 33; i++) {

			timeinfo->tm_mday = i;

			mktime(timeinfo);

			if (timeinfo->tm_mon > m) {

				printf("\n                 %s\n", month[timeinfo->tm_mon]);
				printf("_______________________________\n");
				printf("  ��  ��  ��  ��  ��  ��  ��   \n");
				printf("_______________________________\n");
				for (j = 0; j < (timeinfo->tm_wday); j++)
					printf("    ");
				m++;
				break;
			}
			if (m == 11 && timeinfo->tm_mon == 0) {
				m++;
				break;
			}

			printf("%4d", timeinfo->tm_mday);

			if (timeinfo->tm_wday == 6)
				printf("\n");
		}
	}
	getchar();
	getchar();
	return 0;
}
