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

    // -----
    // print
    // -----

    void test_print () {
        std::ostringstream w;
        collatz_print(w, 1, 10, 20);
        CPPUNIT_ASSERT(w.str() == "1 10 20\n");}

    // -----
    // solve
    // -----

    void test_solve () {
        std::istringstream r("1 10\n100 200\n201 210\n900 1000\n");
        std::ostringstream w;
        collatz_solve(r, w);
        CPPUNIT_ASSERT(w.str() == "1 10 20\n100 200 125\n201 210 89\n900 1000 174\n");}



    // --------
    // my tests
    // --------

    // read
    void my_test_read_1 () {
        std::istringstream r("");
        int i;
        int j;
        const bool b = collatz_read(r, i, j);
        CPPUNIT_ASSERT(b == false);}
    
    void my_test_read_2 () {
        std::istringstream r("1 999999\n");
        int i;
        int j;
        const bool b = collatz_read(r, i, j);
        CPPUNIT_ASSERT(b == true);
        CPPUNIT_ASSERT(i == 1);
        CPPUNIT_ASSERT(j == 999999);}
    
    void my_test_read_3 () {
        std::istringstream r("999999 1\n");
        int i;
        int j;
        const bool b = collatz_read(r, i, j);
        CPPUNIT_ASSERT(b == true);
        CPPUNIT_ASSERT(i == 999999);
        CPPUNIT_ASSERT(j == 1);}
    
    void my_test_read_4 () {
        std::istringstream r("1 1\n");
        int i;
        int j;
        const bool b = collatz_read(r, i, j);
        CPPUNIT_ASSERT(b == true);
        CPPUNIT_ASSERT(i == 1);
        CPPUNIT_ASSERT(j == 1);}
    
    void my_test_read_5 () {
        std::istringstream r("654321 654321\n");
        int i;
        int j;
        const bool b = collatz_read(r, i, j);
        CPPUNIT_ASSERT(b == true);
        CPPUNIT_ASSERT(i == 654321);
        CPPUNIT_ASSERT(j == 654321);}
        
    void my_test_read_6 () {
        std::istringstream r("999999 999999\n");
        int i;
        int j;
        const bool b = collatz_read(r, i, j);
        CPPUNIT_ASSERT(b == true);
        CPPUNIT_ASSERT(i == 999999);
        CPPUNIT_ASSERT(j == 999999);}
    
    // eval
    void my_test_eval_1 () {
        const int v = collatz_eval(1, 999999);
        CPPUNIT_ASSERT(v == 525);}
        
    void my_test_eval_2 () {
        const int v = collatz_eval(1, 1);
        CPPUNIT_ASSERT(v == 1);}
        
    void my_test_eval_3 () {
        const int v = collatz_eval(654321, 654321);
        CPPUNIT_ASSERT(v == 186);}
        
    void my_test_eval_4 () {
        const int v = collatz_eval(999999, 1);
        CPPUNIT_ASSERT(v == 525);}
        
    void my_test_eval_5 () {
        const int v = collatz_eval(1000, 900);
        CPPUNIT_ASSERT(v == 174);}
    
    // calc
    void my_test_calc_1 () {
        const int v = collatz_calc(1);
        CPPUNIT_ASSERT(v == 1);}
    
    void my_test_calc_2 () {
        const int v = collatz_calc(999999);
        CPPUNIT_ASSERT(v == 259);}
    
    void my_test_calc_3 () {
        const int v = collatz_calc(654321);
        CPPUNIT_ASSERT(v == 186);}

    void my_test_calc_4 () {
        const int v = collatz_calc(159);
        CPPUNIT_ASSERT(v == 55);}

    void my_test_calc_5 () {
        const int v = collatz_calc(1024);
        CPPUNIT_ASSERT(v == 11);}
    
    // print
    void my_test_print_1 () {
        std::ostringstream w;
        collatz_print(w, 1, 1, 1);
        CPPUNIT_ASSERT(w.str() == "1 1 1\n");}

    void my_test_print_2 () {
        std::ostringstream w;
        collatz_print(w, 1, 999999, 525);
        CPPUNIT_ASSERT(w.str() == "1 999999 525\n");}

    void my_test_print_3 () {
        std::ostringstream w;
        collatz_print(w, 1000, 900, 174);
        CPPUNIT_ASSERT(w.str() == "1000 900 174\n");}
        
    void my_test_print_4 () {
        std::ostringstream w;
        collatz_print(w, 123456789, 987654321, 100000000);
        CPPUNIT_ASSERT(w.str() == "123456789 987654321 100000000\n");}
        
    void my_test_print_5 () {
        std::ostringstream w;
        collatz_print(w, 9, 100, 1344);
        CPPUNIT_ASSERT(w.str() == "9 100 1344\n");}

    // solve
    void my_test_solve_1 () {
        std::istringstream r("1 1\n3 3\n5 5\n7 7\n9 9\n");
        std::ostringstream w;
        collatz_solve(r, w);
        CPPUNIT_ASSERT(w.str() == "1 1 1\n3 3 8\n5 5 6\n7 7 17\n9 9 20\n");}
        
    void my_test_solve_2 () {
        std::istringstream r("1 999999\n999999 1\n");
        std::ostringstream w;
        collatz_solve(r, w);
        CPPUNIT_ASSERT(w.str() == "1 999999 525\n999999 1 525\n");}

    void my_test_solve_3 () {
        std::istringstream r("4962 652\n64 236\n328 2688\n2271 1779\n");
        std::ostringstream w;
        collatz_solve(r, w);
        CPPUNIT_ASSERT(w.str() == "4962 652 238\n64 236 128\n328 2688 209\n2271 1779 183\n");}



    // -----
    // suite
    // -----

    CPPUNIT_TEST_SUITE(TestCollatz);
    CPPUNIT_TEST(test_read);
    CPPUNIT_TEST(test_eval_1);
    CPPUNIT_TEST(test_eval_2);
    CPPUNIT_TEST(test_eval_3);
    CPPUNIT_TEST(test_eval_4);
    CPPUNIT_TEST(test_print);
    CPPUNIT_TEST(test_solve);
    
    // my suite
    CPPUNIT_TEST(my_test_read_1);
    CPPUNIT_TEST(my_test_read_2);
    CPPUNIT_TEST(my_test_read_3);
    CPPUNIT_TEST(my_test_read_4);
    CPPUNIT_TEST(my_test_read_5);
    CPPUNIT_TEST(my_test_read_6);
    CPPUNIT_TEST(my_test_eval_1);
    CPPUNIT_TEST(my_test_eval_2);
    CPPUNIT_TEST(my_test_eval_3);
    CPPUNIT_TEST(my_test_eval_4);
    CPPUNIT_TEST(my_test_eval_5);
    CPPUNIT_TEST(my_test_calc_1);
    CPPUNIT_TEST(my_test_calc_2);
    CPPUNIT_TEST(my_test_calc_3);
    CPPUNIT_TEST(my_test_calc_4);
    CPPUNIT_TEST(my_test_calc_5);
    CPPUNIT_TEST(my_test_print_1);
    CPPUNIT_TEST(my_test_print_2);
    CPPUNIT_TEST(my_test_print_3);
    CPPUNIT_TEST(my_test_print_4);
    CPPUNIT_TEST(my_test_print_5);
    CPPUNIT_TEST(my_test_solve_1);
    CPPUNIT_TEST(my_test_solve_2);
    CPPUNIT_TEST(my_test_solve_3);
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
