/**
 * Contains the main() function
 * @Cody Dronet
 * @since 01-18-18
 * @see Polynomial.h 
 */
#include <iostream>
#include "Polynomial.h"
#include <cstdlib>
#include <chrono>
#include <iomanip>

using namespace std::chrono;

/**
 * Used for generating random doubles in a given range
 *
 * @param fMin Indicates lowest number possible
 * @param fMax Indicates highest number possible
 * @return the value of a random double between fMin and fMax
*/
double fRand(double fMin, double fMax)
{
    double f = (double)rand() / RAND_MAX;
    return fMin + f * (fMax - fMin);
}


int main() {
    //Seeding RNG
    srand(time(NULL));
    
    //Start of part 1
    int deg;
    
    cout<<"Enter the degree of the polynomial->";
    cin>>deg;
    
    //Coff is a temoporary array of coeeficents used in creating a polynomial object
    double *coeff = new double[deg+1];
    cout<<"Enter it's coefficents in order of decending powers->";
    for(int i=0; i<deg+1; i++){
        cin>>coeff[i];
    }

    delete[] coeff;
    
    Polynomial fx(coeff, deg);
    
    cout<<"f(x) = ";
    cout<<fx.str()<<endl;
    
    double x;
    cout<<"Enter the value of x at which the function will be evaluated ->";
    cin>>x;
   
    cout<<"Using Horner's Method f("<<x<<") = "<<fx.hornerEval(x)<<endl;
    cout<<"Using naive Method f("<<x<<") = "<<fx.naiveEval(x)<<endl;
    
    //------------------------------------------Start of Part 2-----------------------------------------
   
    
    //Creation of basic UI for Empirecal Analysis
    cout<<"-------------------------------------------------"<<endl;
    cout<<"-------------------------------------------------"<<endl;
    cout<<"Degree               naive               Horner's"<<endl;
    cout<<"-------------------------------------------------"<<endl;
    
    
    /*LOOP*/
    //1. Allocates array where i is current degree + 1
    //2. Generates random numbers for all coefficints
    //3. Creates a Polynomial object using coeffa as an array of coeffecents and i-1 as the degree
    //4. Sets timer
    //5. Evaluates naive
    //6. Stops timer and outputs it to console
    //7. Steps 4-6 again with Horner's method
    //8. Deallocates coeffa array
    //9. Runs 1-8 10 times
    /*END OF LOOP*/
    
    for(int i=1001; i<=10001; i+= 1000){
        
        cout<<i-1<<right<<setw(22);
        //1. Allocates array of size i to store coefficients
        double* coeffa = new double[i];
        
        //2. Generates Random Numbers for all coefficients
        for(int j=0; j<i; j++){
            coeffa[j] = fRand(0,5);
        }
        
        //2.1 Generates random double to evaluate the function
        x = fRand(.5, 1.2);
        
        //3. Creation of Polynomial object
        Polynomial testx(coeffa, i-1);
        
        //--------------------------Start of naive eval-------------------------------
        //4. Start of timer for naive eval
        auto start1 = high_resolution_clock::now();
        
        //5. Evaluates with naive method
        testx.naiveEval(x);
        
        //6. Stops timer
        auto elapsed1 = high_resolution_clock::now() - start1;
        auto duration1 = duration_cast<nanoseconds>(elapsed1).count();
        
        //7. Outputs to console
        cout<<duration1<<right<<setw(23);
        
        //----------------------End of Naive Eval------------------------------------
        
        
        //----------------------Start of Horner's Eval-------------------------------
        
        //4. Start of timer for Horner's eval
        auto start2 = high_resolution_clock::now();
        
        //5. Evaluates using Horner's method
        testx.hornerEval(x);
        
        //6. Stops timer
        auto elapsed2 = high_resolution_clock::now() - start2;
        auto duration2 = duration_cast<nanoseconds>(elapsed2).count();
        
        //7. Outputs to console
        cout<<duration2<<endl;
        
        //-----------------------End of Horner's Eval----------------------------------
        
        //8. Deallocates coeffa array
        delete[] coeffa;
        
        //9. End of loop
    }
    
    return 0;
}
