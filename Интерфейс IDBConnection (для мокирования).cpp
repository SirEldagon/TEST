#include <string>

class IDBConnection {
public:
    virtual ~IDBConnection() = default;
    virtual bool open() = 0;
    virtual void close() = 0;
    virtual std::string execQuery(const std::string& query) = 0;
};
