//
// Created by Suhas Reddy on 3/9/25.
//

class SQL
{
  class Table
  {
  public:
    int row_id;
    int columns;
    unordered_map<int, vector<string>> rows;  // Use unordered_map for faster lookups

    Table(int cols) : row_id(0), columns(cols) {}
  };

  unordered_map<string, Table*> Database;  // Maps table name to Table object

public:
  SQL(vector<string>& names, vector<int>& columns)
  {
    for(size_t i = 0; i < names.size(); i++)
    {
      Database[names[i]] = new Table(columns[i]);
    }
  }

  bool ins(const string& name, vector<string> row)
  {
    auto it = Database.find(name);
    if (it == Database.end() || row.size() != it->second->columns)
      return false;

    Table* table = it->second;
    int row_id = ++(table->row_id);  // Increment row_id first
    table->rows[row_id] = row; // Move row to avoid deep copy

    return true;
  }

  void rmv(const string& name, int rowId)
  {
    auto it = Database.find(name);
    if (it != Database.end())
      it->second->rows.erase(rowId);
  }

  string sel(const string& name, int rowId, int columnId)
  {
    auto it = Database.find(name);
    if (it != Database.end())
    {
      auto& table = *(it->second);
      auto row_it = table.rows.find(rowId);

      if (row_it != table.rows.end())
      {
        if (columnId >= 1 && columnId <= table.columns)
          return row_it->second[columnId - 1];  // 0-based index for columnId
      }
    }
    return "<null>";
  }

  vector<string> exp(const string& name)
  {
    auto it = Database.find(name);
    if (it == Database.end())
      return {};

    Table* table = it->second;
    vector<string> result;
    result.reserve(table->rows.size());  // Optimize memory allocation

    for (const auto& [id, row] : table->rows)
    {
      string row_data = to_string(id);
      for (const auto& col : row)
        row_data += ',' + col;
      result.push_back(row_data);
    }
    return result;
  }

  ~SQL() {
    for (auto& [name, table] : Database) {
      delete table;
    }
  }
};


/**
 * Your SQL object will be instantiated and called as such:
 * SQL* obj = new SQL(names, columns);
 * bool param_1 = obj->ins(name,row);
 * obj->rmv(name,rowId);
 * string param_3 = obj->sel(name,rowId,columnId);
 * vector<string> param_4 = obj->exp(name);
 */