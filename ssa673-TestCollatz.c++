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
#include "cppunit/TestSuite.h"               // TestSuite
#include "cppunit/TextTestRunner.h"          // TestRunner

#include "Collatz.h"

// -----------
// TestCollatz
// -----------

struct TestCollatz : CppUnit::TestFixture {
    // ----
    // read
    // ----

    void test_read_1 () {
        std::istringstream r("1 10\n");
        int i;
        int j;
        const bool b = collatz_read(r, i, j);
        CPPUNIT_ASSERT(b == true);
        CPPUNIT_ASSERT(i ==    1);
        CPPUNIT_ASSERT(j ==   10);}

    void test_read_2 () {
        std::istringstream r("100 200\n");
        int i;
        int j;
        const bool b = collatz_read(r, i, j);
        CPPUNIT_ASSERT(b == true);
        CPPUNIT_ASSERT(i ==   100);
        CPPUNIT_ASSERT(j ==   200);}

    void test_read_3 () {
        std::istringstream r("201 210\n");
        int i;
        int j;
        const bool b = collatz_read(r, i, j);
        CPPUNIT_ASSERT(b == true);
        CPPUNIT_ASSERT(i ==   201);
        CPPUNIT_ASSERT(j ==   210);}

    void test_read_4 () {
        std::istringstream r("900 1000\n");
        int i;
        int j;
        const bool b = collatz_read(r, i, j);
        CPPUNIT_ASSERT(b == true);
        CPPUNIT_ASSERT(i ==    900);
        CPPUNIT_ASSERT(j ==   1000);}

    void test_read_5 () {
        std::istringstream r("1 2\n");
        int i;
        int j;
        const bool b = collatz_read(r, i, j);
        CPPUNIT_ASSERT(b == true);
        CPPUNIT_ASSERT(i ==   1);
        CPPUNIT_ASSERT(j ==   2);}

    void test_read_6 () {
        std::istringstream r("1 6\n");
        int i;
        int j;
        const bool b = collatz_read(r, i, j);
        CPPUNIT_ASSERT(b == true);
        CPPUNIT_ASSERT(i ==   1);
        CPPUNIT_ASSERT(j ==   6);}

    void test_read_7 () {
        std::istringstream r("500 250\n");
        int i;
        int j;
        const bool b = collatz_read(r, i, j);
        CPPUNIT_ASSERT(b == true);
        CPPUNIT_ASSERT(i ==   500);
        CPPUNIT_ASSERT(j ==   250);}

    void test_read_8 () {
        std::istringstream r("555 5583\n");
        int i;
        int j;
        const bool b = collatz_read(r, i, j);
        CPPUNIT_ASSERT(b == true);
        CPPUNIT_ASSERT(i ==    555);
        CPPUNIT_ASSERT(j ==   5583);}

    void test_read_9 () {
        std::istringstream r("555 555\n");
        int i;
        int j;
        const bool b = collatz_read(r, i, j);
        CPPUNIT_ASSERT(b == true);
        CPPUNIT_ASSERT(i ==   555);
        CPPUNIT_ASSERT(j ==   555);}

    void test_read_10 () {
        std::istringstream r("12345 54321\n");
        int i;
        int j;
        const bool b = collatz_read(r, i, j);
        CPPUNIT_ASSERT(b == true);
        CPPUNIT_ASSERT(i ==   12345);
        CPPUNIT_ASSERT(j ==   54321);}

    void test_read_11 () {
        std::istringstream r("54321 12345\n");
        int i;
        int j;
        const bool b = collatz_read(r, i, j);
        CPPUNIT_ASSERT(b == true);
        CPPUNIT_ASSERT(i ==   54321);
        CPPUNIT_ASSERT(j ==   12345);}

    void test_read_12 () {
        std::istringstream r("11111 55555\n");
        int i;
        int j;
        const bool b = collatz_read(r, i, j);
        CPPUNIT_ASSERT(b == true);
        CPPUNIT_ASSERT(i ==   11111);
        CPPUNIT_ASSERT(j ==   55555);}

    void test_read_13 () {
        std::istringstream r("98765 56789\n");
        int i;
        int j;
        const bool b = collatz_read(r, i, j);
        CPPUNIT_ASSERT(b == true);
        CPPUNIT_ASSERT(i ==   98765);
        CPPUNIT_ASSERT(j ==   56789);}

    void test_read_14 () {
        std::istringstream r("10000 50000\n");
        int i;
        int j;
        const bool b = collatz_read(r, i, j);
        CPPUNIT_ASSERT(b == true);
        CPPUNIT_ASSERT(i ==   10000);
        CPPUNIT_ASSERT(j ==   50000);}

    void test_read_15 () {
        std::istringstream r("3 300000\n");
        int i;
        int j;
        const bool b = collatz_read(r, i, j);
        CPPUNIT_ASSERT(b == true);
        CPPUNIT_ASSERT(i ==        3);
        CPPUNIT_ASSERT(j ==   300000);}

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

    void test_eval_5 () {
        const int v = collatz_eval(1, 2);
        CPPUNIT_ASSERT(v == 2);}

    void test_eval_6 () {
        const int v = collatz_eval(1, 6);
        CPPUNIT_ASSERT(v == 9);}

    void test_eval_7 () {
        const int v = collatz_eval(500, 250);
        CPPUNIT_ASSERT(v == 144);}

    void test_eval_8 () {
        const int v = collatz_eval(555, 5583);
        CPPUNIT_ASSERT(v == 238);}

    void test_eval_9 () {
        const int v = collatz_eval(555, 555);
        CPPUNIT_ASSERT(v == 31);}

    void test_eval_10 () {
        const int v = collatz_eval(12345, 54321);
        CPPUNIT_ASSERT(v == 340);}

    void test_eval_11 () {
        const int v = collatz_eval(54321, 12345);
        CPPUNIT_ASSERT(v == 340);}

    void test_eval_12 () {
        const int v = collatz_eval(11111, 55555);
        CPPUNIT_ASSERT(v == 340);}

    void test_eval_13 () {
        const int v = collatz_eval(98765, 56789);
        CPPUNIT_ASSERT(v == 351);}

    void test_eval_14 () {
        const int v = collatz_eval(10000, 50000);
        CPPUNIT_ASSERT(v == 324);}

    void test_eval_15 () {
        const int v = collatz_eval(3, 300000);
        CPPUNIT_ASSERT(v == 443);}


    // -----
    // solve
    // -----

    void test_solve_1 () {
        std::istringstream r("1 10\n100 200\n201 210\n900 1000\n1 2\n");
        std::ostringstream w;
        collatz_solve(r, w);
        CPPUNIT_ASSERT(w.str() == "1 10 20\n100 200 125\n201 210 89\n900 1000 174\n1 2 2\n");}

    void test_solve_2 () {
        std::istringstream r("1 6\n500 250\n555 5583\n555 555\n12345 54321\n");
        std::ostringstream w;
        collatz_solve(r, w);
        CPPUNIT_ASSERT(w.str() == "1 6 9\n500 250 144\n555 5583 238\n555 555 31\n12345 54321 340\n");}

    void test_solve_3 () {
        std::istringstream r("54321 12345\n11111 55555\n98765 56789\n10000 50000\n3 300000\n");
        std::ostringstream w;
        collatz_solve(r, w);
        CPPUNIT_ASSERT(w.str() == "54321 12345 340\n11111 55555 340\n98765 56789 351\n10000 50000 324\n3 300000 443\n");}

    // -----
    // cycle
    // -----

    void test_cycle_1 () {
        long v = 5;
        long a = collatzCycle(v);
        CPPUNIT_ASSERT(a == 6);}

    void test_cycle_2 () {
        long v = 55;
        long a = collatzCycle(v);
        CPPUNIT_ASSERT(a == 113);}

    void test_cycle_3 () {
        long v = 555;
        long a = collatzCycle(v);
        CPPUNIT_ASSERT(a == 31);}

    void test_cycle_4 () {
        long v = 64568;
        long a = collatzCycle(v);
        CPPUNIT_ASSERT(a == 74);}

    void test_cycle_5 () {
        long v = 8876;
        long a = collatzCycle(v);
        CPPUNIT_ASSERT(a == 97);}

    void test_cycle_6 () {
        long v = 135785;
        long a = collatzCycle(v);
        CPPUNIT_ASSERT(a == 194);}

    void test_cycle_7 () {
        long v = 8746;
        long a = collatzCycle(v);
        CPPUNIT_ASSERT(a == 35);}

    void test_cycle_8 () {
        long v = 463546;
        long a = collatzCycle(v);
        CPPUNIT_ASSERT(a == 108);}

    void test_cycle_9 () {
        long v = 7977;
        long a = collatzCycle(v);
        CPPUNIT_ASSERT(a == 53);}

    void test_cycle_10 () {
        long v = 444000;
        long a = collatzCycle(v);
        CPPUNIT_ASSERT(a == 188);}

    void test_cycle_11 () {
        long v = 336452;
        long a = collatzCycle(v);
        CPPUNIT_ASSERT(a == 92);}

    void test_cycle_12 () {
        long v = 999999;
        long a = collatzCycle(v);
        CPPUNIT_ASSERT(a == 259);}

    void test_cycle_13 () {
        long v = 111111;
        long a = collatzCycle(v);
        CPPUNIT_ASSERT(a == 116);}

    void test_cycle_14 () {
        long v = 357159;
        long a = collatzCycle(v);
        CPPUNIT_ASSERT(a == 149);}

    void test_cycle_15 () {
        long v = 1;
        long a = collatzCycle(v);
        CPPUNIT_ASSERT(a == 1);}


            // -----
    // print
    // -----

    void test_print_1 () {
        std::ostringstream w;
        collatz_print(w, 1, 10, 20);
        CPPUNIT_ASSERT(w.str() == "1 10 20\n");}

    void test_print_2 () {
        std::ostringstream w;
        collatz_print(w, 100, 200, 125);
        CPPUNIT_ASSERT(w.str() == "100 200 125\n");}

    void test_print_3 () {
        std::ostringstream w;
        collatz_print(w, 201, 210, 89);
        CPPUNIT_ASSERT(w.str() == "201 210 89\n");}

    void test_print_4 () {
        std::ostringstream w;
        collatz_print(w, 900, 1000, 174);
        CPPUNIT_ASSERT(w.str() == "900 1000 174\n");}

    void test_print_5 () {
        std::ostringstream w;
        collatz_print(w, 1, 2, 2);
        CPPUNIT_ASSERT(w.str() == "1 2 2\n");}

    void test_print_6 () {
        std::ostringstream w;
        collatz_print(w, 1, 6, 9);
        CPPUNIT_ASSERT(w.str() == "1 6 9\n");}

    void test_print_7 () {
        std::ostringstream w;
        collatz_print(w, 500, 250, 144);
        CPPUNIT_ASSERT(w.str() == "500 250 144\n");}

    void test_print_8 () {
        std::ostringstream w;
        collatz_print(w, 555, 5583, 238);
        CPPUNIT_ASSERT(w.str() == "555 5583 238\n");}

    void test_print_9 () {
        std::ostringstream w;
        collatz_print(w, 555, 555, 31);
        CPPUNIT_ASSERT(w.str() == "555 555 31\n");}

    void test_print_10 () {
        std::ostringstream w;
        collatz_print(w, 12345, 54321, 340);
        CPPUNIT_ASSERT(w.str() == "12345 54321 340\n");}

    void test_print_11 () {
        std::ostringstream w;
        collatz_print(w, 54321, 12345, 340);
        CPPUNIT_ASSERT(w.str() == "54321 12345 340\n");}

    void test_print_12 () {
        std::ostringstream w;
        collatz_print(w, 11111, 55555, 340);
        CPPUNIT_ASSERT(w.str() == "11111 55555 340\n");}

    void test_print_13 () {
        std::ostringstream w;
        collatz_print(w, 98765, 56789, 351);
        CPPUNIT_ASSERT(w.str() == "98765 56789 351\n");}

    void test_print_14 () {
        std::ostringstream w;
        collatz_print(w, 10000, 50000, 324);
        CPPUNIT_ASSERT(w.str() == "10000 50000 324\n");}

    void test_print_15 () {
        std::ostringstream w;
        collatz_print(w, 3, 300000, 443);
        CPPUNIT_ASSERT(w.str() == "3 300000 443\n");}




    // -----
    // massive testing!!
    // -----

    CPPUNIT_TEST_SUITE(TestCollatz);
    CPPUNIT_TEST(test_read_1);
    CPPUNIT_TEST(test_read_2);
    CPPUNIT_TEST(test_read_3);
    CPPUNIT_TEST(test_read_4);
    CPPUNIT_TEST(test_read_5);
    CPPUNIT_TEST(test_read_6);
    CPPUNIT_TEST(test_read_7);
    CPPUNIT_TEST(test_read_8);
    CPPUNIT_TEST(test_read_9);
    CPPUNIT_TEST(test_read_10);
    CPPUNIT_TEST(test_read_11);
    CPPUNIT_TEST(test_read_12);
    CPPUNIT_TEST(test_read_13);
    CPPUNIT_TEST(test_read_14);
    CPPUNIT_TEST(test_read_14);
    CPPUNIT_TEST(test_eval_1);
    CPPUNIT_TEST(test_eval_2);
    CPPUNIT_TEST(test_eval_3);
    CPPUNIT_TEST(test_eval_4);
    CPPUNIT_TEST(test_eval_5);
    CPPUNIT_TEST(test_eval_6);
    CPPUNIT_TEST(test_eval_7);
    CPPUNIT_TEST(test_eval_8);
    CPPUNIT_TEST(test_eval_9);
    CPPUNIT_TEST(test_eval_10);
    CPPUNIT_TEST(test_eval_11);
    CPPUNIT_TEST(test_eval_12);
    CPPUNIT_TEST(test_eval_13);
    CPPUNIT_TEST(test_eval_14);
    CPPUNIT_TEST(test_eval_15);
    CPPUNIT_TEST(test_print_1);
    CPPUNIT_TEST(test_print_2);
    CPPUNIT_TEST(test_print_3);
    CPPUNIT_TEST(test_print_4);
    CPPUNIT_TEST(test_print_5);
    CPPUNIT_TEST(test_print_6);
    CPPUNIT_TEST(test_print_7);
    CPPUNIT_TEST(test_print_8);
    CPPUNIT_TEST(test_print_9);
    CPPUNIT_TEST(test_print_10);
    CPPUNIT_TEST(test_print_11);
    CPPUNIT_TEST(test_print_12);
    CPPUNIT_TEST(test_print_13);
    CPPUNIT_TEST(test_print_14);
    CPPUNIT_TEST(test_print_15);
    CPPUNIT_TEST(test_solve_1);
    CPPUNIT_TEST(test_solve_2);
    CPPUNIT_TEST(test_solve_3);
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
