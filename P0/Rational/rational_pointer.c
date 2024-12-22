/*
 * TITLE: PROGRAMMING II LABS   SUBTITLE: P0 Rational
 * AUTHOR 1: Adrián Edreira Gantes      LOGIN 1: adrian.gantes
 * AUTHOR 2: Miguel Marcos Trillo       LOGIN 2:miguel.mt
 * GROUP: 1.4       DATE: 03/02/2023
 */

#include "rational_pointer.h"
Rational createRational (int n, int d){
    Rational temp;
    temp=malloc (sizeof(*temp));
    temp->num= n;
    temp->den=d;
    return temp;
}
int numerator(Rational r){
    return r->num;
}
int denominator(Rational r){
    return r->den;
}
Rational sum(Rational r1, Rational r2){
    Rational s;
    s=malloc (sizeof(*s));
    s->num= r1->num*r2->den+r2->num*r1->den;
    s->den= r1->den*r2->den;
    return s;
}