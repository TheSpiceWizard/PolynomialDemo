/**
 * Describes a univariate polynomial and basic operations
 * on it.
 * @author Duncan
 * @since 01-11-2018
 */

#ifndef POLYNOMIAL_H
#define	POLYNOMIAL_H

#include <string>
#include <sstream>
using namespace std;

class Polynomial
{
private:
    /**
     * An array of coefficients of this polynomial arranged in order of 
     * descending powers.
     */
    double *coeffs;
	/**
	 * The degree of this polynomial [length of coeffs - 1]
	 */
	int deg;
public:
    /**
     * Creates the polynomial 0.
     */
    Polynomial();
    /**
     * Creates a polynomial with the specified coefficients by allocating the
     * coefficient arrays and then copying the contents of the specified array
     * into it.
     * @param c the coefficients of this polynomial in order of descending powers
     * @param d the degree of this polynomial
     * @throw invalid_argument exception when 
     * 1. d is negative or 
     * 2. c[0] = 0 and d > 0
     */
    Polynomial(double* c, int d) throw (invalid_argument);

    /**
     * (Copy constructor) Creates a copy of the specified polynomial.
     * @param other constant reference to a polynomial
     */	
    Polynomial (const Polynomial& other);
	
    /**
     * (Overloaded copy assignment operator) Assigns one polynomial to the
     * the other so that the two polynomials are equal.
     * @param other constant reference to a polynomial
     * @return a reference to a polynomial that is equal to the specified polynomial
     */		
	Polynomial & operator= (const Polynomial& other);	

    /**
     * (destructor) deallocates the array allocated for the coefficients of this
     * polynomial
     */	 
    ~Polynomial();
    
    /**
     * Evaluates this polynomial at the specified point using the
     * Horner's evaluation method.
     * @param x the point at which this polynomial is to be evaluated
     * @return the value of the polynomial at the specified point
     */
    double hornerEval(double x) const;
    
    /**
     * Evaluates this polynomial at the specified point using a
     * naive evaluation method.
     * @param x the point at which this polynomial is to be evaluated.
     * @return the value of the polynomial at the specified point.
     */
    double naiveEval(double x) const;
    
    /**
     * Gives the degree of this polynomial.
     * @return the degree of this polynomial
     */
    int degree() const;
    
    /**
     * Gives a string representation of this polynomial in descending powers
     * in standard form where zero terms, coeffients 1 and -1, and exponent
     * 1 are not displayed.
     * <pre>
     * Note: Rules for Representing a Polynomial in Normalized Form:
     * 1. If the degree of the polynomial is 0, return the number.
     * 2. Generate the string representation of the highest order term 
     *    without using 1, -1 as a coefficient  or 1 as an exponent.
     * 3. Generate and concatenate the string representations of all other,
     *    but the last two, terms begining from the second highest order term 
     *    without the use of 1 and -1 as coefficients and without concatenating
     *    a zero term.
     * 4. If the degree of the polynomial is greater than 1 and its linear term 
     *    is non-zero, generate and concatenate the linear term but without the 
     *    use of 1 and -1 as its coefficient and 1 as its exponent.
     * 5. Finally, concatenate the constant term, the lowest order term, if it 
     *    is non-zero.	 
     *    eg: [3, 0, -1, 0, 1, 1, 0] -> 3x^6 - x^4 + x^2 + x
     *        [-1, 0, 3, 0, -1, 1] -> -x^5 + 3x^3 - x + 1
     * </pre>
     * @return a string representation of this polynomial
     */
   string str() const;
};
#endif	/* POLYNOMIAL_H */

