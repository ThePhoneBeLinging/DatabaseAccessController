//
// Created by eal on 08/03/25.
//

#include "DatabaseAccessController/DatabaseAccessController.h"

#include <memory>

void DatabaseAccessController::addDatabase(const std::shared_ptr<SQLite::Database>& db, const std::string& key)
{
    databases_[key] = db;
}

std::unique_ptr<DatabaseAccessingObject> DatabaseAccessController::getDatabase(const std::string& key)
{
    return std::make_unique<DatabaseAccessingObject>(databases_[key], key);
}

int DatabaseAccessController::lockDatabase(const std::string& key)
{
    mutexes_[key].lock();
    int maxActiveConnections = 100;
    ++currentID_ %= maxActiveConnections;
    ownershipVerifier_[key] = currentID_;
    return currentID_;
}

void DatabaseAccessController::unlockDatabase(const std::string& key, const int changeID)
{
    if (ownershipVerifier_[key] == changeID)
    {
        mutexes_[key].unlock();
    }
}
