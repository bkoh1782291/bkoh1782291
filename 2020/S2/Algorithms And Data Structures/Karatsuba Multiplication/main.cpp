// PARTNERSHIP WITH Weizhen Fang (a1781116)
// Brian Koh (a1782291)

// C++ implementation of Karatsuba algorithm for string multiplication. 

// the karatsuba's algorithm only needs O(n^log3) bit operation to do the multiplication of two integers, which is better than O(n^2) solutions
// using divide and conquer 

//g++ -o main.out -O2 -Wall main.cpp

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <math.h>

using namespace std;

// Function to make an input large number split to two 'sub' numbers with equal length, a0, a1
string sub(string largeNum, int startP, int endP){

    string subNum = "" ;
    int subSize = largeNum.size();

    if (endP <= startP){
       return 0;
    } else {
        for (int i = startP; i <= endP; i++)
        {
            if (i < subSize)
                subNum = subNum + largeNum[i] ;
        }
    }
    return subNum;
}
// Function to calculate the sum of two integers of bases by using the school method
string school_add(string a, string b, int base){
    
    string result = "";
    int size_a = a.size();
    int size_b = b.size();

    // Adding "0" in front of the number to make the length of two integers equal 
    int difference = abs(size_a - size_b);

    while(difference > 0){

        if(size_a < size_b){
            a = "0" + a;
        } else {
            b = "0" + b;
        }

        difference--;
    }

    // Create three variables for sum operation
    // Current is the current sum of each pair of digits of two number    
    int current = 0;
    int carry = 0;
    int len = 0;

    if(size_a > size_b) {
        len = size_a;
    } else {
        len = size_b;
    }
    
    // for loop to update carries by divide the base 8.
    // find the sum of base B
    for(int i = len-1; i>=0; i--)
    {
        //current value for the result
        current = carry + (a[i] - '0') + (b[i] - '0'); // Add the remaining digits to the carry one by one and store the unit digit.

        carry = current / base;

        current = current % base;

        //easy way to convert integer to char arr
        result = (char)(current + '0') + result;
    }

    // if there is also a carry at last, add 1 at the front of the result.
    if(carry > 0){
        result = (char)(carry + '0') + result;
    }
    return result;
}

string multiply(string num1, string num2, int base) 
{ 
    int len1 = num1.size(); 
    int len2 = num2.size(); 
    if (len1 == 0 || len2 == 0) 
        return "0"; 
  
    vector<int> result(len1 + len2, 0); 
  
    // Position of each index of integer for multiple operation
    int index1 = 0;  
    int index2 = 0;  
      
    // Go from right to left in num1 
    for (int i = len1-1; i >= 0; i--) 
    { 
        int carry = 0; 
    
        // To shift position to left after every 
        // multiplication of a digit in largenum2 
        index2 = 0;  
          
        // Go from right to left in num2              
        for (int j=len2-1; j>=0; j--) 
        {   
            int sum = (num1[i] - '0')*(num2[j] - '0') + result[index1 + index2] + carry; 
  
            // Carry for next iteration 
            carry = sum / base; 
  
            // Store result 
            result[index1 + index2] = sum % base; 
  
            index2++; 
        } 
        // store carry in next cell 
        if (carry > 0){
            result[index1 + index2] += carry; 
        }
        // To shift position to left after every 
        // multiplication of a digit in num1. 
        index1++; 
    } 
  
    // ignore '0's from the right 
    int i = result.size() - 1; 

    while (i >= 0 && result[i] == 0) 
        i--; 
  
    // If all were '0's - means either both or one of num1 or num2 were '0' 
    if (i == -1) 
        return "0"; 
  
    // generate the result string 
    string s_result = ""; 
      
    while (i >= 0)
        s_result = s_result + to_string(result[i--]); 
  
    return s_result; 
} 

string karatsuba(string I1, string I2, int B){
    // length of strings
    int length1 = I1.size();
    int length2 = I2.size();

    // case of base must be between 2 and 10
    while(B < 2 || B > 10){
        return 0;
    }
    // finding the difference between two lengths
    int difference = abs(length1 - length2);
    //Adding "0" in front of the number to make the length of two integers equal
    while(difference > 0){
        if(length1 < length2) {
            I1 = "0" + I1;
        }
        else {
            I2 = "0" + I2;
        }

        difference--;
    }

    string a,b,c,d;

    int maxLen = max(length1, length2); // maximum length

    if(maxLen %2 != 0 && maxLen > 2) // if modulo 2 does not equal to 2
    {
        // split the strings equally
        a = sub(I1, 0, maxLen/2);
        b = sub(I1, maxLen/2+1, maxLen);
        c = sub(I2, 0, maxLen/2);
        d = sub(I2, maxLen/2+1, maxLen);
    }
    else if(maxLen %2 == 0 && maxLen > 2) // if modulo 2 equals to 2
    {
        // split the strings equally
        a = sub(I1, 0, maxLen/2-1);
        b = sub(I1, maxLen/2, maxLen);
        c = sub(I2, 0, maxLen/2-1);
        d = sub(I2, maxLen/2, maxLen);
    }
    // multiply the four numbers based on the karatsuba formula to the products
    // ex. ac = a*c
    string ac = multiply(a, c, B);
    string ad = multiply(a, d, B);
    string bc = multiply(b, c, B);
    string bd = multiply(b, d, B);

    string part1 = ac;
    // adding 0's to the end of the numbers to get the value of a*c + 10^n
    if (maxLen %2 != 0) {
        for (int i = 0; i < maxLen-1; i++){
            part1 = part1 + "0";
        }
    } else {
        for (int i = 0; i < maxLen; i++){
            part1 = part1 + "0";
        }
    }

    string part2 = school_add(ad, bc, B);
    // adding 0's to the end of the numbers to get the value of 10^(n/2) * (a*d+b*c)
    if (maxLen %2 != 0) {
        for (int i = 0; i < (maxLen-1)/2; i++) {
            part2 = part2 + "0";
        }
    } else {
        for (int i = 0; i < maxLen/2; i++)
        {
            part2 = part2 + "0";
        }
    }

    string part3 = bd;

    // ((10^n)*(ac)) + (10^(n/2)*(ad+bc)) = product
    string product = "";
    product = school_add(part1, part2, B);

    // product2 = product + bd
    string product2 = "";
    product2 = school_add(product, part3, B);

    // final result = ((10^n)*(ac)) + (10^(n/2)*(ad+bc)) + bd

    return product2;
}

int main(){

    string in1, in2;
    int base;

    cin >> in1 >> in2 >> base;

    //prevetion of wrong input of B
    while(base < 2 || base > 10){
        return 0;
    }
    
    int length1 = in1.size();
    int length2 = in2.size();
    int lessthan4;
    
    // case if both n is less than 4
    if (length1 < 4 && length2 < 4){
        int a = stoi(in1);
        int b = stoi(in2);
        lessthan4 = a*b;
        cout << school_add(in1, in2, base) << " " << lessthan4 <<endl;
    } else {
        cout << school_add(in1, in2, base) << " " << karatsuba(in1, in2, base) <<endl;
    } 
    
    return 0;
    
}
