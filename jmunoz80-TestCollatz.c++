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

    void test_read_largenum(){
        std::istringstream r("7000 10000\n");
        int i, j;
        const bool b = collatz_read(r, i, j);
        CPPUNIT_ASSERT(b == true);
        CPPUNIT_ASSERT(i == 7000);
        CPPUNIT_ASSERT(j == 10000);}

    void test_read_longrange(){
        std::istringstream r("10000 999999\n");
        int i, j;
        const bool b = collatz_read(r, i, j);
        CPPUNIT_ASSERT(b == true);
        CPPUNIT_ASSERT(i == 10000);
        CPPUNIT_ASSERT(j == 999999);}

    void test_read_reverse(){
        std::istringstream r("210 200\n");
        int i, j;
        const bool b = collatz_read(r, i, j);
        CPPUNIT_ASSERT(b == true);
        CPPUNIT_ASSERT(i == 210);
        CPPUNIT_ASSERT(j == 200);}

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

    void test_eval_basic () {
        const int v = collatz_eval(900, 1000);
        CPPUNIT_ASSERT(v == 174);}

    void test_eval_single() {
        const int v = collatz_eval(5000,5001);
        CPPUNIT_ASSERT(v == 65);}
    
    void test_eval_segfault1() {
        const int v = collatz_eval(5670, 5680);
        CPPUNIT_ASSERT(v == 205);}
    
    void test_eval_largenum(){
        const int v = collatz_eval( 7000, 10000);
        CPPUNIT_ASSERT(v == 260);}

    void test_eval_longrange(){
        const int v = collatz_eval(10000 ,999999 );
        CPPUNIT_ASSERT(v == 525);}

    void test_eval_reverse(){
        const int v = collatz_eval(210 ,200);
        CPPUNIT_ASSERT(v == 89);}
    // -----
    // print
    // -----

    void test_print () {
        std::ostringstream w;
        collatz_print(w, 1, 10, 20);
        CPPUNIT_ASSERT(w.str() == "1 10 20\n");}
    
    void test_print_basic () {
        std::ostringstream w;
        collatz_print(w, 100, 200, 125);
        CPPUNIT_ASSERT(w.str() == "100 200 125\n");}

    void test_print_largenum () {
       std::ostringstream w;
       collatz_print(w, 7000, 10000, 260);
       CPPUNIT_ASSERT(w.str() == "7000 10000 260\n");}

     void test_print_rand () {
       std::ostringstream w;
       collatz_print(w, 767058, 299709, 470);
       CPPUNIT_ASSERT(w.str() == "767058 299709 470\n");}


    // -----
    // solve
    // -----

    void test_solve () {
        std::istringstream r("1 10\n100 200\n201 210\n900 1000\n");
        std::ostringstream w;
        collatz_solve(r, w);
        CPPUNIT_ASSERT(w.str() == "1 10 20\n100 200 125\n201 210 89\n900 1000 174\n");}

    void test_solve_incsize () {
        std::istringstream r("900 1000\n1000 2000\n2000 4000\n4001 4100\n4100 4200\n");
        std::ostringstream w;
        collatz_solve(r, w);
        CPPUNIT_ASSERT(w.str() == "900 1000 174\n1000 2000 182\n2000 4000 238\n4001 4100 189\n4100 4200 189\n");}

    void test_solve_corner () {
        std::istringstream r("1 10\n10000 999999\n");
        std::ostringstream w;
        collatz_solve(r, w);
        CPPUNIT_ASSERT(w.str() == "1 10 20\n10000 999999 525\n");}

    void test_solve_rand () {
        std::istringstream r("796893 550552\n230298 90033\n399135 443182\n898507 990416\n767058 299709\n");
        std::ostringstream w;
        collatz_solve(r, w);
        CPPUNIT_ASSERT(w.str() == "796893 550552 468\n230298 90033 386\n399135 443182 449\n898507 990416 476\n767058 299709 470\n");}


    // -----
    // suite
    // -----

    CPPUNIT_TEST_SUITE(TestCollatz);
    CPPUNIT_TEST(test_read);
    CPPUNIT_TEST(test_read_largenum);
    CPPUNIT_TEST(test_read_longrange);
    CPPUNIT_TEST(test_read_reverse);
    CPPUNIT_TEST(test_eval_1);
    CPPUNIT_TEST(test_eval_2);
    CPPUNIT_TEST(test_eval_3);
    CPPUNIT_TEST(test_eval_basic);
    CPPUNIT_TEST(test_eval_single);
    CPPUNIT_TEST(test_eval_segfault1);
    CPPUNIT_TEST(test_eval_largenum);
    CPPUNIT_TEST(test_eval_longrange);
    CPPUNIT_TEST(test_eval_reverse);
    CPPUNIT_TEST(test_print);
    CPPUNIT_TEST(test_print_basic);
    CPPUNIT_TEST(test_print_largenum);
    CPPUNIT_TEST(test_print_rand);
    CPPUNIT_TEST(test_solve);
    CPPUNIT_TEST(test_solve_incsize);
    CPPUNIT_TEST(test_solve_corner);
    CPPUNIT_TEST(test_solve_rand);
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
