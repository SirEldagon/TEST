#include <gmock/gmock.h>

class MockDBConnection : public IDBConnection {
public:
    MOCK_METHOD(bool, open, (), (override));
    MOCK_METHOD(void, close, (), (override));
    MOCK_METHOD(std::string, execQuery, (const std::string& query), (override));
};
