//
// Created by eal on 01/04/25.
//

#include "include/DatabaseAccessController/DatabaseAccessingObject.h"

#include "include/DatabaseAccessController/DatabaseAccessController.h"

DatabaseAccessingObject::DatabaseAccessingObject(const std::shared_ptr<SQLite::Database>& db, const std::string& key) : db_(db), key_(key), unlockingKey_(DatabaseAccessController::lockDatabase(key))
{
}

std::shared_ptr<SQLite::Database> DatabaseAccessingObject::getDatabase() const
{
  return db_;
}

DatabaseAccessingObject::~DatabaseAccessingObject()
{
  DatabaseAccessController::unlockDatabase(key_, unlockingKey_);
}
