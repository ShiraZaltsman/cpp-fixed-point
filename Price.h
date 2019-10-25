#ifndef CPP_FIXED_POINT_ELANAFELSI_FIXED_POINT_H
#define CPP_FIXED_POINT_ELANAFELSI_FIXED_POINT_H

#include <iostream>
#include <iomanip>

#include "my_math.h"


template<unsigned int SIZE, typename T = int>
class FixedPoint {
public:
    FixedPoint(T integer = 0, int fraction = 0.00);

    FixedPoint(const FixedPoint<SIZE, T> &other);

    FixedPoint &operator=(const FixedPoint<SIZE, T> &other);

    FixedPoint &operator=(const T integer);

    FixedPoint &operator+=(const FixedPoint<SIZE, T> &other);

    /*FixedPoint &operator-=(const FixedPoint<SIZE, T> &other);
    FixedPoint &operator*=(const FixedPoint<SIZE, T> &other);
    FixedPoint &operator/=(const FixedPoint<SIZE, T> &other);
    FixedPoint &operator%=(const FixedPoint<SIZE, T> &other);*/

    FixedPoint &operator++();
    FixedPoint operator-();

    /*FixedPoint& operator--();

    FixedPoint operator++(int);
    FixedPoint operator--(int);

    FixedPoint& operator-();

    double T2double();*/

    unsigned char getPrecision();
    friend std::ostream &operator<<(std::ostream &out, FixedPoint fixedPoint) {
        if (fixedPoint.m_signed)
            out << '-';
        out << +fixedPoint.m_integer << "." << std::setfill('0') << std::setw(SIZE) << fixedPoint.m_fraction << "\n";
        return out;
    }

private:
    T m_integer;
public:
    T getMInteger() const;

    void setMInteger(T mInteger);

    unsigned int getMFraction() const;

    void setMFraction(unsigned int mFraction);

    bool isMSigned() const;

    void setMSigned(bool mSigned);

private:
    unsigned int m_fraction;
    bool m_signed;

};

template<unsigned int SIZE, typename T>
FixedPoint<SIZE, T> operator+(const FixedPoint<SIZE, T> &first, const FixedPoint<SIZE, T> &other);

template<unsigned int SIZE, typename T>
FixedPoint<SIZE, T> operator-(const FixedPoint<SIZE, T> &first, const FixedPoint<SIZE, T> &other);

template<unsigned int SIZE, typename T>
FixedPoint<SIZE, T>::FixedPoint(T integer, int fraction) {
    if (integer < 0) {
        m_signed = true;
        m_integer = integer * -1;
    }
    if (integer >= 0) {
        if (fraction < 0 && integer > 0) {
            throw "ERROR! bad input";
        }
        m_signed = false;
        m_integer = integer;
    }
    if (fraction < 0) {
        m_signed = true;
        m_fraction = fraction * -1;
    } else {
        m_fraction = fraction;
    }

}

template<unsigned int SIZE, typename T>
FixedPoint<SIZE, T> &FixedPoint<SIZE, T>::operator=(const FixedPoint<SIZE, T> &other) {
    if (this != &other) {
        m_integer = other.m_integer;
        m_fraction = other.m_fraction;
        m_signed = other.m_signed;
    }
    return *this;
}

template<unsigned int SIZE, typename T>
FixedPoint<SIZE, T> &FixedPoint<SIZE, T>::operator=(const T integer) {
    if (integer < 0) {
        m_signed = true;
        m_integer = integer * -1;
    }
    if (integer >= 0) {
        m_signed = false;
        m_integer = integer;
    }
    m_fraction = 0;

}

//todo fix +=
template<unsigned int SIZE, typename T>
FixedPoint<SIZE, T> &FixedPoint<SIZE, T>::operator+=(const FixedPoint<SIZE, T> &other)
{
    if(m_signed == other.m_signed)
    {
        //todo if(a>max-b)
        if ((m_fraction + other.m_fraction) >= Power<SIZE>(10)) {
            ++m_integer;
        }
        m_fraction = (other.m_fraction + m_fraction) % Power<SIZE>(10);
        m_integer += other.m_integer;
    }
    else
    {
        if(m_integer < other.m_integer){
            m_signed= !m_signed;
        }


        m_integer = (other.m_integer - m_integer);
        if(m_integer<0){
            m_integer*=-1;
        }

            if ((int)(m_fraction - other.m_fraction) < 0 || (int)( other.m_fraction - this->m_fraction )<0) {
                m_integer--;
            }
            int tmp_fraction = (other.m_fraction -m_fraction);
            if(tmp_fraction<0)
            {
                m_fraction=tmp_fraction*-1;
            }
            else{
                m_fraction=tmp_fraction;
            }

        if(m_integer < 0)
        {
            m_integer = m_integer * -1;
        }
    }
}

template<unsigned int SIZE, typename T>
FixedPoint<SIZE, T> &FixedPoint<SIZE, T>::operator++() {
    m_integer = m_integer + 1;
    return *this;
}

template<unsigned int SIZE, typename T>
inline FixedPoint<SIZE, T> operator+(const FixedPoint<SIZE, T> &first, const FixedPoint<SIZE, T> &other) {
    FixedPoint<SIZE, T> tmp(first);
    tmp+=other;
    return tmp;
}

template<unsigned int SIZE, typename T>
inline FixedPoint<SIZE, T>::FixedPoint(const FixedPoint<SIZE, T> &other) {
    if (this != &other) {
        m_integer = other.m_integer;
        m_fraction = other.m_fraction;
        m_signed = other.m_signed;
    }
}

template<unsigned int SIZE, typename T>
T FixedPoint<SIZE, T>::getMInteger() const {
    return m_integer;
}

template<unsigned int SIZE, typename T>
void FixedPoint<SIZE, T>::setMInteger(T mInteger) {
    m_integer = mInteger;
}

template<unsigned int SIZE, typename T>
unsigned int FixedPoint<SIZE, T>::getMFraction() const {
    return m_fraction;
}

template<unsigned int SIZE, typename T>
void FixedPoint<SIZE, T>::setMFraction(unsigned int mFraction) {
    m_fraction = mFraction;
}

template<unsigned int SIZE, typename T>
bool FixedPoint<SIZE, T>::isMSigned() const {
    return m_signed;
}

template<unsigned int SIZE, typename T>
void FixedPoint<SIZE, T>::setMSigned(bool mSigned) {
    m_signed = mSigned;
}

template<unsigned int SIZE, typename T>
inline unsigned char FixedPoint<SIZE, T>::getPrecision() {
    return (unsigned char)SIZE;
}

template<unsigned int SIZE, typename T>
FixedPoint<SIZE,T> FixedPoint<SIZE, T>::operator-() {
    FixedPoint tmp(*this);
    tmp.setMSigned(!tmp.isMSigned());
    return tmp;
}

template<unsigned int SIZE, typename T>
inline FixedPoint<SIZE, T> operator-(const FixedPoint<SIZE, T> &first, const FixedPoint<SIZE, T> &other) {
    FixedPoint<SIZE, T> tmp(first);

    tmp.setMSigned(!tmp.isMSigned());
    tmp+=other;
    tmp.setMSigned (!tmp.isMSigned());

    return tmp;
}


#endif //CPP_FIXED_POINT_ELANAFELSI_FIXED_POINT_H
