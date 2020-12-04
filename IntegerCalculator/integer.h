/*integer.h*/

//
// An Integer class for adding and shifting integers of unlimited
// digits.  Each integer is stored as a linked-list of individual
// digits.
//
// Initially by: Prof. Hummel, U. of Illinois Chicago, Fall 2020
// Project 06
//

#pragma once

#include <iostream>
#include <string>
#include <exception>
#include <stdexcept>

using namespace std;


class Integer
{
private:

   //
   // Data members:
   //
	struct Node
	{
		int Value;
		Node* Next;
		Node* Prev;
	};

	Node *h;


   //
   // Private function members:
   //


public:   
   //
   // default constructor
   //
   // Constructs an integer object and initializes to the value 0.
   // This function is called automatically when an integer is 
   // constructed; do not call this function directly.
   //
   // pre-condition: an invalid integer object.
   // post-condition: a properly initialized integer set to 0.
   // exception: none.
   //
   Integer()
   {
	   h = (Node*)malloc(sizeof(Node));
	   h->Prev = NULL;
	   h->Next = NULL;
	   h->Value = 0;
   }

   //
   // constructor:
   //
   // Constructs this integer based on the digits from the given 
   // integer string; throws an exception if s is not an integer
   // strnig.  This function is called automatically when an integer
   // is constructed; do not call this function directly.
   //
   // Example:
   //   if s = "1234" => integer is 1234
   //   if s = "oops" => integer is 0 and throws an exception
   //
   // pre-condition: an invalid integer object.
   // post-condition: a properly initialized integer object that has
   //   the same integer value as implied by the string.
   // exception: throws invalid_argument if the string is empty or 
   //   non-numeric, with integer initialized to 0.
   //
   Integer(string s)
   {
	   h = NULL;
	   Node *cur = NULL;
	   for (int i = s.size() - 1; i >= 0; i--) {
		   Node *d = (Node*)malloc(sizeof(Node));
		   d->Prev = cur;
		   d->Next = NULL;		   
		   d->Value = s[i] - '0';

		   if( cur == NULL )
			   cur = d;
		   else
			   cur->Next = d;

		   cur = d;

		   if( h == NULL )
				h = d;		   
	   }
   }

   //
   // copy constructor
   //
   // Constructs this integer via a deep-copy of the other integer.  
   // This function is called automatically when an integer is 
   // constructed; do not call this function directly.
   //
   // pre-condition: an invalid integer object.
   // post-condition: a properly initialized integer object that has
   //   the same integer value as the other integer.
   // exception: none.
   //
   Integer(const Integer& other)
   {
   }

   //
   // destructor
   //
   // Frees the resources associated with this integer.  This function
   // is called automatically when an integer is being destroyed; 
   // do not call this function directly.
   //
   // pre-condition: properly initialized integer objects.
   // post-condition: an invalid integer object.
   // exception: none.
   //
   ~Integer()
   {
	   Node *cur = h;
	   while(cur != NULL)
	   {
		   Node *next = cur->Next;
		   free(cur);
		   cur = next;
	   }
   }

   //
   // operator=
   //
   // Performs a proper C++ assignment of the other integer into
   // this integer.  This implies the existing integer is freed,
   // and then a deep-copy of the other integer is made.  This
   // function is called automatically as part of an assignment
   // operation involving integer objects; do not call this function
   // directly.
   //
   // pre-condition: properly initialized integer objects.
   // post-condition: this integer is a deep-copy of the other integer.
   // exception: none.
   //
   Integer& operator=(const Integer& other)
   {
      if (this == &other)  // special case: check for i = i;
         return *this;     // do nothing and just return THIS object back


      //
      // TODO: free existing integer, then make a deep copy of other
      //


      return *this;  // done, return THIS object back
   }

   //
   // toRawStr
   //
   // Converts this integer to a string, with no leading zeros.
   // The string is returned.
   //
   // Example:
   //   if i = 123456 => returns "123456"
   //   if i = 0 => return "0"
   //
   // pre-condition: a properly initialized integer object.
   // post-condition: integer string is returned with no leading zeros.
   // exception: none.
   //
   string toRawStr()
   {
	   Node *cur = h;
	   string ret = "";
	   while(cur != NULL)
	   {
		   Node *next = cur->Next;

		   string d = std::to_string((unsigned long long)cur->Value);
		   ret = d + ret;

		   cur = next;
	   }

		return ret;
   }

   //
   // toStr()
   //
   // Converts this integer to a string with USA-style commas
   // inserted at every thousandth location, with no leading 
   // zeros.  The string is returned.
   //
   // Example:
   //   if i = 123456 => returns "123,456"
   //   if i = 789 => returns "789"
   //   if i = 0 => return "0"
   //
   // pre-condition: a properly initialized integer object.
   // post-condition: USA-style integer string is returned, with
   //   no leading zeros.
   // exception: none.
   //
   string toStr()
   {
      return "";
   }

   //
   // add
   //
   // Adds the other integer to this integer, in effect computing
   // this += other.  Nothing is returned, the integer is internally
   // updated.
   //
   // pre-condition: properly initialized integer objects.
   // post-condition: this integer increased by other integer.
   // exception: none.
   //
   void add(const Integer& other)
   {
   }

   //
   // shift_left
   //
   // Shifts the integer digits left by the given amount N,
   // in effect multiplying the integer by 10^N.  If the integer
   // is 0, then the result remains 0.  Nothing is returned, 
   // the integer is internally updated.
   //
   // Example: 
   //   if i = 1234 then shift_left(i, 2) => 123400
   //   if i = 0 then shift_left(i, x) => 0
   //
   // pre-condition: a properly initialized integer object.
   // post-condition: if non-zero to start, the integer has 
   //   N lower-order 0's added.
   // exception: throws invalid_argument if N < 0.
   //
   void shift_left(int N)
   {
   }

   //
   // shift_right
   //
   // Shifts the integer digits right by the given amount N,
   // in effect dividing the integer by 10^N.  If the integer
   // contains <= N digits, then the integer is shifted right
   // until 1 digit remains.  Nothing is returned, the integer
   // is internally updated.
   //
   // Example: 
   //   if i = 1234 then shift_right(i, 2) => 12
   //   if i = 1234 then shift_right(i, 4) => 1
   //   if i = 0 then shift_right(i, x) => 0
   //
   // pre-condition: a properly initialized integer object.
   // post-condition: if non-zero to start, the integer has 
   //   N lower-order digits removed.
   // exception: throws invalid_argument if N < 0.
   //
   void shift_right(int N)
   {
   }

};
