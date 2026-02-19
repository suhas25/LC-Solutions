//
// Created by Suhas Reddy on 4/18/25.
//

// Logger.cpp
#include "Logger.h"
#include <ctime>
#include <iomanip>
#include <iostream>
#include <mutex>
#include <sstream>

namespace utils {

struct Logger::Impl {
  std::string name_;
  Logger::Level level_ = Logger::Level::Debug;
  std::mutex mutex_;

  Impl(const std::string &name) : name_(name) {}

  void log(Level level, const std::string &msg) {
    if (level < level_)
      return;

    std::time_t t = std::time(nullptr);
    std::tm tm{};
#ifdef _WIN32
    localtime_s(&tm, &t);
#else
    localtime_r(&t, &tm);
#endif
    std::ostringstream oss;
    oss << "[" << std::put_time(&tm, "%Y-%m-%d %H:%M:%S") << "] "
        << "[" << name_ << "] "
        << "[" << levelToString(level) << "] " << msg;

    std::lock_guard<std::mutex> lock(mutex_);
    std::cout << oss.str() << std::endl;
  }

  void setLevel(Level lvl) {
    std::lock_guard<std::mutex> lock(mutex_);
    level_ = lvl;
  }

  void setName(const std::string &name) {
    std::lock_guard<std::mutex> lock(mutex_);
    name_ = name;
  }

  static const char *levelToString(Level level) {
    switch (level) {
    case Level::Debug:
      return "DEBUG";
    case Level::Info:
      return "INFO";
    case Level::Warning:
      return "WARNING";
    case Level::Error:
      return "ERROR";
    default:
      return "UNKNOWN";
    }
  }
};

Logger::Logger() : impl_(std::make_unique<Impl>("Logger")) {}

// scott meyer thread safe singleton without using double locked checking
// pattern
Logger &Logger::instance() {
  static Logger logger;
  return logger;
}

Logger::~Logger() = default;

void Logger::log(Level level, const std::string &message) {
  impl_->log(level, message);
}

void Logger::setLevel(Level level) { impl_->setLevel(level); }

void Logger::setName(const std::string &name) { impl_->setName(name); }

void Logger::debug(const std::string &message) { log(Level::Debug, message); }

void Logger::info(const std::string &message) { log(Level::Info, message); }

void Logger::warning(const std::string &message) { log(Level::Warning, message); }

void Logger::error(const std::string &message) { log(Level::Error, message); }

} // namespace utils
