// --------------------------------
// projects/collatz/TestCollatz.c++
// Copyright (C) 2013
// Glenn P. Downing
// --------------------------------

/*
To test the program:
    % ls /usr/include/cppunit/
    ...
    TestFixture.h
    ...
    % locate libcppunit.a
    /usr/lib/libcppunit.a
    % g++ -lcppunit -ldl -pedantic -std=c++0x -Wall Collatz.c++ TestCollatz.c++ -o TestCollatz.c++.app
    % valgrind TestCollatz.c++.app >& TestCollatz.c++.out
*/

// --------
// includes
// --------

#include <iostream> // cout, endl
#include <sstream>  // istringtstream, ostringstream
#include <string>   // ==

#include "cppunit/extensions/HelperMacros.h" // CPPUNIT_TEST, CPPUNIT_TEST_SUITE, CPPUNIT_TEST_SUITE_END
#include "cppunit/TestFixture.h"             // TestFixture
#include "cppunit/TextTestRunner.h"          // TextTestRunner

#include "Collatz.h"

// -----------
// TestCollatz
// -----------

struct TestCollatz : CppUnit::TestFixture {
    // ----
    // read
    // ----

    void test_read () {
        std::istringstream r("1 10\n");
        int i;
        int j;
        const bool b = collatz_read(r, i, j);
        CPPUNIT_ASSERT(b == true);
        CPPUNIT_ASSERT(i ==    1);
        CPPUNIT_ASSERT(j ==   10);}
//my read tests

    void test_readw1 () {
        std::istringstream r("30 40\n");
        int i;
        int j;
        const bool b = collatz_read(r, i, j);
        CPPUNIT_ASSERT(b == true);
        CPPUNIT_ASSERT(i ==   30);
        CPPUNIT_ASSERT(j ==   40);}

    void test_readw2 () {
        std::istringstream r("9991 10000\n");
        int i;
        int j;
        const bool b = collatz_read(r, i, j);
        CPPUNIT_ASSERT(b == true);
        CPPUNIT_ASSERT(i == 9991);
        CPPUNIT_ASSERT(j ==10000);}

    void test_readw3 () {
        std::istringstream r("7 17\n");
        int i;
        int j;
        const bool b = collatz_read(r, i, j);
        CPPUNIT_ASSERT(b == true);
        CPPUNIT_ASSERT(i ==    7);
        CPPUNIT_ASSERT(j ==   17);}


    // ----
    // eval
    // ----

    void test_eval_1 () {
        const int v = collatz_eval(1, 10);
        CPPUNIT_ASSERT(v == 20);}

    void test_eval_2 () {
        const int v = collatz_eval(100, 200);
        CPPUNIT_ASSERT(v == 125);}

    void test_eval_3 () {
        const int v = collatz_eval(201, 210);
        CPPUNIT_ASSERT(v == 89);}

    void test_eval_4 () {
        const int v = collatz_eval(900, 1000);
        CPPUNIT_ASSERT(v == 174);}

//my eval tests
    void test_evalw1 () {
        const int v = collatz_eval(20, 30);
        CPPUNIT_ASSERT(v == 112);}

    void test_evalw2 () {
        const int v = collatz_eval(500, 1000);
        CPPUNIT_ASSERT(v == 179);}

    void test_evalw3 () {
        const int v = collatz_eval(300000, 314159);
        CPPUNIT_ASSERT(v == 384);}


    // -----
    // print
    // -----

    void test_print () {
        std::ostringstream w;
        collatz_print(w, 1, 10, 20);
        CPPUNIT_ASSERT(w.str() == "1 10 20\n");}
//my print tests
    void test_printw1 () {
        std::ostringstream w;
        collatz_print(w, 8, 99, 37);
        CPPUNIT_ASSERT(w.str() == "8 99 37\n");}

    void test_printw2 () {
        std::ostringstream w;
        collatz_print(w, 314159, 42, 420);
        CPPUNIT_ASSERT(w.str() == "314159 42 420\n");}

    void test_printw3 () {
        std::ostringstream w;
        collatz_print(w, 8, 99, 1000000);
        CPPUNIT_ASSERT(w.str() == "8 99 1000000\n");}

    // -----
    // solve
    // -----

    void test_solve () {
        std::istringstream r("1 10\n100 200\n201 210\n900 1000\n");
        std::ostringstream w;
        collatz_solve(r, w);
        CPPUNIT_ASSERT(w.str() == "1 10 20\n100 200 125\n201 210 89\n900 1000 174\n");}
//my solve tests
    void test_solvew1 () {
        std::istringstream r("30 60\n5000 99999\n60 90\n909090 090909\n");
        std::ostringstream w;
        collatz_solve(r, w);
        CPPUNIT_ASSERT(w.str() == "30 60 113\n5000 99999 351\n60 90 116\n909090 90909 470\n");}

    void test_solvew2 () {
        std::istringstream r("20 30\n500 1000\n600 1200\n300000 314159\n");
        std::ostringstream w;
        collatz_solve(r, w);
        CPPUNIT_ASSERT(w.str() == "20 30 112\n500 1000 179\n600 1200 182\n300000 314159 384\n");}

    void test_solvew3 () {
        std::istringstream r("1 12000\n202020 404040\n1 404040\n303030 404040\n");
        std::ostringstream w;
        collatz_solve(r, w);
        CPPUNIT_ASSERT(w.str() == "1 12000 268\n202020 404040 443\n1 404040 443\n303030 404040 441\n");}


    // ----
    // calc
    // ----

    void test_calcw1 () {
        CPPUNIT_ASSERT(collatz_calc( 15 ) == 18);
    }

    void test_calcw2 () {
        CPPUNIT_ASSERT(collatz_calc( 1 ) == 1);
    }

    void test_calcw3 () {
        CPPUNIT_ASSERT(collatz_calc( 314159 ) == 185);
    }


    // -----
    // suite
    // -----

    CPPUNIT_TEST_SUITE(TestCollatz);
    CPPUNIT_TEST(test_read);
    CPPUNIT_TEST(test_readw1);
    CPPUNIT_TEST(test_readw2);
    CPPUNIT_TEST(test_readw3);

    CPPUNIT_TEST(test_eval_1);
    CPPUNIT_TEST(test_eval_2);
    CPPUNIT_TEST(test_eval_3);
    CPPUNIT_TEST(test_eval_4);
    CPPUNIT_TEST(test_evalw1);
    CPPUNIT_TEST(test_evalw2);
    CPPUNIT_TEST(test_evalw3);

    CPPUNIT_TEST(test_print);

    CPPUNIT_TEST(test_printw1);
    CPPUNIT_TEST(test_printw2);
    CPPUNIT_TEST(test_printw3);

    CPPUNIT_TEST(test_solve);

    CPPUNIT_TEST(test_solvew1);
    CPPUNIT_TEST(test_solvew2);
    CPPUNIT_TEST(test_solvew3);


    CPPUNIT_TEST(test_calcw1);
    CPPUNIT_TEST(test_calcw2);
    CPPUNIT_TEST(test_calcw3);


    CPPUNIT_TEST_SUITE_END();};

// ----
// main
// ----

int main () {
    using namespace std;
    ios_base::sync_with_stdio(false);  // turn off synchronization with C I/O
    cout << "TestCollatz.c++" << endl;

    CppUnit::TextTestRunner tr;
    tr.addTest(TestCollatz::suite());
    tr.run();

    cout << "Done." << endl;
    return 0;}
