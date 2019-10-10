//
// Created by shira on 10/10/19.
//

#ifndef CPP_FIXED_POINT_SHIRAZALTSMAN_PRICE_H
#define CPP_FIXED_POINT_SHIRAZALTSMAN_PRICE_H

#include "iostream"

class Price {
public:
    Price(int dollar = 0);

    Price(int dollar, int cent);

    Price operator+(Price const &p_other);

    Price operator-(Price const &p_other);

    Price operator*(Price const &p_other);

    Price operator/(Price const &p_other);

    friend std::ostream &operator<<(std::ostream &os, const Price &dt);

    int get_dollars() const;

    int get_cents() const;

    int get_price_in_cent() const;

private:
    int m_price_in_cent;
};

inline Price::Price(int dollar) {
    m_price_in_cent = dollar * 100;
}

inline Price::Price(int dollar, int cent) {
    m_price_in_cent = dollar * 100 + cent;
}

inline int Price::get_dollars() const {
    return (int) m_price_in_cent / 100;
}

inline int Price::get_cents() const {
    return (int) m_price_in_cent % 100;
}

inline std::ostream &operator<<(std::ostream &os, const Price &price) {
    os << price.get_dollars() << '.' << ((price.get_cents() < 0) ? (price.get_cents() * -1) : (price.get_cents()))
       << std::endl;
    return os;
}

inline Price Price::operator+(Price const &p_other) {
    return Price(this->get_dollars() + p_other.get_dollars(), this->get_cents() + p_other.get_cents());
}

inline Price Price::operator-(Price const &p_other) {
    return Price(this->get_dollars() - p_other.get_dollars(), this->get_cents() - p_other.get_cents());
}

inline Price Price::operator*(Price const &p_other) {

    int tmp = this->m_price_in_cent * p_other.get_price_in_cent() / 100;
    return Price(tmp / 100, tmp % 100);
}

inline Price Price::operator/(Price const &p_other) {
    int tmp = (int) (((float) m_price_in_cent / (float) p_other.get_price_in_cent()) * 100);
    return Price(tmp / 100, tmp % 100);
}

inline int Price::get_price_in_cent() const {
    return m_price_in_cent;
}


#endif //CPP_FIXED_POINT_SHIRAZALTSMAN_PRICE_H
