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
    
    void test_read_1 () {
        std::istringstream r("11 19\n");
        int i;
        int j;
        const bool b = collatz_read(r, i, j);
        CPPUNIT_ASSERT(b == true);
        CPPUNIT_ASSERT(i ==    11);
        CPPUNIT_ASSERT(j ==   19);}

    void test_read_2 () {
        std::istringstream r("");
        int i;
        int j;
        const bool b = collatz_read(r, i, j);
        CPPUNIT_ASSERT(b == false);}

    void test_read_3 () {
        std::istringstream r("199 111");
        int i;
        int j;
        const bool b = collatz_read(r, i, j);
        CPPUNIT_ASSERT(b == true);
        CPPUNIT_ASSERT(i ==    199);
        CPPUNIT_ASSERT(j ==   111);}

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
        const int v = collatz_eval(188, 1000);
        CPPUNIT_ASSERT(v == 179);}

    void test_eval_5 () {
        const int v = collatz_eval(1000, 188);
        CPPUNIT_ASSERT(v == 179);}

    void test_eval_6 () {
        const int v = collatz_eval(10, 10);
        CPPUNIT_ASSERT(v == 7);}

    void test_eval_7 () {
        const int v = collatz_eval(1, 2);
        CPPUNIT_ASSERT(v == 2);}

    // -----
    // length 
    // -----

    void test_length_1(){
      const int v = collatz_num(189);
      CPPUNIT_ASSERT(v == 107);
    }

    void test_length_2(){
      const int v = collatz_num(12);
      CPPUNIT_ASSERT(v == 10);
    }

    void test_length_3(){
      const int v = collatz_num(100);
      CPPUNIT_ASSERT(v == 26);
    }

    void test_length_4(){
      const int v = collatz_num(78);
      CPPUNIT_ASSERT(v == 36);
    }

    // -----
    // print
    // -----

    void test_print () {
        std::ostringstream w;
        collatz_print(w, 11, 10, 20);
        CPPUNIT_ASSERT(w.str() == "11 10 20\n");}

    void test_print_1 () {
        std::ostringstream w;
        collatz_print(w, 2, 14, 21);
        CPPUNIT_ASSERT(w.str() == "2 14 21\n");}

    void test_print_2 () {
        std::ostringstream w;
        collatz_print(w, 10, 2, 44);
        CPPUNIT_ASSERT(w.str() == "10 2 44\n");}

    void test_print_3 () {
        std::ostringstream w;
        collatz_print(w, 1300, 4, 77);
        CPPUNIT_ASSERT(w.str() == "1300 4 77\n");}




    // -----
    // solve
    // -----

    void test_solve () {
        std::istringstream r("1 10\n100 200\n201 210\n900 1000\n");
        std::ostringstream w;
        collatz_solve(r, w);
        CPPUNIT_ASSERT(w.str() == "1 10 20\n100 200 125\n201 210 89\n900 1000 174\n");}

    void test_solve_reverse () {
        std::istringstream r("10 1\n200 100\n210 201\n1000 900\n");
        std::ostringstream w;
        collatz_solve(r, w);
        CPPUNIT_ASSERT(w.str() == "10 1 20\n200 100 125\n210 201 89\n1000 900 174\n");}

    void test_solve_3 () {
        std::istringstream r("8 88\n");
        std::ostringstream w;
        collatz_solve(r, w);
        CPPUNIT_ASSERT(w.str() == "8 88 116\n");}

    void test_solve_4 () {
        std::istringstream r("1 2\n9 45\n");
        std::ostringstream w;
        collatz_solve(r, w);
        CPPUNIT_ASSERT(w.str() == "1 2 2\n9 45 112\n");}

    // -----
    // suite
    // -----

    CPPUNIT_TEST_SUITE(TestCollatz);

    CPPUNIT_TEST(test_read);

    CPPUNIT_TEST(test_read_1);
    CPPUNIT_TEST(test_read_2);
    CPPUNIT_TEST(test_read_3);

    CPPUNIT_TEST(test_eval_1);
    CPPUNIT_TEST(test_eval_2);
    CPPUNIT_TEST(test_eval_3);
    CPPUNIT_TEST(test_eval_4);

    CPPUNIT_TEST(test_eval_5);
    CPPUNIT_TEST(test_eval_6);
    CPPUNIT_TEST(test_eval_7);

    CPPUNIT_TEST(test_print);

    CPPUNIT_TEST(test_print_1);
    CPPUNIT_TEST(test_print_2);
    CPPUNIT_TEST(test_print_3);

    CPPUNIT_TEST(test_solve);

    CPPUNIT_TEST(test_solve_reverse);
    CPPUNIT_TEST(test_solve_3);
    CPPUNIT_TEST(test_solve_4);

    CPPUNIT_TEST(test_length_1);
    CPPUNIT_TEST(test_length_2);
    CPPUNIT_TEST(test_length_3);
    CPPUNIT_TEST(test_length_4);

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
