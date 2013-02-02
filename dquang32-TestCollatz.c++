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
    
    // my tests
    void test_read1 () {
        std::istringstream r("8 109\n");
        int i;
        int j;
        const bool b = collatz_read(r, i, j);
        CPPUNIT_ASSERT(b == true);
        CPPUNIT_ASSERT(i ==    8);
        CPPUNIT_ASSERT(j ==   109);}
    
    void test_read2 () {
        std::istringstream r("13 230\n");
        int i;
        int j;
        const bool b = collatz_read(r, i, j);
        CPPUNIT_ASSERT(b == true);
        CPPUNIT_ASSERT(i ==    13);
        CPPUNIT_ASSERT(j ==   230);}
    
    void test_read3 () {
        std::istringstream r("201 1000\n");
        int i;
        int j;
        const bool b = collatz_read(r, i, j);
        CPPUNIT_ASSERT(b == true);
        CPPUNIT_ASSERT(i ==    201);
        CPPUNIT_ASSERT(j ==   1000);}
    
    void test_read4 () {
        std::istringstream r("20 1900\n");
        int i;
        int j;
        const bool b = collatz_read(r, i, j);
        CPPUNIT_ASSERT(b == true);
        CPPUNIT_ASSERT(i ==    20);
        CPPUNIT_ASSERT(j ==   1900);}
    
    // ---------
    // calculate
    // ---------
    
    // my tests
    
    void test_calculate_1 () {
        const int v = collatz_calculate(20, 1900);
        CPPUNIT_ASSERT(v == 182);}

    
    void test_calculate_2 () {
        const int v = collatz_calculate(6, 200);
        CPPUNIT_ASSERT(v == 125);}

    
    void test_calculate_3 () {
        const int v = collatz_calculate(158, 28888);
        CPPUNIT_ASSERT(v == 308);}
    
    void test_calculate_4 () {
        const int v = collatz_calculate(1573, 84844);
        CPPUNIT_ASSERT(v == 351);}



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

    // my tests
    void test_eval_5 () {
    const int v = collatz_eval(8, 109);
    CPPUNIT_ASSERT(v == 119);}
                             
    void test_eval_6 () {
    const int v = collatz_eval(13, 230);
    CPPUNIT_ASSERT(v == 125);}
                             
    void test_eval_7 () {
    const int v = collatz_eval(201, 1000);
    CPPUNIT_ASSERT(v == 179);}
    
    void test_eval_8 () {
        const int v = collatz_eval(20, 1900);
        CPPUNIT_ASSERT(v == 182);}

    // -----
    // print
    // -----

    void test_print () {
    std::ostringstream w;
    collatz_print(w, 1, 10, 20);
    CPPUNIT_ASSERT(w.str() == "1 10 20\n");}
    
    // my tests
    void test_print1 () {
        std::ostringstream w;
        collatz_print(w, 8, 109, 119);
        CPPUNIT_ASSERT(w.str() == "8 109 119\n");}
    
    void test_print2 () {
        std::ostringstream w;
        collatz_print(w, 13, 230, 125);
        CPPUNIT_ASSERT(w.str() == "13 230 125\n");}
    
    void test_print3 () {
        std::ostringstream w;
        collatz_print(w, 201, 1000, 179);
        CPPUNIT_ASSERT(w.str() == "201 1000 179\n");}
    
    void test_print4 () {
        std::ostringstream w;
        collatz_print(w, 20, 1900, 182);
        CPPUNIT_ASSERT(w.str() == "20 1900 182\n");}
    
    // -----
    // solve
    // -----

    void test_solve() {
    std::istringstream r("1 10\n100 200\n201 210\n900 1000\n");
    std::ostringstream w;
    collatz_solve(r, w);
    CPPUNIT_ASSERT(w.str() == "1 10 20\n100 200 125\n201 210 89\n900 1000 174\n");}
    
    // my tests
    void test_solve1() {
        std::istringstream r("8 109\n");
        std::ostringstream w;
        collatz_solve(r, w);
        CPPUNIT_ASSERT(w.str() == "8 109 119\n");}
    
    void test_solve2() {
        std::istringstream r("13 230\n");
        std::ostringstream w;
        collatz_solve(r, w);
        CPPUNIT_ASSERT(w.str() == "13 230 125\n");}
    
    void test_solve3() {
        std::istringstream r("201 1000\n");
        std::ostringstream w;
        collatz_solve(r, w);
        CPPUNIT_ASSERT(w.str() == "201 1000 179\n");}
    
    void test_solve4() {
        std::istringstream r("20 1900\n");
        std::ostringstream w;
        collatz_solve(r, w);
        CPPUNIT_ASSERT(w.str() == "20 1900 182\n");}

    // -----
    // suite
    // -----

    CPPUNIT_TEST_SUITE(TestCollatz);
    CPPUNIT_TEST(test_read);
    CPPUNIT_TEST(test_read1);
    CPPUNIT_TEST(test_read2);
    CPPUNIT_TEST(test_read3);
    CPPUNIT_TEST(test_read4);
    CPPUNIT_TEST(test_calculate_1);
    CPPUNIT_TEST(test_calculate_2);
    CPPUNIT_TEST(test_calculate_3);
    CPPUNIT_TEST(test_calculate_4);
    CPPUNIT_TEST(test_eval_1);
    CPPUNIT_TEST(test_eval_2);
    CPPUNIT_TEST(test_eval_3);
    CPPUNIT_TEST(test_eval_4);
    CPPUNIT_TEST(test_eval_5);
    CPPUNIT_TEST(test_eval_6);
    CPPUNIT_TEST(test_eval_7);
    CPPUNIT_TEST(test_eval_8);
    CPPUNIT_TEST(test_print);
    CPPUNIT_TEST(test_print1);
    CPPUNIT_TEST(test_print2);
    CPPUNIT_TEST(test_print3);
    CPPUNIT_TEST(test_print4);
    CPPUNIT_TEST(test_solve);
    CPPUNIT_TEST(test_solve1);
    CPPUNIT_TEST(test_solve2);
    CPPUNIT_TEST(test_solve3);
    CPPUNIT_TEST(test_solve4);
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
