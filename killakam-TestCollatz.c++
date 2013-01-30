/*
 * TestCollatz.c++
 *
 *  Created on: Jan 27, 2013
 *      Author: Cameron Rison
 */
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

struct TestCollatz: CppUnit::TestFixture {
	// ----
	// read
	// ----

	void test_read_one() {
		std::istringstream r("1 10\n");
		int i;
		int j;
		const bool b = collatz_read(r, i, j);
		CPPUNIT_ASSERT(b == true);
		CPPUNIT_ASSERT(i == 1);
		CPPUNIT_ASSERT(j == 10);
	}
	void test_read_two() {
		std::istringstream r("20 30\n");
		int i;
		int j;
		const bool b = collatz_read(r, i, j);
		CPPUNIT_ASSERT(b == true);
		CPPUNIT_ASSERT(i == 20);
		CPPUNIT_ASSERT(j == 30);

	}
	void test_read_three() {
		std::istringstream r("1000 2000\n");
		int i;
		int j;
		const bool b = collatz_read(r, i, j);
		CPPUNIT_ASSERT(b == true);
		CPPUNIT_ASSERT(i == 1000);
		CPPUNIT_ASSERT(j == 2000);

	}
	void test_read_four() {
		std::istringstream r("10000 20000\n");
		int i;
		int j;
		const bool b = collatz_read(r, i, j);
		CPPUNIT_ASSERT(b == true);
		CPPUNIT_ASSERT(i == 10000);
		CPPUNIT_ASSERT(j == 20000);

	}

	// ----
	// eval
	// ----

	void test_eval_one() {
		const int v = collatz_eval(1, 10);
		CPPUNIT_ASSERT(v == 20);
	}

	void test_eval_two() {
		const int v = collatz_eval(100, 200);
		CPPUNIT_ASSERT(v == 125);
	}

	void test_eval_three() {
		const int v = collatz_eval(201, 210);
		CPPUNIT_ASSERT(v == 89);
	}

	void test_eval_four() {
		const int v = collatz_eval(900, 1000);
		CPPUNIT_ASSERT(v == 174);
	}
	void test_eval_five() {
		const int v = collatz_eval(10, 1);
		CPPUNIT_ASSERT(v == 20);
	}

	void test_eval_six() {
		const int v = collatz_eval(31, 30);
		CPPUNIT_ASSERT(v == 107);
	}

	void test_eval_seven() {
		const int v = collatz_eval(5, 1);
		CPPUNIT_ASSERT(v == 8);
	}

	void test_eval_eight() {
		const int v = collatz_eval(200, 100);
		CPPUNIT_ASSERT(v == 125);
	}

	// -----
	// print
	// -----

	void test_print_one() {
		std::ostringstream w;
		collatz_print(w, 1, 10, 20);
		CPPUNIT_ASSERT(w.str() == "1 10 20\n");
	}
	void test_print_two() {
		std::ostringstream w;
		collatz_print(w, 100, 200, 125);
		CPPUNIT_ASSERT(w.str() == "100 200 125\n");
	}

	void test_print_three() {
		std::ostringstream w;
		collatz_print(w, 20, 210, 125);
		CPPUNIT_ASSERT(w.str() == "20 210 125\n");
	}

	void test_print_four() {
		std::ostringstream w;
		collatz_print(w, 900, 1000, 174);
		CPPUNIT_ASSERT(w.str() == "900 1000 174\n");
	}

	// -----
	// solve
	// -----

	void test_solve_one() {
		std::istringstream r("1 10\n100 200\n201 210\n900 1000\n");
		std::ostringstream w;
		collatz_solve(r, w);
		CPPUNIT_ASSERT(
				w.str() == "1 10 20\n100 200 125\n201 210 89\n900 1000 174\n");
	}

	void test_solve_two() {
		std::istringstream r("5 10\n150 200\n201 210\n200 100\n");
		std::ostringstream w;
		collatz_solve(r, w);
		CPPUNIT_ASSERT(
				w.str() == "5 10 20\n150 200 125\n201 210 89\n200 100 125\n");
	}
	void test_solve_three() {
		std::istringstream r("20 30\n1000 2000\n2050 210\n900 899\n");
		std::ostringstream w;
		collatz_solve(r, w);
		CPPUNIT_ASSERT(
				w.str()
						== "20 30 112\n1000 2000 182\n2050 210 182\n900 899 117\n");
	}

	// ----
	// compute_length
	// ---

	void test_compute_length_one() {

		const int v = collatz_compute_length(7);
		CPPUNIT_ASSERT(v == 17);

	}
	void test_compute_length_two() {

		const int v = collatz_compute_length(1000);
		CPPUNIT_ASSERT(v == 112);

	}
	void test_compute_length_three() {

		const int v = collatz_compute_length(2);
		CPPUNIT_ASSERT(v == 2);

	}
	void test_compute_length_four() {

		const int v = collatz_compute_length(1);
		CPPUNIT_ASSERT(v == 1);

	}
	// -----
	// suite
	// -----

	CPPUNIT_TEST_SUITE (TestCollatz);
	CPPUNIT_TEST (test_read_one);
	CPPUNIT_TEST (test_read_two);
	CPPUNIT_TEST (test_read_three);
	CPPUNIT_TEST (test_read_four);
	CPPUNIT_TEST (test_eval_one);
	CPPUNIT_TEST (test_eval_two);
	CPPUNIT_TEST (test_eval_three);
	CPPUNIT_TEST (test_eval_four);
	CPPUNIT_TEST (test_eval_five);
	CPPUNIT_TEST (test_eval_six);
	CPPUNIT_TEST (test_eval_seven);
	CPPUNIT_TEST (test_eval_eight);
	CPPUNIT_TEST (test_print_one);
	CPPUNIT_TEST (test_print_two);
	CPPUNIT_TEST (test_print_three);
	CPPUNIT_TEST (test_print_four);
	CPPUNIT_TEST (test_solve_one);
	CPPUNIT_TEST (test_solve_two);
	CPPUNIT_TEST (test_solve_three);
	CPPUNIT_TEST (test_compute_length_one);
	CPPUNIT_TEST (test_compute_length_two);
	CPPUNIT_TEST (test_compute_length_three);
	CPPUNIT_TEST (test_compute_length_four);CPPUNIT_TEST_SUITE_END();
};

// ----
// main
// ----

int main() {
	using namespace std;
	//ios_base::sync_with_stdio(false);  // turn off synchronization with C I/O
	cout << "TestCollatz.c++" << endl;

	CppUnit::TextTestRunner tr;
	tr.addTest(TestCollatz::suite());
	tr.run();

	cout << "Done." << endl;
	return 0;
}
