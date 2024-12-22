/*
 * TITLE: PROGRAMMING II LABS   SUBTITLE: P0 Rational
 * AUTHOR 1: Adrián Edreira Gantes      LOGIN 1: adrian.gantes
 * AUTHOR 2: Miguel Marcos Trillo       LOGIN 2:miguel.mt
 * GROUP: 1.4       DATE: 03/02/2023
 */

#ifndef RATIONAL_RATIONAL_STRUCT_H
#define RATIONAL_RATIONAL_STRUCT_H
typedef struct Data Rational;
struct Data{
    int num;
    int den;
};
Rational createRational (int n, int d);
int numerator (Rational r);
int denominator (Rational r);
Rational sum(Rational r1, Rational r2);
#endif //RATIONAL_RATIONAL_STRUCT_H
