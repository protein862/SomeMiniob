/* Copyright (c) 2021 OceanBase and/or its affiliates. All rights reserved.
miniob is licensed under Mulan PSL v2.
You can use this software according to the terms and conditions of the Mulan PSL v2.
You may obtain a copy of Mulan PSL v2 at:
         http://license.coscl.org.cn/MulanPSL2
THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND,
EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT,
MERCHANTABILITY OR FIT FOR A PARTICULAR PURPOSE.
See the Mulan PSL v2 for more details. */

//
// Created by Wangyunlai on 2023/6/13.
//

#include "sql/executor/create_table_executor.h"

#include "event/sql_event.h"
#include "sql/stmt/drop_table_stmt.h"
#include "drop_table_executor.h"
#include "event/session_event.h"
#include "session/session.h"
#include "storage/db/db.h"


RC DropTableExecutor::execute(SQLStageEvent *sql_event)
{
  DropTableStmt *stmt = (DropTableStmt *)sql_event->stmt();
  Db *db = sql_event->session_event()->session()->get_current_db();
  return db->drop_table(stmt->table_name().c_str());

}