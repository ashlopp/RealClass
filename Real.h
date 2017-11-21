// Project: Homework 6
// File: Real.h
// Author:Ashley Lopez
// Description: contains the the real class

#ifndef __REAL_H
#define __REAL_H

#include <iostream>
#include <vector>
//#include <stdlib.h>

class Real
{

        public:
                Real();
                ~Real();
                Real( const Real & );
		Real (int);
                Real(const std::string &);
                Real( long long );
                Real( long long, int );
                Real( double );
                Real( double, int );

                void round (int );
                int precision () const;

                std::string toString()const;

                // I/O stream

                friend std::istream & operator >> (std::istream & ins, Real & );

                friend std::ostream & operator << (std::ostream & outs, const Real & );

                // Operator overloads

                bool operator <  (const Real & ) const;
                bool operator >  (const Real & ) const;
                bool operator <= (const Real & ) const;
                bool operator >= (const Real & ) const;
                bool operator == (const Real & ) const;
                bool operator != (const Real & ) const;

                Real operator +  (const Real & ) const;
                Real operator -  (const Real & ) const;
                Real operator *  (const Real & ) const;
                Real operator /  (const Real & ) const;

                Real & operator  = (const Real & );
                Real operator += (const Real & );
                Real operator -= (const Real & );
                Real operator *= (const Real & );
                Real operator /= (const Real & );

        private:

                // secret
		std:: vector <char> firsts; //before the decimal
		std:: vector <char> seconds; // after the decimal
		Real (std::vector<char> & f, std::vector<char>  & s,bool neg);
		std::string convertDouble(double);
		bool negative = false;
};


#endif
