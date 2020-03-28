#include "rational.h"
#include "gcd.h"

#include <stdexcept>
#include <ostream>
#include <iostream>

const Rational Rational::inverse() const {
  return Rational{ _den, _num};
}

Rational::sign_type Rational::sign() const {
  return _num>=0 ? POSITIVE : NEGATIVE;
}

/* Print the value num/den to the supplied output stream, or 0 if 
 * the Rational happens to be identically zero.
 */
std::ostream& operator<<( std::ostream &os, const Rational &ratio ) {
  if( ratio == 0 ) {
    os << "0";
  } else {
    if( ratio.sign() == Rational::NEGATIVE ) {
      os << "-";
    }
    os << std::abs( ratio.num() ) << "/" << std::abs( ratio.den() );
  }
  return os;
}

/* This function will be called whenever the 
 * Rational is constructed from integers that
 * are supplied as numerator and denominator.
 * It should reduce the fraction to lowest terms;
 * for example, when we try to construct a
 * Rational{ 4, -8 }, this is the function that
 * will cause the number to be exactly the same
 * as Rational{ -1, 2 }. Numerators should be
 * the only value potentially negative after
 * the call to ::normalize().
 * Throw bad_rational if there is an attempt
 * to set one with a zero denominator.
 */
void Rational::normalize() {
  // You should implement
  if( _den == 0)
  {
    throw bad_rational();
  }

  if( _num == 0)
  {
    _den=1;  
    return;
  }

  auto g = gcd( std::abs(_num),std::abs(_num));
  _num /=g; 
  _den /=g;

  if( _den<0 )
  {
    _den = -_den;
    _num = -_num;
  }
}

// Return the float precision number corresponding to the Rational
float Rational::to_float() const {
  // You should implement
  return static_cast<float>( _num ) / static_cast<float>( _den );
}

// Return the double precision number corresponding to the Rational
double Rational::to_double() const {
  // You should implement
  return static_cast<double>( _num ) / static_cast<float>( _den );
}
