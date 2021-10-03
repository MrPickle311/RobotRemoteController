#pragma once

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
#include "../../BluetoothIO.hpp"

using namespace testing;

TEST(FirstTest, FirstTest)
{
    EXPECT_EQ(1, 1);
    ASSERT_THAT(0, Eq(0));
}

