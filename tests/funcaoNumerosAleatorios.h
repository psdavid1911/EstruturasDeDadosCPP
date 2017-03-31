/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   funcaoNumerosAleatorios.h
 * Author: david
 *
 * Created on 30/03/2017, 09:38:22
 */

#ifndef FUNCAONUMEROSALEATORIOS_H
#define FUNCAONUMEROSALEATORIOS_H

#include <cppunit/extensions/HelperMacros.h>

class funcaoNumerosAleatorios : public CPPUNIT_NS::TestFixture {
    CPPUNIT_TEST_SUITE(funcaoNumerosAleatorios);

    CPPUNIT_TEST(testDecimalAleatorio);

    CPPUNIT_TEST_SUITE_END();

public:
    funcaoNumerosAleatorios();
    virtual ~funcaoNumerosAleatorios();
    void setUp();
    void tearDown();

private:
    void testDecimalAleatorio();

};

#endif /* FUNCAONUMEROSALEATORIOS_H */

