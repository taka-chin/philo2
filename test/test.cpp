#include "CppUTest/CommandLineTestRunner.h"
#include "../include/philo.h"
#include <iostream>
#include <vector>
#include <stdio.h>
//TEST GROUPの定義
TEST_GROUP(TestFuncInc)
{
};

TEST(TestFuncInc, CheckReturnValue)
{
				char **s = malloc(sizoeof(char *) * 6);
				int i = 0;
				while(i < 5)
				{
					s[i] = (char *)malloc(sizeof("test"));
					s[i] = "test";
					i++;
				}
				s[i] = NULL
				CHECK(false, input_check(4,s));
				CHECK(true, input_check(5,s));
}

int main(int argc, char **argv)
{
				return(CommandLineTestRunner::RunAllTests(argc,argv));
}
