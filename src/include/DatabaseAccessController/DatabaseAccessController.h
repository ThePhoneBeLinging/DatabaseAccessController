//
// Created by eal on 08/03/25.
//

#ifndef DATABASEACCESSCONTROLLER_H
#define DATABASEACCESSCONTROLLER_H
#include <memory>
#include <unordered_map>

#include "SQLiteCpp/Database.h"


class DatabaseAccessController
{
public:
    static void addDatabase(const std::shared_ptr<SQLite::Database>& db, const std::string& key);
    static std::shared_ptr<SQLite::Database> getDatabase(const std::string& key);
    static int lockDatabase(const std::string& key);
    static void unlockDatabase(const std::string& key, int changeID);
private:
    static inline int currentID_ = 0;
    static inline std::unordered_map<std::string, std::shared_ptr<SQLite::Database>> databases_;
    static inline std::unordered_map<std::string, std::mutex> mutexes_;
    static inline std::unordered_map<std::string, int> ownershipVerifier_;

};



#endif //DATABASEACCESSCONTROLLER_H
