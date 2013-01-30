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
#include <map>      // map

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
        std::istringstream r("100 200\n");
        int i;
        int j;
        const bool b = collatz_read(r, i, j);
        CPPUNIT_ASSERT(b == true);
        CPPUNIT_ASSERT(i ==   100);
        CPPUNIT_ASSERT(j ==   200);}
    
    void test_read_2 () {
        std::istringstream r("201 210\n");
        int i;
        int j;
        const bool b = collatz_read(r, i, j);
        CPPUNIT_ASSERT(b == true);
        CPPUNIT_ASSERT(i ==   201);
        CPPUNIT_ASSERT(j ==   210);}
    
    void test_read_3 () {
        std::istringstream r("900 1000\n");
        int i;
        int j;
        const bool b = collatz_read(r, i, j);
        CPPUNIT_ASSERT(b == true);
        CPPUNIT_ASSERT(i ==    900);
        CPPUNIT_ASSERT(j ==   1000);}
    
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
        const int v = collatz_eval(80, 16);
        CPPUNIT_ASSERT(v == 116);}
    
    void test_eval_6 () {
        const int v = collatz_eval(8090, 14387);
        CPPUNIT_ASSERT(v == 276);}
    
    void test_eval_7 () {
        const int v = collatz_eval(2, 2);
        CPPUNIT_ASSERT(v == 2);}
    
    // -----------------
    // find_cycle_length
    // -----------------
    
    void test_find_cycle_length_1 () {
        std::map<unsigned int, int> cycle_length_cache;
        cycle_length_cache[1] = 1;
        const int result = collatz_find_cycle_length(cycle_length_cache, 10);
        CPPUNIT_ASSERT(result == 7);
    }
    
    void test_find_cycle_length_2 () {
        std::map<unsigned int, int> cycle_length_cache;
        cycle_length_cache[1] = 1;
        const int result = collatz_find_cycle_length(cycle_length_cache, 22);
        CPPUNIT_ASSERT(result == 16);
    }
    
    void test_find_cycle_length_3 () {
        std::map<unsigned int, int> cycle_length_cache;
        cycle_length_cache[1] = 1;
        const int result = collatz_find_cycle_length(cycle_length_cache, 1);
        CPPUNIT_ASSERT(result == 1);
    }
    
    void test_find_cycle_length_4 () {
        std::map<unsigned int, int> cycle_length_cache;
        cycle_length_cache[1] = 1;
        const int result = collatz_find_cycle_length(cycle_length_cache, 516414);
        CPPUNIT_ASSERT(result == 271);
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
        collatz_print(w, 100, 200, 125);
        CPPUNIT_ASSERT(w.str() == "100 200 125\n");}
    
    void test_print_2 () {
        std::ostringstream w;
        collatz_print(w, 201, 210, 89);
        CPPUNIT_ASSERT(w.str() == "201 210 89\n");}
    
    void test_print_3 () {
        std::ostringstream w;
        collatz_print(w, 900, 1000, 174);
        CPPUNIT_ASSERT(w.str() == "900 1000 174\n");}
    
    // -----
    // solve
    // -----
    
    void test_solve () {
        std::istringstream r("1 10\n100 200\n201 210\n900 1000\n");
        std::ostringstream w;
        collatz_solve(r, w);
        CPPUNIT_ASSERT(w.str() == "1 10 20\n100 200 125\n201 210 89\n900 1000 174\n");}
    
    void test_solve_1 () {
        std::istringstream r("9012 231\n");
        std::ostringstream w;
        collatz_solve(r, w);
        CPPUNIT_ASSERT(w.str() == "9012 231 262\n");}
    
    void test_solve_2 () {
        std::istringstream r("93 1000\n");
        std::ostringstream w;
        collatz_solve(r, w);
        CPPUNIT_ASSERT(w.str() == "93 1000 179\n");}
    
    void test_solve_3 () {
        std::istringstream r("2 2\n");
        std::ostringstream w;
        collatz_solve(r, w);
        CPPUNIT_ASSERT(w.str() == "2 2 2\n");}
    
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
    CPPUNIT_TEST(test_find_cycle_length_1);
    CPPUNIT_TEST(test_find_cycle_length_2);
    CPPUNIT_TEST(test_find_cycle_length_3);
    CPPUNIT_TEST(test_find_cycle_length_4);
    CPPUNIT_TEST(test_print);
    CPPUNIT_TEST(test_print_1);
    CPPUNIT_TEST(test_print_2);
    CPPUNIT_TEST(test_print_3);
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
