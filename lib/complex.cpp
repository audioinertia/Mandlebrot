#include "complex.h"
#include <iostream>
#include <sstream>
#include <cmath>
#include "graphics.h"
using namespace std;

// constructors -------------------------------------------
Complex::Complex() {
    r = 0;
    i = 0;
}

Complex::Complex( double r, double i ) {
    this->r = r;
    this->i = i;
}

Complex::Complex( double r ) {
    this->r = r;
    i = 0;
}

// accessors ----------------------------------------------

string Complex::tString( void ) {		//added to handle B more eligantly
    ostringstream  tmp;
    tmp << r;
    return tmp.str();
}

string Complex::toString( void ) {
    ostringstream  tmp;
    tmp << r <<  " + " << i << "i";
    return tmp.str();
}

// operators ----------------------------------------------
Complex Complex::operator + ( const Complex & rhs ) {
    Complex temp;
	temp.r = r + rhs.r;		//adds real numbers
    temp.i = i + rhs.i;  	//adds imaginary numbers
	return temp;
    
    //add: (a+bi) + (c+di) = (a+c) + (b+d)*i
}

Complex Complex::operator - ( const Complex & rhs ) {
    Complex temp;
    temp.r = r - rhs.r;		//subtracts real numbers
    temp.i = i - rhs.i;		//subtracts imaginary numbers
    return temp;
    
    //sub: (a+bi) - (c+di) = (a-c) + (b-d)*i
}

Complex Complex::operator * ( const Complex & rhs ) {
    Complex temp;
    //if constant real number:
    if (rhs.i==0) {
    	temp.r += r * rhs.r;	//multiply real by constant
    	temp.i += i * rhs.r;	//multiply imaginary by constant
    	return temp;    	
	}
	
	//if constant x complex:
	else if (i==0) {
		temp.r += r * rhs.r;	//multiply real by constant
		temp.i += r * rhs.i;	//multiply real by imaginary constant
		return temp; 
	}

    //if complex x complex:
    else {
    	temp.r += (r * rhs.r) + -(i * rhs.i);	//multiply real by constant, add to negative imaginary by constant
    	temp.i += (i * rhs.r) + (r * rhs.i); 	//multiply imaginary by constant, add real x imaginary constant
    	return temp;
    }
	//	these should be able to handle both:     
    //	mul1: (a+bi)+(c+di) = (a*c-b*d) + (a*d+b*c)i <<what's up with this one???
	//	mul2: B * (a+bi) = (a*B + B*bi)
}	

Complex Complex::operator / ( const Complex & rhs ) {
	Complex temp;
	//if divinding by constnat real:
	if (rhs.i==0) {
    	temp.r += r / rhs.r;	//divide real by constant
    	temp.i += i / rhs.r;	//divide imaginary by constant
    	return temp;    	
	}
	
	//if constant / by complex:
	else if (i==0) {
		double div = (rhs.r * rhs.r) + (rhs.i * rhs.i); //within this scope variable to divide by (real x itself, imaginary x itself)
		temp.r += (r * rhs.r) / div; 	//constant x real complex
		temp.i += (-r * rhs.i) / div;	//- constant x imaginary complex
		return temp;
	}

	//if complex / complex: 
    else {
		double div = (rhs.r * rhs.r) + (rhs.i * rhs.i); //within this scope variable to divide by (real x itself, imaginary x itself)
        temp.r += ((r * rhs.r + i * rhs.i) / div);	//constant x real complex + imaginary x imaginary complex 
		temp.i += ((i * rhs.r - r * rhs.i) / div);	//constant x imaginary - real x real complex
		return temp;
    }

	// these should be able to handle both:
	//		div1: (a+bi)/(c+di) = (a*c + b*d)/(c*c + d*d) + (b*c-a*d)/(c*c-d*d)*i 
	//		div2: (a+bi)/B = (a/B + b/B*i)
}
 
//added in, magnitude operator of a floating point value
//abs & operator << ( const Complex & rhs ){

float Complex::magnitude () {
	//z = z*z + c
	// The function used to calculate the fractal
	
	return sqrt( r * r + i * i );	//square root of real x real + imaginary x imaginary
	
//	//this is handled in pixelvalue function already created by prof
//	double Rfactor = (xMax-xMin)/(IMAGE_WIDTH-1);		//real factor
//	double Ifactor = (yMax-ymin)/(IMAGE_HEIGHT-1);		//imaginary factor
//	double cI = yMax - IMAGE_HEIGHT*Ifactor;			//complex imaginary
//    double cR = xMin + IMAGE_WIDTH*Rfactor;				//complex real
//
//	double Zr2 = rhs.r * rhs.r; 	//doubled real complex
//	double Zi2 = rhs.i * rhs.i;		//doubled imaginary complex
//	
//	//	auto func = [] (Complex z, Complex c) -> Complex {return z * z + c; };
//	Complex temp;
//	temp.r = Zr2 - Zi2 + cR;
//	temp.i = 2*cR*cI + cI;
//        return temp;
}
    
////	Complex scale(window<int> &scr, window<double> &fr, Complex c) {
////	Complex temp;
////		c.real() / (double)scr.width() * fr.width() + fr.x_min(),
////		c.imag() / (double)scr.height() * fr.height() + fr.y_min());
////	return temp;
//}
//	temp.r =
//	temp.i =
//	return temp;
//    


ostream & operator << ( ostream & lhs, const Complex & rhs ) {
    lhs << rhs.r << '+' << rhs.i << 'i';
    return lhs;
}

Complex operator + ( double lhs, const Complex & rhs ){		//addition- Prof Black already gave us this in skeleton mode
	return rhs; //return right hand side (imaginary)
}

Complex operator + ( Complex & lhs, const double rhs ) {	//addition- Prof Black already gave us this in skeleton mode
    Complex temp;
    return temp; //return left hand side (real)
}

