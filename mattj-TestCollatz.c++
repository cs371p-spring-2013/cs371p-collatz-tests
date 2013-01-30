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
#include <sstream> // istringtstream, ostringstream
#include <string> // ==

#include "cppunit/extensions/HelperMacros.h" // CPPUNIT_TEST, CPPUNIT_TEST_SUITE, CPPUNIT_TEST_SUITE_END
#include "cppunit/TestFixture.h" // TestFixture
#include "cppunit/TextTestRunner.h" // TextTestRunner

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
        CPPUNIT_ASSERT(i == 1);
        CPPUNIT_ASSERT(j == 10);}

    void test_read_2 (){
        std::istringstream r("6 999\n");
int i;
int j;
const bool b = collatz_read(r, i, j);
CPPUNIT_ASSERT(b == true);
CPPUNIT_ASSERT(i == 6);
CPPUNIT_ASSERT(j == 999);
    }

    void test_read_3 (){
        std::istringstream r("56 86753\n");
int i;
int j;
const bool b = collatz_read(r, i, j);
CPPUNIT_ASSERT(b == true);
CPPUNIT_ASSERT(i == 56);
CPPUNIT_ASSERT(j == 86753);
    }

    void test_read_4 (){
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

    void test_eval_5 () {
        const int v = collatz_eval(44, 9701);
CPPUNIT_ASSERT(v == 262);
    }

    void test_eval_6 () {
        const int v = collatz_eval(51, 3754);
CPPUNIT_ASSERT(v == 238);
    }

    void test_eval_7 () {
        const int v = collatz_eval(142961, 143039);
CPPUNIT_ASSERT(v == 282);
    }


    // ------------
    // cycle_length
    // ------------

    void test_cycle_length_1() {
      const int v = collatz_cycle_length(1000000);
      CPPUNIT_ASSERT(v == 153);
    }

    void test_cycle_length_2() {
      const int v = collatz_cycle_length(1);
      CPPUNIT_ASSERT(v == 1);
    }

    void test_cycle_length_3() {
      const int v = collatz_cycle_length(8023);
      CPPUNIT_ASSERT(v == 190);
    }



    // -----
    // print
    // -----

    void test_print () {
        std::ostringstream w;
        collatz_print(w, 1, 10, 20);
        CPPUNIT_ASSERT(w.str() == "1 10 20\n");}

    void test_print_2 () {
        std::ostringstream w;
        collatz_print(w, 5, 50, 350);
        CPPUNIT_ASSERT(w.str() == "5 50 350\n");
    }

    void test_print_3 () {
        std::ostringstream w;
        collatz_print(w, 86, 75, 309);
        CPPUNIT_ASSERT(w.str() == "86 75 309\n");
    }

    void test_print_4 () {
        std::ostringstream w;
        collatz_print(w, 400, 300, 200);
        CPPUNIT_ASSERT(w.str() == "400 300 200\n");
    }

    // -----
    // solve
    // -----

    void test_solve () {
        std::istringstream r("1 10\n100 200\n201 210\n900 1000\n");
        std::ostringstream w;
        collatz_solve(r, w);
        CPPUNIT_ASSERT(w.str() == "1 10 20\n100 200 125\n201 210 89\n900 1000 174\n");}

    void test_solve_2 () {
        std::istringstream r("812331 811981\n509268 508952\n");
        std::ostringstream w;
        collatz_solve(r, w);
        CPPUNIT_ASSERT(w.str() == "812331 811981 362\n509268 508952 377\n");
    }

    void test_solve_3 () {
        std::istringstream r("606620 606387\n304788 305097\n");
        std::ostringstream w;
        collatz_solve(r, w);
        CPPUNIT_ASSERT(w.str() == "606620 606387 310\n304788 305097 278\n");
    }

    void test_solve_4 () {
        std::istringstream r("619544 619317\n136525 136570\n");
        std::ostringstream w;
        collatz_solve(r, w);
        CPPUNIT_ASSERT(w.str() == "619544 619317 341\n136525 136570 207\n");
    }

    // -----
    // suite
    // -----

    CPPUNIT_TEST_SUITE(TestCollatz);
    CPPUNIT_TEST(test_read);
    CPPUNIT_TEST(test_read_2);
    CPPUNIT_TEST(test_read_3);
    CPPUNIT_TEST(test_read_4);
    CPPUNIT_TEST(test_eval_1);
    CPPUNIT_TEST(test_eval_2);
    CPPUNIT_TEST(test_eval_3);
    CPPUNIT_TEST(test_eval_4);
    CPPUNIT_TEST(test_eval_5);
    CPPUNIT_TEST(test_eval_6);
    CPPUNIT_TEST(test_eval_7);
    CPPUNIT_TEST(test_cycle_length_1);
    CPPUNIT_TEST(test_cycle_length_2);
    CPPUNIT_TEST(test_cycle_length_3);
    CPPUNIT_TEST(test_print);
    CPPUNIT_TEST(test_print_2);
    CPPUNIT_TEST(test_print_3);
    CPPUNIT_TEST(test_print_4);
    CPPUNIT_TEST(test_solve);
    CPPUNIT_TEST(test_solve_2);
    CPPUNIT_TEST(test_solve_3);
    CPPUNIT_TEST(test_solve_4);
    CPPUNIT_TEST_SUITE_END();};

// ----
// main
// ----

int main () {
    using namespace std;
    // ios_base::sync_with_stdio(false); // turn off synchronization with C I/O
    cout << "TestCollatz.c++" << endl;

    CppUnit::TextTestRunner tr;
    tr.addTest(TestCollatz::suite());
    tr.run();

    cout << "Done." << endl;
    return 0;}
