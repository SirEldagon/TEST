TEST(ClassThatUsesDBTest, FullWorkflow) {
    auto mock_conn = std::make_shared<MockDBConnection>();
    {
        InSequence seq;
        EXPECT_CALL(*mock_conn, open()).WillOnce(Return(true));
        EXPECT_CALL(*mock_conn, execQuery(StrEq("QUERY"))).WillOnce(Return("RESULT"));
        EXPECT_CALL(*mock_conn, close());
    }

    ClassThatUsesDB obj(mock_conn);
    EXPECT_TRUE(obj.openConnection());
    EXPECT_EQ(obj.useConnection("QUERY"), "RESULT");
    obj.closeConnection();
}
