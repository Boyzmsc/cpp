
#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
class myPolynomial;
class myTerm
{
public:
    myTerm(long c = 0, unsigned e = 0);
    // copy constructor
    myTerm(const myTerm &term);
    // overloaded operators
    bool operator==(const myTerm &term) const;
    bool operator!=(const myTerm &term) const;
    bool operator<(const myTerm &term) const;
    myTerm operator-() const;
    // accessor functions
    long getCoeff() const { return coeff; }
    unsigned getExp() const { return exp; }
    // mutator functions
    void setCoeff(long c) { coeff = c; }
    void setExp(unsigned e) { exp = e; }
    // member functions
    myTerm ddx() const; // derivative of a term
    // friend functions and classes
    friend ostream &operator<<(ostream &outStream, const myTerm &term);
    friend myPolynomial;

private:
    long coeff;   // longeger coefficient
    unsigned exp; // exponent (non-negative longeger)
};

// Constructor
myTerm::myTerm(long c, unsigned e) : coeff(c), exp(e)
{
}
// copy constructor
myTerm::myTerm(const myTerm &term) : coeff(term.coeff), exp(term.exp)
{
}
// overloaded operators
bool myTerm::operator==(const myTerm &term) const
{
    return (coeff == term.coeff && exp == term.exp);
}
// overloaded operators
bool myTerm::operator!=(const myTerm &term) const
{
    return !(coeff == term.coeff && exp == term.exp);
}
// overloaded operators
bool myTerm::operator<(const myTerm &term) const
{
    return exp > term.exp;
}
myTerm myTerm::operator-() const
{
    return myTerm(-1 * coeff, exp);
}
// derivative of a term
myTerm myTerm::ddx() const
{
    if (exp == 0)
        return myTerm(0, 0);
    return myTerm(exp * coeff, exp - 1);
}
// output operator
ostream &operator<<(ostream &outStream, const myTerm &term)
{
    if (term.exp == 0)
        if (term.coeff == 0) // nothing to output
            return outStream;
        else
            return outStream << term.coeff;
    if (term.coeff == 1)
        outStream << "x";
    else if (term.coeff == -1)
        outStream << "-x";
    else
        outStream << term.coeff << "x";
    if (term.exp == 1)
        return outStream;
    else
        return outStream << "^" << term.exp;
}

#include <iostream>
#include <list>
using namespace std;
class myPolynomial
{
public:
    myPolynomial(long c = 0, unsigned e = 0);
    myPolynomial(long nTerms, long mono[]);
    // copy constructor
    myPolynomial(const myPolynomial &poly);
    // overloaded operators
    bool operator==(const myPolynomial &poly) const;
    bool operator!=(const myPolynomial &poly) const;
    myPolynomial &operator=(const myPolynomial &poly);
    myPolynomial &operator+=(const myPolynomial &poly);
    myPolynomial &operator-=(const myPolynomial &poly);
    myPolynomial &operator*=(const myPolynomial &poly);
    myPolynomial &operator*=(long k);
    myPolynomial operator-() const;
    myPolynomial operator*(long k) const;
    myPolynomial operator+(const myPolynomial &poly) const;
    myPolynomial operator-(const myPolynomial &poly) const;
    myPolynomial operator*(const myPolynomial &poly) const;
    long operator()(long x) const; // evaluate the polynomial
    long getDegree() const;        // get a degree of the polynomial
    unsigned getNumTerms() const;  // number of terms in the polynomial
    myPolynomial ddx() const;      // derivative of a polynomial
    // friend operators and functions
    friend myPolynomial operator*(long k, const myPolynomial &poly);
    friend ostream &operator<<(ostream &outStream, const myPolynomial &poly);
    static const myPolynomial ZERO; // P(x) = 0
    static const myPolynomial ONE;  // P(x) = 1
    static const myPolynomial X;    // P(x) = x
    myPolynomial sort();

private:
    long degree; // maximum expnent
    vector<myTerm> k;
};

myPolynomial::myPolynomial(long c, unsigned e)
{

    degree = e;
    k.push_back(myTerm(c, e));
}
myPolynomial::myPolynomial(long nTerms, long mono[])
{
    if (nTerms == 1 && (mono[0] == 0 && mono[1] == 0))
    {
        degree = -1;
    }
    else
    {
        for (long i = 1; i <= nTerms * 2 - 1; i += 2)
        {
            k.push_back(myTerm(mono[i - 1], mono[i]));
        }
        *this = this->sort();
        degree = this->k[0].getExp();
    }
}
myPolynomial::myPolynomial(const myPolynomial &poly) : degree(poly.degree), k(poly.k)
{
}
long myPolynomial::getDegree() const
{
    return degree;
}
unsigned myPolynomial::getNumTerms() const
{
    return k.size();
}

myPolynomial myPolynomial::ddx() const
{
    myPolynomial a;
    for (long i = 0; i < k.size(); i++)
    {
        a.k.push_back(myTerm(k[i].ddx().getCoeff(), k[i].ddx().getExp()));
    }
    for (long j = 0; j < a.k.size(); j++)
    {
        if (a.k[j].getCoeff() == 0 && a.k[j].getExp() == 0)
        {
            a.k.erase(a.k.begin() + j);
        }
    }
    return a;
}
myPolynomial myPolynomial::sort()
{
    myPolynomial a;
    myPolynomial poly(*this);

    long max;
    long maxidx;
    for (long i = 0; i < k.size(); i++)
    {
        max = 0;
        maxidx = 0;
        for (long j = 0; j < poly.k.size(); j++)
        {
            if (poly.k[j].getExp() > max)
            {
                max = poly.k[j].getExp();
                maxidx = j;
            }
        }
        a.k.push_back(myTerm(poly.k[maxidx].getCoeff(), poly.k[maxidx].getExp()));
        poly.k.erase(poly.k.begin() + maxidx);
    }
    myPolynomial result(a);
    bool isthere = true;
    while (isthere)
    {
        if (result.k.size() == 1)
        {
            break;
        }
        isthere = false;
        for (long i = 0; i < result.k.size(); i++)
        {
            if (result.k[i].getCoeff() == 0)
            {
                isthere = true;
                result.k.erase(result.k.begin() + i);
                continue;
            }
        }
    }

    return result;
}

myPolynomial myPolynomial::operator+(const myPolynomial &poly) const
{
    myPolynomial sub(*this);
    sub = sub.sort();
    myPolynomial sub_poly(poly);
    sub_poly = sub_poly.sort();
    myPolynomial a;
    for (long i = 0; i < sub.k.size(); i++)
    {
        bool found = false;
        for (long j = 0; j < sub_poly.k.size(); j++)
        {
            if (sub.k[i].getExp() == sub_poly.k[j].getExp())
            {
                found = true;
                a.k.push_back(myTerm(sub.k[i].getCoeff() + sub_poly.k[j].getCoeff(), sub.k[i].getExp()));
                break;
            }
        }
        if (found == false)
        {
            a.k.push_back(myTerm(sub.k[i].getCoeff(), sub.k[i].getExp()));
        }
    }
    for (long i = 0; i < sub_poly.k.size(); i++)
    {
        bool f = false;
        for (long j = 0; j < a.k.size(); j++)
        {
            if (sub_poly.k[i].getExp() == a.k[j].getExp())
            {
                f = true;
                break;
            }
        }
        if (f == false)
        {
            a.k.push_back(myTerm(sub_poly.k[i].getCoeff(), sub_poly.k[i].getExp()));
        }
    }
    return a;
}
myPolynomial myPolynomial::operator-(const myPolynomial &poly) const
{
    myPolynomial sub(*this);
    sub = sub.sort();
    myPolynomial sub_poly(poly);
    sub_poly = sub_poly.sort();
    myPolynomial a;
    for (long i = 0; i < sub.k.size(); i++)
    {
        bool found = false;
        for (long j = 0; j < sub_poly.k.size(); j++)
        {
            if (sub.k[i].getExp() == sub_poly.k[j].getExp())
            {
                found = true;
                a.k.push_back(myTerm(sub.k[i].getCoeff() - sub_poly.k[j].getCoeff(), sub.k[i].getExp()));
                break;
            }
        }
        if (found == false)
        {
            a.k.push_back(myTerm(sub.k[i].getCoeff(), sub.k[i].getExp()));
        }
    }
    for (long i = 0; i < sub_poly.k.size(); i++)
    {
        bool f = false;
        for (long j = 0; j < a.k.size(); j++)
        {
            if (sub_poly.k[i].getExp() == a.k[j].getExp())
            {
                f = true;
                break;
            }
        }
        if (f == false)
        {
            a.k.push_back(myTerm(sub_poly.k[i].getCoeff() * -1, sub_poly.k[i].getExp()));
        }
    }
    return a;
}

myPolynomial myPolynomial::operator*(const myPolynomial &poly) const
{
    myPolynomial a;
    for (long i = 0; i < k.size(); i++)
    {
        for (long j = 0; j < poly.k.size(); j++)
        {
            long c = k[i].getCoeff() * poly.k[j].getCoeff();
            unsigned e = k[i].getExp() + poly.k[j].getExp();
            bool found = false;
            for (long w = 0; w < a.k.size(); w++)
            {
                if (e == a.k[w].getExp())
                {
                    a.k[w].setCoeff(a.k[w].getCoeff() + c);
                    found = true;
                    break;
                }
            }
            if (found == false)
            {
                a.k.push_back(myTerm(c, e));
            }
        }
    }
    return a;
}

// overloaded operators
bool myPolynomial::operator==(const myPolynomial &poly) const
{
    if (k.size() != poly.k.size())
    {
        return false;
    }
    else
    {
        for (long i = 0; i < k.size(); i++)
        {
            if (k[i] != poly.k[i])
            {
                return false;
            }
        }
        return true;
    }
}

bool myPolynomial::operator!=(const myPolynomial &poly) const
{
    return !(*this == poly);
}
myPolynomial &myPolynomial::operator=(const myPolynomial &poly)
{
    this->degree = poly.degree;
    this->k = poly.k;
    return *this;
}
myPolynomial &myPolynomial::operator+=(const myPolynomial &poly)
{
    *this = *this + poly;
    return *this;
}
myPolynomial &myPolynomial::operator-=(const myPolynomial &poly)
{
    *this = *this - poly;
    return *this;
}
myPolynomial &myPolynomial::operator*=(const myPolynomial &poly)
{
    *this = *this * poly;
    return *this;
}
myPolynomial &myPolynomial::operator*=(long k)
{
    *this = *this * k;
    return *this;
}
myPolynomial myPolynomial::operator-() const
{
    myPolynomial a(*this);
    for (long i = 0; i < a.k.size(); i++)
    {
        a.k[i].setCoeff(a.k[i].getCoeff() * -1);
    }
    return a;
}
myPolynomial myPolynomial::operator*(long k) const
{
    myPolynomial a(*this);
    for (long i = 0; i < a.k.size(); i++)
    {
        a.k[i].setCoeff(a.k[i].getCoeff() * k);
    }
    return a;
}

myPolynomial operator*(long k, const myPolynomial &poly)
{
    myPolynomial a(poly);
    for (long i = 0; i < a.k.size(); i++)
    {
        a.k[i].setCoeff(a.k[i].getCoeff() * k);
    }
    return a;
}

long myPolynomial::operator()(long x) const
{
    long result = 0;
    for (long i = 0; i < k.size(); i++)
    {
        result += k[i].getCoeff() * pow(x, k[i].getExp());
    }
    return result;
}

// output operator
ostream &operator<<(ostream &outStream, const myPolynomial &poly)
{
    if (poly == myPolynomial::ZERO)
        return outStream << 0;
    myPolynomial a(poly);
    a = a.sort();
    if (a.k[0].getCoeff() == 0)
    {
        return outStream << 0;
    }
    for (long i = 0; i < a.k.size(); i++)
    {

        if (i == 0)
        {
            outStream << a.k[i];
        }
        else if (a.k[i].getCoeff() > 0)
        {
            outStream << "+";
            outStream << a.k[i];
        }
        else if (a.k[i].getCoeff() < 0)
        {
            outStream << a.k[i];
        }
    }
    /********************* add your code here ********************************/
    return outStream;
}
const myPolynomial myPolynomial::ZERO(0);             // the zero polynomial P(x) = 0
const myPolynomial myPolynomial::ONE(1, (unsigned)0); // the monomial P(x) = 1
const myPolynomial myPolynomial::X(1, 1);             // the monomial P(x) = x

#include <fstream>
#include <cstdlib>
void testSimpleCase();
void testDataFromFile();
int main(void)

{
    testSimpleCase();
    testDataFromFile();
}
void testSimpleCase()
{
    // test static variables
    cout << myPolynomial::ZERO << endl;
    cout << myPolynomial::ONE << endl;
    cout << myPolynomial::X << endl;
    myPolynomial p0, p1(1), p2(1, 1), p3(3, 5);
    long testData4[10] = {1, 0, 1, 1, 1, 2, 1, 3, 1, 4};
    long testData5[10] = {-1, 0, -1, 1, -1, 2, -1, 3, -1, 4};
    long testData6[10] = {1, 0, -1, 1, 1, 2, -1, 3, 1, 4};
    long testData7[10] = {2, 2, 5, 5, 4, 4, 1, 1, 3, 3};
    long testData8[12] = {1, 1000000000, 1, 100000000, 1, 1000000, 1, 10000, 1, 100, 1, 0};
    myPolynomial p4(5, testData4);
    myPolynomial p5(5, testData5);
    myPolynomial p6(5, testData6);
    myPolynomial p7(5, testData7);
    myPolynomial p8(6, testData8);
    myPolynomial p9(p7);
    // test constructor
    cout << p0 << endl
         << p1 << endl
         << p2 << endl;
    cout << p4 << endl
         << p8 << endl;
    // test copy constructor
    cout << p9 << endl;
    // test accessor function
    cout << p8.getDegree() << " " << p8.getNumTerms() << endl;
    // test evaluation function
    cout << p1(2) << " " << p2(2) << " " << p3(2) << " " << p4(2) << " " << endl;
    cout << p5(3) << " " << p6(3) << " " << p7(3) << " " << p9(3) << " " << endl;
    // test comparison operators
    cout << (p7 == p9) << " " << (p7 != p9) << endl;
    // test derivative function
    cout << myPolynomial::ZERO.ddx() << endl;
    cout << myPolynomial::ONE.ddx() << endl;
    cout << myPolynomial::X.ddx() << endl;
    cout << p4.ddx() << endl;
    cout << p8.ddx() << endl;
    // test unary operator -
    cout << -myPolynomial::ZERO << endl;
    cout << -p4 << endl;
    // test k*p(x) or p(x) * k
    cout << 3 * myPolynomial::ZERO << endl;
    cout << 3 * myPolynomial::ONE << endl;
    cout << myPolynomial::X * 3 << endl;
    cout << 3 * p4 << " " << p4 * 3 << endl;
    cout << 0 * p5 << " " << p5 * 5 << endl;
    // test binary operator +
    cout << p4 + p5 << endl;
    // test binary operator -
    cout << p6 - p7 << endl;
    // test binary operator *
    cout << p8 * p9 << endl;
    myPolynomial tmp1(p4), tmp2, tmp3, tmp4;
    tmp4 = tmp3 = tmp2 = tmp1;
    cout << (tmp1 += p5) << endl;
    cout << (tmp2 -= p5) << endl;
    cout << (tmp3 *= p5) << endl;
    cout << (tmp4 *= 3) << endl;
}
void testDataFromFile()
{
    long numTestCases;
    cin >> numTestCases;
    for (long i = 0; i < numTestCases; i++)
    {
        long numTerms, terms[100];
        /* read first polynomial */
        cin >> numTerms;
        for (long j = 0; j < numTerms; j++)
            cin >> terms[2 * j] >> terms[2 * j + 1];
        myPolynomial p1(numTerms, terms);
        /* read second polynomial */
        cin >> numTerms;
        for (long j = 0; j < numTerms; j++)
            cin >> terms[2 * j] >> terms[2 * j + 1];
        myPolynomial p2(numTerms, terms);
        cout << p1 << endl
             << p2 << endl;
        cout << p1.getDegree() << " " << p2.getNumTerms() << endl;
        cout << p1.ddx() << endl
             << p2.ddx() << endl;
        cout << (p1 == p2) << " " << (p1 != p2) << endl;
        cout << p1(1) << endl;
        cout << -p1 + p1 * 2 * p2 - p2 * 2 + 3 * p1 << endl;
        myPolynomial p3(myPolynomial::ZERO), p4(myPolynomial::ONE), p5(myPolynomial::X);
        p3 += p1;
        p4 -= p2;
        p5 *= p4;
        p5 *= 2;
        cout << p5 << endl;
    }
}