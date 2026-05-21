#ifndef BIGINT_H
#define BIGINT_H

#include <iostream>
#include <vector>
#include <string>

class BigInt {
private:
    std::vector<int> digits; 

public:
    BigInt();                        
    BigInt(long long number);        
    BigInt(const std::string& str);  
    BigInt(const BigInt& other);     

    
    BigInt& operator=(const BigInt& other); 
    int operator[](size_t index) const;       

    int& operator()(size_t index);

   
    BigInt* operator->();

    
    BigInt operator+(const BigInt& other) const; 
    BigInt operator*(const BigInt& other) const; 

    
    void print() const;
    void saveToFile(const std::string& filename) const;
    void loadFromFile(const std::string& filename);

    
    friend std::ostream& operator<<(std::ostream& out, const BigInt& number);
    friend std::istream& operator>>(std::istream& in, BigInt& number);
};

#endif
