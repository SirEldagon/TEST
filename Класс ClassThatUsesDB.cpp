class ClassThatUsesDB {
public:
    explicit ClassThatUsesDB(std::shared_ptr<IDBConnection> conn)
        : connection(std::move(conn)) {}

    bool openConnection() {
        return connection->open();
    }

    std::string useConnection(const std::string& query) {
        return connection->execQuery(query);
    }

    void closeConnection() {
        connection->close();
    }

private:
    std::shared_ptr<IDBConnection> connection;
};
