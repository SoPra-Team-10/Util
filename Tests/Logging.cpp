#include <gtest/gtest.h>

#include "Logging.hpp"

using namespace util;

TEST(Logging, NoLogSendError) {
    std::stringstream stringstream;

    Logging logging{stringstream, 0};
    ASSERT_NO_THROW(logging.error("abc"));
    ASSERT_TRUE(stringstream.str().empty());
}

TEST(Logging, NoLogSendWarn) {
    std::stringstream stringstream;

    Logging logging{stringstream, 0};
    ASSERT_NO_THROW(logging.warn("abc"));
    ASSERT_TRUE(stringstream.str().empty());
}

TEST(Logging, NoLogSendInfo) {
    std::stringstream stringstream;

    Logging logging{stringstream, 0};
    ASSERT_NO_THROW(logging.info("abc"));
    ASSERT_TRUE(stringstream.str().empty());
}

TEST(Logging, NoLogSendDebug) {
    std::stringstream stringstream;

    Logging logging{stringstream, 0};
    ASSERT_NO_THROW(logging.debug("abc"));
    ASSERT_TRUE(stringstream.str().empty());
}




TEST(Logging, ErrorSendError) {
    std::stringstream stringstream;

    Logging logging{stringstream, 1};
    ASSERT_NO_THROW(logging.error("abc"));
    ASSERT_FALSE(stringstream.str().empty());
}

TEST(Logging, ErrorSendWarn) {
    std::stringstream stringstream;

    Logging logging{stringstream, 1};
    ASSERT_NO_THROW(logging.warn("abc"));
    ASSERT_TRUE(stringstream.str().empty());
}

TEST(Logging, ErrorSendInfo) {
    std::stringstream stringstream;

    Logging logging{stringstream, 1};
    ASSERT_NO_THROW(logging.info("abc"));
    ASSERT_TRUE(stringstream.str().empty());
}

TEST(Logging, ErrorSendDebug) {
    std::stringstream stringstream;

    Logging logging{stringstream, 1};
    ASSERT_NO_THROW(logging.debug("abc"));
    ASSERT_TRUE(stringstream.str().empty());
}



TEST(Logging, WarnSendError) {
    std::stringstream stringstream;

    Logging logging{stringstream, 2};
    ASSERT_NO_THROW(logging.error("abc"));
    ASSERT_FALSE(stringstream.str().empty());
}

TEST(Logging, WarnSendWarn) {
    std::stringstream stringstream;

    Logging logging{stringstream, 2};
    ASSERT_NO_THROW(logging.warn("abc"));
    ASSERT_FALSE(stringstream.str().empty());
}

TEST(Logging, WarnSendInfo) {
    std::stringstream stringstream;

    Logging logging{stringstream, 2};
    ASSERT_NO_THROW(logging.info("abc"));
    ASSERT_TRUE(stringstream.str().empty());
}

TEST(Logging, WarnSendDebug) {
    std::stringstream stringstream;

    Logging logging{stringstream, 2};
    ASSERT_NO_THROW(logging.debug("abc"));
    ASSERT_TRUE(stringstream.str().empty());
}




TEST(Logging, InfoSendError) {
    std::stringstream stringstream;

    Logging logging{stringstream, 3};
    ASSERT_NO_THROW(logging.error("abc"));
    ASSERT_FALSE(stringstream.str().empty());
}

TEST(Logging, InfoSendWarn) {
    std::stringstream stringstream;

    Logging logging{stringstream, 3};
    ASSERT_NO_THROW(logging.warn("abc"));
    ASSERT_FALSE(stringstream.str().empty());
}

TEST(Logging, InfoSendInfo) {
    std::stringstream stringstream;

    Logging logging{stringstream, 3};
    ASSERT_NO_THROW(logging.info("abc"));
    ASSERT_FALSE(stringstream.str().empty());
}

TEST(Logging, InfoSendDebug) {
    std::stringstream stringstream;

    Logging logging{stringstream, 3};
    ASSERT_NO_THROW(logging.debug("abc"));
    ASSERT_TRUE(stringstream.str().empty());
}




TEST(Logging, DebugSendError) {
    std::stringstream stringstream;

    Logging logging{stringstream, 4};
    ASSERT_NO_THROW(logging.error("abc"));
    ASSERT_FALSE(stringstream.str().empty());
}

TEST(Logging, DebugSendWarn) {
    std::stringstream stringstream;

    Logging logging{stringstream, 4};
    ASSERT_NO_THROW(logging.warn("abc"));
    ASSERT_FALSE(stringstream.str().empty());
}

TEST(Logging, DebugSendInfo) {
    std::stringstream stringstream;

    Logging logging{stringstream, 4};
    ASSERT_NO_THROW(logging.info("abc"));
    ASSERT_FALSE(stringstream.str().empty());
}

TEST(Logging, DebugSendDebug) {
    std::stringstream stringstream;

    Logging logging{stringstream, 4};
    ASSERT_NO_THROW(logging.debug("abc"));
    ASSERT_FALSE(stringstream.str().empty());
}



TEST(Logging, ArbitrarySendError) {
    std::stringstream stringstream;

    Logging logging{stringstream, 42};
    ASSERT_NO_THROW(logging.error("abc"));
    ASSERT_FALSE(stringstream.str().empty());
}

TEST(Logging, ArbitrarySendWarn) {
    std::stringstream stringstream;

    Logging logging{stringstream, 42};
    ASSERT_NO_THROW(logging.warn("abc"));
    ASSERT_FALSE(stringstream.str().empty());
}

TEST(Logging, ArbitrarySendInfo) {
    std::stringstream stringstream;

    Logging logging{stringstream, 42};
    ASSERT_NO_THROW(logging.info("abc"));
    ASSERT_FALSE(stringstream.str().empty());
}

TEST(Logging, ArbitrarySendDebug) {
    std::stringstream stringstream;

    Logging logging{stringstream, 42};
    ASSERT_NO_THROW(logging.debug("abc"));
    ASSERT_FALSE(stringstream.str().empty());
}
