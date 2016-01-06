/*
 * ============================================================================
 *               Name: main.cpp
 *             Author: Ben Kirtley
 *       installation: James Madison University
 *       Date Written: May 20, 2014
 *        Description: CS350 PA#1 - Entry point for pa1Kirtley.cpp
 *  ===========================================================================
 */

#include <iostream>
#include "pa1Kirtley.h"

using namespace std;

/*
 *        purpose: This is main.
 *     parameters: Void
 *         return: Status for program exit.
 *  preconditions: NA
 * postconditions: NA
 *
 */
int
main()
{
  int radix;           // The radix of the positional notation system.
  int length;          // The length of the number.
  int base10;          // The Decimal equivalent in Base 10.
  int errorCode = 1;   // error code is less than 0 for error else 1.
  Converter converter; // Object that converts user input.
  char *number;

  cout << "Welcome to Decimal Converter 1.0...\n" << "Enter -1 for radix to exit program."
      << endl;

  while (radix != -1)
    {
      cout << "Please enter a radix:";

      cin >> radix;

      cin.clear();
      cin.ignore(80, '\n');

      if (radix == -1)
        return 0;

      while (radix < 2 || radix > 16)
          {
              cout << "Error: Radix is invalid.\nPlease enter a radix "
                     "between 2 and 16." << endl;

              cout << "Please enter a radix:";

              cin >> radix;

              if (radix == -1)
                 return 0;

              cin.clear();
              cin.ignore(80, '\n');
            }

      cout << "Please enter length of the number:";
      cin >> length;

      if(length > 0 && length < 17)
        {
          number = new char[length];

          cin.clear();
          cin.ignore(80, '\n');
        }
      else
        {
          cin.clear();
          cin.ignore(80, '\n');
        }

      cout << "Please enter the number:";
      cin >> number;

      errorCode = converter.validation(radix, length, number);

      if (errorCode == -2)
        {
          cout << "Error: Radix is invalid.\nPlease enter a radix "
              "between 2 and 16." << endl;
        }
      else if (errorCode == -3)
        {
          cout << "Error: Specified lengths are unequal."
              "\nPlease try again."
              "\nLength is between 0 and 16 digits." << endl;
        }
      else if (errorCode == -4)
        {
          cout << "Error: Number is not within radix bounds."
              "\nPlease enter a correct number." << endl;
        }

      if(errorCode == 1)
        {
          base10 = converter.toDecimal(radix, length, number);

          cout << "Decimal equivalent: "<< base10 << endl;
        }
    }

  //Exit status.
  return 0;
}
