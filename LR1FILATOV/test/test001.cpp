#include <gtest/gtest.h>
#include "../include/del_vowels.h"


TEST(test_01, basic_test_set)
{
    ASSERT_TRUE(del_vowels("abcabc")=="bcbc");
}

TEST(test_02, basic_test_set)
{
    ASSERT_TRUE(del_vowels("bbbbbbbbbbb")=="bbbbbbbbbbb");
}

TEST(test_03, basic_test_set)
{
    ASSERT_TRUE(del_vowels("iiii ababababa i       k")==" bbbb        k");
}

TEST(test_04, basic_test_set)
{
    ASSERT_TRUE(del_vowels("This website is for losers LOL!")=="Ths wbst s fr lsrs LL!");
}

TEST(test_05, basic_test_set)
{
    ASSERT_TRUE(del_vowels("")=="");
}

TEST(test_06, basic_test_set)
{
    ASSERT_TRUE(del_vowels("aaaaeeeeiiiiiooooouuuuuyyyy")=="");
}

TEST(test_07, basic_test_set)
{
    ASSERT_TRUE(del_vowels("!7238428929 476 82 92348 2672346")=="!7238428929 476 82 92348 2672346");
}

TEST(test_08, basic_test_set)
{
    ASSERT_TRUE(del_vowels("Gone.Fludd is my fav singer!")=="Gn.Fldd s m fv sngr!");
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}