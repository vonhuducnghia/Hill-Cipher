#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <stdexcept>
using namespace std;

typedef  array < array <int, 2>, 2> Matrix;

class HillCipher
{
  HillCipher(){}

  Matrix _km; // key matrix
  Matrix _ikm; // inverted key matrix

public:
  HillCipher(const string & key);

  string encode(const string & plain); // encodes a string, 
                                       // if string length is odd then a 'a' is appended (padding)
  string decode(const string & encoded); // decode a string

private:  
  Matrix _build_key_matrix( const string & key);   // creates the key matrix
  static bool _validate_string( const string & s); // makes sure all characters 
                                                   // are in the 'a'..'z' range
  static int _determinant( const Matrix & m);      // computes the (modulo 26) determinant 
                                                   // of a 2x2 matrix
  static vector <int> _apply_matrix( const Matrix & m, const vector <int> & v); // applies (modulo 26) 
                                                   // the 2x2 matrix to the vector
  static int _mod26(int n); // obtains anumber in the 0..25 range
  static vector<int> _string2vector(const string & s); // converts the input string into a vector of int
  static string _vector2string(const vector<int> & v); // converts the input vector of int into a string
};