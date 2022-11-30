#include <iostream>
using namespace std;

#ifndef MONEY_HPP__
#define MONEY_HPP__

class Money{
    private:
        int dollars;
        int cents;
    public:
        typedef int64_t Int;
        class InvalidDecimalNumber : std::runtime_error{
            public:
                InvalidDecimalNumber(const std::string &msg) : std::runtime_error(msg) {}
        };
        class CapacityOverflow : std::runtime_error{
            public:
                CapacityOverflow(const std::string &msg) : std::runtime_error(msg) {}
        };

        Money operator+(const Money &m) const{
            Money mx;
            mx.dollars = this->dollars + m.dollars;
            mx.cents = this->cents + m.cents;
            return (mx);
        }
        Money operator-(const Money &m) const{
            Money mx;
            mx.dollars = this->dollars - m.dollars;
            mx.cents = this->cents - m.cents;
            return (mx);
        }
        Money operator*(double val) const{
            Money mx;
            mx.dollars = this->dollars * val;
            mx.cents = this->cents * val;
            return (mx);
        }
        Money operator/(const Money &m) const{
            Money mx;
            mx.dollars = this->dollars / m.dollars;
            mx.cents = this->cents / m.cents;
            return (mx);
        }

        bool operator==(const Money &m) const{
            if(this->dollars == m.dollars && this->cents == m.cents){
                return 1;
            }
            else {
                return 0;
            }
        }
        bool operator!=(const Money &m) const{
            if(this->dollars == m.dollars && this->cents == m.cents){
                return 1;
            }
            else {
                return 0;
            }
        }
        bool operator>(const Money &m) const{
            if(this->dollars > m.dollars && this->cents > m.cents){
                return 1;
            }
            else {
                return 0;
            }
        }
        bool operator<(const Money &m) const{
            if(this->dollars < m.dollars && this->cents < m.cents){
                return 1;
            }
            else {
                return 0;
            }
        }
        bool operator>=(const Money &m) const{
            if(this->dollars >= m.dollars && this->cents >= m.cents){
                return 1;
            }
            else {
                return 0;
            }
        }
        bool operator<=(const Money &m) const{
            if(this->dollars <= m.dollars && this->cents <= m.cents){
                return 1;
            }
            else {
                return 0;
            }
        }

        Money &operator+=(const Money &m){
            this->dollars = this->dollars + m.dollars;
            this->cents = this->cents + m.cents;
            return *this;

        }
        Money &operator-=(const Money &m){
            this->dollars = this->dollars - m.dollars;
            this->cents = this->cents - m.cents;
            return *this;
        }
        Money &operator*=(double val){
            this->dollars = this->dollars * val;
            this->cents = this->cents * val;
            return *this;
        }
        Money &operator/=(const Money &m){
            this->dollars = this->dollars / m.dollars;
            this->cents = this->cents / m.cents;
            return *this;
        }

        operator bool(void) const;

        Money(void);
        Money(const Money &m);
        ~Money(void);
        friend std::ostream& operator<<(std::ostream& os, const Money& m);

};

#endif