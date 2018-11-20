//
// Created by alian on 11/19/18.
//

#ifndef EXCELLENTEAM_ELLA_CPP_FIXEDPOINT_WALL_ET_FIXEDPOINT_H
#define EXCELLENTEAM_ELLA_CPP_FIXEDPOINT_WALL_ET_FIXEDPOINT_H


#include <ostream>

template<unsigned int SIZE, typename T = int>
class FixedPoint {


public:
    /*explicit FixedPoint(int dollars = 0);*/
    static typename T::theType theType;

    FixedPoint(T dollars = 0, T cents = 0);

    const FixedPoint operator+(const FixedPoint &);

    const FixedPoint operator-(const FixedPoint &);

    const FixedPoint operator*(const FixedPoint &);

    const FixedPoint operator/(const FixedPoint &);

    const FixedPoint operator%(const FixedPoint &);

    FixedPoint &operator+=(const FixedPoint &);

    FixedPoint &operator-=(const FixedPoint &);

    FixedPoint &operator*=(const FixedPoint &);

    FixedPoint &operator/=(const FixedPoint &);

    FixedPoint &operator%=(const FixedPoint &);

    FixedPoint operator-();

    FixedPoint &operator--(); //prefix

    const FixedPoint operator--(int); //postfix

    FixedPoint &operator++(); //prefix

    const FixedPoint operator++(int); //postfix

    bool operator==(const FixedPoint &) const;

    bool operator!=(const FixedPoint &) const;

    bool operator<=(const FixedPoint &) const;

    bool operator>=(const FixedPoint &) const;

    bool operator<(const FixedPoint &) const;

    bool operator>(const FixedPoint &) const;

    operator double();

    friend std::ostream &operator<<(std::ostream &os, const FixedPoint<SIZE,T> &p) {
        os << std::endl << "FixedPoint is: " << p.m_units / p.SINGLE_DOLLAR_VALUE << "."
           << p.m_units % p.SINGLE_DOLLAR_VALUE
           << std::endl;
        return os;

    };
private:
    const T SINGLE_DOLLAR_VALUE;

    T m_units;

    int power1(int x, unsigned int y) {
        if (y == 0)
            return 1;
        else if ((y % 2) == 0)
            return power1(x, y / 2) * power1(x, y / 2);
        else
            return x * power1(x, y / 2) * power1(x, y / 2);

    }

};

template<unsigned int SIZE, class T>
inline FixedPoint<SIZE, T>::FixedPoint(T dollars, T cents) : SINGLE_DOLLAR_VALUE(power1(10,SIZE)){
    m_units = dollars * SINGLE_DOLLAR_VALUE + cents;
}

template<unsigned int SIZE, class T>
inline bool FixedPoint<SIZE, T>::operator==(const FixedPoint<SIZE, T> &other) const {
    return m_units == other.m_units;
}

template<unsigned int SIZE, class T>
inline bool FixedPoint<SIZE, T>::operator!=(const FixedPoint<SIZE, T> &other) const {
    return m_units == other.m_units;
}

template<unsigned int SIZE, class T>
inline bool FixedPoint<SIZE, T>::operator<=(const FixedPoint<SIZE, T> &other) const {
    return m_units <= other.m_units;
}

template<unsigned int SIZE, class T>
inline bool FixedPoint<SIZE, T>::operator>=(const FixedPoint<SIZE, T> &other) const {
    return m_units >= other.m_units;
}

template<unsigned int SIZE, class T>
inline bool FixedPoint<SIZE, T>::operator<(const FixedPoint<SIZE, T> &other) const {
    return m_units < other.m_units;
}

template<unsigned int SIZE, class T>
inline bool FixedPoint<SIZE, T>::operator>(const FixedPoint<SIZE, T> &other) const {
    return m_units > other.m_units;
}

template<unsigned int SIZE, class T>
inline const FixedPoint<SIZE, T> FixedPoint<SIZE, T>::operator+(const FixedPoint<SIZE, T> &other) {
    int amount = m_units + other.m_units;
    return FixedPoint(amount / SINGLE_DOLLAR_VALUE, amount % SINGLE_DOLLAR_VALUE);
}

template<unsigned int SIZE, class T>
inline const FixedPoint<SIZE, T> FixedPoint<SIZE, T>::operator-(const FixedPoint<SIZE, T> &other) {
    int amount = m_units - other.m_units;
    return FixedPoint(amount / SINGLE_DOLLAR_VALUE, amount % SINGLE_DOLLAR_VALUE);
}

template<unsigned int SIZE, class T>
inline const FixedPoint<SIZE, T> FixedPoint<SIZE, T>::operator*(const FixedPoint<SIZE, T> &other) {
    int amount = (m_units * other.m_units) / SINGLE_DOLLAR_VALUE;
    return FixedPoint(amount / SINGLE_DOLLAR_VALUE, amount % SINGLE_DOLLAR_VALUE);
}

template<unsigned int SIZE, class T>
inline const FixedPoint<SIZE, T> FixedPoint<SIZE, T>::operator/(const FixedPoint<SIZE, T> &other) {
    int amount = (double(m_units) / double(other.m_units)) * SINGLE_DOLLAR_VALUE;
    return FixedPoint(amount / SINGLE_DOLLAR_VALUE, amount % SINGLE_DOLLAR_VALUE);
}

template<unsigned int SIZE, class T>
inline const FixedPoint<SIZE, T> FixedPoint<SIZE, T>::operator%(const FixedPoint<SIZE, T> &other) {
    int amount = (m_units % other.m_units);
    return FixedPoint(amount / SINGLE_DOLLAR_VALUE, amount % SINGLE_DOLLAR_VALUE);
}

template<unsigned int SIZE, class T>
inline FixedPoint<SIZE, T> &FixedPoint<SIZE, T>::operator+=(const FixedPoint<SIZE, T> &other) {
    m_units += other.m_units;
    return *this;
}

template<unsigned int SIZE, class T>
inline FixedPoint<SIZE, T> &FixedPoint<SIZE, T>::operator-=(const FixedPoint<SIZE, T> &other) {
    m_units -= other.m_units;
    return *this;
}

template<unsigned int SIZE, class T>
inline FixedPoint<SIZE, T> &FixedPoint<SIZE, T>::operator*=(const FixedPoint<SIZE, T> &other) {
    m_units *= other.m_units;
    m_units /= SINGLE_DOLLAR_VALUE;
    return *this;
}

template<unsigned int SIZE, class T>
inline FixedPoint<SIZE, T> &FixedPoint<SIZE, T>::operator/=(const FixedPoint<SIZE, T> &other) {
    m_units /= other.m_units;
    m_units *= SINGLE_DOLLAR_VALUE;
    return *this;
}

template<unsigned int SIZE, class T>
inline FixedPoint<SIZE, T> &FixedPoint<SIZE, T>::operator%=(const FixedPoint<SIZE, T> &other) {
    m_units %= other.m_units;
    return *this;
}

template<unsigned int SIZE, class T>
inline FixedPoint<SIZE, T> FixedPoint<SIZE, T>::operator-() {
    return FixedPoint((-m_units) / SINGLE_DOLLAR_VALUE, (-m_units) % SINGLE_DOLLAR_VALUE);
}

template<unsigned int SIZE, class T>
inline FixedPoint<SIZE, T>& FixedPoint<SIZE, T>::operator--() {
    return FixedPoint((m_units - SINGLE_DOLLAR_VALUE) / SINGLE_DOLLAR_VALUE,
                      (m_units - SINGLE_DOLLAR_VALUE) % SINGLE_DOLLAR_VALUE);
}

template<unsigned int SIZE, class T>
inline const FixedPoint<SIZE, T> FixedPoint<SIZE, T>::operator++(int) {
    FixedPoint temp = FixedPoint(*this);
    m_units += SINGLE_DOLLAR_VALUE;
    return temp;
}

template<unsigned int SIZE, class T>
inline FixedPoint<SIZE, T>& FixedPoint<SIZE, T>::operator++() {
    m_units += SINGLE_DOLLAR_VALUE;
    return *this;
}

template<unsigned int SIZE, class T>
const FixedPoint<SIZE, T> FixedPoint<SIZE, T>::operator--(int) {
    FixedPoint temp = FixedPoint(*this);
    m_units -= SINGLE_DOLLAR_VALUE;
    return temp;
}

template<unsigned int SIZE, class T>
FixedPoint<SIZE, T>::operator double()   {

    return m_units / SINGLE_DOLLAR_VALUE;
}




#endif //EXCELLENTEAM_ELLA_CPP_FIXEDPOINT_WALL_ET_FIXEDPOINT_H
