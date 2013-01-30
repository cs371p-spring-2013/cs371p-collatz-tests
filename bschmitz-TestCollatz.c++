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
#include <sstream> // istringtstream, ostringstream
#include <string> // ==

#include "cppunit/extensions/HelperMacros.h" // CPPUNIT_TEST, CPPUNIT_TEST_SUITE, CPPUNIT_TEST_SUITE_END
#include "cppunit/TestFixture.h" // TestFixture
#include "cppunit/TextTestRunner.h" // TextTestRunner

#include "Collatz.h"

#include <ctime>

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
        CPPUNIT_ASSERT(i == 1);
        CPPUNIT_ASSERT(j == 10);}

    void test_read_unexpected_type_i_param () {
        std::istringstream r("A 1\n");
        int i;
        int j;
        const bool i_unexpected_type = collatz_read(r, i, j);
        CPPUNIT_ASSERT(i_unexpected_type == false);}

    void test_read_unexpected_type_j_param () {
        std::istringstream r("1 A\n");
        int i;
        int j;
        const bool j_unexpected_type = collatz_read(r, i, j);
        CPPUNIT_ASSERT(j_unexpected_type == false);}

    void test_read_unexpected_type_both_params () {
        std::istringstream r("A B\n");
        int i;
        int j;
        const bool both_unexpected_types = collatz_read(r, i, j);
        CPPUNIT_ASSERT(both_unexpected_types == false);}

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

    void test_eval_snake_eyes () {
        const int v = collatz_eval(1, 1);
        CPPUNIT_ASSERT(v == 1);}

    void test_eval_max () {
        const int v = collatz_eval(999999, 999999);
        CPPUNIT_ASSERT(v == 259);}

    void test_eval_sphere_v2_int_overflow () {
        const int v = collatz_eval(113383, 113383);
        CPPUNIT_ASSERT(v == 248);}

    void test_eval_i_greater_than_j () {
        const int v = collatz_eval(16128, 2216);
        CPPUNIT_ASSERT(v == 276);}
 
    void test_eval_large_range () {
        const int v = collatz_eval(384281, 417720);
        CPPUNIT_ASSERT(v == 449);}

    void test_eval_lower_bound_inclusive () {
        const int v = collatz_eval(3, 4);
        CPPUNIT_ASSERT(v == 8);}

    void test_eval_upper_bound_inclusive () {
        const int v = collatz_eval(2, 3);
        CPPUNIT_ASSERT(v == 8);}

    void test_eval_both_bounds_inclusive () {
        const int v = collatz_eval(3, 3);
        CPPUNIT_ASSERT(v == 8);}

    // -----
    // print
    // -----

    void test_print () {
        std::ostringstream w;
        collatz_print(w, 1, 10, 20);
        CPPUNIT_ASSERT(w.str() == "1 10 20\n");}

    void test_print_min_values () {
        std::ostringstream w;
        collatz_print(w, 1, 1, 1);
        CPPUNIT_ASSERT(w.str() == "1 1 1\n");}
    
    void test_print_different_lengths () {
        std::ostringstream w;
        collatz_print(w, 255, 32767, 2147483647);
        CPPUNIT_ASSERT(w.str() == "255 32767 2147483647\n");}

    void test_print_max_values () {
        std::ostringstream w;
        collatz_print(w, 999999, 999999, 999999);
        CPPUNIT_ASSERT(w.str() == "999999 999999 999999\n");}

    // -----
    // solve
    // -----

    void test_solve_1 () {
        std::istringstream r("1 10\n100 200\n201 210\n900 1000\n");
        std::ostringstream w;
        collatz_solve(r, w);
        CPPUNIT_ASSERT(w.str() == "1 10 20\n100 200 125\n201 210 89\n900 1000 174\n");}

    void test_solve_2 () {
        std::istringstream r("100 200\n");
        std::ostringstream w;
        collatz_solve(r, w);
        CPPUNIT_ASSERT(w.str() == "100 200 125\n");}
    
    void test_solve_3 () {
        std::istringstream r("900 1000\n");
        std::ostringstream w;
        collatz_solve(r, w);
        CPPUNIT_ASSERT(w.str() == "900 1000 174\n");}

    void test_solve_4 () {
        std::istringstream r("1000 900\n");
        std::ostringstream w;
        collatz_solve(r, w);
        CPPUNIT_ASSERT(w.str() == "1000 900 174\n");}


    // -----
    // speed
    // -----

    void eval_speed_benchmark () {
        // Used to benchmark speed of collatz_eval
        using namespace std;
        clock_t begin = clock();
        collatz_eval(1, 999999);
        clock_t end = clock();
        double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
        printf ("Eval Benchmark - Time Elapsed: %f seconds\n", elapsed_secs);}


    // -----
    // suite
    // -----

    CPPUNIT_TEST_SUITE(TestCollatz);
    CPPUNIT_TEST(test_read);
    CPPUNIT_TEST(test_read_unexpected_type_i_param);
    CPPUNIT_TEST(test_read_unexpected_type_j_param);
    CPPUNIT_TEST(test_read_unexpected_type_both_params);
    CPPUNIT_TEST(test_eval_1);
    CPPUNIT_TEST(test_eval_2);
    CPPUNIT_TEST(test_eval_3);
    CPPUNIT_TEST(test_eval_4);
    CPPUNIT_TEST(test_eval_i_greater_than_j);
    CPPUNIT_TEST(test_eval_large_range);
    CPPUNIT_TEST(test_eval_snake_eyes);
    CPPUNIT_TEST(test_eval_max);
    CPPUNIT_TEST(test_eval_sphere_v2_int_overflow);
    CPPUNIT_TEST(test_eval_lower_bound_inclusive);
    CPPUNIT_TEST(test_eval_upper_bound_inclusive);
    CPPUNIT_TEST(test_eval_both_bounds_inclusive);
    CPPUNIT_TEST(test_print);
    CPPUNIT_TEST(test_print_min_values);
    CPPUNIT_TEST(test_print_different_lengths);
    CPPUNIT_TEST(test_print_max_values);
    CPPUNIT_TEST(test_solve_1);
    CPPUNIT_TEST(test_solve_2);
    CPPUNIT_TEST(test_solve_3);
    CPPUNIT_TEST(test_solve_4);
    CPPUNIT_TEST(eval_speed_benchmark);
    CPPUNIT_TEST_SUITE_END();};

// ----
// main
// ----

int main () {
    using namespace std;
    ios_base::sync_with_stdio(false); // turn off synchronization with C I/O
    cout << "TestCollatz.c++" << endl;

    CppUnit::TextTestRunner tr;
    tr.addTest(TestCollatz::suite());
    tr.run();

    cout << "Done." << endl;
    return 0;}
