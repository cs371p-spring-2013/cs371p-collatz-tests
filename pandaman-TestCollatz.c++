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

    void test_read_1 () {
        std::istringstream r("43 657\n");
        int i;
        int j;
        const bool b = collatz_read(r, i, j);
        CPPUNIT_ASSERT(b == true);
        CPPUNIT_ASSERT(i ==    43);
        CPPUNIT_ASSERT(j ==   657);}

    void test_read_2 () {
        std::istringstream r("4570 6129\n");
        int i;
        int j;
        const bool b = collatz_read(r, i, j);
        CPPUNIT_ASSERT(b == true);
        CPPUNIT_ASSERT(i ==    4570);
        CPPUNIT_ASSERT(j ==   6129);}

    void test_read_3 () {
        std::istringstream r("2526 3\n");
        int i;
        int j;
        const bool b = collatz_read(r, i, j);
        CPPUNIT_ASSERT(b == true);
        CPPUNIT_ASSERT(i ==    2526);
        CPPUNIT_ASSERT(j ==   3);}

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
        const int v = collatz_eval(1943, 2281);
        CPPUNIT_ASSERT(v == 183);}

    void test_eval_6 () {
        const int v = collatz_eval(615, 2974);
        CPPUNIT_ASSERT(v == 217);}

    void test_eval_7 () {
        const int v = collatz_eval(7459, 6357);
        CPPUNIT_ASSERT(v == 257);}

    // --------
    // eval_aux
    // --------

    void test_eval_aux_1 () {
	int count = 0;
	int* count_ptr = &count;
        collatz_eval_aux(1, count_ptr);
        CPPUNIT_ASSERT((*count_ptr) == 1);
    }

    void test_eval_aux_2 () {
    int count = 0;
    int* count_ptr = &count;
        collatz_eval_aux(205, count_ptr);
        CPPUNIT_ASSERT((*count_ptr) == 27);
    }

    void test_eval_aux_3 () {
    int count = 0;
    int* count_ptr = &count;
        collatz_eval_aux(913, count_ptr);
        CPPUNIT_ASSERT((*count_ptr) == 130);
    }

    void test_eval_aux_4 () {
    int count = 0;
    int* count_ptr = &count;
        collatz_eval_aux(3636, count_ptr);
        CPPUNIT_ASSERT((*count_ptr) == 18);
    }

    void test_eval_aux_5 () {
    int count = 0;
    int* count_ptr = &count;
        collatz_eval_aux(3705, count_ptr);
        CPPUNIT_ASSERT((*count_ptr) == 163);
    }

    // -------------
    // even_odd_eval
    // -------------
    
    void test_even_odd_eval_1 () {
        const bool v = even_odd_eval(1);
        CPPUNIT_ASSERT(v == false);
    }

    void test_even_odd_eval_2 () {
        const bool v = even_odd_eval(2);
        CPPUNIT_ASSERT(v == true);
    }

    void test_even_odd_eval_3 () {
        const bool v = even_odd_eval(11);
        CPPUNIT_ASSERT(v == false);
    }

    void test_even_odd_eval_4 () {
        const bool v = even_odd_eval(1432);
        CPPUNIT_ASSERT(v == true);
    }

    void test_even_odd_eval_5 () {
        const bool v = even_odd_eval(23451);
        CPPUNIT_ASSERT(v == false);
    }

    void test_even_odd_eval_6 () {
        const bool v = even_odd_eval(223);
        CPPUNIT_ASSERT(v == false);
    }

    void test_even_odd_eval_7 () {
        const bool v = even_odd_eval(222);
        CPPUNIT_ASSERT(v == true);
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
        collatz_print(w, 3360, 9320, 262);
        CPPUNIT_ASSERT(w.str() == "3360 9320 262\n");}

    void test_print_2 () {
        std::ostringstream w;
        collatz_print(w, 615, 2974, 217);
        CPPUNIT_ASSERT(w.str() == "615 2974 217\n");}

    void test_print_3 () {
        std::ostringstream w;
        collatz_print(w, 7459, 6357, 257);
        CPPUNIT_ASSERT(w.str() == "7459 6357 257\n");}

    // -----
    // solve
    // -----

    void test_solve () {
        std::istringstream r("1 10\n100 200\n201 210\n900 1000\n");
        std::ostringstream w;
        collatz_solve(r, w);
        CPPUNIT_ASSERT(w.str() == "1 10 20\n100 200 125\n201 210 89\n900 1000 174\n");}

        void test_solve_1 () {
        std::istringstream r("3135 3760\n5662 9091\n9118 159\n505 3808\n");
        std::ostringstream w;
        collatz_solve(r, w);
        CPPUNIT_ASSERT(w.str() == "3135 3760 238\n5662 9091 262\n9118 159 262\n505 3808 238\n");}

        void test_solve_2 () {
        std::istringstream r("8005 9834\n1255 4674\n4397 3045\n5165 6024\n");
        std::ostringstream w;
        collatz_solve(r, w);
        CPPUNIT_ASSERT(w.str() == "8005 9834 260\n1255 4674 238\n4397 3045 238\n5165 6024 236\n");}

        void test_solve_3 () {
        std::istringstream r("3959 8018\n9956 6148\n2112 7570\n5266 7378\n");
        std::ostringstream w;
        collatz_solve(r, w);
        CPPUNIT_ASSERT(w.str() == "3959 8018 262\n9956 6148 262\n2112 7570 262\n5266 7378 262\n");}

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
    CPPUNIT_TEST(test_eval_aux_1);
    CPPUNIT_TEST(test_eval_aux_2);
    CPPUNIT_TEST(test_eval_aux_3);
    CPPUNIT_TEST(test_eval_aux_4);
    CPPUNIT_TEST(test_eval_aux_5);
    CPPUNIT_TEST(test_eval_aux_6);
    CPPUNIT_TEST(test_even_odd_eval_1);
    CPPUNIT_TEST(test_even_odd_eval_2);
    CPPUNIT_TEST(test_even_odd_eval_3);
    CPPUNIT_TEST(test_even_odd_eval_4);
    CPPUNIT_TEST(test_even_odd_eval_5);
    CPPUNIT_TEST(test_even_odd_eval_6);
    CPPUNIT_TEST(test_even_odd_eval_7);
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
