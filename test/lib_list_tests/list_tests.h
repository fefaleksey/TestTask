#ifndef TESTTASK_LIST_TESTS_H
#define TESTTASK_LIST_TESTS_H

#include "gtest/gtest.h"


class ListTest : public ::testing::Test {

protected:
    ListTest() = default;

    ~ListTest() override = default;

    void SetUp() override;

    void TearDown() override;
};


#endif //TESTTASK_LIST_TESTS_H
