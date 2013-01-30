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

    void test_read_2 () {
        std::istringstream r("58 100\n");
        int i;
        int j;
        const bool b = collatz_read(r, i, j);
        CPPUNIT_ASSERT(b == true);
        CPPUNIT_ASSERT(i == 58);
        CPPUNIT_ASSERT(j == 100);}

    void test_read_3 () {
        std::istringstream r("2 6\n");
        int i;
        int j;
        const bool b = collatz_read(r, i, j);
        CPPUNIT_ASSERT(b == true);
        CPPUNIT_ASSERT(i == 2);
        CPPUNIT_ASSERT(j == 6);}

    void test_read_4 () {
        std::istringstream r("1 10\n");
        int i;
        int j;
        const bool b = collatz_read(r, i, j);
        CPPUNIT_ASSERT(b == true);
        CPPUNIT_ASSERT(i == 1);
        CPPUNIT_ASSERT(j == 10);}

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
        const int v = collatz_eval(10, 1);
        CPPUNIT_ASSERT(v == 20);}

    void test_eval_6 () {
        const int v = collatz_eval(261853, 570779);
        CPPUNIT_ASSERT(v == 470);}

    void test_eval_7 () {
        const int v = collatz_eval(795, 598);
        CPPUNIT_ASSERT(v == 171);}    

    // -----
    // print
    // -----

    void test_print () {
        std::ostringstream w;
        collatz_print(w, 1, 10, 20);
        CPPUNIT_ASSERT(w.str() == "1 10 20\n");}
    void test_print_1 () {
        std::ostringstream w;
        collatz_print(w, 9991, 4142, 262);
        CPPUNIT_ASSERT(w.str() == "9991 4142 262\n");}
    void test_print_2 () {
        std::ostringstream w;
        collatz_print(w, 24719, 26176, 264);
        CPPUNIT_ASSERT(w.str() == "24719 26176 264\n");}
    void test_print_3 () {
        std::ostringstream w;
        collatz_print(w, 8000, 12089, 268);
        CPPUNIT_ASSERT(w.str() == "8000 12089 268\n");}

    // -----
    // solve
    // -----

    void test_solve () {
        std::istringstream r("1 10\n100 200\n201 210\n900 1000\n");
        std::ostringstream w;
        collatz_solve(r, w);
        CPPUNIT_ASSERT(w.str() == "1 10 20\n100 200 125\n201 210 89\n900 1000 174\n");}

    void test_solve_1 () {
        std::istringstream r("1 1\n2 2\n4 4");
        std::ostringstream w;
        collatz_solve(r, w);
        CPPUNIT_ASSERT(w.str() == "1 1 1\n2 2 2\n4 4 3\n");}

    void test_solve_2 () {
        std::istringstream r("1 1\n");
        std::ostringstream w;
        collatz_solve(r, w);
        CPPUNIT_ASSERT(w.str() == "1 1 1\n");}

    void test_solve_3 () {
        std::istringstream r("1 1\n100 100\n");
        std::ostringstream w;
        collatz_solve(r, w);
        CPPUNIT_ASSERT(w.str() == "1 1 1\n100 100 26\n");}

    // -----
    // cycle_length
    // -----  

    void test_cycle_length_1 () {
        const int v = collatz_cycle_length(1);
        CPPUNIT_ASSERT(v == 1);
    }

    void test_cycle_length_2 () {
        const int v = collatz_cycle_length(9);
        CPPUNIT_ASSERT(v == 20);
    }
    void test_cycle_length_3 () {
        const int v = collatz_cycle_length(53);
        CPPUNIT_ASSERT(v == 12);
    }
    void test_cycle_length_4 () {
        const int v = collatz_cycle_length(999999);
        CPPUNIT_ASSERT(v == 259);
    }
    void test_cycle_length_5 () {
        const int v = collatz_cycle_length(8569);
        CPPUNIT_ASSERT(v == 79);
    }
    
    // -----
    // fillcache
    void test_fillcache_1 (){
        int cache[10];
        cache[2] = 2;
        CPPUNIT_ASSERT(cache[2] == 2);
    }
    void test_fillcache_2 (){
        int cache[10];
        cache[4] = 3;

        CPPUNIT_ASSERT(cache[4] == 3);
    }
    void test_fillcache_3 (){
        int cache[10];
        cache[8] = 4;
        CPPUNIT_ASSERT(cache[8] == 4);
    }
    // -----  

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
    CPPUNIT_TEST(test_print);
    CPPUNIT_TEST(test_print_1);
    CPPUNIT_TEST(test_print_2);
    CPPUNIT_TEST(test_print_3);
    CPPUNIT_TEST(test_solve);
    CPPUNIT_TEST(test_solve_1);
    CPPUNIT_TEST(test_solve_2);
    CPPUNIT_TEST(test_solve_3);
    CPPUNIT_TEST(test_cycle_length_1);
    CPPUNIT_TEST(test_cycle_length_2);
    CPPUNIT_TEST(test_cycle_length_3);
    CPPUNIT_TEST(test_cycle_length_4);
    CPPUNIT_TEST(test_cycle_length_5);
    CPPUNIT_TEST(test_fillcache_1);
    CPPUNIT_TEST(test_fillcache_2);
    CPPUNIT_TEST(test_fillcache_3);
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