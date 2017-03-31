/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   funcaoNumerosAleatorios.cpp
 * Author: david
 *
 * Created on 30/03/2017, 09:38:22
 */

#include "funcaoNumerosAleatorios.h"
#include "CabecalhoPrincipal.h"

CPPUNIT_TEST_SUITE_REGISTRATION(funcaoNumerosAleatorios);

void funcaoNumerosAleatorios::testDecimalAleatorio() {
    int result = decimalAleatorio();
    cout << "Resultado:" << result;
}

