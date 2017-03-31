/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   newsimpletest.cpp
 * Author: david
 *
 * Created on 30 de Março de 2017, 10:05
 */

#include <stdlib.h>
#include <iostream>
#include "funcaoNumerosAleatorios.h"

/*
 * Simple C++ Test Suite
 */

void testDecimalAleatorio() {
    int result = decimalAleatorio();
    if (true /*check result*/) {
        std::cout << "%TEST_FAILED% time=0 testname=testDecimalAleatorio (newsimpletest) message=error message sample" << std::endl;
    }
}

int main(int argc, char** argv) {
    std::cout << "%SUITE_STARTING% newsimpletest" << std::endl;
    std::cout << "%SUITE_STARTED%" << std::endl;

    std::cout << "%TEST_STARTED% testDecimalAleatorio (newsimpletest)" << std::endl;
    testDecimalAleatorio();
    std::cout << "%TEST_FINISHED% time=0 testDecimalAleatorio (newsimpletest)" << std::endl;

    std::cout << "%SUITE_FINISHED% time=0" << std::endl;

    return (EXIT_SUCCESS);
}

