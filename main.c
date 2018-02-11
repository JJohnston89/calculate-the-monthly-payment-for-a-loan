/*  This program helps a prospective borrower calculate the monthly payment for a loan.
    The program also prints the amortization table to show the balance of the loan after each monthly payment.
	The program prompts the user for input: principal, interest rate per year, and the number of years.
	  Written by: Joshua Johnston
	  Date: 11/4/2014
*/

#include<stdio.h>
#include<math.h>


//   Function Declarations

void getData(double* principal, int* interest_rate, int* NumYears);

void calculateMonthlyPayment(double principal, int interest_rate, int NumYears, int* NumMonths, 
	                     double* interest_rate_dec, double* monthly_payment);

void print_information(double principal, int interest_rate, double interest_rate_dec, int NumYears, int NumMonths, double monthly_payment);

void print_amortization_table(int months, double old_balance, double monthly_payment, 
	                      double interest_paid, double principal_paid, double new_balance); 
							  

int main(void)
{
	
//  Local Declarations

    int NumYears;              //number of years as an integer
    int NumMonths;             //number of months as an integer
    int interest_rate;         //interest rate per year as an integer
    int months;

    double principal;          //amount of the loan (principal) as a real
    double interest_rate_dec;  //interest rate as a decimal as a real
    double principal_paid;    
    double interest_paid;
    double monthly_payment;
    double old_balance;
    double new_balance;

//  Statements	
	
    getData(&principal, &interest_rate, &NumYears);	
	
    calculateMonthlyPayment(principal, interest_rate, NumYears, &NumMonths, 
	                    &interest_rate_dec, &monthly_payment);
	
    printf("\n");
	
    print_information( principal, interest_rate, interest_rate_dec, NumYears,  NumMonths, monthly_payment);
	

    printf("  Month      Old        Monthly      Interest     Principal      New\n");
    printf("           Balance      Payment        Paid         Paid       Balance\n\n");
		 
		 
		 
     for ( old_balance = principal , months = 1; months <= NumMonths; months++)
         {
			
            interest_paid = (old_balance * interest_rate_dec);
	    principal_paid = (monthly_payment - interest_paid);	
	    new_balance = (old_balance - principal_paid);

	     print_amortization_table( months, old_balance, monthly_payment, 
	                               interest_paid, principal_paid, new_balance);	
			  
	     old_balance = new_balance;			 
		
          } //for
	        
		 
     printf("\nTotal amount paid:%12.2lf\n", NumMonths * monthly_payment);

		 
	
     return 0;
} //main

/* ===============================getData===========================================
   This function reads two integers, and one real from the keyboard into variables
   specified in the parameter list.
   Pre: Nothing.
   Post: Data read and placed in calling function.
*/

void getData(double* principal, int* interest_rate, int* NumYears)
{   

//  Statements	

    printf("Amount of the loan (Principal)? ");
    scanf("%lf", principal);
    printf("Interest rate per year (per cent)? ");
    scanf("%d", interest_rate);
    printf("Number of years? ");
    scanf("%d", NumYears);

    return;

} //getData

/* ================================calculateMonthlyPayment=========================================
   This function calculates the monthly payment. 
   Pre: principal contains a real value, interest_rate, and NumYears contain an integer value
   Post: Number of years is converted into months, and stored in NumMonths as a integer. Interest rate
         is converted into decimal, and stored in interest_rate_dec as a real. Monthly payment is 
         calculated, and stored to monthly_payment as a real.
*/

void calculateMonthlyPayment(double principal, int interest_rate, int NumYears, int* NumMonths, 
	                     double* interest_rate_dec, double* monthly_payment)
{

//  Local Declarations
	
    double p_value;
    double q_value;	
	
//  Statements

    *NumMonths = (NumYears * 12);
    *interest_rate_dec = (((double)interest_rate / 12) / 100);
    p_value =pow((1 + *interest_rate_dec), *NumMonths);
    q_value = (p_value / (p_value - 1));
    *monthly_payment = (principal * *interest_rate_dec * q_value);
		
    return;

} //calculateMonthlyPayment

/* ===================================================print_information===================================================================
   This function prints the user's information: principal, interest rate as a percent, interest rate as a decimal, number of years,
   number of months, and monthly payments.
   Pre: interest_rate, NumYears, and NumMonths contain an integer value. principal, interest_rate_dec, and monthly_payment 
        contain a real value.
   Post: prints
*/

void print_information(double principal, int interest_rate, double interest_rate_dec, int NumYears, int NumMonths, double monthly_payment)
{

//  Statements

    printf("The amount of the loan (principal):%12.2lf\n", principal);
    printf("Interest rate/year (percent):            %3d\n", interest_rate);
    printf("Interest rate/month (decimal):             %1.7lf\n", interest_rate_dec);
    printf("Number of years:                         %3d\n", NumYears);
    printf("Number of months:                        %3d\n", NumMonths);
    printf("Monthly payment:                   %12.2lf\n\n", monthly_payment);

    return;
} // print_information

/* =======================================print_amortization_table=============================
   This function prints the amortization table.
   Pre: months contain an integer value, and old_balance, new_balance, monthly_payment, interest_paid,
        principal_paid contain real value. 
   Post: prints
*/

void  print_amortization_table(int months, double old_balance, double monthly_payment, 
	                       double interest_paid, double principal_paid, double new_balance) 
							   
{   	

//  Statements

    printf("%3d   %12.2lf %12.2lf %12.2lf %12.2lf %12.2lf\n", months, old_balance, monthly_payment, interest_paid, principal_paid, new_balance);

    return;

} // print_amortization_table
