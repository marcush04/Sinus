#include "MyBar.h"
#include <cmath>
#include <iostream>
using namespace std;

MyBar::MyBar(QWidget *parent) : QProgressBar(parent) {
    rellotge = false;
    connect(&timer, SIGNAL(timeout()), this, SLOT(animacio()));
}

void MyBar::inici() {
    amplitud = 0.5;
    fase = 0;
    valor = value();

    int calcul = (amplitud * sin(double(valor + fase)))*100;

    setValue(calcul);
}

void MyBar::amplitudchange(int n) {
    amplitud = float(n)/10;
    int calcul = (amplitud * sin(double(valor + fase)))*100;
    setValue(calcul);
}

void MyBar::fasechange(int n) {
    fase = float(n);
    int calcul = (amplitud * sin(double(valor + fase)))*100;
    setValue(calcul);
}

void MyBar::animacio() {
    ++w;
    int calcul = (amplitud * sin(double(valor + fase + w)))*100;
    setValue(calcul);
}

void MyBar::tictac() {
    w = 0;
    if(rellotge) {
        timer.stop();
        rellotge = false;
    }
    else {
        timer.start(100);
        rellotge = true;
    }
}