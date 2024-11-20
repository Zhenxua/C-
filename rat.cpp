#include "rat.h"
#include <iostream>
#include <numeric>
Rat::Rat(int numerator, int denominator) : num_(numerator), den_(denominator) {
    if (denominator == 0) {
        throw std::invalid_argument("Le dénominateur ne peut pas être nul.");
    }

    if (numerator == 0) {
        num_ = 0;
        den_ = 1;
    } else {

        if (den_ < 0) {
            num_ = -num_;
            den_ = -den_;
        }


    }
}


void Rat::display() const {
    std::cout << num_ << "/" << den_ << std::endl;
}


int Rat::get_num() const {
    return num_;
}


int Rat::get_den() const {
    return den_;
}


Rat& Rat::operator+=(const Rat& other) {
    num_ = num_ * other.den_ + other.num_ * den_;
    den_ *= other.den_;

    return *this;
}

Rat& Rat::operator+=(int integer) {
    num_ += integer * den_;

    return *this;
}

Rat& Rat::operator-=(const Rat& other) {
    num_ = num_ * other.den_ - other.num_ * den_;
    den_ *= other.den_;

    return *this;
}

Rat& Rat::operator-=(int integer) {
    num_ -= integer * den_;

    return *this;
}

Rat& Rat::operator*=(const Rat& other) {
    num_ *= other.num_;
    den_ *= other.den_;

    return *this;
}

Rat& Rat::operator*=(int integer) {
    num_ *= integer;

    return *this;
}


Rat& Rat::operator/=(const Rat& other) {
    if (other.num_ == 0) {
        throw std::invalid_argument("denominateur est 0");
    }
    num_ *= other.den_;
    den_ *= other.num_;

    return *this;
}


Rat& Rat::operator/=(int integer) {
    if (integer == 0) {
        throw std::invalid_argument("denominateur est 0");
    }
    den_ *= integer;

    return *this;
}


bool Rat::operator==(const Rat& other) const {
    return num_ == other.num_ && den_ == other.den_;
}

bool Rat::operator!=(const Rat& other) const {
    return !(*this == other);
}

// 比较运算符重载：<
bool Rat::operator<(const Rat& other) const {
    return num_ * other.den_ < other.num_ * den_;
}

bool Rat::operator<=(const Rat& other) const {
    return *this < other || *this == other;
}

bool Rat::operator>(const Rat& other) const {
    return !(*this <= other);
}

bool Rat::operator>=(const Rat& other) const {
    return !(*this < other);
}


std::ostream& operator<<(std::ostream& os, const Rat& r) {
    if (r.get_den() == 1) {
        os << r.get_num();
    } else {
        os << r.get_num() << "/" << r.get_den();
    }
    return os;
}



