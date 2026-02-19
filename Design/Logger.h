//
// Created by Suhas Reddy on 4/18/25.
//
// Logger.h
#pragma once
#include <memory>
#include <string>

namespace utils {

class Logger {
public:
  enum class Level { Debug, Info, Warning, Error };

  // singleton accessor
  static Logger &instance();

  Logger(const Logger &) = delete;
  Logger &operator=(const Logger &) = delete;

  Logger(Logger &&) = delete;
  Logger &operator=(Logger &&) = delete;

  ~Logger(); // not defaulted here — must be defined in .cpp (for
             // unique_ptr<impl> to work)

  void log(Level level, const std::string &message);
  void setLevel(Level level);
  void setName(const std::string &name);

  // Convenience methods
  void debug(const std::string &message);
  void info(const std::string &message);
  void warning(const std::string &message);
  void error(const std::string &message);

private:
  Logger();
  struct Impl;
  std::unique_ptr<Impl> impl_;
};

} // namespace utils
