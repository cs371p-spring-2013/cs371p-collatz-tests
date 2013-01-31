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

    void test_read_1 () {			//implement 1-3
        std::istringstream r("450 9\n");
        int i;
        int j;
        const bool b = collatz_read(r, i, j);
        CPPUNIT_ASSERT(b == true);
        CPPUNIT_ASSERT(i ==    450);
        CPPUNIT_ASSERT(j ==   9);}

    void test_read_2 () {
        std::istringstream r("010 3625\n");
        int i;
        int j;
        const bool b = collatz_read(r, i, j);
        CPPUNIT_ASSERT(b == true);
        CPPUNIT_ASSERT(i ==    10);
        CPPUNIT_ASSERT(j ==   3625);}

    void test_read_3 () {
        std::istringstream r("96 65\n");
        int i;
        int j;
        const bool b = collatz_read(r, i, j);
        CPPUNIT_ASSERT(b == true);
        CPPUNIT_ASSERT(i ==   96);
        CPPUNIT_ASSERT(j ==   65);}


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

    //new tests
    void test_eval_5() {			//eval should ignore the 0's before value 10
      const int v = collatz_eval(00010, 200);
      CPPUNIT_ASSERT(v == 125);
    }
    void test_eval_6() {			//input order shouldn't affect results
      const int v = collatz_eval(10000, 2000);
      const int v2= collatz_eval(2000, 10000);
      CPPUNIT_ASSERT(v == v2);
    }
    void test_eval_7(){
      const int v = collatz_eval(250, 250);
      CPPUNIT_ASSERT(v==110);

    }
    
    // -----
    // print
    // -----

    void test_print () {
        std::ostringstream w;
        collatz_print(w, 1, 10, 20);
        CPPUNIT_ASSERT(w.str() == "1 10 20\n");}

    void test_print_1 () {
        std::ostringstream w;
        collatz_print(w, 10, 1, 20);
        CPPUNIT_ASSERT(w.str() == "10 1 20\n");}

    void test_print_2 () {
        std::ostringstream w;
        collatz_print(w, 2000, 10000, 262);
        CPPUNIT_ASSERT(w.str() == "2000 10000 262\n");}

    void test_print_3 () {
        std::ostringstream w;
        collatz_print(w, 1001, 1001, 143);
        CPPUNIT_ASSERT(w.str() == "1001 1001 143\n");}

    // -----
    // cycle
    // -----
 
    void test_cycle(){
      int c = 3;
      int n = 25;
      int check = collatz_cycle(c,n);
      CPPUNIT_ASSERT(check == 32);
    }
 
    void test_cycle_2(){
      int c = 35;
      int n = 1;
      int check = collatz_cycle(c,n);
      CPPUNIT_ASSERT(check == 14);
    } 

    void test_cycle_1(){
      int c = 3;
      int n = 0;
      int check = collatz_cycle(c,n);
      CPPUNIT_ASSERT(check == 7);
    }


    // -----
    // solve
    // -----

    void test_solve () {
        std::istringstream r("1 10\n100 200\n201 210\n900 1000\n");
        std::ostringstream w;
        collatz_solve(r, w);
        CPPUNIT_ASSERT(w.str() == "1 10 20\n100 200 125\n201 210 89\n900 1000 174\n");}
    void test_solve_1 () {
        std::istringstream r("668 9936\n568 1225\n");
        std::ostringstream w;
        collatz_solve(r, w);
        CPPUNIT_ASSERT(w.str() == "668 9936 262\n568 1225 182\n");}
    void test_solve_2 () {
        std::istringstream r("9936 668\n");
        std::ostringstream w;
        collatz_solve(r, w);
        CPPUNIT_ASSERT(w.str() == "9936 668 262\n");}
    void test_solve_3 () {
        std::istringstream r("3 3\n96 95\n210 201\n1 10000\n");
        std::ostringstream w;
        collatz_solve(r, w);
        CPPUNIT_ASSERT(w.str() == "3 3 8\n96 95 106\n210 201 89\n1 10000 262\n");}

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
    CPPUNIT_TEST(test_cycle);
    CPPUNIT_TEST(test_cycle_1);
    CPPUNIT_TEST(test_cycle_2);
    CPPUNIT_TEST(test_solve);
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
