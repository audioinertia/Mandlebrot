// Mandlebrot.cpp - fractal generator
#include "Mandlebrot.h"
#include "complex.h"
#include <iostream>
using namespace std;

Mandlebrot::Mandlebrot() {		//setting up the default constructor height/width
    IMAGE_WIDTH = 1;
    IMAGE_HEIGHT = 1;
}

void Mandlebrot::init( int w, int h ) {
    max_iterations = 50;
    xMin = -2.5;
    xMax = 2.5;
    yMin = -2.0;
    yMax = 2.0;
    xOff = 0;
    yOff = 0;
    scale = 0.75;
    IMAGE_HEIGHT = h;		//defines variables for function in init taken from default constructor
    IMAGE_WIDTH = w;		// "^"
    pixelHeight = (yMax - yMin ) / IMAGE_HEIGHT;
    pixelWidth = (xMax - xMin ) / IMAGE_WIDTH;
    bitmap = nullptr;
}

void Mandlebrot::update( int dx, int dy, int dn ) {
    xOff = xOff + dx;
    yOff = yOff + dy;
    max_iterations = max_iterations + dn;
    if( max_iterations < 10 ) max_iterations = 10;
    cout << "xOff = " << xOff << " yOff = " << yOff << " iters = " << max_iterations << endl;
}

int Mandlebrot::pixelValue( double x, double y ) {
    double zmag;
    Complex z, c;
    z = Complex( x, y );
    c = Complex( x, y );
    z = z * z + c;
    zmag = z.magnitude(); 	//changed to abs
    int i = 0;
    for( i = 0; i < max_iterations; i++ ) {
        if( zmag > 2.0 ) {
            break;
        }
        z = z * z + c;
        zmag = z.magnitude();	//changed to abs
    }
    return i;
}

void Mandlebrot:: initBitmap() {
    // create bitmap buffer for this window size
    if( bitmap )
        free( bitmap );
    bitmap = (unsigned char *) malloc( IMAGE_WIDTH * IMAGE_HEIGHT * 4 );
}

unsigned char * Mandlebrot::generate( void ) {
    double mx, my;
    // generate the image
    initBitmap();

    int offset = 0;
    for( int y = 0; y < IMAGE_HEIGHT; y++ )
        for( int x = 0; x < IMAGE_WIDTH; x++ ) {

            // calculate image coordinate
            mx = xMin + x * pixelWidth + xOff;
            my = yMin + y * pixelHeight + yOff;

            // scale image
            mx *= scale;
            my *= scale;

            int fv = pixelValue( mx, my );
            
            // generate color
            int red = 255 * fv / max_iterations;
            if( red > 255) red = 255 - red;

            int green = 255 * fv * 4 / max_iterations;
            if( green > 255) green = 255 - green;
    
            int blue = 255 * fv * 20 / max_iterations;
            if( blue > 255) blue = 255 - blue;
            
            // load into bitmap
            bitmap[offset + 0] = red;
            bitmap[offset + 1] = green;
            bitmap[offset + 2] = blue;
            bitmap[offset + 3] = 255;
            offset = offset + 4;
        }
    return bitmap;
}
