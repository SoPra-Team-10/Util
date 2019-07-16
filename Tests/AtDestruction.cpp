#include <gtest/gtest.h>

#include "AtDestruction.h"

TEST(AtDestruction, DestructorCalled) {
    bool gotCalled = false;
    auto setBool = [&gotCalled](){
        gotCalled = true;
    };

    {
        util::AtDestruction<int> atDestruction{setBool, 0};
        ASSERT_FALSE(gotCalled);
    }

    ASSERT_TRUE(gotCalled);
}