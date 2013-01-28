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

    void test_read_1 () {
        std::istringstream r("1 10\n");
        int i;
        int j;
        const bool b = collatz_read(r, i, j);
        CPPUNIT_ASSERT(b == true);
        CPPUNIT_ASSERT(i ==    1);
        CPPUNIT_ASSERT(j ==   10);}
        
        void test_read_2 () {
        std::istringstream r("100 295\n");
        int i;
        int j;
        const bool b = collatz_read(r, i, j);
        CPPUNIT_ASSERT(b == true);
        CPPUNIT_ASSERT(i ==    100);
        CPPUNIT_ASSERT(j ==   295);}
        
        void test_read_3 () {
        std::istringstream r("300 99\n");
        int i;
        int j;
        const bool b = collatz_read(r, i, j);
        CPPUNIT_ASSERT(b == true);
        CPPUNIT_ASSERT(i ==    300);
        CPPUNIT_ASSERT(j ==   99);}
        
        void test_read_4 () {
        std::istringstream r("6 6\n");
        int i;
        int j;
        const bool b = collatz_read(r, i, j);
        CPPUNIT_ASSERT(b == true);
        CPPUNIT_ASSERT(i ==    6);
        CPPUNIT_ASSERT(j ==   6);}
        
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
        const int v = collatz_eval(100, 200);
        CPPUNIT_ASSERT(v == 125);}

    void test_eval_3 () {
        const int v = collatz_eval(201, 210);
        CPPUNIT_ASSERT(v == 89);}

    void test_eval_4 () {
        const int v = collatz_eval(900, 1000);
        CPPUNIT_ASSERT(v == 174);}
    
    //tests where i >= j    
    void test_eval_5 () {
        const int v = collatz_eval(10, 1);
        CPPUNIT_ASSERT(v == 20);}
        
    void test_eval_6 () {
        const int v = collatz_eval(200, 100);
        CPPUNIT_ASSERT(v == 125);}
        
    void test_eval_7 () {
        const int v = collatz_eval(1000, 900);
        CPPUNIT_ASSERT(v == 174);}
    
    //test where i == j    
    void test_eval_8 () {
        const int v = collatz_eval(5, 5);
        CPPUNIT_ASSERT(v == 6);}
        
    void test_eval_9 () {
        const int v = collatz_eval(1, 1);
        CPPUNIT_ASSERT(v == 1);}
        
        
    // ----------------
    // update_lazyCache
    // ----------------
    void test_update_lazyCache_1 () {
    	collatz_update_lazyCache (5, 7);
    	CPPUNIT_ASSERT(lazyCache[5] == 7);
    }
    
    void test_update_lazyCache_2 () {
    	collatz_update_lazyCache (4, 200);
    	CPPUNIT_ASSERT(lazyCache[4] == 200);
    }
    
    void test_update_lazyCache_3 () {
    	collatz_update_lazyCache (3, 100);
    	CPPUNIT_ASSERT(lazyCache[3] == 100);
    	collatz_update_lazyCache (3, 1);
    	CPPUNIT_ASSERT(lazyCache[3] == 1);
    }
    
    // -----------
    // cycleLength
    // -----------
    void test_cycle_length_1 () {
    	int count;
    	count = collatz_cycle_length (1);
    	CPPUNIT_ASSERT (count == 1);
    }
    
    void test_cycle_length_2 () {
    	int count;
    	count = collatz_cycle_length (2);
    	CPPUNIT_ASSERT (count == 2);
    }
    
    void test_cycle_length_3 () {
    	int count;
    	count = collatz_cycle_length (9);
    	CPPUNIT_ASSERT (count == 20);
    }

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
        std::istringstream r("1 1\n5 5\n10 10\n");
        std::ostringstream w;
        collatz_solve(r, w);
        CPPUNIT_ASSERT(w.str() == "1 1 1\n5 5 6\n10 10 7\n");}

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
    
    //cycle_length tests
    CPPUNIT_TEST(test_cycle_length_1);
    CPPUNIT_TEST(test_cycle_length_2);
    CPPUNIT_TEST(test_cycle_length_3);
    
    //print tests
    CPPUNIT_TEST(test_print_1);
    CPPUNIT_TEST(test_print_2);
    CPPUNIT_TEST(test_print_3);
    CPPUNIT_TEST(test_print_4);
    
    //solve tests
    CPPUNIT_TEST(test_solve_1);
    CPPUNIT_TEST(test_solve_2);
    CPPUNIT_TEST(test_solve_3);
    
    //update_lazyCache tests
    CPPUNIT_TEST(test_update_lazyCache_1);
    CPPUNIT_TEST(test_update_lazyCache_2);
    CPPUNIT_TEST(test_update_lazyCache_3);
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