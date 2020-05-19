/**
 * Defines the functions of the class Polynomial
 * @Cody Dronet
 * @since 01-18-18
 * @see Polynomial.h
 */


#include "Polynomial.h"

Polynomial::Polynomial(){
    deg = 0;
    coeffs = 0;
}

Polynomial::Polynomial(double* c, int d) throw(std::invalid_argument){
    try{
        if(d < 0 or (c[0] == 0 and d > 0)){
            throw;
        }
    coeffs = new double[d+1];
    deg = d;
    for(int i = 0; i<=d; i++){
        coeffs[i] = c[i];
        }
    }catch(invalid_argument){}
}

Polynomial::Polynomial(const Polynomial &other){
    deg = other.deg;
    coeffs = new double [deg+1];
    for(int i = 0; i<=deg; i++){
        coeffs[i] = other.coeffs[i];
    }
}

Polynomial& Polynomial::operator= (const Polynomial& other){
    Polynomial newItem(other);
    
    return  newItem;
}

Polynomial::~Polynomial(){
    delete[] coeffs;
}

double Polynomial::hornerEval(double x) const{
    double result = coeffs[0];
    
    for(int i = 1; i<=deg; i++){
        result = result*x + coeffs[i];
    }
    
    return result;
}

double Polynomial::naiveEval(double x) const{
    double result = 0;
    
    for(int i=0; i<deg; i++){
        double val = x;
        for(int j=1; j<deg-i; j++){
            val*=x;
        }
        result+=(val*coeffs[i]);
    }
    result+=coeffs[deg];
    
    return result;
}

int Polynomial::degree() const{
    return deg;
}

string Polynomial::str() const{
    stringstream ss;
    if(deg == 0){
        ss<<coeffs[0];
        return ss.str();;
    }
    
    if(deg != 1){
    if(coeffs[0] == 1){ss<<"x^"<<deg<<" ";}
    else if(coeffs[0] == -1){ss<<"-x^"<<deg<<" ";}
    else{ss<<coeffs[0]<<"x^"<<deg<<" ";} //May be redundent
    }
        
        
    for(int i = 1; i<deg-1; i++){
        if(coeffs[i] == 0){}
        
        else if(coeffs[i] == 1){
            ss<<"+ x^"<<deg-i<<" ";
        }
        
        else if(coeffs[i] == -1){
            ss<<"- x^"<<deg-i<<" ";
        }
       
        else if(coeffs[i] > 0){
            ss<<"+ "<<coeffs[i]<<"x^"<<deg-i<<" ";
        }
        
        else{
            ss<<"- "<<coeffs[i] * -1<<"x^"<<deg-i<<" ";
        }
        
    }
    
    
    if(coeffs[deg] == 0){}
    else if(coeffs[deg-1] == -1){
        ss<<"- x ";
    }
    else if(coeffs[deg-1] == 1){
        ss<<"+ x ";
    }
    else if(coeffs[deg-1] > 0){
        ss<<"+ "<<coeffs[deg-1]<<"x ";
    }
    else {
            ss<<"- "<<coeffs[deg-1]*-1<<"x ";
    }
    
    if(coeffs[deg] == 0){}
    else if(coeffs[deg] > 0){
        ss<<"+ "<<coeffs[deg];
    }
    else{
        ss<<"- "<<coeffs[deg];
    }

    return ss.str();
}
