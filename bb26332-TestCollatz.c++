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

    void test_read (){
        std::istringstream r("1 10\n");
        int i;
        int j;
        const bool b = collatz_read(r, i, j);
        CPPUNIT_ASSERT(b == true);
        CPPUNIT_ASSERT(i ==    1);
        CPPUNIT_ASSERT(j ==   10);
    }

    void test_read_1(){
        std::istringstream r("25 36\n");
        int i;
        int j;
        const bool b = collatz_read(r, i, j);
        CPPUNIT_ASSERT(b == true);
        CPPUNIT_ASSERT(i == 25);
        CPPUNIT_ASSERT(j == 36);
    }    

    void test_read_2(){
        std::istringstream r("");
        int i;
        int j;
        const bool b = collatz_read(r, i, j);
        CPPUNIT_ASSERT(b == false);
    }    

    // ----
    // eval
    // ----

    void test_eval_1 (){
        const int v = collatz_eval(1, 10);
        CPPUNIT_ASSERT(v == 20);
    }

    void test_eval_2 (){
        const int v = collatz_eval(100, 200);
        CPPUNIT_ASSERT(v == 125);
    }

    void test_eval_3 (){
        const int v = collatz_eval(201, 210);
        CPPUNIT_ASSERT(v == 89);
    }

    void test_eval_4 (){
        const int v = collatz_eval(900, 1000);
        CPPUNIT_ASSERT(v == 174);
    }

    void test_eval_5 (){
        const int v = collatz_eval(900, 1000);
        CPPUNIT_ASSERT(v == 174);
    }

    void test_eval_6(){
        const int v = collatz_eval(21000, 22000);
        CPPUNIT_ASSERT(v == 269);
    }

    void test_eval_7(){
        const int v = collatz_eval(997000, 996001);
        CPPUNIT_ASSERT(v == 365);   
    }

    // -----
    // print
    // -----

    void test_print (){
        std::ostringstream w;
        collatz_print(w, 1, 10, 20);
        CPPUNIT_ASSERT(w.str() == "1 10 20\n");
    }

    void test_print_1 (){
        std::ostringstream w;
        collatz_print(w, 100, 110, 4);
        CPPUNIT_ASSERT(w.str() == "100 110 4\n");
    }

    void test_print_2 (){
        std::ostringstream w;
        collatz_print(w, 9, 11, 12);
        CPPUNIT_ASSERT(w.str() == "9 11 12\n");
    }

    void test_print_3 () {
        std::ostringstream w;
        collatz_print(w, 1, 2, 3);
        CPPUNIT_ASSERT(w.str() == "1 2 3\n");
    }

    // -----
    // solve
    // -----

    void test_solve (){
        std::istringstream r("1 10\n100 200\n201 210\n900 1000\n");
        std::ostringstream w;
        collatz_solve(r, w);
        CPPUNIT_ASSERT(w.str() == "1 10 20\n100 200 125\n201 210 89\n900 1000 174\n");
    }

    void test_solve_1 (){
        std::istringstream r("997000 996001\n");
        std::ostringstream w;
        collatz_solve(r, w);
        CPPUNIT_ASSERT(w.str() == "997000 996001 365\n");
    }

    void test_solve_2 (){
        std::istringstream r("21000 22000\n210 201\n");
        std::ostringstream w;
        collatz_solve(r, w);
        CPPUNIT_ASSERT(w.str() == "21000 22000 269\n210 201 89\n");
    }

    // -----
    // suite
    // -----

    CPPUNIT_TEST_SUITE(TestCollatz);
    
    CPPUNIT_TEST(test_read);
    CPPUNIT_TEST(test_read_1);
    CPPUNIT_TEST(test_read_2);

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
    CPPUNIT_TEST(test_solve_1);
    CPPUNIT_TEST(test_solve_2);
    
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
