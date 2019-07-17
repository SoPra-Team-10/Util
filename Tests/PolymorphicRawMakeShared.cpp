#include <gtest/gtest.h>
#include "PolymorphicRawMakeShared.h"

class Base {
public:
    virtual int a() { return 0;}
    virtual ~Base() = default;
};

class Child1 : public Base {
public:
    int a() override { return 1;}
    void b() {}
};
class Child2 : public Base {
public:
    int a() override { return 2;}
    void c() {}
};
class Child3 : public Base {
public:
    int a() override { return 3;}
    void d() {}
};

TEST(PolymorphicRawMakeShared, Child1) {
    Child1 c;
    Base *base = &c;
    std::shared_ptr<Base> sharedPtr;
    EXPECT_NO_THROW((sharedPtr = util::makeSharedFromRaw<Base, Child1, Child2, Child3>(base)));
    EXPECT_EQ(sharedPtr->a(), c.a());
}

TEST(PolymorphicRawMakeShared, Child2) {
    Child2 c;
    Base *base = &c;
    std::shared_ptr<Base> sharedPtr;
    EXPECT_NO_THROW((sharedPtr = util::makeSharedFromRaw<Base, Child1, Child2, Child3>(base)));
    EXPECT_EQ(sharedPtr->a(), c.a());
}

TEST(PolymorphicRawMakeShared, Child3) {
    Child3 c;
    Base *base = &c;
    std::shared_ptr<Base> sharedPtr;
    EXPECT_NO_THROW((sharedPtr = util::makeSharedFromRaw<Base, Child1, Child2, Child3>(base)));
    EXPECT_EQ(sharedPtr->a(), c.a());
}

TEST(PolymorphicRawMakeShared, NoChildFound) {
    Child3 c;
    Base *base = &c;
    EXPECT_THROW((util::makeSharedFromRaw<Base, Child1, Child2>(base)), std::runtime_error);
}