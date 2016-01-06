/*
 * ============================================================================
 *               Name: pa1Kirtley.h
 *             Author: Ben Kirtley
 *       installation: James Madison University
 *       Date Written: May 20, 2014
 *        Description: Header file for pa1Kirtley.cpp
 *  ===========================================================================
 */

#ifndef PA1KIRTLEY_H_
#define PA1KIRTLEY_H_

class Converter
{
public:

  int toDecimal(int r, int n, char d[]);
  //Method to convert a base between 2-16 to  base 10.

  int validation(int, unsigned int, char[]);
  //Validates user input.

};

#endif
