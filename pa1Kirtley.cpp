/*
 * ============================================================================
 *               Name: pa1Kirtley.cpp
 *             Author: Ben Kirtley
 *       installation: James Madison University
 *       Date Written: May 20, 2014
 *        Description: CS350 PA#1 - Convert a positional notation between
 *                     2 thru 16 to decimal with Base 10.
 *  ===========================================================================
 */

#include "pa1Kirtley.h"
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

/*
 *        purpose: Validates user input.
 *     parameters: r - The radix.
 *                 n - The length of the number.
 *                 d - The number in a char array.
 *         return: errorCode - negative if error occurred.
 *  preconditions: NA
 * postconditions: All user input is within bounds.
 *
 */
int
Converter::validation(int r, unsigned int n, char d[])
{
  int errorCode = 1;  //Status OK.
  string str = d;     //Convert d to string for length comparison.
  unsigned length = str.length();

  //Radix validation.
  if (r < 2 || r > 16)
    return errorCode = -2;

  //Length validation.
  if (length != n || n < 1 || n > 16)
    return errorCode = -3;

  //Input validation for hexadecimal input.
  if(r == 16)
    {
      char alpha[22] = {'0','1','2','3','4','5','6','7','8','9','A','B','C',
                       'D','E','F','a','b','c','d','e','f'};
      bool found = false;

      for (unsigned int i = 0; i < length; i++)
        {
          found = false;

          for(int j = 0; j < 22; j++)
            {
              if(d[i] == alpha[j])
                {
                  found = true;
                  break;
                }
            }

          if(!found)
            return errorCode = -4;
        }

        return errorCode;
  }
else
  {
    //Input validation for radix 1 thru 15
    for (unsigned int i = 0; i < length; i++)
         {
            if((int)d[i] < 48 || (int)d[i] > (r-1) + '0')
              {
              return errorCode = -4;
              }
         }
  }

  return errorCode;
}

/*
 *        purpose: Converts number to decimal base 10.
 *     parameters: r - The radix.
 *                 n - The length of the number.
 *                 d - The number in a char array.
 *         return: number - The converted number.
 *  preconditions: NA
 * postconditions: Converts the number to Base 10. Returns number.
 *
 */
int
Converter::toDecimal(int r, int n, char d[])
{
  int summation = 0;  //Accumulator.
  int power = 0;      //Power of position in base.

  if(r == 16)
    {
      char alpha[22] = {'0','1','2','3','4','5','6','7','8','9','A','B','C',
                       'D','E','F','a','b','c','d','e','f'};

      int numeric[22] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,10,11,12,13,
                        14,15};

      for (int i = n - 1; i >= 0; i--)
        {
          for(int j = 0; j < 22; j++)
            {
              if(d[i] == alpha[j])
                {
                  summation += numeric[j] * pow(r,power);
                  power++;

                }
            }
        }
    }
  else
    {
      //Summation of (powers starting at zero times digit value).
      for (int i = n - 1; i >= 0; i--)
        {
          summation += (static_cast<int>(d[i]) - '0') * pow(r, power);
          power++;
        }
    }

  return summation;
}
