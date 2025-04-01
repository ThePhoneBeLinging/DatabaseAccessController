//
// Created by eal on 01/04/25.
//

#ifndef DATABASEACCESSINGOBJECT_H
#define DATABASEACCESSINGOBJECT_H
#include "SQLiteCpp/Backup.h"


class DatabaseAccessingObject
{
public:
  DatabaseAccessingObject(const std::shared_ptr<SQLite::Database>& db, const std::string& key);
  [[nodiscard]] std::shared_ptr<SQLite::Database> getDatabase() const;
  virtual ~DatabaseAccessingObject();
private:
  std::shared_ptr<SQLite::Database> db_;
  std::string key_;
  int unlockingKey_;
};



#endif //DATABASEACCESSINGOBJECT_H
