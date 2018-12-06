#include "stdafx.h"
#include "CppUnitTest.h"
#include "../Lab_Alg_1/Function.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(is_test_works)
		{
			Assert::IsTrue(true);
		}

		TEST_METHOD(equal_for_different_arrays)
		{
			size_t n = 2, m = 5, k=1;
			size_t array1[5] = { 5, 4, 3, 2, 1 };
			size_t **array2 = new size_t*[n];
			for (size_t i = 0; i < n; i++)
				array2[i] = new size_t[m];
			for (size_t i = 0; i < n; i++)
				for (size_t j = 0; j < m; j++)
				{
					array2[i][j] = k;
					k++;
				}
			Assert::IsFalse(equals(array1, 5, array2, 2, 5));

			for (size_t i = 0; i < n; i++)
				delete[] array2[i];
			delete[]array2;
		}

		TEST_METHOD(equal_for_equal_arrays)
		{
			size_t n = 3, m = 3, k = 1;
			size_t array1[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9 };
			size_t **array2 = new size_t*[n];
			for (size_t i = 0; i < n; i++)
				array2[i] = new size_t[m];
			for (size_t i = 0; i < n; i++)
				for (size_t j = 0; j < m; j++)
				{
					array2[i][j] = k;
					k++;
				}
			Assert::IsTrue(equals(array1, 9, array2, n, m));

			for (size_t i = 0; i < n; i++)
				delete[] array2[i];
			delete[]array2;
		}
		
	        TEST_METHOD(function_for_print)
		{
			size_t n = 2, m = 5, k = 33;
			size_t **array2 = new size_t*[n];
			for (size_t i = 0; i < n; i++)
				array2[i] = new size_t[m];
			k = put_array(array2, n, m, 1);
			Assert::IsFalse(for_print(2, 5, k) == 3);

			for (size_t i = 0; i < n; i++)
				delete[] array2[i];
			delete[]array2;
		}
		
		TEST_METHOD(equal_for_function_put)
		{
			size_t n = 2, m = 2, k = 0;
			size_t array1[4] = { 1, 2, 3, 4 };
			size_t **array2 = new size_t*[n];
			for (size_t i = 0; i < n; i++)
				array2[i] = new size_t[m];
			k = put_array(array2, n, m, 1);
			Assert::IsTrue(equals(array1, 4, array2, n, m));

			for (size_t i = 0; i < n; i++)
				delete[] array2[i];
			delete[]array2;
		}

		TEST_METHOD(equal_for_function_put_elem)
		{
			size_t n = 2, m = 2, k = 0;
			size_t array1[4] = { 1, 2, 3, 4 };
			size_t **array2 = new size_t*[n];
			for (size_t i = 0; i < n; i++)
				array2[i] = new size_t[m];
			k = put_array(array2, n, m, 1);
			Assert::IsTrue(array1[1]==array2[0][1]);

			for (size_t i = 0; i < n; i++)
				delete[] array2[i];
			delete[]array2;
		}

		TEST_METHOD(equal_for_function_put_different_size)
		{
			size_t n = 4, m = 4, k = 0;
			size_t array1[15] = { 1, 2, 4, 7, 3, 5, 8, 11, 6, 9, 12, 14, 10, 13, 15 };
			size_t **array2 = new size_t*[n];
			for (size_t i = 0; i < n; i++)
				array2[i] = new size_t[m];
			k = put_array(array2, n, m, 1);
			Assert::IsFalse(equals(array1, 15, array2, n, m));

			for (size_t i = 0; i < n; i++)
				delete[] array2[i];
			delete[]array2;
		}

		TEST_METHOD(unusual_1x5)
		{
			size_t n = 1, m = 5, k = 0;
			size_t array1[5] = { 1, 2, 3, 4, 5 };
			size_t **array2 = new size_t*[n];
			for (size_t i = 0; i < n; i++)
				array2[i] = new size_t[m];
			k = put_array(array2, n, m, 1);
			Assert::IsTrue(equals(array1, 5, array2, n, m));

			for (size_t i = 0; i < n; i++)
				delete[] array2[i];
			delete[]array2;
		}

		TEST_METHOD(unusual_5x1)
		{
			size_t n = 5, m = 1, k = 0;
			size_t array1[5] = { 1, 2, 3, 4, 5 };
			size_t **array2 = new size_t*[n];
			for (size_t i = 0; i < n; i++)
				array2[i] = new size_t[m];
			k = put_array(array2, n, m, 1);
			Assert::IsTrue(equals(array1, 5, array2, n, m));

			for (size_t i = 0; i < n; i++)
				delete[] array2[i];
			delete[]array2;
		}

		TEST_METHOD(unusual_1x1)
		{
			size_t n = 1, m = 1, k = 0;
			size_t array1[1] = { 1 };
			size_t **array2 = new size_t*[n];
			for (size_t i = 0; i < n; i++)
				array2[i] = new size_t[m];
			k = put_array(array2, n, m, 1);
			Assert::IsTrue(equals(array1, 1, array2, n, m));

			for (size_t i = 0; i < n; i++)
				delete[] array2[i];
			delete[]array2;
		}
		
	};
}
