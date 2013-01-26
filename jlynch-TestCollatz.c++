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

    //My read tests
    
    void test_read_1 () {
        std::istringstream r("8 8\n");
        int i;
        int j;
        const bool b = collatz_read(r, i, j);
        CPPUNIT_ASSERT(b == true);
        CPPUNIT_ASSERT(i ==    8);
        CPPUNIT_ASSERT(j ==   8);}

    void test_read_2 () {
        std::istringstream r("");
        int i;
        int j;
        const bool b = collatz_read(r, i, j);
        CPPUNIT_ASSERT(b == false);}

    void test_read_3 () {
        std::istringstream r("10 1");
        int i;
        int j;
        const bool b = collatz_read(r, i, j);
        CPPUNIT_ASSERT(b == true);
        CPPUNIT_ASSERT(i ==    10);
        CPPUNIT_ASSERT(j ==   1);}

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

    //Test handling of wrong order inputs
    void test_eval_5 () {
        const int v = collatz_eval(1000, 900);
        CPPUNIT_ASSERT(v == 174);}
      //as input string? (might be bad idea)

    //Test handling of range from n to n
    void test_eval_6 () {
        const int v = collatz_eval(8, 8);
        CPPUNIT_ASSERT(v == 4);}

    //Verify that range is inclusive of right boundary
    void test_eval_7 () {
        const int v = collatz_eval(1, 2);
        CPPUNIT_ASSERT(v == 2);}

    //Verify that range is inclusive of left boundary
    void test_eval_8 () {
        const int v = collatz_eval(3, 4);
        CPPUNIT_ASSERT(v == 8);}

    // -----
    // length 
    // -----
    void test_length_1(){
      const int v = collatz_length(1);
      CPPUNIT_ASSERT_EQUAL(1, v);
    }

    void test_length_2(){
      const int v = collatz_length(2);
      CPPUNIT_ASSERT_EQUAL(2, v);
    }

    void test_length_3(){
      const int v = collatz_length(8);
      CPPUNIT_ASSERT_EQUAL(4, v);
    }

    void test_length_4(){
      const int v = collatz_length(5);
      CPPUNIT_ASSERT_EQUAL(6, v);
    }

    // -----
    // print
    // -----

    void test_print () {
        std::ostringstream w;
        collatz_print(w, 1, 10, 20);
        CPPUNIT_ASSERT(w.str() == "1 10 20\n");}

    //My print tests

    void test_print_1 () {
        std::ostringstream w;
        collatz_print(w, 2, 11, 21);
        CPPUNIT_ASSERT(w.str() == "2 11 21\n");}

    void test_print_2 () {
        std::ostringstream w;
        collatz_print(w, 10, 2, 20);
        CPPUNIT_ASSERT(w.str() == "10 2 20\n");}

    void test_print_3 () {
        std::ostringstream w;
        collatz_print(w, 1300, 4, 15);
        CPPUNIT_ASSERT(w.str() == "1300 4 15\n");}




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

    void test_solve_n () {
        std::istringstream r("8 8\n");
        std::ostringstream w;
        collatz_solve(r, w);
        CPPUNIT_ASSERT(w.str() == "8 8 4\n");}

    void test_solve_boundaries () {
        std::istringstream r("1 2\n3 4\n");
        std::ostringstream w;
        collatz_solve(r, w);
        CPPUNIT_ASSERT(w.str() == "1 2 2\n3 4 8\n");}

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
    CPPUNIT_TEST(test_eval_8);

    CPPUNIT_TEST(test_print);

    CPPUNIT_TEST(test_print_1);
    CPPUNIT_TEST(test_print_2);
    CPPUNIT_TEST(test_print_3);

    CPPUNIT_TEST(test_solve);

    CPPUNIT_TEST(test_solve_n);
    CPPUNIT_TEST(test_solve_reverse);
    CPPUNIT_TEST(test_solve_boundaries);

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
