class DBConnection : public IDBConnection {
public:
    bool open() override {
        // Реализация открытия соединения
        return true;
    }
    void close() override {
        // Реализация закрытия
    }
    std::string execQuery(const std::string& query) override {
        // Реализация выполнения запроса
        return "result";
    }
};
