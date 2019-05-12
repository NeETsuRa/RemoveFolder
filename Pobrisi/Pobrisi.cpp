// Pobrisi.cpp : main project file.

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <time.h>

using namespace std;

int main()
{
	fstream log ("log.txt", fstream::app|fstream::in);
		time_t t = time(0); 
    struct tm * now = localtime( & t );
	log << "Datum in èas brisanja datotek: " << endl 
		<< now->tm_mday << "." << now->tm_mon+1 << "."  << now->tm_year+1900 << endl
		<< (now->tm_hour) << ":" <<(now->tm_min) << ":"  << (now->tm_sec) << endl << endl;

	if( remove( "cas.txt" ) != 0 )
    log << "napaka pri brisanju datoteke cas.txt" << endl;
  else
    log << "zbrisana datoteka za cas" << endl;

	fstream stDokInPonov("dokpon.txt", fstream::app);
	stDokInPonov.close();
	stDokInPonov.open("dokpon.txt");
	stDokInPonov << "0" << endl << "1" << endl;

	if( remove( "doku.txt"  ) != 0 )
    log << "napaka pri brisanju datoteke doku.txt" << endl;
  else
    log << "zbrisana datoteka za dokumente" << endl;

	if( remove( "prog.txt" ) != 0 )
    log << "napaka pri brisanju datoteke prog.txt" << endl;
  else
    log << "zbrisana datoteka za programe" << endl;

	cin.ignore();
	cin.get();
    return 0;
}
