// Complex.h - complex number class
//https://support.sas.com/documentation/onlinedoc/ccompiler/doc750/html/cpp/z0274855.htm
//friend double abs(complex a)		returns the absolute value (magnitude) of a 
#pragma once
#include "mandlebrot.h"
#include <iostream>
#include <string>
using namespace std;

class Complex {
    private:
        double r;       // real part
        double i;       // imaginary part

    public:
        Complex();      // default constructor
        Complex( double r, double i );  // normal constructor
        Complex( double r );            // alternate constructor
        
        string tString( void );		//added to handle B more eligantly
        string toString( void );
        Complex operator + ( const Complex & rhs );
        Complex operator - ( const Complex & rhs );
        Complex operator * ( const Complex & rhs );
        Complex operator / ( const Complex & rhs);
        float magnitude();
//        friend float abs & operator << ( const Complex & rhs );		//<<this was added
//        Complex operator magnitude ( const Complex & rhs ); //added this equation/function for Mandlebrot project
        friend ostream & operator << ( ostream & lhs, const Complex & rhs );
        friend Complex operator + ( double lhs, const Complex & rhs );
        friend Complex operator + ( Complex & lhs, const double rhs );
};




