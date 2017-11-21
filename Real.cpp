// Author: Ashley Lopez
// File: Real.cpp
// Description: File contains the Real class in order to handle numbers.  

#include <iostream>
#include <string> 
#include <algorithm>
#include <sstream>
#include "Real.h"


using namespace std;
Real::Real()
{
	firsts.push_back('0');
	seconds.push_back('0');
	negative = false;
}

Real:: ~Real()
{

}

Real:: Real (const Real & r )
{//copy constructor
  for (int i = 0; i < r.firsts.size(); i++)
    firsts.push_back(r.firsts[i]);
  for (int i = 0; i < r.seconds.size(); i++)
    seconds.push_back(r.seconds[i]);
  negative = r.negative;
}

Real:: Real (int real)
{
	string intreal = to_string(real);
	for (int i = 0; i < intreal.length(); i++)
	{
		firsts.push_back(intreal[i]);
		if(firsts[0] == '-')
		{
			negative = true;
			firsts.pop_back();
		}
	}
}

Real:: Real(const string  &S) 
{
  int decimal = 0;
	// fills the vectors depending on where the decimal is in 
	// the string. 
	// firsts is everything before the decimal and seconds is everything
	// after the decimal point 


	for (int i = 0; i < S.length(); i++)
	{
		if (S[i] == '.')
			decimal = 1;
		//need to convert string to char im pretty sure but i also have no idea
		if (decimal != 1)
		{
		 	firsts.push_back(S[i]);
			if(firsts[0] == '-')
			{
				negative = true;
				firsts.pop_back();
			}
		}	
		else
		{
			seconds.push_back(S[i]);
			if (S[i] == '.')
				seconds.pop_back();
		}
	}
}

Real:: Real (long long real)
{
  // turns what ever long long number is stored in real and will convert into
	// string
	string llreal = to_string(real);
	//loops through the string and adds it to the vector firsts since longs dont
	//contain decimals
	for (int i = 0; i < llreal.length(); i++)
	{
		firsts.push_back(llreal[i]);
		if(firsts[0] == '-')
		{
			negative = true;
			firsts.pop_back();
		}
	}
}


Real:: Real (double doubleReal)  
{
  int decimal = 0;
  //takes the double and then stores it as a string in dreal
  string dreal = convertDouble(doubleReal);
  //saves the information into the correct vector
  for (int i = 0; i < dreal.length(); i++)
    {
      if (dreal[i] == '.')
	decimal = 1;
      if (decimal != 1)
	{
	  firsts.push_back(dreal[i]);
	  if(i == 0 && firsts[0] == '-')
	    {
	      negative = true;
	      firsts.pop_back();
	    }
	}	
      else 
	{
	  seconds.push_back(dreal[i]);
	  if (dreal[i] == '.')
	    seconds.pop_back();
	  //if(dreal[i] == '0')
	  //	seconds.pop_back();
	}
    }

}

Real:: Real (double doubleReal, int dplace)
{
	string S = convertDouble(doubleReal);
	int decimal = 0;
	// fills the vectors depending on where the decimal is in 
	// the string. 
	// firsts is everything before the decimal and seconds is everything
	// after the decimal point 


	for (int i = 0; i < S.length(); i++)
	{
		if (S[i] == '.')
			decimal = 1;
		//need to convert string to char im pretty sure but i also have no idea
		if (decimal != 1)
		{
			firsts.push_back(S[i]);
			if(i == 0 && firsts[0] == '-')
			{
				negative = true;
				firsts.pop_back();
			}
		}	
		else
		{
			seconds.push_back(S[i]);
			if (S[i] == '.')
				seconds.pop_back();
		}
	}
	char inttochar;
	//keeps track of the number that we are paying attention to for round
	if (seconds.size() < dplace)
		seconds.resize(dplace);
	int rNumber = seconds[dplace] - '0';
	//if the number is a nine, will replace with zeros
	int zeros = 0;
	//helps for the while loop for the 9's
	int i = dplace - 1;
	//how to handle if the number after perc is >= 5
	int fSize = firsts.size();
	bool usedF = false;
	if (rNumber >= 5)
	{
		int current = seconds[i] - '0';
		if (current < 9)
			seconds[i] = (current + 1) + '0';
		else
		{
			while(current == 9)
			{
				zeros++;
				seconds.pop_back();
				i--;
				current = seconds[i] - '0';
				if(i == 0)
				{
					if(firsts.size() < 1)
					{
						inttochar = 1 + '0';
						firsts.push_back(inttochar);
					}
					else
					{
						int firstNum = firsts[firsts.size()-1] - '0';
						firsts.pop_back();
						firstNum++;
						inttochar = firstNum + '0';
						firsts.push_back(inttochar);
						usedF = true;
					}
					break;
				}
			}
			if (zeros > 0)
			{
				dplace -= zeros;
				current = dplace;
			}
			current++;
			seconds.resize(dplace);
			if(zeros == 0)
				seconds.pop_back();
			if(!usedF)
			{
				current++;
				inttochar = current + '0';
				seconds.push_back(inttochar);
			}
			while(zeros > 1)
			{
				inttochar = 0 + '0';
				seconds.push_back(inttochar);
				zeros--;
			}
		}
	}
	//else
	seconds.resize(dplace);

}

void Real:: round (int perc)
{//only has to handle the numbers in the seconds vector and how to round that
	//keeps track of the number that we are paying attention to for round
	if ( seconds.size() < perc)
	{
		int temp = perc - seconds.size();
		for (int i = 0; i < temp; i++)
			seconds.push_back('0');
		return;	
	}	

	int rNumber = seconds[perc] - '0';
	//if the number is a nine, will replace with zeros
	int zeros = 0;
	//helps for the while loop for the 9's 
	int i = perc;
	//how to handle if the number after perc is >= 5 
	int fSize = firsts.size();
	bool usedF = false;
	if (rNumber >= 5)
	{
		int current = seconds[perc - 1] -'0';
		//takes the current number and will do the proper thing 
		while(current == 9)
		{
			zeros++;
			seconds.pop_back();
			i--;
			current = seconds[i] - '0';
			if(i == 0)
			{
				if(firsts.size() < 1)
					firsts.push_back(1 + '0');
				else
				{
					int firstNum = firsts[firsts.size()-1]-'0';
					firsts.pop_back();
					firstNum++;
					firsts.push_back(firstNum + '0');
					usedF = true;
				}
				break;
			}
		}
		//will only go here if there is a nine as one of the numbers
		//that needs to be changed 
		if(zeros > 0)
		{
			perc -= zeros;				
			current = perc;
		}
		current++;
		seconds.resize(perc);
		if(zeros == 0)
			seconds.pop_back();
		if(!usedF)
		{
			current++;
			seconds.push_back(current + '0');
		}
		while(zeros > 1)
		{
			seconds.push_back(0 + '0');
			zeros--;
		}
	}
	else
		seconds.resize(perc);
}

int Real:: precision () const
{
	return seconds.size();
}

string Real :: toString() const
{
	string temp = "";
	if(negative == true)
		temp += "-";
	for (int i = 0; i < firsts.size(); i++)
		temp += firsts[i];
	if(seconds.size() > 0)
		temp += '.';
	for (int i = 0; i < seconds.size(); i++)
		temp += seconds[i];
	return temp;	
}

istream & operator >>  (istream & ins, Real & r)
{
	r.negative = false;
	//string rstring;
	//ins >> rstring;
	char character;
	ins.get(character);
	r.firsts.clear();
	r.seconds.clear();
	int decimal = 0;
	//if(!ins.fail())
	if(character == '-')
	{
		r.negative = true;
		ins.get(character);
	}
	while((character >= '0' && character <= '9') || character == '.')
	{
		if(decimal == 0 && character == '.')
			decimal = 1;
		else if((character < '0' || character > '9') && character != '.')
			break;
		else if(decimal == 0)
			r.firsts.push_back(character);
		else if(decimal == 1)
			r.seconds.push_back(character);
		ins.get(character);
	}
	if(character != ' ' && character != '\n' && !ins.eof())
	{
		while(character != ' ' && character != '\n' && !ins.eof())
			ins.get(character);
	}

	return ins;
}

ostream & operator << (ostream & outs, const Real & r)
{//isnt grabbing private vector and i dont know why 

	//string s = r.toString();
	//outs << s;

	if(r.negative == true)
		outs <<  '-'; 
	if(r.firsts.size() == 0)
		outs << '0';
	for (int i = 0; i < r.firsts.size(); i++)
	{
		outs << r.firsts[i];
	}
	outs << '.';
	if(r.seconds.size() > 0)
	{	
		for (int i = 0; i < r.seconds.size(); i++)
		{
			outs << r.seconds[i];
		}
	}
	else
		outs << '0';

	return outs;
}

bool Real:: operator < (const Real & r) const
{
//compares the whole real number in firsts to r.firsts
  //checks to see if negative numbers and handle the situations 
  vector<char> tempsecs;
	if(negative && !r.negative)
		return true;
	if(!negative && r.negative)
		return false;
	//if both are negative handle the situation this way
	if(negative && r.negative)
	{
		if (firsts.size() < r.firsts.size())
			return false;
		if (firsts.size() > r.firsts.size())	
			return true;
		//if both numbers are neg and are the same size handle it this way
		if(firsts.size() == r.firsts.size())
		{
			for (int i = 0; i < firsts.size(); i++)
			{
				if (firsts[i] > r.firsts[i])
					return true;
				if(firsts[i] < r.firsts[i])
					return false;
			}
		}
		if(seconds.size() < r.seconds.size())
		  return false;
		if(seconds.size() > r.seconds.size())
		  return true;
		if(seconds.size() == r.seconds.size())
		{
			for (int i = 0; i < seconds.size(); i++)
			{
				if(seconds[i] > r.seconds[i])
					return true;
				if (seconds[i] < r.seconds[i])
					return false;
			}
		}
	}

	//if neither arrays are negative
	if(firsts.size() > r.firsts.size())
		return false;
	if(firsts.size() < r.firsts.size())
		return true;	
	// if both are same size compare each number in each array 
	if(firsts.size() == r.firsts.size())
	{
		for (int i = 0; i < firsts.size(); i++)
		{
			if(firsts[i] > r.firsts[i])
				return false;
			if (firsts[i] < r.firsts[i])
				return true;
			//else
			//return false;
		}
		
	}
	
	//if every single element in firsts and r.firsts is exactly the same it has to 
	//start checking seconds and r.seconds
	if(seconds.size() < r.seconds.size())
	  {
	    for(int i = 0; i < seconds.size(); i++)
	      tempsecs.push_back(seconds[i]);
	    tempsecs.resize(r.seconds.size());
	    for (int i = 0; i < r.seconds.size(); i++)
	      {
		if(tempsecs[i] < r.seconds[i])
		  return true;
		if (tempsecs[i] > r.seconds[i])
		  return false;
	      }
	    
	  }
	//return false;
	else if(seconds.size() > r.seconds.size())
	  {
	    for(int i = 0; i < r.seconds.size(); i++)
	      tempsecs.push_back(r.seconds[i]);
	    tempsecs.resize(seconds.size());
	    for (int i = 0; i < seconds.size(); i++)
	      {
		if(seconds[i] < tempsecs[i])
		  return true;
		if (seconds[i] > tempsecs[i])
		  return false;
	      }
	  }
	
	if(seconds.size() == r.seconds.size())
	  {
	    for (int i = 0; i < seconds.size(); i++)
	      {	
		if(seconds[i] < r.seconds[i])
		  return true;
		if(seconds[i] > r.seconds[i])
		  return false;
		//else
		//return false;
	      }
	  }
	return false;	
	
}

bool Real:: operator > (const Real & r) const
{
	//handles negative cases
	if(negative && !r.negative)
		return false;
	if(!negative && r.negative)
		return true;
	//handles if both firsts and r.frists are negative
	if (negative && r.negative)
	{
		//handles the firsts for negative numbers
		if(firsts.size() > r.firsts.size())
			return false;
		if(firsts.size() < r.firsts.size())
			return true;
		if(firsts.size() == firsts.size())
		{
			for (int i = 0; i < firsts.size(); i++)
			{
				if(firsts[i] > r.firsts[i])
					return true;
				if(firsts[i] < r.firsts[i])
					return false;
			}
		}
		//handles the seconds if negative numbers 
		if(seconds.size()  < r.seconds.size())
			return true;
		if (seconds.size() > r.seconds.size())
			return false;
		if(seconds.size() == r.seconds.size())
		{
			for (int i = 0; i < seconds.size(); i++)
			{
				if(seconds[i] < r.seconds[i])
					return true;
				if(seconds[i] > r.seconds[i])
					return false;
			}
		}
		
	}
	
	//if both numbers are positive it will compare firsts and r.firsts with this
	if(firsts.size() < r.firsts.size())
		return false;
	if(firsts.size() > r.firsts.size())
		return true;
	//if the size of firsts and r.firsts are equal check each element and compare
	if(firsts.size() == r.firsts.size())
	{
		for (int i = 0; i < firsts.size(); i++)
		{
			if(firsts[i] > r.firsts[i])
				return true;
			if(firsts[i] < r.firsts[i])
				return false;
		}
	}
	
	//handles the seconds if both firsts and r.firsts are exactly the same number
	if(seconds.size() < r.seconds.size())
		return false;
	if(seconds.size() > r.seconds.size())
		return true;
	if(seconds.size() == r.seconds.size())
	{
		for (int i = 0 ; i < seconds.size(); i++)
		{
			if(seconds[i] < r.seconds[i])
				return false;
			if(seconds[i] > r.seconds[i])
				return true;
		}
	}
	return false;				
}

bool Real:: operator <= (const Real &r) const
{

	if(negative && !r.negative)
		return true;
	if(!negative && r.negative)
		return false;
	//if both are negative handle the situation this way
	if(negative && r.negative)
	{
		if (firsts.size() < r.firsts.size())
			return false;
		if (firsts.size() > r.firsts.size())	
			return true;
		//if both numbers are neg and are the same size handle it this way
		if(firsts.size() == r.firsts.size())
		{
			for (int i = 0; i < firsts.size(); i++)
			{
				if (firsts[i] > r.firsts[i])
					return true;
				if(firsts[i] < r.firsts[i])
					return false;
			}
		}
		//if both are negative and firsts and r.firsts match up perfectly 
		if(seconds.size() < r.seconds.size())
			return false;
		if(seconds.size() > r.seconds.size())
			return true;
		if(seconds.size() == r.seconds.size())
		{
			for (int i = 0; i < seconds.size(); i++)
			{
				if(seconds[i] > r.seconds[i])
					return true;
				if (seconds[i] < r.seconds[i])
					return false;
			}
		}
	}

	//if neither arrays are negative
	if(firsts.size() > r.firsts.size())
		return false;
	if(firsts.size() < r.firsts.size())
		return true;	
	// if both are same size compare each number in each array 
	if(firsts.size() == r.firsts.size())
	{
		for (int i = 0; i < firsts.size(); i++)
		{
			if(firsts[i] > r.firsts[i])
				return false;
			if (firsts[i] < r.firsts[i])
				return true;
		}
	}
	
	//if every single element in firsts and r.firsts is exactly the same it has to 
	//start checking seconds and r.seconds
	if(seconds.size() < r.seconds.size())
		return true;
	if(seconds.size() > r.seconds.size())
		return false;
	if(seconds.size() == r.seconds.size())
	{
		for (int i = 0; i < seconds.size(); i++)
		{	
			if(seconds[i] < r.seconds[i])
				return true;
			if(seconds[i] > r.seconds[i])
				return false;
		}
	}	
	return true;	
	
}


bool Real:: operator >= (const Real &r) const
{
	//handles negative cases
	if(negative && !r.negative)
	{
		return false;
	}
	if(!negative && r.negative)
	{
		return true;
	}
	//handles if both firsts and r.frists are negative
	if (negative && r.negative)
	{
		//handles the firsts for negative numbers
		if(firsts.size() > r.firsts.size())
			return false;
		if(firsts.size() < r.firsts.size())
			return true;
		if(firsts.size() == firsts.size())
		{
			for (int i = 0; i < firsts.size(); i++)
			{
				if(firsts[i] > r.firsts[i])
					return true;
				if(firsts[i] < r.firsts[i])
					return false;
			}
		}
		//handles the seconds if negative numbers 
		if(seconds.size()  < r.seconds.size())
			return true;
		if (seconds.size() > r.seconds.size())
			return false;
		if(seconds.size() == r.seconds.size())
		{
			for (int i = 0; i < seconds.size(); i++)
			{
				if(seconds[i] < r.seconds[i])
					return true;
				if(seconds[i] > r.seconds[i])
					return false;
			}
		}
		
	}
	
	//if both numbers are positive it will compare firsts and r.firsts with this
	if(firsts.size() < r.firsts.size())
	{
		return false;
	}
	if(firsts.size() > r.firsts.size())
	{
		return true;
	}
	//if the size of firsts and r.firsts are equal check each element and compare
	if(firsts.size() == r.firsts.size())
	{
		for (int i = 0; i < firsts.size(); i++)
		{
			if(firsts[i] > r.firsts[i])
				return true;
			if(firsts[i] < r.firsts[i])
				return false;
		}
	}
	
	//handles the seconds if both firsts and r.firsts are exactly the same number
	if(seconds.size() < r.seconds.size())
		
		return false;
	if(seconds.size() > r.seconds.size())
		return true;
	if(seconds.size() == r.seconds.size())
	{
		for (int i = 0 ; i < seconds.size(); i++)
		{
			if(seconds[i] < r.seconds[i])
				return false;
			if(seconds[i] > r.seconds[i])
				return true;
		}
	}
	return true;				

}

bool Real:: operator == (const Real &r) const
{
	//checks the numbers to see if firsts or r.firsts is negative
	if(negative && !r.negative)
		return false;
	if(!negative && r.negative)
		return false;
	//will continue with the code if both firsts and r.frists are negative and positive
	//then checks the size of firsts
	if(firsts.size() != r.firsts.size())
		return false;
	//if firsts and r.firsts are the same size it will then loop through both and see
	//if both contian the same numbers. 
	if(firsts.size() == r.firsts.size())
	{
		for (int i = 0; i < firsts.size(); i++)
		{
			if(firsts[i] != r.firsts[i])
				return false;
		}
	}
	//checks to see if seconds and r.seconds is the same size
	if(seconds.size() != r.seconds.size())
		return false;
	//if both are the same size then compares the each number by number
	if(seconds.size() == seconds.size())
	{
		for (int i = 0; i < seconds.size(); i++)
		{
			if(seconds[i] != r.seconds[i])
				return false;
		}
	}
	return true;
	
}

bool Real:: operator != (const Real &r) const
{
	//compares both numbers if one is negative and one isnt then the the numbers are different
	if(negative && !r.negative)
		return true;
	if(!negative && r.negative)
		return true;
	//compares the size of firsts and r.firsts 
	if(firsts.size() != r.firsts.size())
		return true;
	//compares the size of seconds and r.seconds
	if(seconds.size() != r.seconds.size())
		return true;
	//loops through to find a different number in the firsts and r.frists array 
	if(firsts.size() == r.firsts.size())
	{
		for (int i = 0; i < firsts.size(); i++)
		{
			if(firsts[i] != r.firsts[i])
				return true;
		}
	}
	//looops through the seconds and r.seconds to find a different number
	if(seconds.size() == r.seconds.size())
	{
		for (int i = 0; i < seconds.size(); i++)
		{
			if(seconds[i] != r.seconds[i])
				return true;
		}
	}
	return false;
}

Real:: Real (vector<char> &f, vector <char> &s, bool neg)
{
 	firsts = f;
	seconds = s;
	negative = neg;
}

Real Real:: operator + (const Real & r) const
{
	vector <char> plus; //stores the new number
	vector <char> plusSeconds;
	vector<char> tempfirsts;
	vector<char> temprfirsts;
	vector<char> temprseconds;
	vector<char> tempseconds;
	
	tempfirsts = firsts;
	tempseconds = seconds;
	temprfirsts = r.firsts;
	temprseconds = r.seconds;
	int newnum; 
	bool neg = false;
	bool carry = false;
	string number;
	
	//checks to see if vector are same lenght and if not resizes to be the same size
	if(tempfirsts.size() < temprfirsts.size())
	  {
	    reverse(tempfirsts.begin(), tempfirsts.end());
	    tempfirsts.resize(temprfirsts.size(), '0');
	    reverse(tempfirsts.begin(), tempfirsts.end());
	  }
	if(tempfirsts.size() > temprfirsts.size())
	  {
	    reverse(temprfirsts.begin(), temprfirsts.end());
	    temprfirsts.resize(tempfirsts.size(), '0');
	    reverse(temprfirsts.begin(), temprfirsts.end());
	  }
	if(tempseconds.size() < temprseconds.size())
	  tempseconds.resize(temprseconds.size(), '0');
	if(tempseconds.size() > temprseconds.size())
	  temprseconds.resize(tempseconds.size(), '0');

	if (negative && r.negative) // - - // adding (will add later)
		neg = true;
	if(negative && !r.negative) // - + // subtracting
	  {
	    neg = true;
	    string tempfbigger = "equal";
	    bool borrow = false;
	    for(int i = 0; i < tempfirsts.size(); i++) // finding which is bigger (absolute value)
	      {
		if((tempfirsts[i] -'0') > (temprfirsts[i] - '0'))
		  {
		    tempfbigger = "bigger";
		    break;
		  }
		else if((tempfirsts[i] -'0') < (temprfirsts[i] - '0'))
		  {
		    tempfbigger = "smaller";
		    break;
		  }
	      }
	    if(tempfbigger == "equal") // checking seconds to find which is bigger
	      {
		for(int i = 0; i < tempseconds.size(); i++)
		  {
		    if((tempseconds[i] -'0') > (temprseconds[i] - '0'))
		      {
			tempfbigger = "bigger";
			break;
		      }
		    else if((tempseconds[i] -'0') < (temprseconds[i] - '0'))
		      {
			tempfbigger = "smaller";
			break;
		      }
		  }
	      }
	    if(tempfbigger == "bigger") // *this > r =>  *this - r
	      {
		for (int i = tempseconds.size() - 1; i>= 0; i--)
		  {
		    if(borrow == true)
		      newnum = ((tempseconds[i] - '0') - 1) - (temprseconds[i] - '0');
		    else
		      newnum = (tempseconds[i] - '0') - (temprseconds[i] - '0');
		    
		    if(newnum < 0)
		      {
			if(borrow == true)
			  newnum = (((tempseconds[i] - '0') - 1) + 10) - (temprseconds[i] - '0');
			else
			  newnum = ((tempseconds[i] - '0') + 10) - (temprseconds[i] - '0');
			plusSeconds.push_back(newnum + '0');
			borrow = true;
		      }
		    else
		      {
			plusSeconds.push_back(newnum + '0');
			borrow = false;
		      }
		  }
		for (int i = tempfirsts.size() - 1; i >= 0; i--)
		  {
		    if(borrow == true)
		      newnum = ((tempfirsts[i] - '0') - 1) - (temprfirsts[i] - '0');
		    else
		      newnum = (tempfirsts[i] - '0') - (temprfirsts[i] - '0');
		    if(newnum < 0)
		      {
			if(borrow == true)
			  newnum = (((tempfirsts[i] - '0') - 1) + 10) - (temprfirsts[i] - '0');
			else
			newnum = ((tempfirsts[i] - '0') + 10) - (temprfirsts[i] - '0');
			plus.push_back(newnum +'0');
			borrow = true;
		      }
		    else
		      {
			plus.push_back(newnum +'0');
			borrow = false;
		      }
		    neg = negative;
		  }
	      }
	    else if(tempfbigger == "smaller") // *this < r => r - *this
	      {
		for(int i = temprseconds.size() - 1; i >= 0; i--)
		  {
		    if(borrow == true)
		      newnum = ((temprseconds[i] - '0') - 1) - (tempseconds[i] -'0');
		    else
		      newnum = (temprseconds[i] - '0') - (tempseconds[i] -'0');
		    if(newnum < 0)
		      {
			if(borrow == true)
			  newnum = (((temprseconds[i] - '0') - 1) + 10) - (tempseconds[i] -'0');
			else
			  newnum = ((temprseconds[i] - '0') + 10) - (tempseconds[i] -'0');
			plusSeconds.push_back(newnum + '0');
			borrow = true;
		      }
		    else
		      {
			plusSeconds.push_back(newnum + '0');
			borrow = false;
		      }
		  }
		for(int i = temprfirsts.size() - 1; i >= 0; i--)
		  {
		    if(borrow == true)
		      newnum = ((temprfirsts[i] -'0') - 1) - (tempfirsts[i] - '0');
		    else
		      newnum = (temprfirsts[i] -'0') - (tempfirsts[i] - '0');
		    if(newnum < 0)
		      {
			if(borrow == true)
			  newnum = (((temprfirsts[i] - '0') - 1) + 10) - (tempfirsts[i] -'0');
			else
			  newnum = ((temprfirsts[i] -'0') + 10) - (tempfirsts[i] - '0');
			plus.push_back(newnum + '0');
			borrow = true;
		      }
		    else
		      {
			plus.push_back(newnum + '0');
			borrow = false;
		      }
		  }
		neg = r.negative;
	      }
	    else if(tempfbigger == "equal")
	      neg = false;
	    reverse(plus.begin(), plus.end());
	    reverse(plusSeconds.begin(), plusSeconds.end());
	    Real answer(plus, plusSeconds, neg);
	    return answer;
	  }
	if(!negative && r.negative) // + - // subtracting
	  {
	    neg = true;
	    bool borrow = false;
	    string tempfbigger = "equal";
	    for(int i = 0; i < tempfirsts.size(); i++) // finding which is bigger (absolute value)
	      {
		if((tempfirsts[i] -'0') > (temprfirsts[i] - '0'))
		  {
		    tempfbigger = "bigger";
		    break;
		  }
		else if((tempfirsts[i] -'0') < (temprfirsts[i] - '0'))
		  {
		    tempfbigger = "smaller";
		    break;
		  }
	      }
	    if(tempfbigger == "equal") // checking seconds for bigger value
	      {
		for(int i = 0; i < tempseconds.size(); i++)
		  {
		    if((tempseconds[i] -'0') > (temprseconds[i] - '0'))
		      {
			tempfbigger = "bigger";
			break;
		      }
		    else if((tempseconds[i] -'0') < (temprseconds[i] - '0'))
		      {
			tempfbigger = "smaller";
			break;
		      }
		  }
	      }
	    if(tempfbigger == "bigger") // *this > r => *this - r
	      {
		for (int i = tempseconds.size() - 1; i>= 0; i--)
		  {
		    if(borrow == true)
		      newnum = ((tempseconds[i] - '0') - 1) - (temprseconds[i] - '0');
		    else
		      newnum = (tempseconds[i] - '0') - (temprseconds[i] - '0');
		    if(newnum < 0)
		      {
			if(borrow == true)
			  newnum = (((tempseconds[i] - '0') -1) + 10) - (temprseconds[i] - '0');
			else
			  newnum = ((tempseconds[i] - '0') + 10) - (temprseconds[i] - '0');
			plusSeconds.push_back(newnum + '0');
			borrow = true;
		      }
		    else
		      {
			plusSeconds.push_back(newnum + '0');
			borrow = false;
		      }
		  }
		for (int i = tempfirsts.size() - 1; i >= 0; i--)
		  {
		    if(borrow == true)
		      newnum = ((tempfirsts[i] - '0') - 1) - (temprfirsts[i] - '0');
		    else
		      newnum = (tempfirsts[i] - '0') - (temprfirsts[i] - '0');
		    if(newnum < 0)
		      {
			if(borrow == true)
			  newnum = (((tempfirsts[i] - '0') - 1) + 10) - (temprfirsts[i] - '0');
			else
			  newnum = ((tempfirsts[i] - '0') + 10) - (temprfirsts[i] - '0');
			plus.push_back(newnum +'0');
			borrow = true;
		      }
		    else
		      {
			plus.push_back(newnum +'0');
			borrow = false;
		      }
		  }
		neg = negative;
	      }
	    else if(tempfbigger == "smaller") // *this < r => r - *this
	      {
		for(int i = tempseconds.size() - 1; i >= 0; i--)
		  {
		    if(borrow == true)
		      newnum = ((temprseconds[i] - '0') - 1) - (tempseconds[i] -'0');
		    else
		      newnum = (temprseconds[i] - '0') - (tempseconds[i] -'0');
		    if(newnum < 0)
		      {
			if(borrow == true)
			  newnum = (((tempseconds[i] - '0') - 1) + 10) - (temprseconds[i] - '0');
			else
			  newnum = ((temprseconds[i] - '0') + 10) - (tempseconds[i] -'0');
			plusSeconds.push_back(newnum + '0');
			borrow = true;
		      }
		    else
		      {
			plusSeconds.push_back(newnum + '0');
			borrow = false;
		      }
		  }
		for(int i = tempfirsts.size() - 1; i >= 0; i--)
		  {
		    if(borrow == true)
		      newnum = ((temprfirsts[i] -'0') - 1) - (tempfirsts[i] - '0');
		    else
		      newnum = (temprfirsts[i] -'0') - (tempfirsts[i] - '0');
		    if(newnum < 0)
		      {
			if(borrow == true)
			  newnum = (((tempseconds[i] - '0') - 1) + 10) - (temprseconds[i] - '0');
			else
			  newnum = ((temprfirsts[i] -'0') + 10) - (tempfirsts[i] - '0');
			plus.push_back(newnum + '0');
			borrow = true;
		      }
		    else
		      {
			plus.push_back(newnum + '0');
			borrow = false;
		      }
		  }
		neg = r.negative;
	      }
	    else if(tempfbigger == "equal")
	      neg = false;
	    reverse(plus.begin(), plus.end());
	    reverse(plusSeconds.begin(), plusSeconds.end());
	    //neg = true;
	    Real answer(plus, plusSeconds, neg);
	    return answer;
	  }
	//deals with the seconds adding together // adding
	char n;
	for (int i = tempseconds.size() - 1; i >= 0; i--)
	  {
	    if(carry == true)
	      newnum = (tempseconds[i] - '0') + (temprseconds[i] - '0') + 1;
	    else
	      newnum = (tempseconds[i] - '0') + (temprseconds[i] - '0');
	    if(newnum > 9)
	      {
		number = to_string(newnum);
		plusSeconds.push_back(number[1]);
		carry = true;
	      }
	    else
	      {
		plusSeconds.push_back(newnum + '0');
		carry = false;
	      }
	  }
	reverse(plusSeconds.begin(), plusSeconds.end());
	//for loop to add the individual numbers together and add them into a new vector. 
	for (int i = tempfirsts.size() -1 ; i >= 0; i--)
	{
	  if(carry == true)
	    newnum =(tempfirsts[i] - '0') + (temprfirsts[i] - '0') + 1;
	  else
	    newnum =(tempfirsts[i] - '0') + (temprfirsts[i] - '0');
	  if (newnum > 9)
	    {
	      number = to_string(newnum);
	      plus.push_back(number[1]);
	      carry = true;
	    }
	  else
	    {
	      plus.push_back(newnum + '0');
	      carry = false;
	    }
	}
	if (carry == true)
		plus.push_back('1');
	//reverses plus vector to return correct number, might need to change when calling firsts
	//for rounding purposes
	reverse(plus.begin(), plus.end());
	
	Real answer(plus, plusSeconds, neg);	
	return answer;
}


Real Real:: operator - (const Real & r) const
{
	//makes the temporary vectors since Real and R are const vectors and we are not able to change them
	vector <char> plus; //stores the new number
	vector <char> plusSeconds;
	vector<char> tempfirsts;
	vector<char> temprfirsts;
	vector<char> temprseconds;
	vector<char> tempseconds;
	
	tempfirsts = firsts;
	tempseconds = seconds;
	temprfirsts = r.firsts;
	temprseconds = r.seconds;
	int newnum; //used to make the new num to add the new vectors 
	bool neg = false;//flags for negative numbers
	bool carry = false;//flag for when we need to carry for adding 
	string number; //stores the new number in string form

	if(tempfirsts.size() < temprfirsts.size())
	  {
	    reverse(tempfirsts.begin(), tempfirsts.end());
	    tempfirsts.resize(temprfirsts.size(), '0');
	    reverse(tempfirsts.begin(), tempfirsts.end());
	  }
	if(tempfirsts.size() > temprfirsts.size())
	  {
	    reverse(temprfirsts.begin(), temprfirsts.end());
	    temprfirsts.resize(tempfirsts.size(), '0');
	    reverse(temprfirsts.begin(), temprfirsts.end());
	  }
	if(tempseconds.size() < temprseconds.size())
	  tempseconds.resize(temprseconds.size(), '0');
	if(tempseconds.size() > temprseconds.size())
	  temprseconds.resize(tempseconds.size(), '0');

	if(negative && r.negative) // if both numbers are negative, set the flag and do regular addition
	{
		neg = true;
	}	
	if(negative && !r.negative) // - + // subtracting
	  { 
	    neg = true; //sets neg flag to true
	    string tempfbigger = "equal"; 
	    bool borrow = false;
	    for(int i = 0; i < tempfirsts.size(); i++) // finding which is bigger (absolute value)
	      {	//sees which first number is bigger so we can put the proper one on top for easy subtraction
		if((tempfirsts[i] -'0') > (temprfirsts[i] - '0'))
		  {
		    tempfbigger = "bigger";
		    break;
		  }
		else if((tempfirsts[i] -'0') < (temprfirsts[i] - '0'))
		  {
		    tempfbigger = "smaller";
		    break;
		  }
	      }
	    if(tempfbigger == "equal") // checking seconds to find which is bigger
	      {
		for(int i = 0; i < tempseconds.size(); i++)
		  {
		    if((tempseconds[i] -'0') > (temprseconds[i] - '0'))
		      {
			tempfbigger = "bigger";
			break;
		      }
		    else if((tempseconds[i] -'0') < (temprseconds[i] - '0'))
		      {
			tempfbigger = "smaller";
			break;
		      }
		  }
	      }
	    if(tempfbigger == "bigger") // *this > r =>  *this - r
	      {
		for (int i = tempseconds.size() - 1; i>= 0; i--)
		  {
		    if(borrow == true)
		      newnum = ((tempseconds[i] - '0') - 1) - (temprseconds[i] - '0');
		    else
		      newnum = (tempseconds[i] - '0') - (temprseconds[i] - '0');
		    
		    if(newnum < 0)
		      {
			if(borrow == true)
			  newnum = (((tempseconds[i] - '0') - 1) + 10) - (temprseconds[i] - '0');
			else
			  newnum = ((tempseconds[i] - '0') + 10) - (temprseconds[i] - '0');
			plusSeconds.push_back(newnum + '0');
			borrow = true;
		      }
		    else
		      {
			plusSeconds.push_back(newnum + '0');
			borrow = false;
		      }
		  }
		for (int i = tempfirsts.size() - 1; i >= 0; i--)
		  {
		    if(borrow == true)
		      newnum = ((tempfirsts[i] - '0') - 1) - (temprfirsts[i] - '0');
		    else
		      newnum = (tempfirsts[i] - '0') - (temprfirsts[i] - '0');
		    if(newnum < 0)
		      {
			if(borrow == true)
			  newnum = (((tempfirsts[i] - '0') - 1) + 10) - (temprfirsts[i] - '0');
			else
			newnum = ((tempfirsts[i] - '0') + 10) - (temprfirsts[i] - '0');
			plus.push_back(newnum +'0');
			borrow = true;
		      }
		    else
		      {
			plus.push_back(newnum +'0');
			borrow = false;
		      }
		    neg = negative;
		  }
	      }
	    else if(tempfbigger == "smaller") // *this < r => r - *this
	      {
		for(int i = temprseconds.size() - 1; i >= 0; i--)
		  {
		    if(borrow == true)
		      newnum = ((temprseconds[i] - '0') - 1) - (tempseconds[i] -'0');
		    else
		      newnum = (temprseconds[i] - '0') - (tempseconds[i] -'0');
		    if(newnum < 0)
		      {
			if(borrow == true)
			  newnum = (((temprseconds[i] - '0') - 1) + 10) - (tempseconds[i] -'0');
			else
			  newnum = ((temprseconds[i] - '0') + 10) - (tempseconds[i] -'0');
			plusSeconds.push_back(newnum + '0');
			borrow = true;
		      }
		    else
		      {
			plusSeconds.push_back(newnum + '0');
			borrow = false;
		      }
		  }
		for(int i = temprfirsts.size() - 1; i >= 0; i--)
		  {
		    if(borrow == true)
		      newnum = ((temprfirsts[i] -'0') - 1) - (tempfirsts[i] - '0');
		    else
		      newnum = (temprfirsts[i] -'0') - (tempfirsts[i] - '0');
		    if(newnum < 0)
		      {
			if(borrow == true)
			  newnum = (((temprfirsts[i] - '0') - 1) + 10) - (tempfirsts[i] -'0');
			else
			  newnum = ((temprfirsts[i] -'0') + 10) - (tempfirsts[i] - '0');
			plus.push_back(newnum + '0');
			borrow = true;
		      }
		    else
		      {
			plus.push_back(newnum + '0');
			borrow = false;
		      }
		  }
		neg = r.negative;
	      }
	    else if(tempfbigger == "equal")
	      neg = false;
	    reverse(plus.begin(), plus.end());
	    reverse(plusSeconds.begin(), plusSeconds.end());
	    Real answer(plus, plusSeconds, neg);
	    return answer;
	  }
	if(!negative && r.negative) // + - // subtracting
	  {
	    neg = true;
	    bool borrow = false;
	    string tempfbigger = "equal";
	    for(int i = 0; i < tempfirsts.size(); i++) // finding which is bigger (absolute value)
	      {
		if((tempfirsts[i] -'0') > (temprfirsts[i] - '0'))
		  {
		    tempfbigger = "bigger";
		    break;
		  }
		else if((tempfirsts[i] -'0') < (temprfirsts[i] - '0'))
		  {
		    tempfbigger = "smaller";
		    break;
		  }
	      }
	    if(tempfbigger == "equal") // checking seconds for bigger value
	      {
		for(int i = 0; i < tempseconds.size(); i++)
		  {
		    if((tempseconds[i] -'0') > (temprseconds[i] - '0'))
		      {
			tempfbigger = "bigger";
			break;
		      }
		    else if((tempseconds[i] -'0') < (temprseconds[i] - '0'))
		      {
			tempfbigger = "smaller";
			break;
		      }
		  }
	      }
	    if(tempfbigger == "bigger") // *this > r => *this - r
	      {
		for (int i = tempseconds.size() - 1; i>= 0; i--)
		  {
		    if(borrow == true)
		      newnum = ((tempseconds[i] - '0') - 1) - (temprseconds[i] - '0');
		    else
		      newnum = (tempseconds[i] - '0') - (temprseconds[i] - '0');
		    if(newnum < 0)
		      {
			if(borrow == true)
			  newnum = (((tempseconds[i] - '0') -1) + 10) - (temprseconds[i] - '0');
			else
			  newnum = ((tempseconds[i] - '0') + 10) - (temprseconds[i] - '0');
			plusSeconds.push_back(newnum + '0');
			borrow = true;
		      }
		    else
		      {
			plusSeconds.push_back(newnum + '0');
			borrow = false;
		      }
		  }
		for (int i = tempfirsts.size() - 1; i >= 0; i--)
		  {
		    if(borrow == true)
		      newnum = ((tempfirsts[i] - '0') - 1) - (temprfirsts[i] - '0');
		    else
		      newnum = (tempfirsts[i] - '0') - (temprfirsts[i] - '0');
		    if(newnum < 0)
		      {
			if(borrow == true)
			  newnum = (((tempfirsts[i] - '0') - 1) + 10) - (temprfirsts[i] - '0');
			else
			  newnum = ((tempfirsts[i] - '0') + 10) - (temprfirsts[i] - '0');
			plus.push_back(newnum +'0');
			borrow = true;
		      }
		    else
		      {
			plus.push_back(newnum +'0');
			borrow = false;
		      }
		  }
		neg = negative;
	      }
	    else if(tempfbigger == "smaller") // *this < r => r - *this
	      {
		for(int i = tempseconds.size() - 1; i >= 0; i--)
		  {
		    if(borrow == true)
		      newnum = ((temprseconds[i] - '0') - 1) - (tempseconds[i] -'0');
		    else
		      newnum = (temprseconds[i] - '0') - (tempseconds[i] -'0');
		    if(newnum < 0)
		      {
			if(borrow == true)
			  newnum = (((tempseconds[i] - '0') - 1) + 10) - (temprseconds[i] - '0');
			else
			  newnum = ((temprseconds[i] - '0') + 10) - (tempseconds[i] -'0');
			plusSeconds.push_back(newnum + '0');
			borrow = true;
		      }
		    else
		      {
			plusSeconds.push_back(newnum + '0');
			borrow = false;
		      }
		  }
		for(int i = tempfirsts.size() - 1; i >= 0; i--)
		  {
		    if(borrow == true)
		      newnum = ((temprfirsts[i] -'0') - 1) - (tempfirsts[i] - '0');
		    else
		      newnum = (temprfirsts[i] -'0') - (tempfirsts[i] - '0');
		    if(newnum < 0)
		      {
			if(borrow == true)
			  newnum = (((tempseconds[i] - '0') - 1) + 10) - (temprseconds[i] - '0');
			else
			  newnum = ((temprfirsts[i] -'0') + 10) - (tempfirsts[i] - '0');
			plus.push_back(newnum + '0');
			borrow = true;
		      }
		    else
		      {
			plus.push_back(newnum + '0');
			borrow = false;
		      }
		  }
		neg = r.negative;
	      }
	    else if(tempfbigger == "equal")
	      neg = false;
	    reverse(plus.begin(), plus.end());
	    reverse(plusSeconds.begin(), plusSeconds.end());
	    //neg = true;
	    Real answer(plus, plusSeconds, neg);
	    return answer;
	  }
//	if(negativ && r.negative)
//		operator + (Real & r);
	
	reverse(plusSeconds.begin(), plusSeconds.end());
	//for loop to add the individual numbers together and add them into a new vector. 
	for (int i = tempfirsts.size() -1 ; i >= 0; i--)
	{
	  if(carry == true)
	    newnum =(tempfirsts[i] - '0') + (temprfirsts[i] - '0') + 1;
	  else
	    newnum =(tempfirsts[i] - '0') + (temprfirsts[i] - '0');
	  if (newnum > 9)
	    {
	      number = to_string(newnum);
	      plus.push_back(number[1]);
	      carry = true;
	    }
	  else
	    {
	      plus.push_back(newnum + '0');
	      carry = false;
	    }
	}
	if (carry == true)
		plus.push_back('1');
	//reverses plus vector to return correct number, might need to change when calling firsts
	//for rounding purposes
	reverse(plus.begin(), plus.end());
	
	Real answer(plus, plusSeconds, neg);	
	return answer;
}
/*
Real Real:: operator * (const Real &) const
{

}

Real Real:: operator / (const Real &) const
{

}
*/

Real & Real :: operator = (const Real & r)
{
	firsts.clear();
  	seconds.clear();

  	for (int i = 0; i < r.firsts.size(); i++)
		firsts.push_back(r.firsts[i]);
  	for (int i = 0; i < r.seconds.size(); i++)
  		seconds.push_back(r.seconds[i]);
  	negative = r.negative;
}
Real Real:: operator += (const Real & r)
{
	*this = *this + r;
	return *this;
}

Real Real:: operator -= (const Real & r)
{
	*this = *this - r;
	return *this;
}

Real Real:: operator *= (const Real & )
{

}

Real Real:: operator /= (const Real & )
{

}

//PRIVATE FUNCTIONS: helper and other things will go here
//and dont forget to add the implementation to the ".h" file
// function that front fills for numbers that are smaller then the other
// and back fill the numbers that are missing to make the decimal points have the same 
// amount of numbers
//
// 00123.4567
// 99999.1200

string Real:: convertDouble(double doubleNum)
{
  //int max = 9; 
  int ntemp = 1; 
  int num = doubleNum; 
  string stemp;
  string strDecimal;
  strDecimal = to_string(num) + '.';
  doubleNum -= num;
  while (doubleNum > 0)
    {
      //for(int i =0; i < max; i++)
      ntemp *= 10;
      doubleNum = doubleNum * ntemp;
      num = doubleNum;
      stemp = to_string(num);
      strDecimal += stemp;
      doubleNum -= num;
      ntemp = 1;
    }
  return strDecimal;
}
