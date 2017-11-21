/* Author: Ashley Lopez
 * Assignment:Homework 4 test cases
 * File: lopezH4.cpp
 * Date: 3/23
 * Description: This is the test cases for numbers 1, 2, 5, 6,
 * 		11, 12, 13, 18, 19, 25, 26
 */
#include "Real.h" 
#include<istream>

using namespace std;

int main()
{
  Real R26;
	string s = "9.10";
	int i = 6;
	long long l = 6346;
	double d = 12.3345;
	string s1 = "32.234967";
	string s2 = "123.1256341";
	double dd = 345.247;
	double d3 = 2.123575553 ;
	int negi = -1;
	long long negl = -127;
	double negd = -463.134;	
	string negs = "-1234.34";
	int lr = 3;
	int lr1 = 5;
	double ld = -23.1235;
	double ld2 = -23.1234;
	string s4 = "123";
	long long ll1 = 1235;
	int i1= 7;
	int i2= 0;
	double ld3 = 1724.57452;
	double ld4 = 35.24536;
	double ld5 = -5.2457;

	cout << "constructors" << endl;
	Real R1(s);
	Real R2(i);
	Real R3(l);
	Real R4(d);
	Real R5(s1);
	Real R6(s2);
	Real R7(l);
	Real R8(d, 2);
	Real R9(dd, 2);
	Real R10(d3, 4);
	Real R11(negi);
	Real R12(negl);
	Real R13(negd);
	Real R14(negs);
	Real R15(lr);
	Real R16(lr1);
	Real R17(ld);
	Real R18(ld2);
	Real R19(s4);
	Real R20(ll1);
	Real R21(i1);
	Real R22(i2);
	Real R23(ld3);
	Real R24(ld4);
	Real R25(ld5);
	
/*
	cout << "testing string " << R1 << endl;
	cout << "testing int " << R2 << endl;
	cout << "testing long long " << R3 << endl;
	cout << "testing double " << R4 << endl;
	cout << endl << "testing negative int: " << R11 << endl;
	cout << "teesting negative long long: " <<  R12 << endl;	
	cout << "testing negative double: " <<  R13 << endl;
	cout << "testing negative string: " << R14 << endl;
	cout << R17 << endl;
	cout << R18 << endl;
	cout <<endl << "testing double int percision of 12.3445 and 2: " << R8 << endl;
	cout  << "double int percision of 345.247 and 2: " << R9 << endl;

	//fix the real round function. percision is off and doesnt round 
	//correctly. 


	//precision isnt right with this expample. its pulling the wrong number 
	cout << "double int percision of 2.123575553 with a 4: " << R10 << endl;
	
	//need to fix round to deal with a 9 carry problem 
	R5.round(4);
	cout << endl << "rounded 32.23496: " << R5 << endl; 
	R6.round(5);
	cout << "rounded 123.1256341 to fifth place: " << R6 << endl;		
	
	int precisionNum = R6.precision();
	cout << endl << "precision number: " << precisionNum << endl;
	cout << "percision should match the number of decimal places for: " <<R6<<endl;
	
	cout << endl <<"R7: " << R7 << endl;
	string snum = R7.toString();
	cout << "R7 string number: " << R7 << endl;

	cin >> R26;
	cout << "R26:  "<< R26 <<endl;

	if(R15 < R16)
		cout << endl << "R15 is less than R16" << endl;
	else
		cout << endl << "WRONG" << endl;
	if(R17 < R18 )
		cout << "R17 is less than R18" << endl;
	else
		cout << "WRONG"<< endl;
	

	if(R3 < R17)
		cout << "R3 is not smaller then R17" << endl;
	else
		cout << "Correct! " << endl;

	if(R17 > R18)
		cout << endl << "R17 is bigger then R18" << endl;
	else
		cout << endl << "correct: R17 is smaller then R18" << endl;
	cout << R17 << endl;
	cout << R18 << endl;	
	if(R15 > R25)
		cout << "correct: R15 is bigger then R25" << endl;
	else
		cout << "r15 is smaller the r25" << endl;

	if (R23 > R24)
		cout << "correct: R23 is greater then R24" <<endl;	
	else
		cout << "R23 is smaller then R25" << endl; 
	
	if(R23 <= R23)
		cout << endl <<"correct: same string" << endl;
	else
		cout << endl << "wrong " << endl;
	
	if(R17 <= R18)
		cout << "correct: R17 <= R18 " << endl;
	else
		cout << "wrong" << endl;

	if(R7 <= R17)
		cout << "wrong R7 <= R17" << endl;
	else
		cout << "correct " << endl; 

	if(R17 >= R12)
		//r17 = -23.1235
		//r12 = -127
		cout << endl << "correct: -23.1235 >= -127" << endl;
	else
		cout << endl << "wrong ahskf " << endl;
	
	if(R19 >= R19)
		cout << "correct they are the same number" << endl;
	else
		cout << "wrong" << endl;

	if(R21 >= R11)
		cout << "correct 0 >= -1" << endl;
	else
		cout << "wrong " << endl; 

	if(R3 == R3)
		cout << endl << "correct: R3 == R3 " << endl;
	else
		cout << endl << "wrong" << endl;
	
	if(R17 == R18)
		cout << "wrong " << endl;
	else
		cout << "correct: R17 != R18" << endl;
	
	if(R19 == R20)
		cout << "wrong" << endl;
	else
		cout << "correct: R19 != R20" << endl;
	
	if(R23 == R23)
		cout << "correct: R23 == R23" << endl;
	else
		cout << "wrong" << endl;
	
	if(R3 != R3)
		cout << endl <<"wrong" << endl;
	else
		cout << endl << "correct: R3 is equal to R3 " << endl;
	if(R17 != R18)
		cout << "correct: R17 != R18" << endl;
	else
	{
	}
	if(R19 != R20)
		cout << "correct: R19 != R20" << endl;
	else
		cout << "wrong" << endl;
*/
	Real R27 ("1.2");
	Real R28 ("1.2");
	R4 = R27 + R28;
	cout << endl<<R27 << "+" << R28 << "=" << R4 <<endl;

	Real R29("-4.3");
	Real R30("1.2");
	R4 = R29 + R30;
	cout << R29 << "+" << R30 << "=" << R4 << endl;
	Real R31 ("1");
	Real R32("-2");
	R4= R31 + R32;
	cout << R31 << "+" << R32 << "=" << R4 << endl;

	R4 = R30 + R32;
	cout << R30 << "+" << R32 << "=" << R4 << endl;
	return 0;
}
