#include "pch.h"
#include "CppUnitTest.h"
#include "..\\lab6.1.it\lab.cpp" 

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Tests
{
    TEST_CLASS(TestClass1)
    {
    public:

        TEST_METHOD(TestGenerateRandomNumber)
        {
            int min = -19;
            int max = 25;

           
            int randomNumber = generateRandomNumber(min, max);

            
            Assert::IsTrue(randomNumber >= min && randomNumber <= max);
        }
    };
}