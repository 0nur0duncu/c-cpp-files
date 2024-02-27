#include <iostream>
#include <sqlite3.h>

int main() {
  sqlite3* db;
  int rc = sqlite3_open("mydatabase.db", &db);

  if (rc != SQLITE_OK) {
    std::cerr << "Failed to open database: " << sqlite3_errmsg(db) << std::endl;
    sqlite3_close(db);
    return 1;
  }

  sqlite3_stmt* stmt;
  rc = sqlite3_prepare_v2(db, "SELECT name FROM users WHERE age > ?", -1, &stmt, nullptr);

  if (rc != SQLITE_OK) {
    std::cerr << "Failed to prepare statement: " << sqlite3_errmsg(db) << std::endl;
    sqlite3_close(db);
    return 1;
  }

  rc = sqlite3_bind_int(stmt, 1, 18);

  if (rc != SQLITE_OK) {
    std::cerr << "Failed to bind parameter: " << sqlite3_errmsg(db) << std::endl;
    sqlite3_finalize(stmt);
    sqlite3_close(db);
    return 1;
  }

  while (sqlite3_step(stmt) == SQLITE_ROW) {
    const char* name = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0));
    std::cout << name << std::endl;
  }

  sqlite3_finalize(stmt);
  sqlite3_close(db);
  return 0;
}
