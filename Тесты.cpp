#include <gtest/gtest.h>

using ::testing::Return;
using ::testing::InSequence;
using ::testing::StrEq;

TEST(ClassThatUsesDBTest, OpenConnectionSuccess) {
    auto mock_conn = std::make_shared<MockDBConnection>();
    EXPECT_CALL(*mock_conn, open())
        .Times(1)
        .WillOnce(Return(true));

    ClassThatUsesDB obj(mock_conn);
    EXPECT_TRUE(obj.openConnection());
}

TEST(ClassThatUsesDBTest, UseConnectionExecutesQuery) {
    auto mock_conn = std::make_shared<MockDBConnection>();
    std::string query = "SELECT * FROM table";

    EXPECT_CALL(*mock_conn, execQuery(StrEq(query)))
        .Times(1)
        .WillOnce(Return("mocked_result"));

    ClassThatUsesDB obj(mock_conn);
    std::string result = obj.useConnection(query);
    EXPECT_EQ(result, "mocked_result");
}

TEST(ClassThatUsesDBTest, CloseConnectionCalled) {
    auto mock_conn = std::make_shared<MockDBConnection>();

    EXPECT_CALL(*mock_conn, close())
        .Times(1);

    ClassThatUsesDB obj(mock_conn);
    obj.closeConnection();
}
