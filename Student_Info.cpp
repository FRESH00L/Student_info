#include <iostream>

using namespace std;

using Nazwisko = char[50];
using NrAlbumu = int;
using Ocena = double;

enum class Plec { mężczyzna, kobieta };
const char* tabPlec[] = { "mężczyzna", "kobieta" };

struct Student
{
	Nazwisko nazwisko;
	NrAlbumu nr;
	Ocena ocena;
	Plec plec;
};

double ocena(Ocena o)
{
	if (o > 5.0)
		o = 5.0;
	else if (o < 2.0)
		o = 2.0;
	return o;
}

double srednia(Student* S, int liczStud)
{
	double sr = 0;
	for (int i = 0; i < liczStud; i++)
	{
		sr += S[i].ocena;
	}
	sr = sr / liczStud;
	return sr;
}

void wypełnij(Student& s, char const* naz, NrAlbumu nr, Ocena o, Plec pl)
{
	strcpy_s(s.nazwisko, naz);
	s.nr = nr;
	o = ocena(o);
	s.ocena = o;
	s.plec = pl;
}

ostream& operator<<(ostream& inf, Student const& S)
{
	inf << "Student: \t" << S.nazwisko << "| Numer Albumu: " << S.nr << "| Ocena: " << S.ocena << "| Płeć: " << tabPlec[(int)S.plec] << endl << endl;
	return inf;
}

int main()
{
	setlocale(LC_ALL, "");

	Student st1, st2, st3, st4, st5;
	const int LiczbaStudentow = 5;

	wypełnij(st1, "Kowalczyk", 123123, 5.0, Plec::kobieta);
	wypełnij(st2, "Tyniek", 234234, 2.2, Plec::mężczyzna);
	wypełnij(st3, "Fronczak", 345345, 1.5, Plec::mężczyzna);
	wypełnij(st4, "Krawczyk", 456456, 6.0, Plec::kobieta);
	wypełnij(st5, "Lasek", 567567, 4.0, Plec::mężczyzna);

	Student tabStudenci[LiczbaStudentow] = { st1,st2,st3,st4,st5 };

	cout << st1 << st2 << st3 << st4 << st5;
	cout << "Średnia ocen studentów: " << srednia(tabStudenci, LiczbaStudentow) << endl;
}