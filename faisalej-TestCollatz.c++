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
    % g++ -pedantic -std=c++0x -Wall Collatz.c++ TestCollatz.c++ -lcppunit -ldl -o TestCollatz.c++.app
    % valgrind TestCollatz.c++.app >& TestCollatz.c++.out
*/

/*Name: Faisal Ejaz
 *UT EID: fe2333
 *UT CS ID: faisalej
 *CS 371P - Downing
 *Collatz Project
 *TestCollatz.c++
 *Runs tests on all functions from Collatz.c++ and RunCollatz.c++ to check correctness
 *
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

    void test_read_1 () {
        std::istringstream r("1 10\n");
        int i;
        int j;
        const bool b = collatz_read(r, i, j);
        CPPUNIT_ASSERT(b == true);
        CPPUNIT_ASSERT(i ==    1);
        CPPUNIT_ASSERT(j ==   10);}
        
        void test_read_2 () {
        std::istringstream r("1 1\n");
        int i;
        int j;
        const bool b = collatz_read(r, i, j);
        CPPUNIT_ASSERT(b == true);
        CPPUNIT_ASSERT(i ==    1);
        CPPUNIT_ASSERT(j ==   1);}
        
        void test_read_3 () {
        std::istringstream r("999 2\n");
        int i;
        int j;
        const bool b = collatz_read(r, i, j);
        CPPUNIT_ASSERT(b == true);
        CPPUNIT_ASSERT(i ==    999);
        CPPUNIT_ASSERT(j ==   2);}
        
        void test_read_4 () {
        std::istringstream r("5 22\n");
        int i;
        int j;
        const bool b = collatz_read(r, i, j);
        CPPUNIT_ASSERT(b == true);
        CPPUNIT_ASSERT(i ==    5);
        CPPUNIT_ASSERT(j ==   22);}
        
        //test faliure cases
        void test_read_5 () {
        std::istringstream r("\n");
        int i;
        int j;
        const bool b = collatz_read(r, i, j);
        CPPUNIT_ASSERT(b == false);}
        
        void test_read_6 () {
        std::istringstream r("");
        int i;
        int j;
        const bool b = collatz_read(r, i, j);
        CPPUNIT_ASSERT(b == false);}

    // ----
    // eval
    // ----
     void test_eval_1 () {
        const int v = collatz_eval(1, 10);
        CPPUNIT_ASSERT(v == 20);}

    void test_eval_2 () {
        const int v = collatz_eval(125, 9999);
        CPPUNIT_ASSERT(v == 262);}

    void test_eval_3 () {
        const int v = collatz_eval(201, 210);
        CPPUNIT_ASSERT(v == 89);}

    void test_eval_4 () {
        const int v = collatz_eval(900, 1000);
        CPPUNIT_ASSERT(v == 174);}
    
    //test if i >= j    
    void test_eval_5 () {
        const int v = collatz_eval(10, 1);
        CPPUNIT_ASSERT(v == 20);}
        
    void test_eval_6 () {
        const int v = collatz_eval(200, 100);
        CPPUNIT_ASSERT(v == 125);}
        
    void test_eval_7 () {
        const int v = collatz_eval(29962, 627);
        CPPUNIT_ASSERT(v == 308);}

    void test_eval_8 () {
        const int v = collatz_eval(4913, 4834);
        CPPUNIT_ASSERT(v == 179);}
        
    void test_eval_9 () {
        const int v = collatz_eval(533460, 591101);
        CPPUNIT_ASSERT(v == 452);}

    //test if i==j
    void test_eval_10 () {
        const int v = collatz_eval(49, 49);
        CPPUNIT_ASSERT(v == 25);}

    // -----
    // print
    // -----

    void test_print_1 () {
        std::ostringstream w;
        collatz_print(w, 1, 10, 20);
        CPPUNIT_ASSERT(w.str() == "1 10 20\n");}
        
    void test_print_2 () {
        std::ostringstream w;
        collatz_print(w, 200, 100, 125);
        CPPUNIT_ASSERT(w.str() == "200 100 125\n");}
        
    void test_print_3 () {
        std::ostringstream w;
        collatz_print(w, 100, 200, 125);
        CPPUNIT_ASSERT(w.str() == "100 200 125\n");}
        
    void test_print_4 () {
        std::ostringstream w;
        collatz_print(w, 1, 1, 1);
        CPPUNIT_ASSERT(w.str() == "1 1 1\n");}

    // -----
    // solve
    // Tests solve.Checks for large numbers and corner cases
    // -----

    void test_solve_1 () {
        std::istringstream r("1 10\n100 200\n201 210\n900 1000\n");
        std::ostringstream w;
        collatz_solve(r, w);
        CPPUNIT_ASSERT(w.str() == "1 10 20\n100 200 125\n201 210 89\n900 1000 174\n");}
        
    void test_solve_2 () {
        std::istringstream r("10 1\n200 100\n210 201\n1000 900\n");
        std::ostringstream w;
        collatz_solve(r, w);
        CPPUNIT_ASSERT(w.str() == "10 1 20\n200 100 125\n210 201 89\n1000 900 174\n");}
        
    void test_solve_3 () {
        std::istringstream r("45418 24444\n6735 24133\n160359 3494\n");
        std::ostringstream w;
        collatz_solve(r, w);
        CPPUNIT_ASSERT(w.str() == "45418 24444 324\n6735 24133 282\n160359 3494 383\n");
    }


    void test_solve_4 () {
        std::istringstream r("42825 46148\n15782 677\n25094 48153\n8099 40298\n");
        std::ostringstream w;
        collatz_solve(r, w);
        CPPUNIT_ASSERT(w.str() == "42825 46148 314\n15782 677 276\n25094 48153 324\n8099 40298 324\n");}


    void test_collatz_cycle_1(){
       const int v = collatz_eval(1, 1);
        CPPUNIT_ASSERT(v == 1);
    }    

    void test_collatz_cycle_2(){
       const int v = collatz_eval(1, 1000000);
        CPPUNIT_ASSERT(v == 525);
    } 

    void test_collatz_cycle_3(){
       const int v = collatz_eval(7016, 2);
        CPPUNIT_ASSERT(v == 262);
    } 

    void test_collatz_cycle_4(){
       const int v = collatz_eval(572, 988);
        CPPUNIT_ASSERT(v == 179);
    } 


    // -----
    // suite
    // -----

    CPPUNIT_TEST_SUITE(TestCollatz);
    
    //read tests
    CPPUNIT_TEST(test_read_1);
    CPPUNIT_TEST(test_read_2);
    CPPUNIT_TEST(test_read_3);
    CPPUNIT_TEST(test_read_4);
    CPPUNIT_TEST(test_read_5);
    CPPUNIT_TEST(test_read_6);
    
    //eval tests
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
    
    //print tests
    CPPUNIT_TEST(test_print_1);
    CPPUNIT_TEST(test_print_2);
    CPPUNIT_TEST(test_print_3);
    CPPUNIT_TEST(test_print_4);
    
    //solve tests
    CPPUNIT_TEST(test_solve_1);
    CPPUNIT_TEST(test_solve_2);
    CPPUNIT_TEST(test_solve_3);

    CPPUNIT_TEST(test_collatz_cycle_1);
    CPPUNIT_TEST(test_collatz_cycle_2);
    CPPUNIT_TEST(test_collatz_cycle_3);
    CPPUNIT_TEST(test_collatz_cycle_4);

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