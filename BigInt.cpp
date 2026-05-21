#include "BigInt.h"
#include <fstream>
#include <algorithm>


BigInt::BigInt() {
    digits.push_back(0);
}

BigInt::BigInt(long long number) {
    if (number == 0) digits.push_back(0);
    while (number > 0) {
        digits.push_back(number % 10);
        number /= 10;
    }
}

BigInt::BigInt(const std::string& str) {
    for (int i = str.length() - 1; i >= 0; --i) {
        digits.push_back(str[i] - '0'); 
    }
}


BigInt::BigInt(const BigInt& other) {
    this->digits = other.digits;
}


BigInt& BigInt::operator=(const BigInt& other) {
    if (this != &other) {
        this->digits = other.digits;
    }
    return *this;
}

int BigInt::operator[](size_t index) const {
    if (index >= digits.size()) return 0;
    return digits[index];
}


int& BigInt::operator()(size_t index) {
    if (index >= digits.size()) {
        digits.resize(index + 1, 0);
    }
    return digits[index];
}

BigInt* BigInt::operator->() {
    return this;
}


BigInt BigInt::operator+(const BigInt& other) const {
    BigInt result;
    result.digits.clear();
    int carry = 0; 
    size_t maxSize = std::max(digits.size(), other.digits.size());

    for (size_t i = 0; i < maxSize || carry; ++i) {
        int sum = carry;
        if (i < digits.size()) sum += digits[i];
        if (i < other.digits.size()) sum += other.digits[i];
        result.digits.push_back(sum % 10);
        carry = sum / 10;
    }
    return result;
}


BigInt BigInt::operator*(const BigInt& other) const {
    BigInt result;
    result.digits.resize(digits.size() + other.digits.size(), 0);

    for (size_t i = 0; i < digits.size(); ++i) {
        int carry = 0;
        for (size_t j = 0; j < other.digits.size() || carry; ++j) {
            long long cur = result.digits[i + j] + digits[i] * 1LL * (j < other.digits.size() ? other.digits[j] : 0) + carry;
            result.digits[i + j] = cur % 10;
            carry = cur / 10;
        }
    }
    
    while (result.digits.size() > 1 && result.digits.back() == 0) {
        result.digits.pop_back();
    }
    return result;
}


void BigInt::print() const {
    for (int i = digits.size() - 1; i >= 0; --i) {
        std::cout << digits[i];
    }
}
void BigInt::saveToFile(const std::string& filename) const {
    std::ofstream out(filename);
    if (out.is_open()) {
        out << *this; 
        out.close();
    }
}


void BigInt::loadFromFile(const std::string& filename) {
    std::ifstream in(filename);
    if (in.is_open()) {
        in >> *this; 
        in.close();
    }
}

std::ostream& operator<<(std::ostream& out, const BigInt& number) {
    for (int i = number.digits.size() - 1; i >= 0; --i) {
        out << number.digits[i];
    }
    return out;
}

std::istream& operator>>(std::istream& in, BigInt& number) {
    std::string s;
    in >> s;
    number = BigInt(s);
    return in;
}