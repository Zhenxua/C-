#include <iostream>

class Rat {
private:
    int num_;
    int den_;

public:
    Rat(int numerator = 0, int denominator = 1);
    void display() const;
    int get_num() const;
    int get_den() const;

    Rat& operator+=(const Rat& other);
    Rat& operator+=(int integer);

    Rat& operator-=(const Rat& other);
    Rat& operator-=(int integer);

    Rat& operator*=(const Rat& other);
    Rat& operator*=(int integer);

    Rat& operator/=(const Rat& other);
    Rat& operator/=(int integer);

    bool operator==(const Rat& other) const;
    bool operator!=(const Rat& other) const;
    bool operator<(const Rat& other) const;
    bool operator<=(const Rat& other) const;
    bool operator>(const Rat& other) const;
    bool operator>=(const Rat& other) const;

private:

    int gcd(int a, int b) const;
};

    std::ostream& operator<<(std::ostream& os, const Rat& rat);
    Rat operator+(const Rat& r1, const Rat& r2);
    Rat operator+(const Rat& r, int integer);
    Rat operator+(int integer, const Rat& r);
    Rat operator-(const Rat& r1, const Rat& r2);
    Rat operator-(const Rat& r, int integer);
    Rat operator-(int integer, const Rat& r);
    Rat operator*(const Rat& lhs, const Rat& rhs);
    Rat operator*(const Rat& lhs, int value);
    Rat operator/(const Rat& lhs, const Rat& rhs);
    Rat operator/(const Rat& lhs, int value);








