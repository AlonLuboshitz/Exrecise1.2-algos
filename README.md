# Exrecise1.2-algos
 
**Compilation & Running**
in order to compile and run the code you need to enter the following:
1. $ git clone "https://github.com/AlonLuboshitz/Exrecise1.2-algos.git"
2. enter username "your username"
3. enter password "your password"
4. after project have been colned enter the following:
5. cd Exrecise1.2-algos/
6. g++ -std=c++11 *.cpp ,ENTER
7. ./a.out , ENTER - command which will run the code.
8. enter first vector (each number seperated by a space), ENTER
9. enter second vector (each number seperated by a space), ENTER


**Code discription**
This code takes two vecotrs from the user input and calculates thier distance from each other using five diffrenet algorithems as desrcibed below.
in order to have independant functionality and generalized implementation, we divided the code into three main sections:
1. validation of user input.
2. function calculating each algo.
3. additional functions to apply universal vector manipulations needed for all of the algorithems.
a key concepte to separate the deduction of two vectors from the algorithems.

**validation**
threefunctions - 1. streaming a string, dividing between spaces.
                 2. converting each string seperated by a space into a double variable (if valid).
                 3. checking if the vecors are the same size
                
**algorithems functionality**
key variables: Two const double vectors.
               one Vector which stands for the deduction of one from the second, (used in all of the algorithems). 
               m_diff vector -> each i place holds v1[i]-v2[i] 
algorithems: (psodue code)
1. euclidian() - sqrt(sum((v1[i]-v2[i])^2))
2. manhatan() - sum(|v1[i]-v2[i]|)
3. minkovsky(p) - (sum(|v1[i]-v2[i]|^p))^(1/p)
              p - set to be 2 -> returns euclidian distance.
4. Canberra() - sum(|v1[i]-v2[i]|/(|v1[i]| + |v2[i]|))
5. Cevichev() - max(|v1[i]-v2[i]|)

**Manipulation on vectors**
dudction- function to calculate m_diff key variable of the algorithems functionality.
sum- sums up all of the vector's values
print vec- prints all of the vector's values in their order





