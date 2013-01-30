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


    // -------------
    // student tests
    // -------------

    //read
    void s_test_read_1 () {
        std::istringstream r("a 10\n");
        int i;
        int j;
        const bool b = collatz_read(r, i, j);
        CPPUNIT_ASSERT(b == false);
    }
    void s_test_read_2 () {
        std::istringstream r("999999 999999\n");
        int i;
        int j;
        const bool b = collatz_read(r, i, j);
        CPPUNIT_ASSERT(b == true);
        CPPUNIT_ASSERT(i == 999999);
        CPPUNIT_ASSERT(j == 999999);
    }
    void s_test_read_3 () {
        std::istringstream r("12345 54321\n");
        int i;
        int j;
        const bool b = collatz_read(r, i, j);
        CPPUNIT_ASSERT(b == true);
        CPPUNIT_ASSERT(i == 12345);
        CPPUNIT_ASSERT(j == 54321);
    }
    void s_test_read_4 () {
        std::istringstream r("1 1\n");
        int i;
        int j;
        const bool b = collatz_read(r, i, j);
        CPPUNIT_ASSERT(b == true);
        CPPUNIT_ASSERT(i ==    1);
        CPPUNIT_ASSERT(j ==    1);
    }
    void s_test_read_5 () {
        std::istringstream r("");
        int i;
        int j;
        const bool b = collatz_read(r, i, j);
        CPPUNIT_ASSERT(b == false);
    }

    //eval
    void s_test_eval_1 () {
        const int v = collatz_eval(1, 999999);
        CPPUNIT_ASSERT(v == 525);
    }
    void s_test_eval_2 () {
        const int v = collatz_eval(1, 20);
        CPPUNIT_ASSERT(v == 21);
    }
    void s_test_eval_3 () {
        const int v = collatz_eval(1, 1);
        CPPUNIT_ASSERT(v == 1);
    }
    void s_test_eval_4 () {
        const int v = collatz_eval(1, 100);
        CPPUNIT_ASSERT(v == 119);
    }
    void s_test_eval_5 () {
        const int v = collatz_eval(100, 200);
        CPPUNIT_ASSERT(v == 125);
    }

    //print
    void s_test_print_1 () {
        std::ostringstream w;
        collatz_print(w, 15, 105, 205);
        CPPUNIT_ASSERT(w.str() == "15 105 205\n");
    }
    void s_test_print_2 () {
        std::ostringstream w;
        collatz_print(w, 7854, 1, 2000);
        CPPUNIT_ASSERT(w.str() == "7854 1 2000\n");
    }
    void s_test_print_3 () {
        std::ostringstream w;
        collatz_print(w, 1, 1, 1);
        CPPUNIT_ASSERT(w.str() == "1 1 1\n");
    }
    void s_test_print_4 () {
        std::ostringstream w;
        collatz_print(w, 999999, 999999, 999999);
        CPPUNIT_ASSERT(w.str() == "999999 999999 999999\n");
    }
    void s_test_print_5 () {
        std::ostringstream w;
        collatz_print(w, 123, 456, 789);
        CPPUNIT_ASSERT(w.str() == "123 456 789\n");
    }

    //solve
    void s_test_solve_1 () {
        std::istringstream r("1 999999\n900 1000\n");
        std::ostringstream w;
        collatz_solve(r, w);
        CPPUNIT_ASSERT(w.str() == "1 999999 525\n900 1000 174\n");
    }
    void s_test_solve_2 () {
        std::istringstream r("1 1\n1 2\n1 3\n");
        std::ostringstream w;
        collatz_solve(r, w);
        CPPUNIT_ASSERT(w.str() == "1 1 1\n1 2 2\n1 3 8\n");
    }
    void s_test_solve_3 () {
        std::istringstream r("1 4\n1 5\n");
        std::ostringstream w;
        collatz_solve(r, w);
        CPPUNIT_ASSERT(w.str() == "1 4 8\n1 5 8\n");
    }
    void s_test_solve_4 () {
        std::istringstream r("5 5\n");
        std::ostringstream w;
        collatz_solve(r, w);
        CPPUNIT_ASSERT(w.str() == "5 5 6\n");
    }
    void s_test_solve_5 () {
        std::istringstream r("1 10\n1 10\n1 10\n");
        std::ostringstream w;
        collatz_solve(r, w);
        CPPUNIT_ASSERT(w.str() == "1 10 20\n1 10 20\n1 10 20\n");
    }

    //compute
    void s_test_compute_1 () {
        const int v = collatz_compute(1);
        CPPUNIT_ASSERT(v == 1);
    }
    void s_test_compute_2 () {
        const int v = collatz_compute(12345);
        CPPUNIT_ASSERT(v == 51);
    }
    void s_test_compute_3 () {
        const int v = collatz_compute(999999);
        CPPUNIT_ASSERT(v == 259);
    }
    void s_test_compute_4 () {
        const int v = collatz_compute(10);
        CPPUNIT_ASSERT(v == 7);
    }
    void s_test_compute_5 () {
        const int v = collatz_compute(84765);
        CPPUNIT_ASSERT(v == 59);
    }


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

    // student tests
    CPPUNIT_TEST(s_test_read_1);
    CPPUNIT_TEST(s_test_read_2);
    CPPUNIT_TEST(s_test_read_3);
    CPPUNIT_TEST(s_test_read_4);
    CPPUNIT_TEST(s_test_read_5);
    CPPUNIT_TEST(s_test_eval_1);
    CPPUNIT_TEST(s_test_eval_2);
    CPPUNIT_TEST(s_test_eval_3);
    CPPUNIT_TEST(s_test_eval_4);
    CPPUNIT_TEST(s_test_eval_5);
    CPPUNIT_TEST(s_test_print_1);
    CPPUNIT_TEST(s_test_print_2);
    CPPUNIT_TEST(s_test_print_3);
    CPPUNIT_TEST(s_test_print_4);
    CPPUNIT_TEST(s_test_print_5);
    CPPUNIT_TEST(s_test_solve_1);
    CPPUNIT_TEST(s_test_solve_2);
    CPPUNIT_TEST(s_test_solve_3);
    CPPUNIT_TEST(s_test_solve_4);
    CPPUNIT_TEST(s_test_solve_5);
    CPPUNIT_TEST(s_test_compute_1);
    CPPUNIT_TEST(s_test_compute_2);
    CPPUNIT_TEST(s_test_compute_3);
    CPPUNIT_TEST(s_test_compute_4);
    CPPUNIT_TEST(s_test_compute_5);
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
