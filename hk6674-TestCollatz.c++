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

    void hk6674_test_read_1 () {
        std::istringstream r("1 1\n");
        int i;
        int j;
        const bool b = collatz_read(r, i, j);
        CPPUNIT_ASSERT(b == true);
        CPPUNIT_ASSERT(i == 1);
        CPPUNIT_ASSERT(j == 1);
    }
    
    void hk6674_test_read_2 () {
        std::istringstream r("100 1\n");
        int i;
        int j;
        const bool b = collatz_read(r, i, j);
        CPPUNIT_ASSERT(b == true);
        CPPUNIT_ASSERT(i == 100);
        CPPUNIT_ASSERT(j == 1);
    }

    void hk6674_test_read_3 () {
        std::istringstream r(" ");
        int i;
        int j;
        const bool b = collatz_read(r, i, j);
        CPPUNIT_ASSERT(b == false);
    }

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

    void hk6674_test_eval_5 () {
        const int v = collatz_eval(1, 1);
        CPPUNIT_ASSERT(v == 1);}

    void hk6674_test_eval_6 () {
        const int v = collatz_eval(2, 1);
        CPPUNIT_ASSERT(v == 2);}

    void hk6674_test_eval_7 () {
        const int v = collatz_eval(1, 2);
        CPPUNIT_ASSERT(v == 2);}

    void hk6674_test_eval_8 () {
        const int v = collatz_eval(12345, 23456);
        CPPUNIT_ASSERT(v == 279);}

    void hk6674_test_eval_9 () {
        const int v = collatz_eval(999999, 1000000);
        CPPUNIT_ASSERT(v == 259);}

    // -----
    // print
    // -----

    void test_print () {
        std::ostringstream w;
        collatz_print(w, 1, 10, 20);
        CPPUNIT_ASSERT(w.str() == "1 10 20\n");}

    void hk6674_test_print_1 () {
        std::ostringstream w;
        collatz_print(w, 100, 900, 2000);
        CPPUNIT_ASSERT(w.str() == "100 900 2000\n");}

    void hk6674_test_print_2 () {
        std::ostringstream w;
        collatz_print(w, 999, 5555, 2222);
        CPPUNIT_ASSERT(w.str() == "999 5555 2222\n");}

    void hk6674_test_print_3 () {
        std::ostringstream w;
        collatz_print(w, 1234567, 12345, 123);
        CPPUNIT_ASSERT(w.str() == "1234567 12345 123\n");}

    void hk6674_test_print_4 () {
        std::ostringstream w;
        collatz_print(w, 01, 02, 03);
        CPPUNIT_ASSERT(w.str() == "1 2 3\n");}

    // -----
    // solve
    // -----

    void test_solve () {
        std::istringstream r("1 10\n100 200\n201 210\n900 1000\n");
        std::ostringstream w;
        collatz_solve(r, w);
        CPPUNIT_ASSERT(w.str() == "1 10 20\n100 200 125\n201 210 89\n900 1000 174\n");}

    void hk6674_test_solve_1 () {
        std::istringstream r("10 10\n100 100\n201 201\n900 900\n");
        std::ostringstream w;
        collatz_solve(r, w);
        CPPUNIT_ASSERT(w.str() == "1 10 7\n100 100 26\n201 201 19\n900 900 55\n");}

    void hk6674_test_solve_2 () {
        std::istringstream r("123 1234\n123 12345\n123 123456\n123 1234567\n");
        std::ostringstream w;
        collatz_solve(r, w);
        CPPUNIT_ASSERT(w.str() == "123 1234 182\n123 12345 268\n123 123456 354\n123 1234567 476\n");}

    void hk6674_test_solve_3 () {
        std::istringstream r("1 10\n");
        std::ostringstream w;
        collatz_solve(r, w);
        CPPUNIT_ASSERT(w.str() == "1 10 7\n");}


    // -----
    // suite
    // -----

    CPPUNIT_TEST_SUITE(TestCollatz);

//  read tests
    CPPUNIT_TEST(test_read);
    CPPUNIT_TEST(hk6674_test_read_1);
    CPPUNIT_TEST(hk6674_test_read_2);
    CPPUNIT_TEST(hk6674_test_read_3);

//  eval tests    
    CPPUNIT_TEST(test_eval_1);
    CPPUNIT_TEST(test_eval_2);
    CPPUNIT_TEST(test_eval_3);
    CPPUNIT_TEST(test_eval_4);
    CPPUNIT_TEST(hk6674_test_eval_5);
    CPPUNIT_TEST(hk6674_test_eval_6);
    CPPUNIT_TEST(hk6674_test_eval_7);
    CPPUNIT_TEST(hk6674_test_eval_8);
    CPPUNIT_TEST(hk6674_test_eval_9);

// print tests
    CPPUNIT_TEST(test_print);
    CPPUNIT_TEST(hk6674_test_print_1);
    CPPUNIT_TEST(hk6674_test_print_2);
    CPPUNIT_TEST(hk6674_test_print_3);
    CPPUNIT_TEST(hk6674_test_print_4);

// solve tests
    CPPUNIT_TEST(test_solve);
    CPPUNIT_TEST(hk6674_test_solve_1);
    CPPUNIT_TEST(hk6674_test_solve_2);
    CPPUNIT_TEST(hk6674_test_solve_3);

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