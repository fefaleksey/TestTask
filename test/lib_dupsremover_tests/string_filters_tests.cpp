#include "string_filters.h"

#include "string_filters_tests.h"


void RemoveDupsTest::SetUp() {}

void RemoveDupsTest::TearDown() {}

TEST_F(RemoveDupsTest, Empty) {
    char data[] = "";
    RemoveDups(data);
    EXPECT_EQ('\0', data[0]);
}

TEST_F(RemoveDupsTest, DoNothing) {
    char data1[] = "A B a A h H hf kj";
    const char expected1[] = "A B a A h H hf kj";
    RemoveDups(data1);
    EXPECT_EQ(0, strncmp(expected1, data1, 18));

    char data2[] = "a";
    const char expected2[] = "a";
    RemoveDups(data2);
    EXPECT_EQ(0, strncmp(expected2, data2, 2));

    char data3[] = "asd";
    const char expected3[] = "asd";
    RemoveDups(data3);
    EXPECT_EQ(0, strncmp(expected3, data3, 4));
}

TEST_F(RemoveDupsTest, FilterSymbols) {
    char data1[] = "AAA BBB AAA";
    const char expected1[] = "A B A";
    RemoveDups(data1);
    EXPECT_EQ(0, strncmp(expected1, data1, 6));

    char data2[] = "aaabbbddd";
    const char expected2[] = "abd";
    RemoveDups(data2);
    EXPECT_EQ(0, strncmp(expected2, data2, 4));

    char data3[] = "aaaaaaaaaaaaaaaaaaaaaabbbaaaaaaaaaaa";
    const char expected3[] = "aba";
    RemoveDups(data3);
    EXPECT_EQ(0, strncmp(expected3, data3, 4));

    char data4[] = "aaaaaaaaaaaaaaaaaaaaaabbbaaaaaaaaaaa";
    const char expected4[] = "aba";
    RemoveDups(data4);
    EXPECT_EQ(0, strncmp(expected4, data4, 4));
}
